#include <iostream>
#include <vector>

using namespace std;

// check min k required by grouping ascending numbers
// add ranges taken by groups into taken ranges vector
// if any number is contained within a range, return no
// if all numbers processed and k is more than calculated min k return yes


int main(){
  int n, m, k, v;
  cin >> n;
  for(int i = 0; i< n; ++i){
    vector<int> array;
    cin >> m >> k;
    for(int j = 0; j< m; ++j){
      cin >> v;
      array.push_back(v);
    }
    cout<< ( minK(array,k)? "YES": "NO" )<<endl;
  }
}
