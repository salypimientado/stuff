#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int VALOR, n;

vector<int> obj;
vector<bool> include;

void subsets(int i, int acum, int total){
  {
    if(acum+total>=VALOR && (acum == VALOR || acum+obj[i+1] <= VALOR)){
      if(acum==VALOR){
        for(int k = 1; k<=n; k++){
          if(include[k]){
            cout<<obj[k] << " ";
          }
        }
        cout << endl;
      }
      else{
        include[i+1] = true;
        subsets(i+1,acum+obj[i+1],total-obj[i+1]);
        include[i+1] = false;
        subsets(i+1,acum,total-obj[i+1]);
      }

    }
  }
}

int main(){
  cin >> n >> VALOR;
  int dato, total = 0;
  for(int i = 0; i< n; ++i){
    cin >> dato;
    obj.push_back(dato);
    total+=dato;
    include.push_back(false);
  }
  sort(obj.begin(),obj.end());
  subsets(-1,0,total);
}

