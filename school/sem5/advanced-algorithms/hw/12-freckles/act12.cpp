#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_set>

using namespace std;
 
typedef  pair<int, int> iPair;
 
struct Graph {
    int V, E;
  double costMSTKruskal, costMSTPrim;
    vector< pair<double, pair<int, int>> > edges;
    vector<vector<pair<int, double>>> adjList;
    vector<pair<int,int>> selectedEdgesP;
    vector<pair<int,int>> selectedEdgesK;
 
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        adjList.resize(V);
        costMSTKruskal = 0;
        costMSTPrim = 0;
    }
 
    void addEdge(int u, int v, double w) {
        edges.push_back({w, {u, v}});
        adjList[u].push_back({v,w});
    }
    void load();
    void print();
    void printEdges(int mode);
    void kruskalMST();
    void primMST();
};
 
// To represent Disjoint Sets
struct DisjointSets
{
    int *parent, *rnk;
    int n;
 
    DisjointSets(int n){
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++){
            rnk[i] = 0;
            parent[i] = i;
        }
    }
 
    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
      /* Make the parent of the nodes in the path
           from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
  
        /* Make tree with smaller height
           a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

void Graph::load(){
    float v1, v2, v3, v4;
    vector<pair<float,float>> points;
    for (int i=0; i<V; i++){
      //cout << "i:"<< i;
        cin >> v1 >> v2;
        points.push_back(make_pair(v1,v2));
    }
    for(auto i =0; i< points.size(); ++i){
      v1 = points[i].first;
      v2 = points[i].second;
      for(auto j =0; j< points.size(); ++j){
        if(j!=i){
        v3 = points[j].first;
        v4 = points[j].second;
        auto distance = sqrt(pow(v1-v3,2) + pow(v2-v4,2));
        //cout<<"("<< v1<<","<<v2<<")"<< ", ("<< v3<<","<<v4<<") : "<< distance<<endl;
        addEdge(i,j,distance);
        }
      }
    }
}

void Graph::print(){
    cout << "Adjacent List:" << endl;
    for (int i=0; i<V; i++){
      cout << " " << i << ": ";
        for (int j=0; j<adjList[i].size(); j++){
            cout << "(" << adjList[i][j].first << "," << adjList[i][j].second << ") ";
        }
        cout << endl;
    }
}
void Graph::kruskalMST(){
// Aquí va tu código
  costMSTKruskal = 0;
  sort(edges.begin(),edges.end());
  DisjointSets ds(V);
  for(auto i:edges){
    int u = i.second.first;
    int v = i.second.second;
    int set_u = ds.find(u);
    int set_v = ds.find(v);
    if(set_u != set_v){
      ds.merge(u,v);
      costMSTKruskal += i.first;
      selectedEdgesK.push_back(make_pair(u,v));
    }

  }
}

// O(V^2)
void Graph::primMST(){
// Aquí va tu código
  int selectedSource = 0;
  costMSTPrim = 0;
  unordered_set<int> selected;
  unordered_set<int> missing;
  selected.insert(0);
  for(int i =1; i<V;i++){
    missing.insert(i);
  }
  int connected = V-1, selVertex;
  float minCost;
  while(connected > 0){
    minCost = INT_MAX-1;
    for(auto it1:selected){
      for(auto it2 = adjList[it1].begin(); it2!=adjList[it1].end();it2++){
        if(missing.find((*it2).first) != missing.end() && (*it2).second < minCost){
          minCost = (*it2).second;
          selVertex = (*it2).first;
          selectedSource = it1;
        }
      }
    }
    costMSTPrim += minCost;
    selected.insert(selVertex);
    missing.erase(selVertex);
    selectedEdgesP.push_back(make_pair(selectedSource,selVertex));
    connected--;
  }
}

void Graph::printEdges(int mode){
  switch (mode){
  case 0:
    cout<<"Selected Edges Prim: "<<endl;
    for(auto i: selectedEdgesP) cout<< "(" << i.first<<","<<i.second<<")"<<endl;
    break;
  case 1:
    cout<<"Selected Edges Kruskal: "<<endl;
    for(auto i: selectedEdgesK) cout<< "(" << i.first<<","<<i.second<<")"<<endl;
    break;
    }
}

int main(){
  int V, E;
  cin>> V;
  E = V*V;
  Graph g(V, E-1);

  g.load();
  g.primMST();
  g.kruskalMST();
  //auto value = std::round(g.costMSTPrim * 100.0) / 100.0;
  printf("%f\n",g.costMSTPrim);
  printf("%f\n",g.costMSTKruskal);
  return 0;
}

/*
  origin target cost
Unidrected Graph
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

7
73692.0 51121.0
8269.0 6553.0
56208.0 90591.0
35772.0 35859.0
86938.0 23299.0
3883.0 66193.0
93085.0 89307.0

9
86087 69233
5385 -81607
30783 -16800
40238 82064
52439 -47509
-90507 47216
-34353 26527
51282 98207
-26932 -50592

3
1.0 1.0
2.0 2.0
2.0 4.0

80
0.0056 0.52
0.76 0.66
0.28 0.95
0.21 0.029
0.67 0.7
0.51 0.43
0.23 0.41
0.43 0.9
0.12 0.72
0.16 0.2
0.78 0.97
0.0038 0.79
0.47 0.89
0.3 0.59
0.72 0.016
0.23 0.15
0.65 0.23
0.2 0.59
0.54 0.63
0.95 0.0065
0.25 0.71
0.8 0.52
0.56 0.67
0.37 0.49
0.32 0.6
0.48 0.84
0.34 0.57
0.76 0.46
0.83 0.81
0.86 0.43
0.14 0.54
0.56 0.27
0.93 0.17
0.96 0.58
0.75 0.37
0.29 0.62
0.74 0.15
0.9 0.67
0.28 0.93
0.47 0.24
0.058 0.48
0.02 0.032
0.42 0.81
0.96 0.42
0.49 0.39
0.48 0.48
0.31 1
0.09 0.9
0.062 0.88
0.82 0.48
0.059 0.38
0.53 0.73
0.4 0.94
0.29 0.68
0.26 0.026
0.25 0.074
0.5 0.22
0.11 0.075
0.54 0.009
0.23 0.61
0.71 0.91
0.17 0.38
0.83 0.96
0.47 0.2
0.78 0.99
0.11 0.18
0.32 0.7
0.88 0.16
0.27 0.55
0.092 0.94
0.96 0.025
0.53 0.39
0.56 0.061
0.38 0.92
0.58 0.95
0.58 0.1
0.37 0.66
0.12 0.31
0.4 0.58
0.52 0.86

-0.4 0.38
-0.61 0.91
-0.4 0.66
-0.78 0.61
-0.19 0.026
-0.29 0.033
-0.28 0.64
-0.46 0.57
-0.96 0.81
-0.85 0.6
-0.32 0.019
-0.11 0.095
-0.029 0.018
-0.53 0.16
-0.72 0.82
-0.41 0.46
-0.8 1
-0.59 0.3
-0.24 0.78
-0.84 0.11
-0.58 0.0032
-0.078 0.65
-0.32 0.97
-0.91 0.13
-0.74 0.23
-0.85 0.56
-0.87 0.55
-0.38 0.61
-0.66 0.73
-0.71 0.6
-0.19 0.93
-0.26 0.049
-0.72 0.98
-0.88 0.0046
-0.46 0.82
-0.81 0.89
-0.12 0.75
-0.8 0.32
-0.18 0.76
-0.88 0.51
-0.49 0.31
-1 0.73
-0.6 0.88
-0.36 0.74
-0.76 0.72
-0.42 0.67
-0.078 0.54
-0.42 0.96
-0.38 0.92
-0.16 0.93
-0.44 0.95
-0.87 0.37
-0.99 0.92
-0.32 0.0019
-0.4 0.87
-0.13 0.24
-0.023 0.77
-0.25 0.033
-0.28 0.33
-0.33 0.33
-0.17 0.88
-0.067 0.8
-0.96 0.84
-0.55 0.036
-0.29 0.82
-0.24 0.44
-0.5 0.71
-0.52 0.55
-0.72 0.014
-0.81 0.74
-0.82 0.46
-0.15 0.64
-0.77 0.9
-0.9 0.54
-1 0.23
-0.59 0.56
-0.053 0.53
-0.98 0.33
-0.96 0.32
-0.51 0.21

80
66 7
37 1
57 35
81 45
34 9
3 21
6 17
6 99
98 63
80 49
84 87
13 11
58 27
34 50
51 83
31 77
64 7
30 45
12 94
76 88
4 36
15 18
55 54
67 18
30 61
63 90
93 89
19 34
3 3
83 1
17 19
26 49
70 72
32 50
8 70
7 92
41 79
56 65
99 10
52 41
16 38
4 85
69 29
65 10
13 95
92 34
47 68
47 33
38 68
94 10
11 99
67 96
50 12
3 7
5 38
69 77
1 19
1 47
32 42
42 74
56 59
10 36
59 2
55 52
9 75
31 62
2 61
50 6
49 46
55 63
98 6
52 85
68 68
63 61
28 90
68 82
34 76
85 64
78 60
25 39
*/
