/*
 *
 */

#include <stdio.h>
#include <string.h>

void reverse_str(char* str, size_t s, size_t e) {
  char tmp;
  while (s < e) {
    tmp = str[s];
    str[s++] = str[e];
    str[e--] = tmp;
  }
}

void reverse_word(char* str) {
  size_t e = strlen(str) - 1;
  reverse_str(str, 0, e);
}

void reverse_sentence(char* str) {
  size_t len = strlen(str);
  size_t s = 0;
  size_t e = 0;
  for (e = 0; e < len; e++) {
    if (str[e] == ' ') {
      reverse_str(str, s, e - 1);
      s = e + 1;
    }
  }
  reverse_str(str, s, e - 1);
  reverse_str(str, 0, len - 1);
}

int main() {
  char* s1 = strdup("test");
  char* s2 = strdup("apple");
  char* s3 = strdup("this is test");
  //  reverse_word(s1);
  printf("%s\n", s1);
  //  reverse_word(s2);
  printf("%s\n", s2);
  reverse_sentence(s3);
  printf("%s\n", s3);
}

