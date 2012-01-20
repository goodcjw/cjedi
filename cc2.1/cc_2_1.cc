/*
 * set matrix to zero
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 5

void printMatrix(int ma[M][N]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", ma[i][j]);
    }
    printf("\n");
  }
}

void setZero(int ma[M][N]) {
  int row[M];
  int col[N];
  for (int i = 0; i < M; i++) {
    row[i] = 0;
  }
  for (int j = 0; j < N; j++) {
    col[j] = 0;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (ma[i][j] == 0) {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (row[i] == 1 || col[j] == 1) {
        ma[i][j] = 0;
      }
    }
  }
  printMatrix(ma);
}

int main() {
  srand(time(NULL));
  /* create a random matrix */
  int ma[M][N];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      ma[i][j] = rand() % 10;
    }
  }
  printMatrix(ma);
  setZero(ma);
  return 0;
}
