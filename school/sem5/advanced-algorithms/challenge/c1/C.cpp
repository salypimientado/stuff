#include <iostream>
#include <string>

using namespace std;

void danger(string players, char team, int amount) {
  for (auto i : players) {
    if (team == 'z') {
      team = i;
      ++amount;
    } else if (team != i) {
        team = i;
        amount=1;
    } else
      ++amount;
    cout<< i<< " " <<amount<< endl;
    if (amount == 7) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main(){
  string players;
  cin >> players;
  int amount = 0;
  char team = 'z';

  danger(players,team,amount);

}

