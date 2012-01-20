/*
 * number of zeroes in factorial
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

bool isTFS(int x) {
  while (x % 3 == 0)
    x /= 3;
  while (x % 5 == 0)
    x /= 5;
  while (x % 7 == 0)
    x /= 7;
  return 1 == x;
}

int findkth(int k) {
  int i = 0;
  int ret = 0;
  while (i < k) {
    if (isTFS(++ret))
      i++;
  }
  return ret;
}

int main() {
  for (int i = 0; i < 100; i++) {
    printf("%d -> %d\n", i, findkth(i));
  }
  return 0;
}
