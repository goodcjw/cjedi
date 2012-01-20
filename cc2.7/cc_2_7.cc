/*
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int missing_int(int* array, int len) {
  int final = 0;
  int test = 0;
  for (int j = 0; j < len; j++) {
    final ^= array[j];
    test ^= (j + 1);
  }
  printf("\n");
  printf("%d\n", final);
  printf("%d\n", test);
  return final ^ test;
}

void test_missing(int len) {
  int* array = (int*) malloc(sizeof(int) * len);
  srand(time(NULL));
  int miss = rand() % (len + 1);
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (j == miss)
      j++;
    array[i] = j++;
  }
  int test = missing_int(array, len);
  printf("test = %d\n", test);
  printf("miss = %d\n", miss);
  free(array);
}

int main() {
  test_missing(50);
  return 0;
}
