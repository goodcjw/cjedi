/*
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int char_cmp(const void* c1, const void* c2) {
  if (!c1 || !c2)
    return 0;
  if (*(char*) c1 == *(char*) c2)
    return 0;
  else if (*(char*) c1 < *(char*) c2)
    return -1;
  else
    return 1;
}

int isAnagram(const char* str1, const char* str2) {
  int ret = 0;
  if (strlen(str1) != strlen(str2))
      return ret;

  char* stra = strdup(str1);
  char* strb = strdup(str2);

  qsort(stra, strlen(str1), sizeof(char), char_cmp);
  qsort(strb, strlen(str1), sizeof(char), char_cmp);

  size_t len = strlen(str1);
  ret = 1;
  for (size_t i = 0; i < len; i++) {
    if (stra[i] != strb[i]) {
      ret = 0;
      break;
    }
  }

  free(stra);
  free(strb);
  return ret;
}

int main() {
  assert(isAnagram("lib", "bil"));
  assert(isAnagram("test", "ttes"));
  assert(!isAnagram("", "test"));
  assert(!isAnagram("app", "ape"));
  return 0;
}
