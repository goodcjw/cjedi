/*
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int isRotated(const char* str1, const char* str2) {
  if (str1 == NULL && str2 == NULL) {
    return 0;
  }
  if (str2 == NULL) {
    return 1;
  }
  char* tmpstr = (char*) malloc(strlen(str1) * 2 - 1);
  strncpy(tmpstr, str1, strlen(str1));
  strncpy(tmpstr + strlen(str1), str1);
  char* find = strstr(tmpstr, str2);
  if (find == NULL) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  assert(isRotated("keli", "lik") == 1);
  assert(isRotated("test", "set") == 0);
  assert(isRotated("stbe", "best") == 1);
  return 0;
}
