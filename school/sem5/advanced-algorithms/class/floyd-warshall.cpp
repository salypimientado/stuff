#include <iostream>
#include <climits>
#include <vector>

#define MAX 100

using namespace std;

void leeArcos(vector<vector<int>>& costs, vector<vector<int>>& path, int edges){
  int a,b,c;
    for(int i = 1; i<edges;++i){
      cin >> a >> b >> c;
      costs[a-1][b-1] = costs[b-1][a-1] = c;
    }
}

void floyd(vector<vector<int>>& costs, vector<vector<int>>& path, int n){
  for(int k = 0; k< n; k++){
    for(int i = 0; i< n; i++){
      for(int j = 0; j< n; j++){
        if(costs[i][k] != INT_MAX && costs[k][j] != INT_MAX && costs[i][k]+costs[k][j]<costs[i][j]){
          costs[i][j] = costs[i][k] + costs[k][j];
          path[i][j] = k;
        }
      }
    }
  }
}

void printmat(const vector<vector<int>>& matrix, int n){
  for(int i = 0; i< n; ++i){
    for(int j = 0; j< n; ++j) cout<<matrix[i][j]<< "\t";
    cout<<endl;
  }
}

int main(){
  vector<vector<int>> costs(MAX,vector<int>(MAX,INT_MAX)), path(MAX,vector<int>(MAX,-1));
  for(int i = 0; i< costs.size();++i) costs[i][i] = 0;
  int cases, vsize, nodes, edges, tests;

  cin >> cases;

  for(int i=0; i<cases; i++){
    cin >> nodes >> edges >> tests;
    leeArcos(costs,path,edges);
  }
  printmat(costs,nodes);
  floyd(costs,path,nodes);
  cout<<endl;
  printmat(costs,nodes);
  cout<<endl;
  printmat(path,nodes);
}

/*
  1
  7 9 3
  1 2 50
  1 3 60
  2 4 120
  2 5 90
  3 6 50
  4 6 80
  4 7 70
  5 7 40
  6 7 140
  1 7
  2 6
  6 2    
*/ 
