/*
 *  reverse string
 */

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void reverse_str(string& str) {
  string::iterator its = str.begin();
  if (its == str.end()) return;
  string::iterator ite = str.end();
  ite--;
  while (its < ite) {
    char tmp = *its;
    *its = *ite;
    *ite = tmp;
    its++;
    ite--;
  }
  return;
}

bool is_palindrome(const string& str) {
  string tmp(str);
  reverse_str(tmp);
  if (str == tmp) return true;
  else return false;
}

void test() {
  assert(is_palindrome("aaaa"));
  assert(!is_palindrome("abab"));
  assert(is_palindrome("wow"));
}

int main() {
  test();
  return 0;
}
