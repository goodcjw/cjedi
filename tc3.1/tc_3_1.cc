/*
 *  reverse string
 */

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

void reverse_stn(string& str) {
  reverse_str(str);
  size_t blanks = 0;
  size_t blanke = 0;
  blanke = str.find(' ', blanks);
  while (blanke != string::npos) {
    string tmp = str.substr(blanks, blanke - blanks);
    reverse_str(tmp);
    str.replace(blanks, blanke - blanks, tmp);
    blanks = blanke + 1;
    blanke = str.find(' ', blanks);
  }
  string tmp = str.substr(blanks, str.length() - blanks);
  reverse_str(tmp);
  str.replace(blanks, str.length() - blanks, tmp);
}

void test() {
  string s1("the member");
  cout << s1 << endl;
  reverse_stn(s1);
  cout << s1 << endl;
  string s2("size t");
  cout << s2 << endl;
  reverse_stn(s2);
  cout << s2 << endl;
}

int main() {
  test();
  return 0;
}
