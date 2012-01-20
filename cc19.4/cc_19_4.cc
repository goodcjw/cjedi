/*
 * A merge sort implemented using stack
 * currently only works for power of two
 */

#include <cassert>
#include <stack>
#include <iostream>

using namespace std;

void dumbSortStack(stack<int>& stk) {
  stack<int> tmpstk;
  int tmpint;
  while (!stk.empty()) {
    tmpstk.push(stk.top());
    stk.pop();
  }
  while (!tmpstk.empty()) {
    while (stk.empty() || stk.top() >= tmpstk.top()) {
      stk.push(tmpstk.top());
      tmpstk.pop();
      if (tmpstk.empty())
        return;
    }
    tmpint = tmpstk.top();
    tmpstk.pop();
    while (!stk.empty() && stk.top() <= tmpint) {
      tmpstk.push(stk.top());
      stk.pop();
    }
    stk.push(tmpint);
  }
}

void sortStack(stack<int>* stk) {

  stack<int>* s1 = new stack<int>();
  stack<int>* s2 = new stack<int>();
  stack<int>* from = stk;
  stack<int>* to = new stack<int>();
  stack<int>* tmp;
  size_t stk_size = from->size();
  size_t step = 1;
  size_t i, j;

  while (step < stk_size) {
    for (i = 0; i < stk_size; i += 2*step) {
      assert(s1->size() == 0);
      assert(s2->size() == 0);
      for (j = 0; j < step; j++) {
        if (from->size() == 0) break;
        s1->push(from->top());
        from->pop();
      }
      for (j = 0; j < step; j++) {
        if (from->size() == 0) break;
        s2->push(from->top());
        from->pop();
      }
      // merge
      while (s1->size() != 0 && s2->size() != 0) {
        if (s1->top() < s2->top()) {
          cout << s1->top() << endl;
          to->push(s1->top());
          s1->pop();
        }
        else {
          cout << s2->top() << endl;
          to->push(s2->top());
          s2->pop();
        }
      }
      while (s1->size() != 0) {
        cout << s1->top() << endl;
        to->push(s1->top());
        s1->pop();
      }
      while (s2->size() != 0) {
        cout << s2->top() << endl;
        to->push(s2->top());
        s2->pop();
      }
    }
    cout << "step: " << step << endl;
    step *= 2;
    // swap
    tmp = from;
    from = to;
    to = tmp;
    assert(to->size() == 0);
  }

  assert(s1->size() == 0);
  assert(s2->size() == 0);
  if (from != stk) {
    assert(stk->size() == 0);
    while (from->size() != 0) {
      s1->push(from->top());
      from->pop();
    }
    while (s1->size() != 0) {
      stk->push(s1->top());
      s1->pop();
    }
    delete from;
  }
  else {
    delete to;
  }
  delete s1;
  delete s2;
}

int main() {
  stack<int> stest;
  stest.push(12);
  stest.push(2);
  stest.push(23);
  stest.push(3);
  stest.push(8);
  stest.push(123);
  stest.push(7);
  stest.push(11);
  stest.push(17);
  stest.push(10);
  stest.push(102);
  //  sortStack(&stest);
  dumbSortStack(stest);
  while (stest.size() != 0) {
    cout << stest.top() << endl;
    stest.pop();
  }
  return 0;
}
