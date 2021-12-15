#!/usr/bin/env python
# coding: utf-8

# In[1]:


# La clase `Model` se hace cargo de los atributos a nivel del modelo, maneja los agentes. 
# Cada modelo puede contener múltiples agentes y todos ellos son instancias de la clase `Agent`.
from mesa import Agent, Model

from mesa.space import MultiGrid

from mesa.batchrunner import BatchRunnerMP
# Con `SimultaneousActivation` hacemos que todos los agentes se activen de manera simultanea.
from mesa.time import SimultaneousActivation, RandomActivation, BaseScheduler

# Vamos a hacer uso de `DataCollector` para obtener el grid completo cada paso (o generación) y lo usaremos para graficarlo.
from mesa.datacollection import DataCollector

# mathplotlib lo usamos para graficar/visualizar como evoluciona el autómata celular.
'''
%matplotlib inline
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import cm
plt.rcParams["animation.html"] = "jshtml"
matplotlib.rcParams['animation.embed_limit'] = 2**128
'''

# Definimos los siguientes paquetes para manejar valores númericos.
import numpy as np
import pandas as pd

import itertools
import random
from enum import Enum
from collections import OrderedDict

from flask import Flask

# Definimos otros paquetes que vamos a usar para medir el tiempo de ejecución de nuestro algoritmo.
import time
import datetime


# In[2]:


def get_grid(model):
    dimensions = model.grid.width, model.grid.height
    grid = np.zeros(dimensions)
    for x, line in enumerate(grid):
        for y, _ in enumerate(line):
            # amount of dirt agents in cell
            car = len(list(filter(lambda agent: isinstance(agent,carAgent), model.grid.iter_neighbors((x,y), False, True, 0)))) 
            #print(f'{x=} {y=} {dirt=}')
            # len of dirt agents in cell
            lights = list(filter(lambda agent: isinstance(agent,trafficLight), model.grid.iter_neighbors((x,y), False, True, 0)))
            light_status = lights[0].state if lights else (4 if car else 5)
            #print(f'{vacuums=}')
            if not car:
                if light_status == 0:
                    grid[x][y] = 0
                elif light_status == 1:
                    grid[x][y] = 5
                elif light_status == 2 or light_status == 3:
                    grid[x][y] = 2
                elif light_status == 5:
                    grid[x][y] = 8
            else:
                if light_status != 4:
                    if light_status == 0:
                        grid[x][y] = 4
                    elif light_status == 1:
                        grid[x][y] = 5
                    elif light_status == 2 or light_status == 3:
                        grid[x][y] = 1
                else:
                    grid[x][y] = 7
    return grid

def get_other_lights(id, model):
    return [agent for agent in model.traffic_lights_schedule.agents if agent.id != id]

class direction():
    UP = -1, 0
    DOWN = 1, 0
    LEFT = 0, -1
    RIGHT = 0, 1
    lst = [UP,DOWN,RIGHT,LEFT]
    
class states():
    RED = 0
    YELLOW = 1
    GREEN = 2
    SECONDTICK = 3

class carAgent(Agent):
    def __init__(self, unique_id, coords, direction, model):
        super().__init__(unique_id,model)
        self.id = unique_id
        self.coords = coords
        self.model = model
        self.direction = direction
        self.next_coords = coords
        self.done = False
    
    def step(self):
        canMove = not any([(isinstance(agent,trafficLight) and agent.state == states.RED)
                          for agent in self.model.grid.iter_neighbors(self.coords, False, True, 0)]) and not \
                                       any([isinstance(agent,carAgent) and agent.coords == (self.coords[0] + self.direction[0], self.coords[1] + self.direction[1]) \
                                            and agent.direction == self.direction for agent in self.model.grid.iter_neighbors(self.coords, False, True, 1)])
        if canMove:
            self.next_coords = self.coords[0] + self.direction[0], self.coords[1] + self.direction[1]
            if self.model.grid.out_of_bounds(self.next_coords):
                if not self.done:
                    self.model.kill_agents.append(self)
                self.done = True
                
        
    def advance(self):
        if not self.done:
            self.coords = self.next_coords
            self.model.grid.move_agent(self,self.coords)

