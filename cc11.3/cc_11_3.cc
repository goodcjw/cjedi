/*
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class WordFreq {
 private:
  unordered_map<string, int> wd_base;
  int wd_cnt;
  void loadFile(const char* fileName);

 public:
  WordFreq(const char* fileName);
  double query(string word);
};

WordFreq::WordFreq(const char* fileName) {
  wd_cnt = 0;
  wd_base.clear();
  loadFile(fileName);
}

void WordFreq::loadFile(const char* fileName) {
  ifstream ifs(fileName, ifstream::in);
  string word;
  while (ifs.good()) {
    ifs >> word;
    wd_cnt++;
    if (wd_base.find(word) != wd_base.end())
      wd_base[word]++;
    else
      wd_base[word] = 1;
  }
}

double WordFreq::query(string word) {
  if (wd_base.find(word) != wd_base.end())
    return ((double) wd_base[word]) / wd_cnt;
  else
    return 0;
}

int main(int argc, const char** argv) {
  WordFreq wf("Makefile");
  cout << "clean: " << wf.query("TARGET") << endl;
  cout << "jwcai: " << wf.query("jwcai") << endl;
  cout << "rm:    " << wf.query("rm") << endl;
  cout << "cs35l: " << wf.query("cs35l") << endl;
}
