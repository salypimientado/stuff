#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

struct Edge{
  int src,dest,valor;
   Edge(int i, int j, int k){
    src = i;
    dest = j;
    valor = k;
   }
};

struct graph {

  vector<Edge> edges;

  int V;
  int E;

   graph(int V, int E){
    this->V = V;
    this->E = E;
  }

  void print(){
    for(auto i : edges){
      cout<< i.src<< "-" << i.dest<< ":"<<i.valor<<endl;
    }
  }
};


int main(){
  string nodos, edges, value, node, targetNode, num;
  int src;
  cout<<"Introduzca el numero de nodos:";
  cin>>nodos;
  cout<<"Introduzca el numero de conexiones totales:";
  cin>>edges;
  cout<<edges<<endl;
  cout<<"Introduzca el numero del nodo inicial:";
  cin>>num;
  src = stoi(num)-1;
  vector<int> distanciaAlNodoInicial(stoi( nodos ),INT_MAX);
  vector<int> nodoAnterior(stoi(nodos),-1);
  graph grafo(stoi(nodos), stoi(edges));
  cout<<"Introduzca las conexiones en el formato origen objetivo distancia: \n";
  for(int i = 0; i< stoi(edges); i++){
  cin >> node >> targetNode >> value;
  grafo.edges.push_back(Edge(stoi(node)-1,stoi(targetNode)-1,stoi(value)));
  }

  distanciaAlNodoInicial[src] = 0;

  for(int i = 0; i<stoi(nodos)-1;i++){
    bool changed = 0;
    for(int j = 0; j<stoi(edges);j++){
      int inicial = grafo.edges[j].src;
      int destino = grafo.edges[j].dest;
      if(distanciaAlNodoInicial[destino] > distanciaAlNodoInicial[inicial] + grafo.edges[j].valor && distanciaAlNodoInicial[inicial] != INT_MAX){
        changed = 1;
        distanciaAlNodoInicial[destino] = distanciaAlNodoInicial[inicial] + grafo.edges[j].valor;
        nodoAnterior[destino] = inicial;
      }
    }
    if(!changed) break;
  }

  cout<<"Camino desde el nodo inicial hasta todos los nodos: "<<endl;
  cout<<distanciaAlNodoInicial.size()<<endl;
  for(int i = 0; i< distanciaAlNodoInicial.size(); i++){

  int temp = i;
  cout<<1+i<<" : "<<1+i;
  if(distanciaAlNodoInicial[i] != INT_MAX)
    {
      while(temp != src){
        cout<< "<-"<<1+nodoAnterior[temp];
        temp = nodoAnterior[temp];
      }
    }

  cout << " | Distancia total: " << distanciaAlNodoInicial[i]<<endl;
  }

  return 0;
}

/* Ejemplo del examen 1
  8
  15
  1
  1 2 20
  1 4 18
  1 5 22
  2 3 65
  3 6 21
  3 8 19
  4 3 41
  4 5 20
  4 6 30
  5 6 33
  5 8 93
  6 7 30
  6 8 70
  7 3 25
  7 8 6
 */
