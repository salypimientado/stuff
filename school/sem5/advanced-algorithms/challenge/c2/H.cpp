#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

  int t, n, a;

  cin >> t;
  while(t --> 0){
    cin >> n;
    vector<int> elements;
    int max = 0;
    string it = "a";
    while(n --> 0){
      cin>> a;
      max = a > max? a: max;
      elements.push_back(a);
    }
    while(max --> 0){
      it += 'a';
    }
    cout<<it<<endl;
    for(int i = 0; i<elements.size(); ++i){
      if(elements[i] != it.size()){
        auto charToChange = it[elements[i]];
        it[elements[i]] = ( ( charToChange - 'a' +1) % 26 ) + 'a';
      }
      cout<<it<<endl;
    }
  }
}
