#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX
#define Edge pair<int,int>
#define Graph vector<vector<Edge>>
#define Vertex pair<int,int>

vector<int> dijkstra(const Graph &G, int source){
  vector<int> dist(G.size(), INF);
  dist[source] = 0;
  priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue;
  Vertex vs(0,source);
  queue.push(vs);
  while(!queue.empty()){
    int u = queue.top().second;
    queue.pop();
    for(int i=0;i<G[u].size();i++){
      Edge e = G[u][i];
      int v = e.first;
      int w = e.second;
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        Vertex vtx(dist[v],v);
        queue.push(vtx);
      }
    }
  }

  return dist;
}


int main(){
  int nodes, edges, source, u, v, w;
  cin >> nodes >> edges >> source;
  Graph G(nodes);
  while(edges --> 0){
    cin >> u >> v >> w;
    Edge edge1(v-1,w);
    G[u-1].push_back(edge1);
    Edge edge2(u-1,w);
    G[v-1].push_back(edge2);
  }
  vector<int> distances = dijkstra(G,source-1);
  cout<<"Distances:"<<endl;
  for(int i = 0; i< distances.size(); i++){
    if(i != source-1){
      cout << source << " --> " << (1+i) << " : ";
      if(distances[i] == INF){
        cout<<"INF"<<endl;
      }
      else{
        cout<<distances[i]<<endl;
      }
    }
  }
}

// Cantidad de nodos, cantidad de arcos, nodo origen
// arcos punto origen punto destino y costo.
/*
  5 8 1
  1 2 2
  1 3 12
  1 4 10
  2 3 9
  2 5 5
  3 4 6
  3 5 3
  4 5 7
*/ 
