/*
 *
 */

#include <iostream>
#include <string>

using namespace std;

void dispParenthH(int open, int close, string str) {
  if (close == 0) {
    cout << str << endl;
    return;
  }
  if (open > 0)
    dispParenthH(open - 1, close, str + "(");
  if (open < close)
    dispParenthH(open, close - 1, str + ")");
}

void dispParenth(int n) {
  dispParenthH(n, n, "");
}

int main(int argc, const char** argv) {
  dispParenth(4);
  return 0;
}
