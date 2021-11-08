#include <vector>

class trieNode {
 public:
  trieNode(char c, trieNode* parent);
  trieNode* getChild(char c);
  trieNode* addChild(trieNode* node);
  bool end;

 private:
  trieNode* children[26];
  char letter;
  trieNode* parent;

};

trieNode::trieNode(char c, trieNode *p){
  parent = p;
  letter = c;
  end = false;
  for(int i = 0; i< 26; ++i){
    children[i] = nullptr;
  }
}

trieNode* trieNode::getChild(char c){
  return children[c-'a'];
}

trieNode* trieNode::addChild(trieNode *node){
  children[node->letter -'a'] = node;
  return children[node->letter -'a'];
}
