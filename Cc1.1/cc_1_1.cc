/*
 * fibonacci, fib
 */

#include <stdio.h>

int fibonacci(int x) {
  if (x < 0)
    return -1;
  if (x == 0)
    return 0;
  if (x < 3)
    return 1;
  int prev = 1;
  int fib = 1;
  for (int i = 2; i < x; i++) {
    fib += prev;
    prev = fib - prev;
  }
  return fib;
}

int main() {
  for (int i = 0; i < 10; i++) {
    printf("fib %d\t%d\n", i, fibonacci(i));
  }
  return 0;
}
