#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

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

string legend(string text){
  auto Z = zFunction(text);
  int curSuffix = 0;
  int max = 0;
   // for(auto i: Z) cout<< i<< " ";
   // cout<<endl;
  for(int i = Z.size()-1;i>=1;--i){
    if(Z[i] >= curSuffix) {
      //new max
      string stri = "";
      if(curSuffix > max) max = curSuffix;
    }
    //cout<<Z[i]<< " "<< Z.size() -i<<endl;
    if(Z[i] == Z.size() -i && Z[i] != 0) curSuffix = Z[i];
  }
  if(max != 0) return text.substr(0,max);
  return "Just a legend";
}

int main(){
  string c;
  cin >> c;
  cout<< legend(c)<<endl;
}
