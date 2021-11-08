// A01740200
// Juan Pablo Salazar

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// O(nm) donde n y m son los dos lados de la matriz, ya que ocupa recorrer toda la matriz cuadrada
int robot(vector<vector<int>>& matrix, int& a, int& b){
  for(int i = a-1; i >= 0; --i){
    for(int j = b-1; j>=0; --j){
      int abajo = i<a-1 ? matrix[i+1][j] : INT_MAX;
      int derecha = j<b-1 ? matrix[i][j+1] : INT_MAX;
      matrix[i][j] += abajo <= derecha ? abajo == INT_MAX ? 0: abajo : derecha;
    }
  }
  return matrix[0][0];
}

int main(){
  int a, b, c;
  cin >> a >> b;
  vector<vector<int>> matrix(a,vector<int>(b));
  for(int i = 0; i< a; ++i){
    for(int j = 0; j < b; ++j){
      cin >> c;
      matrix[i][j] = c;
    }
  }
  cout<< robot(matrix,a,b)<<endl;
}

//5 4 2 2 15 1 5 1 15 1 5 3 10 1 5 2 1 1 8 13 2 15
