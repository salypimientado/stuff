#include <iostream>
#include <climits>
#include <vector>

using namespace std;

float BSTOp(vector<float> &p, vector<float> &pacum){
  int n = p.size();
  float A[n+2][n+1];
  for(int i = 1; i<=n; i++){
    A[i][i-1] = 0;
    A[i][i] = p[i-1];
  }
  A[n+1][n] = 0;

  for(int diag=1;diag<n;diag++){
    for(int i=1; i<=n-diag;i++){
      int j = i+diag;
      float min = INT_MAX;
      for(int k=i;k<=j;k++){
        if(A[i][k-1]+A[k+1][j] < min){
          min = A[i][k-1]+A[k+1][j];
        }
      }
      A[i][j] = min + pacum[j] - pacum[i-1];
    }
  }
  return A[1][n];
}

int main(){
  int n;
  float dato;
  cin >> n;
  vector<float> p, pacum;
  pacum.push_back(0);
  for(int i = 0; i< n; i++){
    cin >> dato;
    p.push_back(dato);
    pacum.push_back(pacum[i]+dato);
  }
  cout<< BSTOp(p,pacum)<<endl;
}

/*
5
.2
.15
.2
.3
.15
*/
