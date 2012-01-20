/*
 *
 */

#include <queue>
#include <iostream>

using namespace std;

class NodeInt {
 public:
  int val;
  NodeInt* left;
  NodeInt* right;

  NodeInt() {
    val = 0;
    left = NULL;
    right = NULL;
  }
};

NodeInt* create_tree() {
  NodeInt* root = new NodeInt();
  root->val = 0;
  NodeInt* root_l = new NodeInt();
  root->left = root_l;
  root_l->val = 1;
  NodeInt* root_r = new NodeInt();
  root->right = root_r;
  root_r->val = 2;
  NodeInt* root_ll = new NodeInt();
  root_l->left = root_ll;
  root_ll->val = 3;
  NodeInt* root_lr = new NodeInt();
  root_l->right = root_lr;
  root_lr->val = 4;
  NodeInt* root_lll = new NodeInt();
  root_ll->left = root_lll;
  root_lll->val = 5;
  return root;
}

void level_traverse(NodeInt* root) {
  queue<NodeInt*> levelq;
  
  if (root == NULL)
    return;
  levelq.push(root);
  levelq.push(NULL);
  while (levelq.size() != 0) {
    NodeInt* tmp = levelq.front();
    levelq.pop();
    if (tmp == NULL) {
      cout << endl;
      if (levelq.size() != 0)
        levelq.push(NULL);
    } else {
      if (tmp->left)
        levelq.push(tmp->left);
      if (tmp->right)
        levelq.push(tmp->right);
      cout << tmp->val << " ";
    }
  }
}

int main(int argc, const char** argv) {
  NodeInt* root = create_tree();
  level_traverse(root);
  return 0;
}
