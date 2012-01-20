/*
 *  reverse string
 */

#include <cassert>
#include <iostream>
#include <string>
#include <cctype>

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
  string istr(str);
  size_t pos = 0;
  pos = istr.find_first_of(" ,.", pos);
  while (pos != string::npos) {
    istr.erase(pos, 1);
    pos = istr.find_first_of(" ,.", pos);
  }
  string::iterator it = istr.begin();
  for (; it != istr.end(); it++) {
    *it = tolower(*it);
  }
  string tmp(istr);
  reverse_str(tmp);
  if (istr == tmp) return true;
  else return false;
}

void test() {
  assert(is_palindrome("aaaa"));
  assert(!is_palindrome("abab"));
  assert(is_palindrome("wow"));
  assert(is_palindrome("Civic"));
  assert(!is_palindrome("ab bb"));
  assert(is_palindrome("Ci, vic"));
}

int main() {
  test();
  return 0;
}
