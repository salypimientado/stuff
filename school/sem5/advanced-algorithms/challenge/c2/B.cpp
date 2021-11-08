#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

vector<vector<vector<string>>> memo;

vector<string> lcsstr3(string s1, string s2, string s3)
{
  vector<vector<vector<int>>> dp(s3.length(),vector<vector<int>>( s2.length(),vector<int>(s1.length(),0)));
  int max = 0;
  vector<string> maxRes;

  for(int m = 0; m< s3.length();++m){
    for(int i = 0; i< s2.length();++i){
      for(int j = 0; j< s1.length(); ++j){
        int tm = m, ti = i, tj = j;
        if(dp[tm][ti][tj] != 0) continue;
        if(s1[tj] == s2[ti] && s2[ti] == s3[tm]){
          bool notBreak = true;
          int val = 1;
          string res = string() + s1[tj];
          if(val >= max) max = val;
          dp[tm++][ti++][tj++] = val++;
          while(tm < s3.length() && ti < s2.length()  && tj < s1.length() && notBreak){
            if(s1[tj] == s2[ti] && s2[ti] == s3[tm]){
              res += s1[tj];
              dp[tm++][ti++][tj++] = val;
              if(val > max) {
                maxRes.clear();
                maxRes.push_back(res);
                max = val;
              }
              if(val == max)
                {
                  maxRes.push_back(res);
                }
              val++;
            }
            else{
              notBreak = false;
            }
          }
        }
      }
    }
  }
  
  return maxRes;
}

int lcsstr(string s1, string s2)
{
  vector<vector<int>> dp(s2.length(),vector<int>(s1.length(),0));
  int max = 0;

  for(int i = 0; i< s2.length();++i){
    for(int j = 0; j< s1.length(); ++j){
      int ti = i, tj = j;
      if(dp[ti][tj] != 0) continue;
      if(s1[tj] == s2[ti]){
        bool notBreak = true;
        int val = 1;
        if(val >= max) max = val;
        dp[ti++][tj++] = val++;
        while(ti < s2.length()  && tj < s1.length() && notBreak){
          if(s1[tj] == s2[ti]){
          dp[ti++][tj++] = val;
          if(val >= max) max = val;
          val++;
          }
          else{
            notBreak = false;
          }
        }
      }
    }
  }

  return max;
}

int main(){
  string s1, s2, s3;
  int n;

  cin >> n;
  while(n --> 0){
    cin >> s1 >> s2;
    auto res = lcsstr(s1,s2);
    int l = s1.size() + s2.size();
    l -= res*2;
    cout<<l<<endl;
  }
}
