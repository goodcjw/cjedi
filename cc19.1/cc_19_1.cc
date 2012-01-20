/*
 *
 */

#include <cassert>
#include <stack>
#include <iostream>

using namespace std;

class QueueByStacks {
 private:
  stack<int> instack;
  stack<int> outstack;
  void transport();

 public:
  void push(int val);
  int front();
  void pop();
};

void QueueByStacks::transport() {
  if (outstack.size() != 0) {
    return;
  }
  while (instack.size() != 0) {
    int tmp = instack.top();
    instack.pop();
    outstack.push(tmp);
  }
}

void QueueByStacks::push(int val) {
  instack.push(val);
}

int QueueByStacks::front() {
  if (outstack.size() == 0) {
    transport();
  }
  return outstack.top();
}

void QueueByStacks::pop() {
  if (outstack.size() == 0) {
    transport();
  }
  outstack.pop();
}

int main(int argc, const char** argv) {
  QueueByStacks q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);
  assert(q1.front() == 1);
  q1.pop();
  assert(q1.front() == 2);
  q1.push(4);
  q1.push(5);
  for (int i = 2; i <= 5; i++) {
    assert(q1.front() == i);
    q1.pop();
  }
  return 0;
}
