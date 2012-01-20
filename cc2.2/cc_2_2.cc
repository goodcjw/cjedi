/*
 * remove duplicate characters in a string
 */

#include <stdio.h>
#include <string.h>

void removeDup(char* str) {
  if (!str)
    return;

  size_t cur = 0;
  size_t end = 0;
  for (; cur < strlen(str); cur++) {
    size_t i;
    for (i = 0; i < end; i++) {
      if (*(str + i) == *(str + cur)) {
        break;
      }
    }
    if (i == end) {
      // no dup, a new character
      *(str + end++) = *(str + cur);
    }
  }
  *(str + end) = '\0';
}

int main() {
  char str_1[] = "";
  char str_2[] = "nodup";
  char str_3[] = "dupdup";
  char str_4[] = "ddaddbd";
  removeDup(str_1);
  removeDup(str_2);
  removeDup(str_3);
  removeDup(str_4);
  printf("%s\n", str_1);
  printf("%s\n", str_2);
  printf("%s\n", str_3);
  printf("%s\n", str_4);
  return 0;
}
