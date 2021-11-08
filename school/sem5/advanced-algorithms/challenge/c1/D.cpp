#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  Node *insert(Node *root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node *cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }

  /*
  class Node {
      public:
          int data;
          Node *left;
          Node *right;
          Node(int d) {
              data = d;
              left = NULL;
              right = NULL;
          }
  };

  */

  void topView(Node *root) {
    map<int, int> *top = new map<int, int>();
    traverse(root, 0, top);

    for (auto i : *top) {
      cout << i.second << " ";
    }
  }

  void traverse(Node *root, int num, map<int, int> *top) {
    queue<tuple<Node*,int,int>> queue;

    // [nodo, direccion y numero de este nodo]
    top->insert(make_pair(0, root->data));
    queue.push(make_tuple(root->right, 1, 1));
    queue.push(make_tuple(root->left, -1, -1));
    while(!queue.empty()){
      Node* cur = nullptr;
      int side, currentNumber;
      tie(cur, side, currentNumber) = queue.front();
      //if(cur) cout<< cur->data << " " <<currentNumber<<endl;
      queue.pop();
      if(cur){
        top->insert(make_pair(currentNumber, cur->data));

        if(side == -1){
        queue.push(make_tuple(cur->right, 1, currentNumber + 1));
        queue.push(make_tuple(cur->left, -1, currentNumber - 1));
        }
        else{
          queue.push(make_tuple(cur->right, 1, currentNumber + 1));
          queue.push(make_tuple(cur->left, -1, currentNumber - 1));
        }
      }
    }
  }

}; // End of Solution

int main() {

  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }
  myTree.topView(root);
  return 0;
}

// input

//
// 116 37 23 108 59 86 64 94 14 105 17 111 65 55 31 79 97 78 25 50 22 66 46 104
// 98 81 90 68 40 103 77 74 18 69 82 41 4 48 83 67 6 2 95 54 100 99 84 34 88 27
// 72 32 62 9 56 109 115 33 15 91 29 85 114 112 20 26 30 93 96 87 42 38 60 7 73
// 35 12 10 57 80 13 52 44 16 70 8 39 107 106 63 24 92 45 75 116 5 61 49 101 71
// 11 53 43 102 110 1 58 36 28 76 47 113 21 89 51 19 3

// expected 1 2 4 14 23 37 108 111 115 116 83 84 85
