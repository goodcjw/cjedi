/*
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

bool isValid(int* board, int col, int row) {
  for (int i = 0; i < col; i++) {
    if (row == board[i])
      return false;
    if (row == board[i] + col - i)
      return false;
    if (row == board[i] - col + i)
      return false;
  }
  return true;
}

void printBoard(const int *board) {
  for (int i = 0; i < 8; i++) {
    printf("%d ", board[i]);
  }
  printf("\n");
}

void placeQueen(int* board, int col) {
  if (col == 8) {
    printBoard(board);
  } else {
    for (int i = 0; i < 8; i++) {
      if (isValid(board, col, i)) {
        board[col] = i;
        placeQueen(board, col + 1);
      }
    }
  }
}

int main(int argc, const char** argv) {
  int board[8];
  placeQueen(board, 0);
  return 0;
}
