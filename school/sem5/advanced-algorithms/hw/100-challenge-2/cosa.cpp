#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>

#define MAX 50

using namespace std;

struct Nodo {
	int niv;
	int costoAcum;
	int costoPos;
	vector<int> verticesAnteriores;
	int verticeActual;
	bool visitados[MAX];
	bool operator<(const Nodo &otro) const{ //Para que la fila priorizada tenga la prioridad de 
		return costoPos >= otro.costoPos; 	// menor costo posible.
	}
};

struct multiGraph {
    int originalGraph[MAX][MAX];
    int vertices;
    vector<pair<string,int>> centrales;

    multiGraph(int graph[MAX][MAX], int vertices, vector<pair<string,int>> centrales){
        for(int i = 0; i<vertices;++i){
            for(int j = 0; j<vertices;++j){
                originalGraph[j][i] = originalGraph[i][j] = graph[i][j];
            }
        }
        this->vertices = vertices;
        this->centrales = centrales;
    }
};

struct Point {
  string name;
  float x,y;
  Point() {
    name = " ";
    x = y = 0;
  }
  Point(string name,float x,float y) {
    this->name = name;
    this->x = x;
    this->y = y;
  }
};

struct colonia {
    string nombre;
    pair<int,int> position;
    bool central;
};

struct Graph {
    int V, E, costMSTKruskal;
    vector< pair<int, pair<int, int>> > edges;
    vector<vector<pair<int, int>>> adjList;
    vector<pair<int,int>> selectedEdgesK;
 
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        adjList.resize(V);
        costMSTKruskal = 0;
    }
 
    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
        adjList[u].push_back({v,w});
    }
    void printEdges();
    void kruskalMST();
};
 
// To represent Disjoint Sets
struct DisjointSets {
    int *parent, *rnk;
    int n;
 
