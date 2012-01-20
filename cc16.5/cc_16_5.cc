/*
 * fibonacci, fib
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* rand_subset(int* arr, int n, int m) {
  int* out = (int*) malloc(sizeof(int) * m);
  for (int i = 0; i < n; i++) {
    if (rand() % (n-i) < m) {
      out[m-1] = arr[i];
      m--;
    }
  }
  return out;
}

int* create_list(int n) {
  int* out = (int*) malloc(sizeof(int) * n);
  if (out == NULL) {
    return NULL;
  }
  for (int i = 0; i < n; i++) {
    out[i] = i;
  }
  return out;
}

void print_list(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

bool test_list(int* arr, int n, int t) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == t) {
      return true;
    }
  }
  return false;
}

void test_sub_1() {
  int* oril = create_list(100);
  int* subl = rand_subset(oril, 100, 5);
  print_list(subl, 5);
  free(oril);
  free(subl);
}

void test_sub_2() {
  int* oril = create_list(100);
  int* subl;
  int test = 100000;
  int hits = 0;
  for (int i = 0; i < test; i++) {
    subl = rand_subset(oril, 100, 5);
    if (test_list(subl, 5, 0)) {
      hits++;
    }
    free(subl);
  }
  printf("test %d\n", test);
  printf("hits %d\n", hits);
  free(oril);
}

int main() {
  srand(time(0));
  test_sub_2();
  return 0;
}
