#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, a, b;
  cin >> n;

  unordered_map<int,pair<int,int>> times;
  // num: <home,visitor>

  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    auto rethost = times.insert(make_pair(a, make_pair(1, 0)));
    auto retvisit = times.insert(make_pair(b, make_pair(0, 1)));

    if(!rethost.second){
      rethost.first->second.first++;
    }
    if (!retvisit.second) {
      retvisit.first->second.second++;
    }
  }

  int sum = 0;
  for(auto i: times){
    //cout << i.first<<": <"<< i.second.first<< ","<<i.second.second << ">"<< endl;
    sum += i.second.first * i.second.second;
  }
  cout<<sum<<endl;

}
