#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct item{
  int valor, peso;
  float valpeso;
};

struct node{
  int niv;
  int va;
  int pa;
  int vp;
  bool operator<(const node& otro) const{
    return vp<otro.vp;
  }
};

int max(int a, int b)
{
  return (a > b) ? a : b;
}


int dp(vector<item> &items,int N, int weight){
  vector<vector<int>> mat(N+1,vector<int>(weight+1));
  for(int i = 0; i<=N; i++){
    for(int j=0; j<=weight; j++){

      if(i == 0 || j == 0){
        mat[i][j] = 0;
      }
      else if(items[i-1].peso > j){
        mat[i][j] = mat[i-1][j];
      }
      else{
        mat[i][j] = max(mat[i-1][j], items[i-1].valor+mat[i-1][j-items[i-1].peso]);
      }
    }
  }
  return mat[N][weight];
}

int dq(vector<item> &items,int N, int weight){
  if(N==0 || items[N-1].peso > weight){
    return 0;
  }
  return max(dq(items,N-1,weight),items[N-1].valor + dq(items, N-1, weight-items[N-1].peso));
}

bool comp(const item &a,const item &b){
  return a.valpeso > b.valpeso;
}
int calculateVP(vector<item> &items, int i, int vpAux, int pesoAux, int N, int PESO){
  int k = i + 1;
  while(k<N && pesoAux+items[k].peso <= PESO){
    vpAux += items[k].valor;
    pesoAux += items[k].peso;
    k++;
  }
  if(k<N){
    vpAux += ((PESO-pesoAux)*items[k].valpeso);
  }
  return vpAux;
}

int bb(vector<item> &items, int N, int PESO){
  priority_queue<node> pq;
  int valOptimo = 0;
  int vp = calculateVP(items,-1,0,0,N,PESO);
  node arranque;
  arranque.niv = -1;
  arranque.va = 0;
  arranque.pa = 0;
  arranque.vp = vp;
  pq.push(arranque);
  while(!pq.empty()){
    arranque = pq.top();
    pq.pop();
    if(arranque.va > valOptimo) valOptimo = arranque.va;
    if(arranque.vp > valOptimo) {
      arranque.niv++;
      arranque.vp = calculateVP(items, arranque.niv, arranque.va, arranque.pa, N, PESO);
      if(arranque.vp > valOptimo && arranque.pa <= PESO){
        pq.push(arranque);
      }
      arranque.va += items[arranque.niv].valor;
      arranque.pa += items[arranque.niv].peso;
      arranque.vp = calculateVP(items,arranque.niv,arranque.va,arranque.pa,N,PESO);
      if(arranque.vp > valOptimo && arranque.pa <= PESO){
        pq.push(arranque);
      }
    }
  }
  return valOptimo;
}

void bt_helper(vector<item> &items, int i, int va, int pa,int vp, int N, int PESO, int &valOptimo, vector<bool> &res, vector<bool> &inc){
  if (i<N && pa <= PESO && vp > valOptimo){
    if(va> valOptimo){
      valOptimo = va;
      for(int j=0; j<N;j++){
        res[j] = inc[j];
      }
    }
    if(i+1<N){
    inc[i+1] = true;
    bt_helper(items,i+1,va+items[i+1].valor,pa+items[i+1].peso,vp,N,PESO,valOptimo,res,inc);
    inc[i+1] = false;
    int vpAux = calculateVP(items, i+1, va, pa, N, PESO);
    bt_helper(items,i+1,va,pa,vpAux,N,PESO,valOptimo,res,inc);
}
  }
}

int BT(vector<item> &items,int N, int weight, vector<bool> &res){
  vector<bool> inc(res.size(), false);
  int vpAux =  calculateVP(items,-1,0,0,N,weight);
  int valOptimo = 0;
  bt_helper(items,-1,0,0,vpAux, N, weight, valOptimo,res,inc);
  return valOptimo;
}

int main(){
  int v, p, N, maxWeight, tests, members,member;
  float vp;
    vector<item> items;
  int total = 0;
  cin>> N >> maxWeight;
  for(int i = 0; i<N; ++i){
    cin >> v >> p;
    vp = v*1.0/p;
    item obj;
    obj.valor = v;
    obj.peso = p;
    obj.valpeso = vp;
    items.push_back(obj);
  }
  vector<bool> res(items.size(),false);
  cout<<"Recursion: "<< dq(items,N,maxWeight)<<endl;
  cout<<"Dynamic programming: "<< dp(items,N,maxWeight)<<endl;
  cout<<"Backtracking: "<< BT(items,N,maxWeight,res)<<endl;
  cout<<"Con los objetos: "<<endl;
  for(int i = 0; i< res.size(); i++){
    if(res[i]) cout<< items[i].peso<< " "<< items[i].valor<<endl;
  }
  cout<<"Branch and bound: "<< bb(items,N,maxWeight)<<endl;
}


/*
2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26
 */
