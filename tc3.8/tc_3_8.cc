/*
 *  find anagram (palindrome)
 */

#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <tr1/unordered_set>

using namespace std;
using namespace std::tr1;

void toLowerCase(string& str) {
  string::iterator its;
  for (its = str.begin(); its != str.end(); its++) {
    *its = tolower(*its);
  }
}

bool isPalindrome(const string& str) {
  size_t len = str.length();
  for (size_t i = 0; i < len / 2; i++) {
    if (str[i] != str[len-i-1]) return false;
  }
  return true;
}

int main(int argc, char** argv) {
  if (argc != 2) return -1;

  ifstream ifs(argv[1], ifstream::in);
  if (!ifs) return -1;

  unordered_set<string> palindrome;
  string tmps;
  while (!ifs.eof()) {
    ifs >> tmps;
    toLowerCase(tmps);
    if (isPalindrome(tmps))
      palindrome.insert(tmps);
  }

  unordered_set<string>::iterator itp;
  for (itp = palindrome.begin(); itp != palindrome.end(); itp++) {
    cout << *itp << endl;
  }
  return 0;
}
