/*
 * Check balanced tree
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node() : val(0), left(NULL), right(NULL) {}
};

int isBalancedTree(Node* nd) {
  int left_height;
  int right_height;
  if (nd == NULL)
    return 0;
  left_height = isBalancedTree(nd->left);
  if (left_height < 0) return -1;
  right_height = isBalancedTree(nd->right);
  if (right_height < 0) return -1;
  if (left_height > right_height + 1 ||
      right_height > left_height + 1)
    return -1;
  else
    return 1 + ((left_height > right_height) ? left_height : right_height);
}

int main() {
  int h;
  Node* r = new Node();
  h = isBalancedTree(r);
  printf("h: %d\n", h);
  assert(h == 1);
  r->left = new Node();
  r->right = new Node();
  h = isBalancedTree(r);
  printf("h: %d\n", h);
  assert(h == 2);
  r->left->left = new Node();
  h = isBalancedTree(r);
  printf("h: %d\n", h);
  assert(h == 3);
  r->left->left->left = new Node();
  h = isBalancedTree(r);
  printf("h: %d\n", h);
  assert(h == -1);
}
