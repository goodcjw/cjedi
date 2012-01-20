/*
 *  replace string
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void replaceOneLine(string& str, string from, string to) {
  size_t pos = 0;
  pos = str.find(from, pos);
  while (pos != string::npos) {
    str.replace(pos, from.length(), to);
    pos = str.find(from, pos);
  }
}

int main(int argc, char** argv) {
  if (argc != 4) {
    return -1;
  }
  ifstream ifs(argv[1], ifstream::in);
  string tmp;
  while (ifs.good()) {
    getline(ifs, tmp);
    replaceOneLine(tmp, string(argv[2]), string(argv[3]));
    cout << tmp << endl;
  }
  ifs.close();
  return 0;
}
