/*
 * binary search on matrix
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_element(int** ma, int row, int col, int target, int& irow, int& icol) {
  int i = 0;
  int j = col-1;
  while (i != row && j != 0) {
    if (ma[i][j] == target) {
      irow = i;
      icol = j;
      return 1;
    } else if (ma[i][j] < target) {
      i++;
    } else {
      j--;
    }
  }
  return 0;
}

int** create_young_matrix(int row, int col) {
  srand(time(NULL));
  int** ret_ma = (int**) malloc(sizeof(int*) * row);
  for (int i = 0; i < row; i++) {
    ret_ma[i] = (int*) malloc(sizeof(int) * col);
    for (int j = 0; j < col; j++) {
      ret_ma[i][j] = rand() % 3 + j * 3;
      if (i != 0) {
        ret_ma[i][j] += ret_ma[i-1][j];
      }
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

int main() {
  int** m1 = create_young_matrix(4, 4);
  print_matrix(m1, 4, 4);
  int irow;
  int icol;
  if (find_element(m1, 4, 4, 10, irow, icol)) {
    printf("AT %d %d\n", irow, icol);
  }
  delete_matrix(m1, 4, 4);
  return 0;
}
