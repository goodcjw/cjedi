/*
 *
 */

#include <cassert>
#include <cstring>
#include <bitset>

using namespace std;

int isAllUniqChar(const char* str) {
  bitset<256> charbits;
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++) {
    if (charbits[str[i]])
      return 0;
    charbits.set(str[i]);
  }
  return 1;
}

int main() {
  assert(isAllUniqChar("endl"));
  assert(isAllUniqChar(""));
  assert(!isAllUniqChar("apple"));
  assert(!isAllUniqChar("test"));
  return 0;
}