    DisjointSets(int n) {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++) {
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

// Complejidad: O(n^3)
void floyd(int mtx[MAX][MAX], vector<vector<int>>& p, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mtx[i][k] != INT_MAX && mtx[k][j] != INT_MAX && mtx[i][k] + mtx[k][j] < mtx[i][j]) {
                    mtx[i][j] = mtx[i][k] + mtx[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}

void checarTrayectoria(vector<vector<int>> p, int a, int b, vector<colonia> colonias) {
    if (p[a][b] != -1) {
        checarTrayectoria(p, a, p[a][b], colonias);
        cout << colonias.at(p[a][b]).nombre << " - ";
        checarTrayectoria(p, p[a][b], b, colonias);
    }
}

// central1/2 en indices
void consulta(int mtx[MAX][MAX], vector<vector<int>> p, pair<string,int> central1, pair<string,int> central2, vector<colonia> colonias) {
    if (mtx[central1.second][central2.second] == INT_MAX) {
        cout << "No path" << endl;
    } else {
        cout << central1.first << " - ";
        checarTrayectoria(p, central1.second, central2.second, colonias);
        cout << central2.first;
        cout << " (" << mtx[central1.second][central2.second] << ")" << endl;
        cout << endl;
    }
}

// toExclude = {0,2}
// num = 1
// num & 1 bitwise and
// num 5 = 101
// 101 
// 111 & 1
vector<bool> getMask(int num, vector<pair<string,int>> toExclude, int size){
    vector<int> res;
    for(int i = 0; num != 0; i++){
        if(num & 1) res.push_back(toExclude[i].second);
        num >>= 1;
    }
    vector<bool> mask(size,1);
    auto excludeIndex = 0;
    for(int i = 0; i < size; i++){
      if(res.size() != 0 && res[excludeIndex] == i) {
          mask[i] = 0;
          ++excludeIndex;
      }
    }
    return mask;
}

vector<int> getMaskedIndexes(int size, vector<bool> mask){
    vector<int> res;
    for(int i = 0; i< size; i++){
        if(mask[i]) res.push_back(i);
    }
    return res;
}

void getVariant(multiGraph mg, int res[MAX][MAX], vector<int> includes){
    int i = 0;
    for(auto idx: includes){
         int j = 0;
        for(auto idy: includes){
            res[j+1][i+1] = res[i+1][j+1] = mg.originalGraph[idx][idy];
            j++;
        }
        i++;
    }
}

void Graph::kruskalMST() {
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

void Graph::printEdges() {
  cout<<"Selected Edges Kruskal: "<<endl;
  for(auto i: selectedEdgesK) cout<< "(" << i.first<<","<<i.second<<")"<<endl;
}

void calculaCostoPosibleOptimizado(Nodo &nodoActual, int matAdj[MAX][MAX], int n, vector<int> centrales, unordered_map<int,int> indicesReales, int realMat[MAX][MAX]){
	nodoActual.costoPos = nodoActual.costoAcum;
	int costoObtenido;
  int costToReach = 0;
	for (int i=1; i<=n; i++){
		costoObtenido = INT_MAX;
		// No he visitado al nodo i o soy el ultimo visitado
		if (!nodoActual.visitados[i] || i == nodoActual.verticeActual){
			if(!nodoActual.visitados[i]){// No lo he visitado
				for (int j=1; j<=n; j++){
					if (i != j && (!nodoActual.visitados[j] || j == 1)){
            for(auto k: centrales){
              cout << "matAdj[i][j] = " << matAdj[i][j]<<endl;
              cout << "realMat[indicesReales[i]][k] = " << realMat[indicesReales[i]][k]<<endl;
              cout << "realMat[k][indicesReales[j]] = " << realMat[k][indicesReales[j]]<<endl;
              costToReach = min(matAdj[i][j], realMat[indicesReales[ i ]][k] + realMat[k][indicesReales[ j  ]]);
            }
						costoObtenido = min(costoObtenido, costToReach);
					}
				}
			}
			else{ // Soy el último visitado
				for (int j=1; j<=n; j++){
					if (!nodoActual.visitados[j]){
            for(auto k: centrales){

              cout << "matAdj[i][j] = " << matAdj[i][j]<<endl;
              cout << "realMat[indicesReales[i]][k] = " << realMat[indicesReales[i]][k]<<endl;
              cout << "realMat[k][indicesReales[j]] = " << realMat[k][indicesReales[j]]<<endl;
              costToReach = min(matAdj[i][j], realMat[indicesReales[ i ]][k] + realMat[k][indicesReales[ j  ]]);
            }
						costoObtenido = min(costoObtenido, costToReach);
					}
				}
			}
			nodoActual.costoPos += costoObtenido;
		}
	}
}

int tspOptimizado(int matAdj[MAX][MAX], vector<int> includes, vector<int> centrales, int realMat[MAX][MAX]) {
  unordered_map<int,int> indicesReales;
  for(int i = 1; i<= includes.size(); i++) indicesReales.insert(make_pair(i, includes[i]));
  int n = includes.size();
  int costoOptimo = INT_MAX;
  Nodo raiz;
  raiz.niv = 0;
  raiz.costoAcum = 0;
  raiz.verticeActual = 1;
  raiz.visitados[1] = true; // garantizar que todos los demás tengan false.
  calculaCostoPosibleOptimizado(raiz, matAdj, n, centrales, indicesReales, realMat);
  priority_queue<Nodo> pq;
  vector<int> ordenTSP;
  pq.push(raiz);
  int m = 0;
  while (!pq.empty()) {
    // cout<< "loop #"<<m++<<endl;
    auto tmp = pq.top();
    pq.pop();
    if (tmp.costoPos < costoOptimo) {
      int costToReach = 0;
      for (int i = 1; i <= n; ++i) {
        for(auto k: centrales){
          cout << "matAdj[tmp.verticeActual][i] = " << matAdj[tmp.verticeActual][i]<<endl;
          cout << "realMat[indicesReales[ tmp.verticeActual ]][k] = " << realMat[indicesReales[ tmp.verticeActual ]][k]<<endl;
          cout << "realMat[k][indicesReales[i]] = " << realMat[k][indicesReales[i]]<<endl;
          costToReach = min(matAdj[tmp.verticeActual][i], realMat[indicesReales[ tmp.verticeActual ]][k] + realMat[k][indicesReales[i]]);
        }
        if (!tmp.visitados[i] && costToReach != INT_MAX) {
          Nodo newNode;
          newNode.niv = tmp.niv + 1;
          newNode.costoAcum = tmp.costoAcum + costToReach;
          newNode.verticeActual = i;
          newNode.verticesAnteriores = tmp.verticesAnteriores;
          newNode.verticesAnteriores.push_back(indicesReales[tmp.verticeActual-1]);
          for (int j = 1; j <= n; j++)
            newNode.visitados[j] = tmp.visitados[j];
          newNode.visitados[i] = true;
          calculaCostoPosibleOptimizado(newNode, matAdj, n, centrales, indicesReales, realMat);
          // cout<<"niv:"<<newNode.niv<<endl;
          for(auto k: centrales){
            costToReach = min(matAdj[tmp.verticeActual][1], realMat[indicesReales[ i ]][k] + realMat[k][1]);
          }
          if (newNode.niv == n - 1 && costToReach != INT_MAX) {
            newNode.costoAcum = newNode.costoAcum + costToReach;
            if (newNode.costoAcum < costoOptimo) {
              costoOptimo = newNode.costoAcum;
              ordenTSP = newNode.verticesAnteriores;
            }
             cout<<"vertice: "<<newNode.verticeActual<<endl;
             for(int j = 1; j<=n;j++) cout<< newNode.visitados[j]<<" ";
             cout<<endl;
             cout<<newNode.costoAcum<<" "<< matAdj[i][1]<<endl;
          } else {
            pq.push(newNode);
          }
        }
      }
    }
    // else{
    //   cout<<"less than optimal"<<endl;
    //   cout<< tmp.costoPos<<" vs "<< costoOptimo<<endl;
    // }
    // Aquí va tu implementación.
  }
  cout << "orden tsp" << endl;
  for(auto i: ordenTSP) cout << i << " "; 
  if(!ordenTSP.size()) cout <<"not possible"<<endl;
  cout<<endl;
  return costoOptimo;
}

void calculaCostoPosible(Nodo &nodoActual, int matAdj[MAX][MAX], int n){
	nodoActual.costoPos = nodoActual.costoAcum;
	int costoObtenido;
	for (int i=1; i<=n; i++){
		costoObtenido = INT_MAX;
		// No he visitado al nodo i o soy el ultimo visitado
		if (!nodoActual.visitados[i] || i == nodoActual.verticeActual){
			if(!nodoActual.visitados[i]){// No lo he visitado
				for (int j=1; j<=n; j++){
					if (i != j && (!nodoActual.visitados[j] || j == 1)){
						costoObtenido = min(costoObtenido, matAdj[i][j]);
					}
				}
			}
			else{ // Soy el último visitado
				for (int j=1; j<=n; j++){
					if (!nodoActual.visitados[j]){
						costoObtenido = min(costoObtenido, matAdj[i][j]);
					}
				}
			}
			nodoActual.costoPos += costoObtenido;
		}
	}
}

int tsp(int matAdj[MAX][MAX], int n) {
  int costoOptimo = INT_MAX;
  Nodo raiz;
  raiz.niv = 0;
  raiz.costoAcum = 0;
  raiz.verticeActual = 1;
  raiz.visitados[1] = true; // garantizar que todos los demás tengan false.
  calculaCostoPosible(raiz, matAdj, n);
  priority_queue<Nodo> pq;
  vector<int> ordenTSP;
  pq.push(raiz);
  int m = 0;
  while (!pq.empty()) {
    // cout<< "loop #"<<m++<<endl;
    auto tmp = pq.top();
    pq.pop();
    if (tmp.costoPos < costoOptimo) {
      for (int i = 1; i <= n; ++i) {
        if (!tmp.visitados[i] && matAdj[tmp.verticeActual][i] != INT_MAX) {
          Nodo newNode;
          newNode.niv = tmp.niv + 1;
          newNode.costoAcum = tmp.costoAcum + matAdj[tmp.verticeActual][i];
          newNode.verticeActual = i;
          newNode.verticesAnteriores = tmp.verticesAnteriores;
          newNode.verticesAnteriores.push_back(tmp.verticeActual);
          for (int j = 1; j <= n; j++)
            newNode.visitados[j] = tmp.visitados[j];
          newNode.visitados[i] = true;
          calculaCostoPosible(newNode, matAdj, n);
          // cout<<"niv:"<<newNode.niv<<endl;
          if (newNode.niv == n - 1 && matAdj[i][1] != INT_MAX) {
            newNode.costoAcum = newNode.costoAcum + matAdj[i][1];
            if (newNode.costoAcum < costoOptimo) {
              costoOptimo = newNode.costoAcum;
              ordenTSP = newNode.verticesAnteriores;
            }
            // cout<<"vertice: "<<newNode.verticeActual<<endl;
            // for(int j = 1; j<=n;j++) cout<< newNode.visitados[j]<<" ";
            // cout<<endl;
            // cout<<newNode.costoAcum<<" "<< matAdj[i+1][1]<<endl;
          } else {
            pq.push(newNode);
          }
        }
      }
    }
    // else{
    //   cout<<"less than optimal"<<endl;
    //   cout<< tmp.costoPos<<" vs "<< costoOptimo<<endl;
    // }
    // Aquí va tu implementación.
  }
  cout << "orden tsp" << endl;
  for(auto i: ordenTSP) cout << i << " "; 
  if(!ordenTSP.size()) cout <<"not possible"<<endl;
  cout<<endl;
  return costoOptimo;
}

/*
 * 1. Kruskal de todo el grafo
 * 2. Minimo de TSP de combinaciones entre todas las versiones posibles del grafo (con y sin cada central)
 * 3. Floyd-Warshall del grafo completo
 * 4. Sacar distancia minima entre nuevos puntos y actuales
 */


// Descripción: Esta función obtiene la distancia entre dos puntos.
// Complejidad: O(nlogn)
float dist(int x, int y, int dx, int dy) {
  return sqrt((abs(x)-abs(dx))*(abs(x)-abs(dx))+(abs(y)-abs(dy))*(abs(y)-abs(dy)));
}

bool sortbysec(const pair<string,float> &a, const pair<string,float> &b)
{
    return (a.second < b.second);
}

int main() {
  fstream file("in2");
  // ====== Variables ======
  string nombreColonia;
  string desdeColonia;
  string hastaColonia;
  int x;
  int y;
  int costo;
  bool esCentral;
  vector<pair<string,int>> centrales;
  vector<int> indicesCentrales;
  int n; file >> n; // cantidad de colonias
  int m; file >> m; // número de conexiones entre colonias
  int q; file >> q; // futuras nuevas colonias que se desean conectar
  Graph g(n, m);
  vector<colonia> colonias;
  unordered_map<string,int> numeroColonia;
  int matAdj[MAX][MAX];

  // Agregar Colonias
  // Nombre de la Colonia - Posición en X - Posición en Y - Si es central o no
  for (int i = 0; i < n; i++) {
    file >> nombreColonia >> x >> y >> esCentral;
    colonia col;
    col.nombre = nombreColonia;
    col.position = make_pair(x,y);
    if(esCentral) centrales.push_back({nombreColonia,i});
    colonias.push_back(col);
    numeroColonia.insert(make_pair(nombreColonia,i));
  }
  // Agregar Conexiones
  // Desde la Colonia - Hasta la Colonia - Costo de la conexión
  for (int i = 0; i < m; i++) {
    file >> desdeColonia >> hastaColonia >> costo;
    auto c1 = numeroColonia[desdeColonia];
    auto c2 = numeroColonia[hastaColonia];
    matAdj[c2][c1] = matAdj[c1][c2] = costo;
    g.addEdge(c1,c2,costo);

  }

  g.kruskalMST();
  g.printEdges();
  /*
  -------------------
  1 – Cableado óptimo de nueva conexión.
  Tecnologico - AltaVista 15
  LindaVista - Roma 17
  Roma - AltaVista 18
  Purisima - Tecnologico 40
  Costo Total: 90
  -------------------
  */
  cout << "-------------------" << endl;
  cout << "1 – Cableado óptimo de nueva conexión." << endl << endl;
  cout << "Costo Total: " << g.costMSTKruskal << endl << endl;
  cout << "-------------------" << endl;

    vector<vector<int>> path(MAX,vector<int>(MAX,-1));
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            if(matAdj[i][j] == 0 && i != j) matAdj[i][j] = INT_MAX;
        }
    }
  auto mg = multiGraph(matAdj,m, centrales);

  for(int i = 0; i< pow(2,mg.centrales.size());++i) {
      int variantMatAdj[MAX][MAX];
      //cout<<"variant #"<< i<<endl;
      auto mask= getMask(i, mg.centrales, n);
      auto includes = getMaskedIndexes(n, mask);
      getVariant(mg,variantMatAdj,includes);

    // for(int i = 1; i<= includes.size(); i++){
    //     for(int j = 1; j<= includes.size(); j++){
    //         cout<< variantMatAdj[i][j] << " ";
    //     }
    //     cout<<endl;
    // }
  auto tspRes = tsp(variantMatAdj,includes.size());
  cout<<tspRes<<endl;
  }

  int variantMatAdj[MAX][MAX];

  auto mask= getMask(pow(2,mg.centrales.size())-1, mg.centrales, n);
  auto includes = getMaskedIndexes(n, mask);
  getVariant(mg,variantMatAdj,includes);

  int orig[MAX][MAX];

  mask = getMask(0, mg.centrales, n);
  includes = getMaskedIndexes(n, mask);
  getVariant(mg,orig,includes);
  
  auto tspOptRes = tspOptimizado(variantMatAdj, includes, indicesCentrales, orig);
  cout << "optimizado" <<endl;
  cout << tspOptRes<< endl;
    floyd(matAdj,path,n);
  
    cout << "-------------------" << endl;
    cout << "3 – Caminos más cortos entre centrales" << endl; 
    cout << endl;
//void consulta(int mtx[MAX][MAX], vector<vector<int>> p, int central1, int central2) {
  for(int i = 0; i < centrales.size(); ++i){
      for(int j = i+1; j < centrales.size(); ++j)
      consulta(matAdj, path, centrales[i], centrales[j], colonias);
  }
  
  //for(punto in puntosnuevos)
  // min = INT_MAX
  // colonia minpoint
  // for(auto colonia: colonias){
// if dist(punto,colonia) < min
// min = dist(punto,colonia)
// }
// print punto a hacia colonia no se que(x,y) - distancia

  // Agregar futuras Colonias
  // Nombre de la Colonia - Posición en X - Posición en Y
  cout << "-------------------" << endl;
  cout << "4 – Conexión de nuevas colonias." << endl;
  cout << endl;
  vector<pair<string,float>> distances;
  for (int i = 0; i < q; i++) {
    file >> nombreColonia >> x >> y;
    for (int j = 0; j < colonias.size(); j++) {
      auto pos = colonias[j].position;
      auto col = colonias[j].nombre;
      auto dx = pos.first;
      auto dy = pos.second;

      distances.push_back({col,dist(dx,dy,x,y)});
    }
    /*for (int k = 0; k < distances.size(); k++) {
      cout << "La distancia con " << distances.at(k).first << " es: " << distances.at(k).second << endl;
    }*/
    sort(distances.begin(), distances.end(), sortbysec);
    /*cout << "DESPUES DEL SORT" << endl;
    for (int m = 0; m < distances.size(); m++) {
      cout << "La distancia con " << distances.at(m).first << " es: " << distances.at(m).second << endl;
    }*/
    cout << nombreColonia << " debe conectarse con " << distances.at(0).first << endl;
    distances.clear();
  }
  cout << endl;
  cout << "-------------------" << endl;

  return 0;
}
