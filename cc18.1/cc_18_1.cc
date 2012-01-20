/*
 *
 */

#include <stdio.h>

void print_array(int* arr, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void inpl_merge(int* arr, size_t s, size_t len_a, size_t len_b) {

  size_t tmp_a = s;
  size_t tmp_b = s + len_a;
  size_t t_offset = s + len_a;
  size_t buf_sz = 0;
  int tmp;

  while (tmp_a < s + len_a || tmp_b < s + len_a + len_b) {
    if (arr[tmp_a] <= arr[tmp_b] && 
        (buf_sz == 0 || arr[tmp_a] <= arr[t_offset])) {
      tmp_a++;
    }
    else if (arr[tmp_b] <= arr[tmp_a] &&
             (buf_sz == 0 || arr[tmp_b] <= arr[t_offset])) {
      tmp = arr[tmp_b];
      arr[tmp_b] = arr[t_offset];
      arr[t_offset] = arr[tmp_a];
      arr[tmp_a] = tmp;
      
    }
  }

}

void test_inpl_merge() {
  int t_arr[10] = {1, 3, 4, 5, 6, 2, 4, 6, 10, 19};
  inpl_merge(t_arr, 0, 5, 5);
  print_array(t_arr, 10);
}

int main(int argc, const char** argv) {
  test_inpl_merge();
  return 0;
}
