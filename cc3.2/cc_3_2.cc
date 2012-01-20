/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swapEvenOddBit(int x) {
  int bitOdd = x & 0x55555555;
  return ((x >> 1) & 0x55555555) | (bitOdd << 1);
}

void test() {
  srand(time(NULL));
  int s;
  for (int i = 0; i < 10; i++) {
    s = rand();
    printf("%8X, %8X\n", s, swapEvenOddBit(s));
  }
}

int main() {
  test();
  return 0;
}
