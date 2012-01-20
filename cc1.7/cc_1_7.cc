/*
 * number of zeroes in factorial
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int arithmetic_sub(int x, int y) {
  return x + (~y + 1);
}

int arithmetic_mul(int x, int y) {
  if (y == 0) return 0;
  if (y == 1) return x;
  if (y == 2) return x + x;
  int y1 = y >> 1;
  int y2 = arithmetic_sub(y, y1);
  return arithmetic_mul(x, y1) + arithmetic_mul(x, y2);
}

int arithmetic_div(int x, int y) {
  int ret = 0;
  x = arithmetic_sub(x, y);
  while (x >= 0) {
    ret++;
    x = arithmetic_sub(x, y);
  }
  return ret;
}

int main() {
  for (int i = 0; i < 100; i++) {
    int x = rand() % 100;
    int y = rand() % 100;
    printf("%d, %d, %d, %d\n", x, y, x - y, arithmetic_sub(x, y));
    assert(x - y == arithmetic_sub(x, y));
    printf("%d, %d, %d, %d\n", x, y, x * y, arithmetic_mul(x, y));
    assert(x * y == arithmetic_mul(x, y));
    printf("%d, %d, %d, %d\n", x, y, x / y, arithmetic_div(x, y));
    assert(x / y == arithmetic_div(x, y));
  }
  return 0;
}
