// Juan Pablo Salazar Garcia - A01740200

#include <iostream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

const double EPSILON = 10 * pow(10,-8);

struct Vertice{
  double x;
  double y;
  Vertice(double x, double y){
    this->x = x;
    this->y = y;
  }
};

double triangleArea(Vertice v1, Vertice v2, Vertice v3){
  return abs(v1.x*(v2.y-v3.y) + v2.x*(v3.y-v1.y) + v3.x*(v1.y-v2.y))/2;
}

double getArea(Vertice v1, Vertice prev, Vertice door, Vertice topRight){
  Vertice topLeft = Vertice(0,topRight.y);
    double res = 0;
    int triangles = 0;
    if(v1.x == prev.x || v1.y == prev.y) triangles = 1;
    else if(v1.x != prev.x && v1.y != prev.y) triangles = 2;
    else triangles = 3;
    auto t1 = triangleArea(v1,prev,door);
    res += t1;
    if(triangles == 2){
      if(prev.x == topRight.x){
        res += triangleArea(v1, prev, topRight);
      }
      else{
        res += triangleArea(v1, prev, topLeft);
      }
    }
    else if(triangles == 3){
      res += triangleArea(v1, prev, topLeft);
      res += triangleArea(v1, prev, topRight);
    }
    return res;
}

double WHToLength(double width, double height){
  return width + 2*height;
}

double verticeToLength(Vertice v, double maxWidth, double maxHeight){
  if(v.x == maxWidth) return maxWidth + 2*maxHeight - v.y;
  if(v.y == maxHeight) return maxHeight + v.x;
  else return v.y;
}

Vertice lengthToVertice(double length, double maxWidth, double maxHeight){
  if(maxHeight - length >= 0) return Vertice(0,length);
  auto rem = length - maxHeight;
  if(maxWidth - rem >= 0) return Vertice(rem, maxHeight);
  rem -= maxWidth;
  return Vertice(maxWidth, maxHeight-rem);
}

// WIDTH HEIGHT DOOR WORKERS

// Complejidad por vertice a buscar O(logm) donde m es el largo del perimetro en el que buscar
// Complejidad completa: O(nlogm) donde n es el numero de trabajadores
int main(){
  double width, height, idoor, workers;
  string test;

  workers;

  cin >> width >> height >> idoor >> workers;
  while(width || height || idoor || workers) {
  auto remainingLength = WHToLength(width, height);

  Vertice door(idoor,0);
  Vertice prev(width,0);
  Vertice right(width,0);
  Vertice topRight(width, height);
  Vertice left(0,0);
  Vertice midPoint(0,0);
  
  vector<Vertice> res;
  auto start = Vertice(0,0);
  double area = 0;
  double targetArea = width * height / (workers);
  for(int i = 0; i<workers-1; i++){
    left = lengthToVertice(0, width, height);
    right = lengthToVertice(remainingLength, width, height);
    area = 0;
    while(verticeToLength(left,width, height) < verticeToLength(right,width, height) && abs(area-targetArea) > EPSILON)
      {
        double offset = 0;
        //cout << verticeToLength(left,width, height) << " - " << verticeToLength(right,width, height) <<endl;
        midPoint = lengthToVertice((verticeToLength(left, width, height) + verticeToLength(right, width, height))/2, width, height);
        area = getArea(midPoint,prev,door,topRight);
        if(abs(area-targetArea) < EPSILON){
          break;
        }
        if(area < targetArea){
          right = midPoint;
          //cout << "set right to" << right.x << ", " << right.y << endl;
        }
        if(area > targetArea){
          left = midPoint;
        }
      }
    //cout << "area "<< area << endl;
    res.push_back(midPoint);
    prev = midPoint;
    remainingLength = verticeToLength(midPoint,width,height);
  }
  printf("%.3f %.3f",res[0].x, res[0].y);
  for(int i = 1; i< res.size(); i++) printf(" %.3f %.3f",res[i].x, res[i].y);
  cout <<endl;
    cin >> width >> height >> idoor >> workers;
}
}
