/*
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char& c1, char& c2) {
  char tmp = c1;
  c1 = c2;
  c2 = tmp;
}

void permh(char* str, size_t pos) {
  if (pos == strlen(str) - 1)
    printf("%s\n", str);
  for (size_t i = pos; i < strlen(str); i++) {
    swap(str[pos], str[i]);
    permh(str, pos + 1);
    swap(str[pos], str[i]);
  }
}

void perm(const char* str) {
  char* tmp = strdup(str);
  permh(tmp, 0);
  free(tmp);
}

int main(int argc, const char** argv) {
  perm("abcd");
  return 0;
}
