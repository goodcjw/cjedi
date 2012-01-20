/*
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* formatAsUrl(const char* str) {
  size_t str_len = strlen(str);
  size_t i;
  size_t j = 0;
  int ws_cnt = 0;
  // count number of whitespaces
  for (i = 0; i < str_len; i++) {
    if (str[i] == ' ')
      ws_cnt++;
  }
  size_t new_len = str_len + 2 * ws_cnt;
  char* new_str = (char*) malloc(new_len + 1);
  for (i = 0; i < str_len; i++) {
    if (str[i] == ' ') {
      new_str[j++] = '%';
      new_str[j++] = '2';
      new_str[j++] = '0';
    }
    else {
      new_str[j++] = str[i];
    }
  }
  assert(j == new_len);
  new_str[j] = '\0';
  return new_str;
}

int main() {
  const char s1[] = "test this";
  const char s2[] = "given two words of equal length that are in a dictionary";
  char* s1_new = formatAsUrl(s1);
  char* s2_new = formatAsUrl(s2);
  printf("%s\n%s\n", s1, s1_new);
  printf("%s\n%s\n", s2, s2_new);
  free(s1_new);
  free(s2_new);
}
