/*
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
  int sg = ((a - b) >> 31) & 0x1;
  return a * (1 - sg) + b * sg;
}

void test() {
  srand(time(NULL));
  int s, t;
  for (int i = 0; i < 10; i++) {
    s = rand();
    t = rand();
    printf("%d\n%d\nmax %d\n", s, t, max(s, t));
    assert(max(s, t) >= s);
    assert(max(s, t) >= t);
    assert(max(s, t) == s || max(s, t) == t);
  }
}

int main() {
  test();
  return 0;
}
