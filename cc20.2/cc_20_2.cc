/*
 *
 */

#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string intToEnglishBase(int x) {
  switch (x) {
    case 0:
      return string("zero");
    case 1:
      return string("one");
    case 2:
      return string("two");
    case 3:
      return string("three");
    case 4:
      return string("four");
    case 5:
      return string("five");
    case 6:
      return string("six");
    case 7:
      return string("seven");
    case 8:
      return string("eight");
    case 9:
      return string("nine");
    case 10:
      return string("ten");
    case 11:
      return string("eleven");
    case 12:
      return string("tweleve");
    case 13:
      return string("thirteen");
    case 14:
      return string("fourteen");
    case 15:
      return string("fifteen");
    case 16:
      return string("sixteen");
    case 17:
      return string("seventeen");
    case 18:
      return string("eighteen");
    case 19:
      return string("nineteen");
    case 20:
      return string("twenty");
    case 30:
      return string("thirty");
    case 40:
      return string("forty");
    case 50:
      return string("fifty");
    case 60:
      return string("sixty");
    case 70:
      return string("seventy");
    case 80:
      return string("eighty");
    case 90:
      return string("nighty");
    default:
      return string("");
  }
}

string intToEnglishTen(int x) {
  if (x < 0 || x > 99) {
    return string("");
  }
  string strEng;
  if (x <= 20) {
    strEng += intToEnglishBase(x);
  } else {
    strEng += intToEnglishBase(x/10*10);
    if (x%10 != 0) {
      strEng += ("-" + intToEnglishBase(x%10));
    }
  }
  return strEng;
}

string intToEnglishHun(int x) {
  if (x < 0 || x > 999) {
    return string("");
  }
  string strEng;
  if (x / 100 > 0) {
    strEng += (intToEnglishBase(x / 100) + " hundred");
    if (x % 100 > 0) {
      strEng += " and ";
    }
  }
  if (x % 100 > 0) {
    strEng += intToEnglishTen(x % 100);
  }
  return strEng;
}

string intToEnglish(int x) {
  if (x < 0 || x > 999999) {
    return string("Not Supported");
  }
  string strEng;
  if (x / 1000 != 0) {
    strEng += intToEnglishHun(x / 1000);
    strEng += string(" thousand");
    if (x % 1000 != 0) {
      strEng += ", ";
    }
  }
  if (x % 1000 != 0) {
    strEng += intToEnglishHun(x % 1000);
  }
  return strEng;
}

void test_trans(int x) {
  cout << x << endl;
  cout << intToEnglish(x) << endl;
}

int main() {
  srand(time(0));
  for (int i = 0; i < 100; i++) {
    int x = rand() % 1000000;
    test_trans(x);
  }
}
