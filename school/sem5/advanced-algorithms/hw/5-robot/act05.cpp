#include <iostream>
#include <vector>

using namespace std;

#define TESTING false

void trainChecker(vector<int> train1, vector<int> train2,vector<int> desiredTrain){
  vector<vector<int>> matrix(train2.size()+1,vector<int>(train1.size()+1,-1));
  matrix[0][0] = 0;

  for(int i = 0; i < matrix.size();++i){
    for(int j = 0; j < matrix[i].size();++j){
      auto index = matrix[i][j];
      if(index != -1){
        if(j < matrix[i].size()-1){
          if(train1[j] == desiredTrain[index]) matrix[i][j+1] = index+1;
        }
        if(i < matrix.size()-1){
          if(train2[i] == desiredTrain[index]) matrix[i+1][j] = index+1;
        }
      }
    }
  }
  if(TESTING){
    for(auto i: matrix){
      for(auto j: i)cout<<j << "\t";
      cout<<endl;
    }
  }

  cout << (matrix[train2.size()][train1.size()] != -1? "possible":"not possible")<<endl;
}

int main() {
  int size1, size2, input;

  cin >> size1 >> size2;

  while (size1 != 0 || size2 != 0) {

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i = 0; i < size1; ++i) {
      cin >> input;
      v1.push_back(input);
    }
    for (int i = 0; i < size2; ++i) {
      cin >> input;
      v2.push_back(input);
    }
    for (int i = 0; i < size1 + size2; ++i) {
      cin >> input;
      v3.push_back(input);
    }
    trainChecker(v1,v2,v3);



    cin >> size1 >> size2;
  }
}

/*



  if both heads not equal desired head and temp list head doesnt either (empty)
  possible = false and break

*/


      /*
        deque<int> train1;
        deque<int> train2;
        deque<int> desiredTrain;
        deque<int> temp;
        bool possible = true;
      while (!desiredTrain.empty()) {

        // if a list is empty and temp list is not empty, push it into it
        if (train1.empty() || train2.empty()) {
          if(TESTING) cout<<"list is empty and temp list is not empty"<<endl;
          if (train1.empty()) {
            while (!temp.empty()) {
              train1.push_front(temp.back());
              temp.pop_back();
            }
          } else {
            while (!temp.empty()) {
              train2.push_front(temp.back());
              temp.pop_back();
            }
          }
        }

        int headTrain1 = train1.front();
        int headTrain2 = train2.front();
        int desiredHead = desiredTrain.front();
        int headTemp = temp.empty() ? -1 : temp.front();

        bool firstEquals =
            headTrain1 != -1 ? headTrain1 == desiredTrain.front() : false;
        bool secondEquals =
            headTrain2 != -1 ? headTrain2 == desiredTrain.front() : false;
        bool noneEquals = !firstEquals && !secondEquals;
        bool sameHeads = headTrain1 == headTrain2;
        bool differentHeads = headTrain1 != headTrain2;
        bool oneNotBoth = firstEquals ^ secondEquals;
        bool both = firstEquals && secondEquals;
        bool tempEquals =
            headTemp != -1 ? headTemp == desiredTrain.front() : false;
        bool tempExists = headTemp != -1;

        // if there is a temp list and both heads are not the same, push the
        // temp list into the list whose head is not the head of the desired
        // train and restart step
        if (tempExists && differentHeads) {
          if(TESTING) cout<<"notSameTemp"<<endl;
          if (firstEquals) {
            while (!temp.empty()) {
              train2.push_front(temp.back());
              temp.pop_back();
            }
          } else if (secondEquals) {
            while (!temp.empty()) {
              train1.push_front(temp.back());
              temp.pop_back();
            }
          }
          else if(!tempEquals)throw 0;
          else{
            temp.pop_front();
            desiredTrain.pop_front();
          }
        }
        else{

        // if only one head of the two lists is equal to the head of the desired
        // train pop them both
        if (oneNotBoth) {
          if(TESTING) cout<<"oneNotBoth"<<endl;
          if (firstEquals)
            train1.pop_front();
          else
            train2.pop_front();
          desiredTrain.pop_front();
        }

        // if both heads are equal, pop all of them and push one to the temp
        // list
        else if (both) {
          if(TESTING) cout<<"both"<<endl;
          train1.pop_front();
          train2.pop_front();
          desiredTrain.pop_front();
          temp.push_back(headTrain1);
        }

        // if both heads not equal to desired head check temp list, if head
        // equals pop it
        else if (noneEquals) {
          if(TESTING) cout<<"noneEquals"<<endl;
          if (tempEquals) {
            desiredTrain.pop_front();
            temp.pop_front();
          } else {
            throw 0;
          }
        }
}

        display
      }
    cout << (possible ? "possible" : "not possible") << endl;

    // trainCheckerRec(train1, train2, desiredTrain);

#define display                                                                \
  if (TESTING) {                                                               \
    cout << "\na = " << headTrain1 << "\nb = " << headTrain2                   \
         << "\nc = " << desiredHead << endl;                                   \
    cout << "train1: ";                                                        \
    for (auto i : train1) {                                                    \
      cout << i;                                                               \
    }                                                                          \
    cout << endl;                                                              \
    cout << "train2: ";                                                        \
    for (auto i : train2) {                                                    \
      cout << i;                                                               \
    }                                                                          \
    cout << endl;                                                              \
    cout << "desiredtrain: ";                                                  \
    for (auto i : desiredTrain) {                                              \
      cout << i;                                                               \
    }                                                                          \
    cout << endl;                                                              \
    cout << "temp: ";                                                          \
    for (auto i : temp) {                                                      \
      cout << i;                                                               \
    }cout << endl;}                                                     \
    */

