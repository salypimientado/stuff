#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>

using namespace std;
 
typedef  pair<int, int> iPair;
 
struct Graph {
    int V, E, costMSTKruskal, costMSTPrim;
    vector< pair<int, pair<int, int>> > edges;
    vector<vector<pair<int, int>>> adjList;
    vector<pair<int,int>> selectedEdgesP;
    vector<pair<int,int>> selectedEdgesK;
 
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        adjList.resize(V);
        costMSTKruskal = 0;
        costMSTPrim = 0;
    }
 
    void addEdge(int u, int v, int w) {
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
    int a, b, c;
    for (int i=0; i<E; i++){
      //cout << "i:"<< i;
        cin >> a >> b >> c;
        addEdge(a,b,c);
    }
    cout << adjList[0].size() << endl;
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
  int connected = V-1, minCost, selVertex;
  while(connected > 0){
    minCost = INT_MAX;
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
    cin >> V >> E;
    Graph g(V, E);

    g.load();
    g.print();
    g.kruskalMST();
    cout << "Costo Total del MST(kruskal) es: " << g.costMSTKruskal<<endl;
  	g.primMST();
    cout << "Costo Total del MST(prim) es: " << g.costMSTPrim<<endl;
    g.printEdges(0);
    g.printEdges(1);
    return 0;
} 

/*
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
*/
