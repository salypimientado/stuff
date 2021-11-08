#include <bits/stdc++.h>

using namespace std;

pair<int, string> palindrome(string text){
  int mxl = 0; int mxr = 0;
  string altered = "";
  for(auto i: text) altered += std::string() + '|'+i;
  altered += "|";
  vector<int> d1(altered.size());
  for(int i = 0, l = 0, r = -1; i< altered.size(); ++i){
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < altered.size() && altered[i - k] == altered[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
    if( r - l > mxr - mxl){
      if(altered[mxr] == '|') mxr = r-1;
      else mxr = r;
      mxl = l;
    }
  }
  return make_pair(mxl/2,text.substr(( mxl/2 ),(mxr/2)-(mxl/2)));
}

int main(){
  string str;
  cin >> str;
  int index;
  string pal;
  auto res = palindrome(str);
  cout<<res.first<<" "<<res.second<<endl;
}
