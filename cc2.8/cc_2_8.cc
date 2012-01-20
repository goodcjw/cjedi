/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create_rand_matrix(int row, int col) {
  srand(time(NULL));
  int** ret_ma = (int**) malloc(sizeof(int*) * row);
  for (int i = 0; i < row; i++) {
    ret_ma[i] = (int*) malloc(sizeof(int) * col);
    for (int j = 0; j < col; j++) {
      ret_ma[i][j] = rand() % 21 - 10;
    }
  }
  return ret_ma;
}

void delete_matrix(int** ma, int row, int col) {
  if (ma == NULL)
    return;
  for (int i = 0; i < row; i++) {
    if (ma[i] == NULL)
      return;
    free(ma[i]);
  }
  free(ma);
}

void print_matrix(int** ma, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d\t", ma[i][j]);
    }
    printf("\n");
  }
}

int** create_sum_matrix(int** ma, int row, int col) {
  int** mb = (int**) malloc(sizeof(int*) * row);
  for (int i = 0; i < row; i++) {
    mb[i] = (int*) malloc(sizeof(int) * col);
  }
  mb[0][0] = ma[0][0];
  /* initialize head row */
  for (int j = 1; j < col; j++) {
    mb[0][j] = ma[0][j] + mb[0][j-1];
  }
  /* initialize head col */
  for (int i = 1; i < row; i++) {
    mb[i][0] = ma[i][0] + mb[i-1][0];
  }
  /* initialize the reset */
  for (int i = 1; i < row; i++) {
    for (int j = 1; j < col; j++) {
      mb[i][j] = ma[i][j] + mb[i-1][j] + mb[i][j-1] - mb[i-1][j-1];
    }
  }
  return mb;
}

int max_sub_sum(int** ma, int row, int col) {
  int max_sum = 0;
  int tmp_sum = 0;
  int** m_sum = create_sum_matrix(ma, row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      tmp_sum = m_sum[i][j];
      if (tmp_sum > max_sum)
        max_sum = tmp_sum;
      /* full row */
      for (int l = 0; l < i; l++) {
        tmp_sum = m_sum[i][j] - m_sum[l][j];
        if (tmp_sum > max_sum)
          max_sum = tmp_sum;
      }
      /* full col */
      for (int k = 0; k < j; k++) {
        tmp_sum = m_sum[i][j] - m_sum[i][k];
        if (tmp_sum > max_sum)
          max_sum = tmp_sum;
      }
      /* the rest */
      for (int k = 0; k < i; k++) {
        for (int l = 0; l < j; l++) {
          tmp_sum = m_sum[i][j] - m_sum[l][j]
              - m_sum[i][k] + m_sum[l][k];
          if (tmp_sum > max_sum)
            max_sum = tmp_sum;
        }
      }
    }
  }
  delete_matrix(m_sum, row, col);
  return max_sum;
}

void test_square(int len) {
  int** m1 = create_rand_matrix(len, len);
  print_matrix(m1, len, len);
  int** m1s = create_sum_matrix(m1, len, len);
  printf("\n");
  print_matrix(m1s, len, len);
  int sum = max_sub_sum(m1, len, len);
  printf("max sum = %d\n", sum);
  delete_matrix(m1s, len, len);
  delete_matrix(m1, len, len);
}

int main() {
  test_square(3);
  return 0;
}
