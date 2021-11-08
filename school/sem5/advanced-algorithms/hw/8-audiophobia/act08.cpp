#include <iostream>
#include <climits>
#include <vector>

#define MAX 100

using namespace std;

void leeArcos(vector<vector<int>>& costs, vector<vector<int>>& path, int edges){
  int a,b,c;
    for(int i = 1; i<=edges;++i){
      cin >> a >> b >> c;
      costs[a-1][b-1] = costs[b-1][a-1] = c;
    }
}

void floyd(vector<vector<int>>& costs, vector<vector<int>>& path, int n){
  for(int k = 0; k< n; k++){
    for(int i = 0; i< n; i++){
      for(int j = 0; j< n; j++){
        if(costs[i][k] != INT_MAX && costs[k][j] != INT_MAX
           && ( costs[i][k] < costs[i][j] && costs[k][j]<costs[i][j] )){
          auto max = costs[i][k] > costs[k][j] ? costs[i][k]: costs[k][j];
          costs[i][j] = max;
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
  int cases, vsize, nodes, edges, tests, origin, dest;

  cin >> cases;

  for(int i=0; i<cases; i++){
    cout<<"Case " << i+1<< ":"<<endl;
    vector<vector<int>> costs(MAX,vector<int>(MAX,INT_MAX)), path(MAX,vector<int>(MAX,-1));
    for(int m = 0; m< costs.size();++m) costs[m][m] = 0;
    cin >> nodes >> edges >> tests;
    leeArcos(costs,path,edges);
    floyd(costs,path,nodes);
    //printmat(costs,nodes);
    for(int j = 0; j< tests; ++j){
      origin = 0;
      dest = 0;
      cin >> origin >> dest;
      --origin;
      --dest;
      //cout<<"segfaulted at costs[" << origin<< "][" <<dest<<"]"<<endl;
      if(costs[origin][dest] == INT_MAX) cout<< "no path"<<endl;
      else cout<< costs[origin][dest]<<endl;
    }
  }
}

/*
2
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
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
*/ 
