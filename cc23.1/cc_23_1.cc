/*
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define ERR_NODE  1
#define ERR_ARR   2
#define ERR_RANGE 3

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node() : val(0), left(NULL), right(NULL) {}
};

int expand_bst(Node* nd, int* arr, size_t s, size_t e) {
  if (nd == NULL) {
    return -ERR_NODE;
  }
  if (arr == NULL) {
    return -ERR_ARR;
  }
  if (s > e) {
    return -ERR_RANGE;
  }

  int ret = 0;
  size_t m = s + (e - s) / 2;
  nd->val = arr[m];

  if (s < m) {
    nd->left = new Node();
    ret = expand_bst(nd->left, arr, s, m - 1);    
  }
  if (e > m) {
    nd->right = new Node();
    ret = expand_bst(nd->right, arr, m + 1, e);
  }
  if (ret != 0) {
    if (nd->left)
      delete nd->left;
    if (nd->right)
      delete nd->right;
  }
  return ret;
}

void print_inorder(Node* nd) {
  if (nd->left)
    print_inorder(nd->left);
  printf("%d ", nd->val);
  if (nd->right)
    print_inorder(nd->right);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  
  for (int i = 0; i < 8; i++) {
    Node* nd = new Node();
    expand_bst(nd, arr, 0, i);
    print_inorder(nd);
    printf("\n");
    // release memory
  }
  return 0;
}
