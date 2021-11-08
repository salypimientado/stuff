// A01740200
// Juan Pablo Salazar

#include <iostream>
#include <vector>

//Partir matriz en 4 cuadrantes y ver en cual esta el ocupado
// Se llenan los 4 del medio con un numero, que al final uno de las esquinas se sobreescribe y se hace un triomino
// En las que no hay ocupado de direccion se apunta al centro
// Si se tiene de direccion -1 se vuelve a llamar la primera funcion con este cuadrante
// Si se tiene una direccion normal se parte en cuadrantes y se vuelve a llamar la funcion con nuevas direcciones
// Si es de 2x2 la direccion indica cual casilla no se va a llenar con numero

// Tomando en cuenta que se parten las matrices hasta llegar a matrices de 2x2 y no se procesa nada antes de esto,
// la complejidad de este algoritmo es O(n^2) donde N es el numero introducido

using namespace std;

int num = 1;
vector<vector<int>> direcciones {{0,2,1,0},{3,1,1,0},{3,2,2,0},{3,2,1,3}};


void fill2x2(vector<vector<int>>& matrix, int  x, int  y, int emptyquadrant){
  switch (emptyquadrant){
  case 0:
    matrix[x][y+1] = num;
    matrix[x+1][y] = num;
    matrix[x+1][y+1] = num++;
    break;
  case 1:
    matrix[x][y] = num;
    matrix[x+1][y] = num;
    matrix[x+1][y+1] = num++;
    break;
  case 2:
    matrix[x][y] = num;
    matrix[x][y+1] = num;
    matrix[x+1][y+1] = num++;
    break;
  case 3:
    matrix[x][y] = num;
    matrix[x][y+1] = num;
    matrix[x+1][y] = num++;
    break;
  case -1:
    matrix[x][y] = num;
    matrix[x][y+1] = num;
    matrix[x+1][y] = num;
    matrix[x+1][y+1] = num++;
  }
}

void fillcenter(vector<vector<int>>& matrix, int  x, int  y){
  matrix[x][y] = num;
  matrix[x+1][y+1] = num;
  matrix[x][y+1] = num;
  matrix[x+1][y] = num++;
}

void fill(vector<vector<int>>& matrix, int  x1, int x2, int  y1, int  y2, int direction, int takenx, int takeny){
  if(x1 == x2) while(true);
  if(x2-x1 == 1){
    fill2x2(matrix,x1,y1,direction);
    return;
  }
  int halfx = ( x1+x2 )/2;
  int halfy = ( y1+y2 )/2;
  fillcenter(matrix,halfx,halfy);
  if(direction == -1){
    if(takenx<= halfx){
      if(takeny<= halfy){
        //q1
        fill(matrix,x1,halfx,y1,halfy,-1,takenx,takeny);
        //q2
        fill(matrix,halfx+1,x2,y1,halfy,1,takenx,takeny);
        //q3
        fill(matrix,x1,halfx,halfy+1,y2,2,takenx,takeny);
        //q4
        fill(matrix,halfx+1,x2,halfy+1,y2,0,takenx,takeny);
      }
      else{
        //q1
        fill(matrix,x1,halfx,y1,halfy,3,takenx,takeny);
        //q2
        fill(matrix,halfx+1,x2,y1,halfy,1,takenx,takeny);
        //q3
        fill(matrix,x1,halfx,halfy+1,y2,-1,takenx,takeny);
        //q4
        fill(matrix,halfx+1,x2,halfy+1,y2,0,takenx,takeny);
      }
    }
    else{
      if(takeny< halfy){
        //q1
        fill(matrix,x1,halfx,y1,halfy,3,takenx,takeny);
        //q2
        fill(matrix,halfx+1,x2,y1,halfy,-1,takenx,takeny);
        //q3
        fill(matrix,x1,halfx,halfy+1,y2,2,takenx,takeny);
        //q4
        fill(matrix,halfx+1,x2,halfy+1,y2,0,takenx,takeny);
      }
      else{
        //q1
        fill(matrix,x1,halfx,y1,halfy,3,takenx,takeny);
        //q2
        fill(matrix,halfx+1,x2,y1,halfy,1,takenx,takeny);
        //q3
        fill(matrix,x1,halfx,halfy+1,y2,2,takenx,takeny);
        //q4
        fill(matrix,halfx+1,x2,halfy+1,y2,-1,takenx,takeny);
      }
    }
    return;
  }
    vector<int> directions = direcciones[direction];
    //q1
    fill(matrix,x1,halfx,y1,halfy,directions[0],takenx,takeny);
    //q2
    fill(matrix,halfx+1,x2,y1,halfy,directions[2],takenx,takeny);
    //q3
    fill(matrix,x1,halfx,halfy+1,y2,directions[1],takenx,takeny);
    //q4
    fill(matrix,halfx+1,x2,halfy+1,y2,directions[3],takenx,takeny);
  return;
}

void printmatrix(vector<vector<int>>& matrix){
  for(auto i: matrix){
    for(auto j: i){
      cout<<j<< "\t";
    }
    cout<<endl;
  }
  cout<<endl;
}

int main(){
  string input;
  cin >> input;
  int N = stoi(input);
  string x, y;
  cin >> y >> x;
  int ix = stoi(x);
  int iy = stoi(y);

  vector<vector<int>> matrix(N,vector<int>(N,0));


  fill(matrix,0,N-1,0,N-1,-1,ix,iy);
  matrix[ix][iy] = 0;
  printmatrix(matrix);
}
// void fill(vector<vector<int>>& matrix, int  x1, int x2, int  y1, int  y2, int direction, int takenx, int takeny){
