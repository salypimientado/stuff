#include "trieNode.h"
#include <string>

class trie{
 public:
  trie();
  void insert(std::string word);
  bool search(std::string word);
 private:
  trieNode *root;
};

trie::trie(){
  root = new trieNode('\0', nullptr);
}

void trie::insert(std::string word){
  trieNode* cur = root;
  for(int i = 0; i< word.length(); i++){
    char c = word[i];
    trieNode *sub = cur->getChild(c);
    if(sub == nullptr) {
      cur = cur->addChild(new trieNode(c,cur));
    }
    else{
      cur = sub;
    }
  }
  cur->end = true;
}

bool trie::search(std::string word){
  trieNode *cur = root;
  for(int i=0; i< word.length(); ++i){
    char c = word[i];
    cur = cur->getChild(c);
    if(cur == nullptr){
      return false;
    }
  }
  return cur->end;
}
