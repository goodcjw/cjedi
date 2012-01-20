/*
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEN 10;

int compare_int(const void* a, const void* b) {
  return *((int*) a) - *((int*) b);
}

void print_array(const int* array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void find_pair(const int* array, int len, int target) {
  int* sorted = (int*) malloc(sizeof(int) * len);
  memcpy(sorted, array, sizeof(int) * len);
  qsort(sorted, len, sizeof(int), compare_int);
  print_array(sorted, len);
  int s = 0;
  int e = len - 1;
  while (s < e) {
    if (sorted[s] + sorted[e] == target) {
      printf("%d = %d + %d\n", target, array[s], array[e]);
      s++;
      e--;
    }
    else if (sorted[s] + sorted[e] < target) {
      s++;
    } else {
      e--;
    }
  }
  free(sorted);
}

void test_find_pair_zero(int len) {
  int* array = (int*) malloc(sizeof(int) * len);
  srand(time(NULL));
  for (int i = 0; i < len; i++) {
    array[i] = rand() % 101 - 50;
  }
  find_pair(array, len, 0);
}

int main() {
  //  test_find_pair_zero(10);
  test_find_pair_zero(20);
  //  test_find_pair_zero(30);
}
