// Juan Pablo Salazar - A01740200
#include <iostream>
#include <climits>

using namespace std;

#define MAX 51

int constantCalls = 0;
int linearCalls = 0;

int memo[MAX][MAX];

void refreshMemo(int n){
  for(int i = 0; i< n; ++i){
    for(int j = 0; j < n; ++j){
      memo[i][j] = 0;
    }
  }
}

// O(n^2)
int cut(int d[MAX], int start, int end){
  if(memo[start][end] != 0) {constantCalls++; return memo[start][end];}
  if(start+1 == end) {constantCalls++; return 0;}
  linearCalls++;
  int min = INT_MAX, tempstart, tempmin;
  for(int i = start+1; i <end; ++i){
    auto res = d[end]-d[start] + cut(d,start,i) + cut(d,i,end);
    if(res < min) min = res;
  }
  memo[start][end] = min;
  return min;
}

// O(n^3)
void calcula(int D[MAX][MAX], int P[MAX][MAX], int d[MAX], int n){
// Aquí va tu código
  for(int i = 1; i<=n ;++i){
    D[i][i] = P[i][i] = 0;
  }
  int j, aux, men, menk;
  for(int diag=1; diag<=n-1;diag++){
    for(int i=1; i<=n-diag;++i){
      j = i+diag;
      men = INT_MAX;
      for(int k=i;k<j;k++){
        aux = D[i][k] + D[k+1][j] + d[i-1]*d[k]*d[j];
        if(aux < men){
          men = aux;
          menk = k;
        }
      }
      D[i][j] = men;
      P[i][j] = menk;
    }
  }
}


void recorre(int P[MAX][MAX], int ini, int fin){
// Aquí va tu código
  if(P[ini][fin] != 0){
    cout<<"(";
    recorre(P,ini,P[ini][fin]);
    cout<<")x(";
    recorre(P,P[ini][fin]+1,fin);
    cout<<")";
  }
  else{
    char ch = 'A'+ini-1;
    cout<<ch;
  }
}

void despliega(int P[MAX][MAX], int n){
	recorre(P,1,n);
	cout << endl;
}

void despM(int D[MAX][MAX], int P[MAX][MAX], int n){
	cout << "------------"<<endl;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cout << D[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------"<<endl;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cout << P[i][j] << " ";
		}
		cout << endl;
	}}

int main(){
	// D guarda las múltipicaciones minimas escalares desde la matriz i hasta la matriz j
	// P guarda la k que minimiza las MEM Mi...Mj
	// int D[MAX][MAX], P[MAX][MAX];
	int size,n; // cantidad de matrices a mult.
	// for (int i=0; i<MAX; i++){
	// 	for (int j=0; j<MAX; j++){
	// 		D[i][j] = P[i][j] = 0;
	// 	}
	// }
	 cin >> size;
   while(size != 0){
     int d[MAX]; // Las dimensiones de las matrices
     cin >> n;

     d[0] = 0;
     for (int i=1; i<=n; i++){
       cin >> d[i];
     }
     d[n+1] = size;

     cout<<"The minimum cutting is "<< cut(d,0,n+1)<<"."<<endl;
                                                          cout<<"linear calls:"<<linearCalls<<endl;
                                                          cout<<"constant calls:"<<constantCalls<<endl;
                                                          linearCalls = 0;
                                                          constantCalls = 0;
     refreshMemo(n+2);
     cin >> size;
   }


	// calcula(D, P, d, n);
	//despliega(P, n);
//	despM(D,P,n);
}

/*
4
20 2 30 12 8

RESP = 1232
(A)x(((B)x(C))x(D))
*/

// A  8 x 2
// B  2 x 5
// C  5 x 4
// n = 3
// d  8 2 5 4
