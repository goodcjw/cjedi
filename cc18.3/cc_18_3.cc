/*
 *
 */
#include <assert.h>
#include <stdio.h>
#include <string.h>

ssize_t rotated_bsearch(const int* arr, size_t s, size_t e, int t) {
  if (s > e)
    return -1;
  size_t m = s + (e - s) / 2;
  if (arr[m] == t) {
    return m;
  }
  if (arr[m] >= arr[s]) {
    if (t < arr[m] && t >= arr[s]) {
      return rotated_bsearch(arr, s, m - 1, t);
    } else {
      return rotated_bsearch(arr, m + 1, e, t);
    }
  } else {
    if (t > arr[m] && t <= arr[e]) {
      return rotated_bsearch(arr, m + 1, e, t);
    } else {
      return rotated_bsearch(arr, s, m - 1, t);
    }
  }
}

ssize_t rotated_bsearch(const int* arr, size_t len, int t) {
  if (len == 0)
    return -1;
  return rotated_bsearch(arr, 0, len-1, t);
}

void rotate_one(int* arr, size_t len) {
  int tmp = arr[0];
  for (size_t i = 1; i < len; i++) {
    arr[i-1] = arr[i];
  }
  arr[len-1] = tmp;
}

void print_array(int* arr, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void print_point(size_t len, size_t pos) {
  for (size_t i = 0; i < len; i++) {
    if (pos == i)
      printf("^ ");
    else
      printf("  ");
  }
  printf("\n");
}

int main(int argc, const char** argv) {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 10; i++) {
    assert(rotated_bsearch(arr, 10, 10) == -1);
    assert(rotated_bsearch(arr, 10, 5) == (15 - i) % 10);
    print_array(arr, 10);
    print_point(10, rotated_bsearch(arr, 10, 5));
    rotate_one(arr, 10);
  }
  return 0;
}
