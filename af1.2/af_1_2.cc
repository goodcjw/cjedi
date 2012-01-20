/*
 *  find square root
 */

#include <assert.h>
#include <stdio.h>

int find(int a[], int len, int k) {
  int lo = 0;
  int up = len - 1;
  int m;
  while (lo <= up) {
    m = lo + (up - lo) / 2;
    if (a[m] == k)
      break;
    else if (a[m] > k)
      up = m - 1;
    else
      lo = m + 1;
  }
  if (lo <= up) {
    /*
    while (m > 0 && a[m-1] == k)
      m--;
    */
    return m;
  }
  return -1;
}

void test() {
  int a_1[] = {1, 2, 3, 4, 5};
  assert(find(a_1, 5, 3) == 2);
  int a_2[] = {1, 2, 3};
  assert(find(a_2, 3, 4) == -1);
  int a_3[] = {1, 1, 2, 2, 3};
  assert(find(a_3, 5, 1) == 0);
  int a_4[] = {};
  assert(find(a_4, 0, 1) == -1);
}

int main(int argc, char** argv) {
  test();
  return 0;
}
