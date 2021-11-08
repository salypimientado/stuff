#include <iostream>
#include <queue>

using namespace std;

int minCoins(priority_queue<int> nums, int max) {
  for (int i = 0; nums.size() != 0; ++i) {
    max -= nums.top();
    nums.pop();

    if (max < 0)
      return i+1;
  }
  return -1;
}

int main(){
  int n, a;
  cin >> n;

  priority_queue<int> nums;

  int total = 0;
  //add num to heap and to max total
  for(int i = 0; i < n; ++i){
    cin >> a;
    nums.push(a);
    total += a;
    
  }

  cout<< minCoins(nums, total/2);

}
