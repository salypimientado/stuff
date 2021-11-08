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

int dp(const vector<item> &items,int N, const int weight){
  vector<vector<int>> mat(N+1,vector<int>(weight+1,0));
  for(int i = 1; i<=N; i++){
    for(int j=1; j<=weight; j++){
      if(items[i-1].peso > j){
        mat[i][j] = mat[i-1][j];
      }
      else{
        mat[i][j] = max(mat[i-1][j], items[i-1].valor+mat[i-1][j-items[i-1].peso]);
      }
    }
  }
  for(auto i: mat) for(auto j:i) cout<<j<<" "; cout<<endl;
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
  vector<item> items;
  int v, p, N, maxWeight, tests, members;
  float vp;
  cin>>tests;
  while(tests-->0){
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
  cin>>members;
  int member;
  while(members-->0){
    cin >> member;
    total += dp(items,N,member);
    //cout<<"total miembro "<< members<<" "<< dp(items,N,member)<<endl;
    //cout<<"total miembro dq "<< members<<" "<< dq(items,N,member)<<endl;
  }
  cout<<total<<endl;
}
  // sort(items.begin(),items.end(),comp);
  // cout<<"Objetos ordenados: "<<endl;
  // for(auto i: items) cout<< i.valor << " "<< i.peso<< " "<< i.valpeso<<endl;
  // cout<<"Divide and conquer: "<< dq(items,N,maxWeight)<<endl;
  // cout<<"Dynamic programming: "<< dp(items,N,maxWeight)<<endl;
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
