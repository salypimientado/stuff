#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;


vector<int> zFunction(string text){
  vector<int> Z(text.size(),0);

  int R = 0, L = 0, k = 0, n = text.size();
  Z[0] = text.size();
  for(int i = 1; i< text.size();++i){

    // case 1: r < i
    if(R < i){
      L = R = i;
 
      // R-L = 0 in starting, so it will start
      // checking from 0'th index. For example,
      // for "ababab" and i = 1, the value of R
      // remains 0 and Z[i] becomes 0. For string
      // "aaaaaa" and i = 1, Z[i] and R become 5
      while (R<n && text[R-L] == text[R])
        R++;
      Z[i] = R-L;
      R--;
    }

  //case 2a: z[k'] < beta (r-i+1)
    else{
      k = i-L;

      //case 2a: z[k'] < beta (r-i+1)
      if (Z[k] < R-i+1)
        Z[i] = Z[k];

      //case 2b: z[k'] > beta (r-i+1)
      else if(Z[k] > R-i+1){
        Z[i] = R-i+1;
      }
      //case 2c: z[k'] = beta (r-i+1)
      else {
          // else start from R and check manually
          L = i;
          while (R<n && text[R-L] == text[R])
            R++;
          Z[i] = R-L;
          R--;
      }
    }
  }
  return Z;
}

int main(){

  string text;
  cin >> text;

  auto Z = zFunction(text);

  vector<bool> found(Z.size()+1);

  int count = 0;
  for(int i = 0; i<Z.size(); ++i){
    if(i + Z[i] == Z.size()){
      count++;
      found[Z[i]] = true;
    }
  }
  cout<<count<<endl;
  // for(auto i: Z) cout<< i<< " ";
  vector<int> amount(Z.size()+1);

  for(int i = 0; i< Z.size(); ++i){
    amount[Z[i]]++;
  }
  // sum of bigger nums
  for(int i = Z.size()-1; i >=0; --i){
    amount[i] += amount[i+1];
  }
  for(int i = 1; i<=Z.size(); ++i){
    if(found[i]) cout<<i<<" "<<amount[i]<<endl;
  }

}
