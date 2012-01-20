/*
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 100

int comint(const void* a, const void* b) {
  return (*(int*) b) - (*(int*) a);
}

int findKth(int* array, int len, int k) {
  assert(k <= len);
  int p = rand() % len;
  int pivot = array[p];
  int tmp = array[0];
  array[0] = pivot;
  array[p] = tmp;
  int i = 1;
  int j = len - 1;

  if (len == 1) {
    assert(k == 1);
    return array[0];
  }

  while (i <= j) {
    while (array[i] >= pivot && i < len)
      i++;
    while (array[j] < pivot && j > 0)
      j--;
    if (i < j) {
      tmp = array[i];
      array[i++] = array[j];
      array[j--] = tmp;
    }
  }

  tmp = array[i-1];
  array[i-1] = array[0];
  assert(array[0] == pivot);
  array[0] = tmp;

  assert(i != j);
  if (i == k) {
    return pivot;
  } else if (k > i) {
    return findKth(array+i, len-i, k-i);
  } else {
    return findKth(array, i-1, k);
  }
}

int main(int argc, const char** argv) {
  int array[N];
  srand(time(NULL));
  for (int time = 0; time < 100; time++) {
    for (int i = 0; i < N; i++) {
      array[i] = rand() % 100;
    }
    int k1 = findKth(array, N, N/10);
    qsort(array, N, sizeof(int), comint);
    int k2 = array[N/10-1];
    printf("k1: %d, k2: %d\n", k1, k2);
    assert(k1 == k2);
  }
  return 0;
}
