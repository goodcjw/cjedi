/*
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_STR 10

int compare_char(const void* char_a, const void* char_b) {
  if (*(const char*) char_a > *(const char*) char_b)
    return 1;
  else if (*(const char*) char_a < *(const char*) char_b)
    return -1;
  else
    return 0;
}

int compare_anagram(const void* str_a, const void* str_b) {
  char* anag_a = strdup(*((const char**) str_a));
  char* anag_b = strdup(*((const char**) str_b));
  if (strlen(anag_a) > strlen(anag_b)) {
    return 1;
  } if (strlen(anag_a) < strlen(anag_b)) {
    return -1;
  } else {
    qsort(anag_a, strlen(anag_a), sizeof(char), compare_char);
    qsort(anag_b, strlen(anag_b), sizeof(char), compare_char);
    for (size_t i = 0; i < strlen(anag_a); i++) {
      if (anag_a[i] > anag_b[i])
        return 1;
      if (anag_a[i] < anag_b[i])
        return -1;
    }
    return 0;
  }
}

int main(int argc, const char** argv) {
  char** str_arr = (char**) malloc(sizeof(char*) * NUM_STR);
  str_arr[0] = strdup("as");
  str_arr[1] = strdup("ack");
  str_arr[2] = strdup("asck");
  str_arr[3] = strdup("test");
  str_arr[4] = strdup("sack");
  str_arr[5] = strdup("set");
  str_arr[6] = strdup("sa");
  str_arr[7] = strdup("at");
  str_arr[8] = strdup("apple");
  str_arr[9] = strdup("b");
  qsort(str_arr, NUM_STR, sizeof(char*), compare_anagram);
  for (int i = 0; i < NUM_STR; i++) {
    printf("%s\n", str_arr[i]);
  }
  return 0;
}
