/*
 * fibonacci, fib
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* shuffle_list(int n) {
  int randp;
  int* base = (int*) malloc(sizeof(int) * n);
  if (base == NULL) {
    return NULL;
  }
  int* out = (int*) malloc(sizeof(int) * n);
  if (out == NULL) {
    free(base);
    return NULL;
  }
  for (int i = 0; i < n; i++) {
    base[i] = i;
  }
  for (int i = 0; i < n; i++) {
    randp = rand() % (n-i);
    out[i] = base[randp];
    base[randp] = base[n-i-1];
  }
  return out;
}

void print_list(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

bool test_list(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] != i) {
      return false;
    }
  }
  return true;
}

void test_shuffle() {
  int base = 66666;
  int hit = 0;
  for (int i = 0; i < base; i++) {
    int* ll = shuffle_list(3);
    print_list(ll, 3);
    if (test_list(ll, 3)) {
      hit++;
    }
    free(ll);
  }
  printf("%d\n", base);
  printf("%d\n", hit);
}

int main() {
  srand(time(0));
  test_shuffle();
  return 0;
}