# scheduler goes through each traffic light randomly
# if light has car below it, set all other lights to red
# next step does nothing
# next step sets all lights to yellow before anything happens
class trafficLight(Agent):
    def __init__(self, unique_id, coords, model):
        super().__init__(unique_id,model)
        self.id = unique_id
        self.coords = coords
        self.model = model
        self.state = states.YELLOW
        self.blocked_steps = 0
        self.reset_state = False
    

    def setRed(self):
        self.state = states.RED
        self.blocked_steps = 3
    
    def unblock(self):
        self.blocked_steps = self.blocked_steps - 1
        if self.blocked_steps == 0:
            self.reset_state = True
    
    def step(self):
        isGreen = self.state == states.GREEN
        if self.blocked_steps > 0 and not isGreen:
            return
        if self.reset_state:
            self.state = states.YELLOW
            self.reset_state = False
        car = any([isinstance(agent, carAgent) for agent in self.model.grid.iter_neighbors(self.coords, False, True, 0)])
        if car:
            for light in get_other_lights(self.id, self.model):
                light.setRed()
            self.state = states.GREEN
            self.blocked_steps = 3
        
                
class TrafficScheduler(BaseScheduler):
    def __init__(self, model):
        self.model = model
        self.steps = 0
        self.time = 0
        self._agents=OrderedDict()
        
    def step(self):
        v = list(self._agents.values())
        random_lights = random.sample(v, len(v))
        for agent in random_lights:
            agent.step()
        for agent in self._agents.values():
            agent.unblock()
        self.steps += 1
        self.time += 1 
        
def stateToString(state):
    if state == states.RED:
        return "RED"
    elif state == states.YELLOW:
        return "YELLOW"
    else:
        return "GREEN"

class trafficSimulation(Model):
    def __init__(self, spawn_speed):
        self.spawn_speed = spawn_speed
        self.counter = 0
        self.traffic_lights_schedule = TrafficScheduler(self)
        self.cars_schedule = SimultaneousActivation(self)
        self.grid = MultiGrid(10,10,False)
        self.id = 0
        self.spawnpoints = [(9,5),(0,4),(6,0),(5,9)]
        self.kill_agents = []
        
        self.datacollector = DataCollector(
            model_reporters={"Grid": get_grid})
        
        traffic_light_coords = [(7,5),(4,4),(6,3),(5,6)]

        for coord in traffic_light_coords:
            light = trafficLight(self.id, coord, self)
            self.id = self.id + 1
            self.grid.place_agent(light,coord)
            self.traffic_lights_schedule.add(light)
            self.datacollector.collect(self)
            
    def get_data(self):
        traffic_lights = [{"coords":{"x":agent.coords[0],"y":agent.coords[1]}, "state": stateToString(agent.state)} for agent in get_other_lights(-1,self)]
        cars = [{"direction":{"x":agent.direction[0],"y":agent.direction[1]},"coords": {"x":agent.coords[0],"y":agent.coords[1]}} for agent in self.cars_schedule.agents]
        return traffic_lights, cars
    
    def step(self):

        self.traffic_lights_schedule.step()
        self.cars_schedule.step()
        
        if self.counter == self.spawn_speed-1 and random.random() > 0.5:
            orientation, coords = random.choice([x for x in zip(direction.lst,self.spawnpoints)])
            anyCar = any([isinstance(agent, carAgent) for agent in self.grid.iter_neighbors(coords, False, True, 0)])
            if not anyCar:
                car = carAgent(self.id, coords, orientation, self)
                self.grid.place_agent(car,coords)
                self.cars_schedule.add(car)
                self.id = self.id + 1
        self.counter = (self.counter + 1) % self.spawn_speed
        
        
        for x in self.kill_agents:
            self.grid.remove_agent(x)
            self.cars_schedule.remove(x)
            self.kill_agents.remove(x)
        


# In[47]:


m = trafficSimulation(1)


# In[48]:




app = Flask(__name__)

@app.route("/")
def get_next_version():
    m.step()
    traffic_lights, cars = m.get_data()
    return {"traffic_lights":traffic_lights, "cars": cars}


# In[49]:


'''
%%capture
df = m.datacollector.get_model_vars_dataframe()

cmap = plt.cm.Pastel1
fig, axs = plt.subplots(figsize=(10,10))
axs.set_xticks([])
axs.set_yticks([])
patch = plt.imshow(df.iloc[0][0], cmap=cmap, vmin=-0.1)

def animate(i):
    patch.set_data(df.iloc[i][0])
    
anim = animation.FuncAnimation(fig, animate, frames=steps)

anim
'''


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




