// Juan Pablo Salazar - A01740200
#include <iostream>
#include <climits>
#include <queue>
#define MAX 21
using namespace std;
struct Nodo{
int niv;
int costoAcum;
int costoPos;
int verticeAnterior;
int verticeActual;
bool visitados[MAX];
bool operator<(const Nodo &otro) const{ //Para que la fila priorizada tenga la prioridad de 
return costoPos >= otro.costoPos;  // menor costo posible.
}
};
void iniciaMat(int matAdj[MAX][MAX]){
for (int i=0; i<MAX; i++){
matAdj[i][i] = 0;
for (int j=i+1; j<MAX; j++){
matAdj[i][j] = matAdj[j][i] = INT_MAX;
}
}
}
void leeArcos(int matAdj[MAX][MAX], int m){
int c;
char a, b;
for (int i=0; i<m; i++){
cin >> a >> b >> c;
matAdj[a-'A'+1][b-'A'+1] = matAdj[b-'A'+1][a-'A'+1] = c;
}
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
costoObtenido = min(costoObtenido, matAdj[i]
[j]);
}
}
}
else{ // Soy el último visitado
for (int j=1; j<=n; j++){
if (!nodoActual.visitados[j]){
costoObtenido = min(costoObtenido, matAdj[i]
[j]);
}
}
}
nodoActual.costoPos += costoObtenido;
}
}
}
void print(int mat[MAX][MAX], int n){
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      cout<< mat[i][j]<< "\t";
    }
    cout<<endl;
  }
}
// Complejidad de tiempo: O(2^n)
int tsp(int matAdj[MAX][MAX], int n){
int costoOptimo = INT_MAX;
Nodo raiz;
raiz.niv = 0;
raiz.costoAcum = 0;
raiz.verticeActual = 1;
raiz.verticeAnterior = 0;
raiz.visitados[1] = true; // garantizar que todos los demás tengan false.
calculaCostoPosible(raiz, matAdj, n);
priority_queue<Nodo> pq;
pq.push(raiz);
  int m = 0;
while (!pq.empty()){
    // cout<< "loop #"<<m++<<endl;
    auto tmp = pq.top();
    pq.pop();
    if(tmp.costoPos < costoOptimo){
      for(int i = 1; i<= n; ++i){
        if(!tmp.visitados[i] && matAdj[tmp.verticeActual][i] != INT_MAX){
          Nodo newNode;
          newNode.niv = tmp.niv+1;
          newNode.costoAcum = tmp.costoAcum + matAdj[tmp.verticeActual][i];
          newNode.verticeActual = i;
          newNode.verticeAnterior = 0;
          for(int j = 1; j<=n;j++) newNode.visitados[j] = tmp.visitados[j];
          newNode.visitados[i] = true; 
          calculaCostoPosible(newNode,matAdj,n);
          // cout<<"niv:"<<newNode.niv<<endl;
          if(newNode.niv == n-1 && matAdj[i][1] != INT_MAX){
            newNode.costoAcum = newNode.costoAcum + matAdj[i][1];
            if(newNode.costoAcum < costoOptimo ) {
              costoOptimo = newNode.costoAcum;
            }
            //cout<<"vertice: "<<newNode.verticeActual<<endl;
            // for(int j = 1; j<=n;j++) cout<< newNode.visitados[j]<<" ";
            // cout<<endl;
            //cout<<newNode.costoAcum<<" "<< matAdj[i+1][1]<<endl;
          }
          else{
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
return costoOptimo;
}
int main(){
// n = cantidad de nodos
// m = cantidad de arcos
int n, m;
cin >> n >> m;
int matAdj[MAX][MAX];  // Asumimos que ocupamos en base1 A=1, B=2, C=3....
iniciaMat(matAdj);
leeArcos(matAdj, m);
  auto res = tsp(matAdj,n);
cout << ( res == INT_MAX? "INF": to_string(res) ) << endl;
}
/*
4 5
A B 5
A C 10
A D 8
B C 2
C D 1
5 7
A B 4
A C 8
A D 2
B C 7
B D 2
C D 1
D E 3
*/
