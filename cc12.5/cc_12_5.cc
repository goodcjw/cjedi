/*
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tr1/unordered_set>

using namespace std;
using namespace std::tr1;

class NodeInt {
public:
  NodeInt* next;
  int val;
};

NodeInt* create_list(int n) {
  NodeInt* head;
  NodeInt* tmp;
  NodeInt* prev;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      head = tmp = new NodeInt();
    } else {
      tmp = new NodeInt();
      prev->next = tmp;
    }
    tmp->val = rand() % 10;
    prev = tmp;
  }
  tmp->next = NULL;
  return head;
}

void print_list(NodeInt* head) {
  NodeInt* tmp = head;
  while (tmp != NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
  printf("\n");
}

void remove_dup(NodeInt* head) {
  unordered_set<int> uniq;
  
  NodeInt* tmp = head;
  NodeInt* prev = NULL;

  while (tmp != NULL) {
    if (uniq.find(tmp->val) == uniq.end()) {
      prev = tmp;
      uniq.insert(tmp->val);
      tmp = tmp->next;
    } else {
      assert(prev != NULL);
      prev->next = tmp->next;
      // free
      delete tmp;
      tmp = tmp->next;
    }
  }
}

int delete_node(NodeInt* head, NodeInt* nd) {
  NodeInt* tmp;
  NodeInt* prev;
  if (head == NULL || nd == NULL) return 0;
  if (head == nd) {
    head = nd->next;
    delete nd;
    return 0;
  }
  tmp = head->next;
  prev = head;
  while (tmp != NULL) {
    if (tmp == nd) {
      prev->next = nd->next;
      delete tmp;
      return 0;
    }
    tmp = tmp->next;
    prev = prev->next;
  }
  return -1;
}

NodeInt* reverse(NodeInt* head) {
  NodeInt* prev = NULL;
  NodeInt* cur = head;
  NodeInt* next;

  if (head == NULL) return NULL;

  while (cur != NULL) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

int main(int argc, const char** argv) {
  srand(time(0));

  NodeInt* l1 = create_list(5);
  print_list(l1);
  NodeInt* todel = l1->next->next;
  delete_node(l1, todel);
  print_list(l1);
  l1 = reverse(l1);
  print_list(l1);
  return 0;
}
