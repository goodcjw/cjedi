/*
 *  find square root
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

int findRoot(int x) {
  if (x < 0) return -1;
  if (x == 0) return 0;
  if (x == 1) return 1;

  int l = 1;
  int u = x > 65536 ? 65536 : x;
  int g;
  while (l <= u) {
    g = (l + u) / 2;
    if (g * g <= x && (g + 1) * (g + 1) > x)
      return g;
    else if (g * g < x)
      l = g + 1;
    else
      u = g - 1;
  }
  return 1;
}

int main(int argc, char** argv) {
  for (int i = 0; i < 1000000000; i++) {
    int r = findRoot(i);
    int lr = (int) sqrt(i);
    assert(r == lr);
    if (i % 10000 == 0) {
      printf("%d OK\n", i);
    }
  }
  return 0;
}
