// Juan Pablo Salazar Garcia - A01740200

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>
#define Graph vector<vector<Edge>>
#define Vertex pair<int, int>

int letterToIndex(char letter) {
  //cout << letter - 'A' << endl;
  return letter - 'A';
}

// Complejidad: O(nlogn)
int dijkstra(const Graph &G, int source) {
  vector<int> dist(G.size(), INF);
  dist[source] = 0;
  priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue;
  Vertex vs(0, source);
  queue.push(vs);
  while (!queue.empty()) {
    int u = queue.top().second;
    int y = queue.top().first;
    queue.pop();
    for (int i = 0; i < G[u].size(); i++) {
      Edge e = G[u][i];
      int v = e.first;
      int w = e.second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        Vertex vtx(dist[v], v);
        queue.push(vtx);
      }
    }
  }

   // for(auto i: dist) cout<<i<<" "; cout<<endl;
  int maxI = -1;
  for(int i = 0; i < dist.size(); ++i) maxI = dist[i]>dist[maxI]? i: maxI;

  return maxI;
}

int main() {
  char a, b;
  int nodes, edges, u, v, w, tests;
  cin >> tests;
  for(int i = 0; i++<tests;) {
    cin >> nodes >> edges;
    Graph G(nodes);
    while (edges-- > 0) {
      cin >> a >> b >> w;
      u = letterToIndex(a);
      v = letterToIndex(b);

      Edge edge1(v, w);
      G[u].push_back(edge1);
      Edge edge2(u, w);
      G[v].push_back(edge2);
    }
    auto res = dijkstra(G, 0);
    cout << "Case " << i<< ": " << char(res+ 'A') <<endl;
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
