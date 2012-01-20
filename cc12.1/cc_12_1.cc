/*
 *
 */

#include <assert.h>
#include <stdio.h>

class NodeInt {
public:
  NodeInt* next;
  int val;
};

NodeInt* create_list() {
  NodeInt* head;
  NodeInt* tmp;
  NodeInt* prev;
  for (int i = 0; i < 5; i++) {
    if (i == 0) {
      head = tmp = new NodeInt();
    } else {
      tmp = new NodeInt();
      prev->next = tmp;
    }
    tmp->val = i;
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

int* nthToLastOff(NodeInt* head, int n) {
  if (head == NULL)
    return NULL;
  NodeInt* p1 = head;
  NodeInt* p2 = head;
  for (int j = 0; j < n - 1; ++j) {
    if (p2 == NULL)
      return NULL;
    p2 = p2->next;
  }
  while(p2->next != NULL) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return &(p1->val);
}

int* nthToLast(NodeInt* head, int n) {
  if (n <= 0)
    return NULL;
  NodeInt* tmp = head;
  NodeInt* ret = head;
  int cnt = 0;
  while (tmp != NULL) {
    tmp = tmp->next;
    if (cnt < n)
      cnt++;
    else
      ret = ret->next;
  }
  if (cnt == n) return &(ret->val);
  else return NULL;
}

int main(int argc, const char** argv) {
  NodeInt* l1 = create_list();
  print_list(l1);
  /*
  for (int i = 1; i < 10; i++) {
    assert(nthToLast(l1, i) == nthToLastOff(l1, i));
  }
  */
  int* t;
  for (int i = 1; i < 10; i++) {
    t = nthToLastOff(l1, i);
    if (t)
      printf("%d\n", *t);
    else
      printf("NULL\n");
  }
  return 0;
}
