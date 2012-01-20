/*
 *
 */

#include <iostream>
#include <utility>
#include <string>
#include <set>

using namespace std;

class PathFinder {
 private:
  int size;
  set<pair<int, int> > mOffLimit;
  set<string> mPathes;
  void findPossiblePath(pair<int, int> p, string path);

 public:
  PathFinder(int tSize) : size(tSize) {}    
  void setOffLimit(pair<int, int> p);
  void findAllPath();
  void dispAllPath();
};

void PathFinder::setOffLimit(pair<int, int> p) {
  mOffLimit.insert(p);
}

void PathFinder::findAllPath() {
  pair<int, int> init_pos(0, 0);
  findPossiblePath(init_pos, "");
}

void PathFinder::dispAllPath() {
  set<string>::iterator it;
  for (it = mPathes.begin(); it != mPathes.end(); it++) {
    cout << *it << endl;
  }
}

void PathFinder::findPossiblePath(pair<int, int> p, string path) {
  if (p.first == size - 1 && p.second == size -1) {
    mPathes.insert(path);
    return;
  }
  pair<int, int> right_pos(p.first + 1, p.second);
  pair<int, int> down_pos(p.first, p.second + 1);
  if (p.first < size && mOffLimit.find(right_pos) == mOffLimit.end()) {
    findPossiblePath(right_pos, path + "R");
  }
  if (p.second < size && mOffLimit.find(down_pos) == mOffLimit.end()) {
    findPossiblePath(down_pos, path + "D");
  }
}

int main(int argc, const char** argv) {
  PathFinder pf(3);
  pair<int, int> off1(1, 1);
  pf.setOffLimit(off1);
  pf.findAllPath();
  pf.dispAllPath();
  return 0;
}
