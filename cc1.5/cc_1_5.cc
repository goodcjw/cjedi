/*
 * number of zeroes in factorial
 */

#include <stdio.h>

int factnzero(int x) {
  int nzero = 0;
  int nfive = 0;
  for (int i = 1; i <= x; i++) {
    int j = i;
    while (j % 10 == 0) {
      nzero++;
      j /= 10;
    }
    while (j % 10 == 5) {
      nfive++;
      j /= 5;
    }
  }
  return nzero + nfive;
}

int factnzero2(int x) {
  int count = 0;
  for (int i = 5; x / i > 0; i *= 5) {
    count += x / i;
  }
  return count;
}

int main() {
  for (int i = 0; i < 100; i++) {
    printf("factnzero %d\t%d\n", i, factnzero(i));
    printf("factnzero %d\t%d\n", i, factnzero2(i));
  }
  return 0;
}
