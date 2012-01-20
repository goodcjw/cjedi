/*
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

ssize_t search_str(vector<string>& strvec, string str) {
  size_t s = 0;
  size_t e = strvec.size() - 1;
  size_t m = s + (e - s) / 2;

  while (s <= e) {
    m = s + (e - s) / 2;
    if (strvec[m] == str)
      return m;
    while (m <= e && strvec[m] == " ")
      m++;
    if (m == e) {
      if (strvec[m] == str)
        return m;
      e = s + (e - s) / 2 - 1;  // e = m - 1
    }
    else {
      if (strvec[m] == str)
        return m;
      else if (strvec[m] > str)
        e = s + (e - s) / 2 - 1;
      else
        s = m + 1;
    }
  }
  return -1;
}

vector<string>* generate_str_vector() {
  vector<string>* strvec = new vector<string>();
  strvec->push_back(string("a"));
  strvec->push_back(string(" "));
  strvec->push_back(string("b"));
  strvec->push_back(string(" "));
  strvec->push_back(string(" "));
  strvec->push_back(string(" "));
  strvec->push_back(string("c"));
  strvec->push_back(string("d"));
  strvec->push_back(string(" "));
  strvec->push_back(string(" "));
  strvec->push_back(string("e"));
  strvec->push_back(string("f"));
  strvec->push_back(string(" "));
  strvec->push_back(string(" "));
  strvec->push_back(string("g"));
  strvec->push_back(string(" "));
  strvec->push_back(string("h"));
  return strvec;
}

void print_str_vector(vector<string>* strvec) {
  vector<string>::iterator its = strvec->begin();
  for (; its != strvec->end(); ++its) {
    cout << "\"" << *its << "\"" << " ";
  }
  cout << endl;
}

void print_point(size_t len, size_t pos) {
  for (size_t i = 0; i < len; ++i) {
    if (i == pos)
      cout << " ^  ";
    else
      cout << "    ";
  }
  cout << endl;
}

int main(int argc, const char** argv) {
  vector<string>* strvec = generate_str_vector();
  ssize_t pos;
  print_str_vector(strvec);
  pos = search_str(*strvec, "a");
  print_point(strvec->size(), pos);
  print_str_vector(strvec);
  pos = search_str(*strvec, "b");
  print_point(strvec->size(), pos);
  print_str_vector(strvec);
  pos = search_str(*strvec, "c");
  print_point(strvec->size(), pos);
  print_str_vector(strvec);
  pos = search_str(*strvec, "d");
  print_point(strvec->size(), pos);
  print_str_vector(strvec);
  pos = search_str(*strvec, "e");
  print_point(strvec->size(), pos);
  print_str_vector(strvec);
  pos = search_str(*strvec, "f");
  print_point(strvec->size(), pos);
  print_str_vector(strvec);
  pos = search_str(*strvec, "g");
  print_point(strvec->size(), pos);
  print_str_vector(strvec);
  pos = search_str(*strvec, "h");
  print_point(strvec->size(), pos);
  delete strvec;
}
