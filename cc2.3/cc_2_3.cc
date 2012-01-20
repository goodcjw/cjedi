/*
 * remove duplicate characters in a string
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max_subseq(int* array, int len) {

  int max = 0;
  int cur_max = 0;

  for (int i = 0; i < len; i++) {
    if (cur_max + array[i] > 0) {
      cur_max += array[i];
    }
    else {
      cur_max = 0;
    }
    if (cur_max > max) {
      max = cur_max;
    }
  }

  return max;
}

int main() {
  int array[10];
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    array[i] = rand() % 21 - 10;
    printf("%d ", array[i]);
  }
  printf("\n");
  printf("max len = %d\n", max_subseq(array, 10));
}
