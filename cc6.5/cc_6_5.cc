/*
 *
 */

#include <set>
#include <list>
#include <iostream>

using namespace std;

void allSubsets(set<int> s, set<int> t) {
  if (s.empty()) {
    set<int>::iterator it = t.begin();
    for (; it != t.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
    return;
  }
  set<int>::iterator it = s.begin();
  int tmp = *it;
  s.erase(it);
  allSubsets(s, t);
  t.insert(tmp);
  allSubsets(s, t);
}

int main(int argc, const char** argv) {
  set<int> s;
  set<int> t;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  allSubsets(s, t);
  return 0;
}
