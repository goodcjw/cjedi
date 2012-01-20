/*
 *
 */

#include <cassert>
#include <climits>
#include <stack>

using namespace std;

class MinStack {
 private:
  stack<int> minstack;
 public:
  int min();
  int top();
  void push(int val);
  void pop();
};

int MinStack::min() {
  return minstack.top();
}

int MinStack::top() {
  int min = minstack.top();
  minstack.pop();
  int ret = minstack.top();
  minstack.push(min);
  return ret;
}

void MinStack::push(int val) {
  int min;
  if (minstack.size() == 0) {
    min = INT_MAX;
  } else {
    min = minstack.top();
  }
  minstack.push(val);
  minstack.push(val < min ? val : min);
}

void MinStack::pop() {
  minstack.pop();
  minstack.pop();
}

int main() {
  MinStack msk;
  msk.push(2);
  msk.push(5);
  assert(msk.top() == 5);
  assert(msk.min() == 2);
  msk.push(1);
  assert(msk.top() == 1);
  assert(msk.min() == 1);
  msk.push(10);
  assert(msk.top() == 10);
  assert(msk.min() == 1);
  msk.pop();
  msk.pop();
  assert(msk.min() == 2);
  msk.pop();
  assert(msk.min() == 2);
}
