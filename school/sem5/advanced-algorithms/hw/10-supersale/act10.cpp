// Juan Pablo Salazar - A01740200
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

int max(int a, int b)
{
  return (a > b) ? a : b;
}

//O(nw) where n is items.size() and w is weight
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

int bt_helper(vector<item> &items, int i, int va, int pa,int vp, int &valOptimo){
  
}

int BT(vector<item> &items,int N, int weight){
  int vpAux = 0, vpPeso = 0, k = -1;
  while (k<N && vpPeso+items[k+1].peso <= weight){
    k++;
    vpAux+=items[k].valor;
    vpPeso+=items[k].peso;
  }
  k++;
  if(k<N){
    vpAux += (weight-vpPeso)*items[k].valpeso;
  }
  int valOptimo = 0;
  bt_helper(items,-1,0,0,vpAux, valOptimo);
  return valOptimo;
}

int main(){
  int v, p, N, maxWeight, tests, members,member;
  float vp;
  cin>>tests;
  while(tests-->0){
    vector<item> items;
  int total = 0;
  cin>> N;
  for(int i = 0; i<N; ++i){
    cin >> v >> p;
    vp = v*1.0/p;
    item obj;
    obj.valor = v;
    obj.peso = p;
    obj.valpeso = vp;
    items.push_back(obj);
  }
  cin >> members;
  vector<int> weights;
  while(members-->0){
    cin >> member;
    weights.push_back(member);
  }
  for(auto member: weights){
    total += dp(items,N,member);
  }  
  cout<<total<<endl;
}
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
