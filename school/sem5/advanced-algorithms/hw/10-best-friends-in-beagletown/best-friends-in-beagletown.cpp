// A01740200 - Juan Pablo Salazar Garcia
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

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

pair<float,pair<Point,Point>> bruteForce(vector<Point> &P, int ini, int fin) {
  float minBF = FLT_MAX;
  auto i1 = P[ini];
  auto i2 = P[fin];
  for (int i = ini; i < fin; i++) {
    for (int j = i+1; j <= fin; j++) {
      if(dist(P[i], P[j]) < minBF){
        minBF = dist(P[i],P[j]);
        i1 = P[i];
        i2 = P[j];
      }
      
    }
  }
  return make_pair(minBF,make_pair(i1,i2));
}

pair<float,pair<Point,Point>> stripClosest(vector<Point> &strip, float dMenor, Point m1, Point m2){
  float minStrip = dMenor;
  auto i1 = m1;
  auto i2 = m2;
  sort(strip.begin(),strip.end(),[](auto p1, auto p2){ return p1.y < p2.y;});
  for(int i=0; i<strip.size()-1; ++i){
    for(int j = i+1; j< strip.size() && (strip[j].y-strip[i].y)< minStrip; ++j){
      if(dist(strip[i], strip[j]) < minStrip){
        minStrip = dist(strip[i], strip[j]);
        i1 = strip[i];
        i2 = strip[j];
      }
    }
  }
    return make_pair(minStrip,make_pair(i1,i2));
}

pair<float,pair<Point,Point>> closestHelper(vector<Point> &P, int ini, int fin) {
  // Si existen 3 o menos puntos bruteforce mejor
  if (fin - ini < 3) {
    return bruteForce(P, ini, fin);
  }
  int mid = (fin + ini) /2;
  Point midPoint = P[mid];
  auto res = closestHelper(P, ini, mid);
  auto dl = res.first;
  auto points1 = res.second;
  auto res2 = closestHelper(P, mid+1, fin);
  auto dr = res2.first;
  auto points2 = res2.second;
  float dMenor;
  pair<Point,Point> pIndexes;
  if(dl < dr){
    dMenor = dl;
    pIndexes = points1;
  }
  else{
    dMenor = dr;
    pIndexes = points2;
  }
  vector<Point> strip;
  copy_if(P.begin()+ini,P.begin()+fin,back_inserter(strip),[&midPoint, &dMenor](Point p1){return abs(p1.x - midPoint.x) < dMenor;});
  auto dResult = stripClosest(strip, dMenor, pIndexes.first, pIndexes.second);
  return dResult;
}

// O(nlogn)
pair<float,pair<Point,Point>> closest(vector<Point> &P) {
  // sort based on x axis
  sort(P.begin(), P.end(), [](Point p1, Point p2) { return p1.x < p2.x; });
  return closestHelper(P, 0, P.size() - 1);
}

struct pair_hash
{
  template <class T1, class T2>
  std::size_t operator() (const std::pair<T1, T2> &pair) const {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};

int main() {
  int n;
  float x, y;
  string name;
  unordered_map<pair<float,float>,string, pair_hash> names;
  cin >> n;
  vector<Point> P(n);
  for (int i = 0; i < n; i++) {
    cin >>name>> x >> y;
    P[i] = Point(x, y);
    names.insert({make_pair(x,y),name});
  }

  cout.precision(2);
  auto ans= closest(P);
  auto res = ans.first;
  auto indexes = ans.second;
  auto p1 = make_pair(float(indexes.first.x),float(indexes.first.y));
  auto p2 = make_pair(float(indexes.second.x),float(indexes.second.y));
  cout<< "Posicion perro 1: "<< fixed<<p1.first << ", "<<p1.second<<endl;
  cout<< "Posicion perro 2: "<< fixed<<p2.first << ", "<<p2.second<<endl;
  string perro1 = names.at(p1);
  string perro2 = names.at(p2);

  if(perro1.compare(perro2) > 0){
    auto tmp = perro1;
    perro1 = perro2;
    perro2 = tmp;
  }
  cout << "Best friend in BeagleTown are: " << perro1 << " & " << perro2 << " (" <<fixed<< res << ")"<< endl;
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
