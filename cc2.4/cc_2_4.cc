/*
 * rotate matrix 
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
      ret_ma[i][j] = rand() % 10;
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
      printf("%d ", ma[i][j]);
    }
    printf("\n");
  }
}

void rotate_matrix(int** ma, int row, int col) {
  if (row != col)
    return;
  int n = row;
  for (int i = 0; i < n/2; i++) {
    for (int j = 0; j < n - 1 - 2*i; j++) {
      int k = i + j;
      int tmp = ma[i][k];
      ma[i][k] = ma[n-1-k][i];
      ma[n-1-k][i] = ma[n-1-i][n-1-k];
      ma[n-1-i][n-1-k] = ma[k][n-1-i];
      ma[k][n-1-i] = tmp;
    }
  }
}

int main() {
  int** m1 = create_rand_matrix(4, 4);
  print_matrix(m1, 4, 4);
  rotate_matrix(m1, 4, 4);
  printf("\n");
  print_matrix(m1, 4, 4);
  delete_matrix(m1, 4, 4);

  m1 = create_rand_matrix(10, 10);
  print_matrix(m1, 10, 10);
  rotate_matrix(m1, 10, 10);
  printf("\n");
  print_matrix(m1, 10, 10);
  delete_matrix(m1, 10, 10);

  return 0;
}
