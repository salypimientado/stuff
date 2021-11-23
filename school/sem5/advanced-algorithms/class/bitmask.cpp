#include <iostream>
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

  double getArea(Vertice v1, Vertice prev, Vertice door){
    float extra = 0;
    int triangles = 0;
    if(v1.x == prev.x || v1.y == prev.y) triangles = 1;
    if(v1.x != prev.x && v1.y != prev.y) triangles = 2;
    else triangles = 3;
    auto t1 = (v1.x*prev.y - prev.x*v1.y + prev.x*door.y - door.x*prev.y + door.x*v1.y - v1.x*door.y)/2;

    return (v1.x*prev.y - prev.x*v1.y + prev.x*door.y - door.x*prev.y + door.x*v1.y - v1.x*door.y)/2;
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

int main(){
  int width, height, idoor, workers;
  cin >> width >> height >> idoor >> workers;

  workers--;

  auto remainingLength = WHToLength(width, height);

  Vertice door(idoor,0);
  Vertice prev(width,0);
  Vertice right(width,0);
  Vertice left(0,0);
  Vertice midPoint(0,0);
  
  vector<Vertice> res;
  auto start = Vertice(0,0);
  double area = 0;
  double targetArea = width * height / workers+1;
  for(int i = 0; i<=workers; i++){
    left = lengthToVertice(0, width, height);
    right = lengthToVertice(remainingLength, width, height);
    while(verticeToLength(left,width, height) < verticeToLength(right,width, height) && abs(area-targetArea) > EPSILON)
      {
        cout << verticeToLength(left,width, height) << " - " << verticeToLength(right,width, height) <<endl;
        midPoint = lengthToVertice((verticeToLength(left, width, height) + verticeToLength(right, width, height))/2, width, height);
         // cout << "left " << left.x << ", " << left.y << endl;
         // cout << "midPoint " << midPoint.x << ", " << midPoint.y << endl;
         // cout << "right " << right.x << ", " << right.y << endl;
        cin >> idoor;
        area = getArea(midPoint,prev,door);
        cout << "area " << area << endl;
        if(abs(area-targetArea) < EPSILON){
          break;
        }
        if(area < targetArea){
          right = midPoint;
        }
        if(area > targetArea){
          left = midPoint;
        }
      }
    res.push_back(midPoint);
    prev = midPoint;
    remainingLength = verticeToLength(midPoint,width,height);
  }
  for(auto v: res) cout << v.x << ", " << v.y << endl;
}
