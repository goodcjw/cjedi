/*
 *
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char** argv) {
  if (argc != 3) return -1;

  int k = atoi(argv[1]);
  const char* filename = argv[2];

  ifstream ifs(filename, ifstream::in);
  queue<string> qs;
  int cnt = 0;
  string tmp;

  getline(ifs, tmp);
  while (ifs.good()) {
    qs.push(tmp);
    if (++cnt > k) {
      qs.pop();
    }
    getline(ifs, tmp);
  }

  while (!qs.empty()) {
    tmp = qs.front();
    cout << tmp << endl;
    qs.pop();
  }

  return 0;
}
