
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <ranges>

using namespace std;

struct Point {
  float x, y;
  Point() { x = y = 0; }
  Point(float x, float y) {
    this->x = x;
    this->y = y;
  }
};

float dist(Point &p1, Point &p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

float bruteForce(vector<Point> &P, int ini, int fin) {
  float minBF = FLT_MAX;
  for (int i = ini; i < fin; i++) {
    for (int j = i+1; j <= fin; j++) {
      minBF = min(minBF, dist(P[i],P[j]));
    }
  }
  return minBF;
}

float stripClosest(vector<Point> &strip, float dMenor){
  float minStrip = dMenor;
  sort(strip.begin(),strip.end(),[](auto p1, auto p2){ return p1.y < p2.y;});
  for(int i=0; i<strip.size()-1; ++i){
    for(int j = i+1; j< strip.size() && (strip[j].y-strip[i].y)< minStrip; ++j){
      minStrip = min(minStrip, dist(strip[i], strip[j]));
    }
  }
  return minStrip;
}

float closestHelper(vector<Point> &P, int ini, int fin) {
  // Si existen 3 o menos puntos bruteforce mejor
  if (fin - ini < 3) {
    return bruteForce(P, ini, fin);
  }
  int mid = (fin + ini) /2;
  Point midPoint = P[mid];
  float dl = closestHelper(P, ini, mid);
  float dr = closestHelper(P, mid+1, fin);
  float dMenor = min(dl,dr);
  vector<Point> strip;
  copy_if(P.begin()+ini,P.begin()+fin,back_inserter(strip),[&midPoint, &dMenor](Point p1){return abs(p1.x - midPoint.x) < dMenor;});
  auto dResult = stripClosest(strip, dMenor);
  return dResult;
}

float closest(vector<Point> &P) {
  // sort based on x axis
  sort(P.begin(), P.end(), [](Point p1, Point p2) { return p1.x < p2.x; });
  return closestHelper(P, 0, P.size() - 1);
}

int main() {
  int n;
  float x, y;
  cin >> n;
  vector<Point> P(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    P[i] = Point(x, y);
  }
  cout.precision(2);
  cout << "La distancia menor es: " << fixed << closest(P) << endl;
}

// ordenar nombres lexicograficamente para tarea

/*
5
5 10
2 30
1 15
10 2
20 5
 */
