/*
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rand5() {
  return rand() % 5;
}

int rand7() {
  int test = 0;
  for (int i = 0; i < 7; i++) {
    test += rand5();
  }
  return test % 7;
}

int rand7b() {
  return rand() % 7;
}


void test_rand(int n, int (*randf) (void)) {
  int* res = (int*) calloc(n, sizeof(int));
  int t;
  for (int i = 0; i < 100000; i++) {
    t = randf();
    res[t]++;
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", res[i]);
  }
  printf("---\n%d\n", 100000 / n);
}

int main(int argc, const char** argv) {
  srand(time(0));
  test_rand(5, rand5);
  printf("\n");
  test_rand(7, rand7);
  printf("\n");
  test_rand(7, rand7b);
  return 0;
}
