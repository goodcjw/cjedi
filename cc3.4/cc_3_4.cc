/*
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* convertFloatBin(const char* input) {
  return NULL;
}

void convertTest(float x) {
  for (int i = 0; i < 32 && x != 0; i++) {
    if (x * 2 > 1) {
      x = x * 2 - 1;
      printf("1");
    } else {
      x = x * 2;
      printf("0");
    }
  }
  printf("\n");
}

void test() {
  srand(time(NULL));
  float s;
  for (int i = 0; i < 10; i++) {
    s = ((float) (rand() % 1000)) / 1000;
    printf("%f\t", s);
    convertTest(s);
  }
  convertTest(0.2);
}

int main() {
  test();
  return 0;
}
