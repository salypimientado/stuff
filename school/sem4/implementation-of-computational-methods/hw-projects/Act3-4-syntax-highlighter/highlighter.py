import subprocess
import re

def getTokens():
    cmd = subprocess.Popen("./highlighter test.txt",shell=True,stdout=subprocess.PIPE)
    for line in cmd.stdout:
        line = line.decode('ascii').replace('\n', '')
        line = line.split(' ',1)
        #state = re.match('^\w+', line)
       # token = re.match('(?<!(^\w+))',line)
       # print(state[0])
       # print(token[0])
        print(line[0])
        print(line[1])

getTokens()
