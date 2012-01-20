/*
 * number of zeroes in factorial
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int arithmetic_add(int x, int y) {
  if (y == 0)
    return x;

  int xor_sum = x ^ y;
  int carry_sum = (x & y) << 1;

  return arithmetic_add(xor_sum, carry_sum);
}

int main() {
  for (int i = 0; i < 100; i++) {
    int x = rand() % 100;
    int y = rand() % 100;
    assert(x + y == arithmetic_add(x, y));
    printf("%d, %d, %d, %d\n", x, y, x + y, arithmetic_add(x, y));
  }
  return 0;
}
