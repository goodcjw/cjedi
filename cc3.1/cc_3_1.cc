/*
 *
 */

#include <assert.h>
#include <stdio.h>

int bitSwapReqd(int a, int b) {
  int c = a ^ b;
  int cnt = 0;
  for (int i = 0; i < 32; i++) {
    if (c & 0x1) cnt++;
    c = c >> 1;
  }
  return cnt;
}

void test() {
  printf("31, 14, 2\n");
  assert(2 == bitSwapReqd(31, 14));
  printf("30, 31, 1\n");
  assert(1 == bitSwapReqd(30, 31));
  printf("0, 31, 5\n");
  assert(5 == bitSwapReqd(0, 31));
  printf("31, -1, %d\n", bitSwapReqd(1, -1));
  assert(31 == bitSwapReqd(1, -1));
  printf("31, -2, %d\n", bitSwapReqd(2, -2));
  assert(30 == bitSwapReqd(2, -2));
}

int main() {
  test();
  return 0;
}
