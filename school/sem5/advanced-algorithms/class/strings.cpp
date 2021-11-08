
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> kmp(string texto, string patron){
  vector<int> matches;


}

int main(){
  string texto, patron;
  cin >> texto >> patron;

  vector<int> matches = kmp(texto,patron);
  if(matches.size() == 0){
    cout << "No match" <<endl;
  }
  else{
    for(auto i: matches) cout<<i<<" ";
    cout<<endl;
  }

}
/*
int main(){
  string texto, patron;
  cin >> texto >> patron;
  vector<int> pos = solve(texto,patron);
  if(!pos.size()){
    cout<<"no existe el patron"<<endl;
  }
  else{
    for(auto i: pos){
      cout<<i<< " ";
    }
    cout<<endl;
  }
}
*/
