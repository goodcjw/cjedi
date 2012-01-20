/*
 *
 */

#include <assert.h>
#include <set>
#include <string>
#include <iostream>

using namespace std;

#define WHITE 'W'
#define BLACK 'B'
#define BLANK '0'

class TicTacToe {
 private:
  set<string> white_win;
  set<string> black_win;
  void generate(string cur, int i);
  char checkwin(const char* board);
 public:
  TicTacToe();
  char whowin(const char* board);
};

TicTacToe::TicTacToe() {
  generate("", 9);
}

char TicTacToe::whowin(const char* board) {
  string tmp(board);
  if (white_win.find(tmp) != white_win.end())
    return WHITE;
  if (black_win.find(tmp) != black_win.end())
    return BLACK;
  return BLANK;
}

void TicTacToe::generate(string cur, int i) {
  if (i == 0) {
    char w = checkwin(cur.c_str());
    if (w == WHITE)
      white_win.insert(cur);
    if (w == BLACK)
      black_win.insert(cur);
    return;
  }
  generate(cur + WHITE, i - 1);
  generate(cur + BLACK, i - 1);
  generate(cur + BLANK, i - 1);
}

char TicTacToe::checkwin(const char* board) {
  int white_win = 0;
  int black_win = 0;

  // row
  for (int i = 0; i < 3; i++) {
    if (board[i*3] == board[i*3+1] &&
        board[i*3+1] == board[i*3+2]) {
      if (board[i*3] == WHITE) white_win = 1;
      if (board[i*3] == BLACK) black_win = 1;
    }
  }

  // col
  for (int i = 0; i < 3; i++) {
    if (board[i] == board[3+i] &&
        board[3+i] == board[6+i]) {
      if (board[i] == WHITE) white_win = 1;
      if (board[i] == BLACK) black_win = 1;
    }
  }

  // cross
  if (board[0] == board[4] && board[4] == board[8]) {
    if (board[0] == WHITE) white_win = 1;
    if (board[0] == BLACK) black_win = 1;
  }

  // cross
  if (board[2] == board[4] && board[4] == board[6]) {
    if (board[2] == WHITE) white_win = 1;
    if (board[2] == BLACK) black_win = 1;
  }

  if (white_win > black_win) return WHITE;
  if (white_win < black_win) return BLACK;
  return BLANK;
}

int main(int argc, const char** argv) {
  char t1[] = { WHITE, WHITE, WHITE, \
                BLACK, WHITE, BLANK, \
                BLACK, BLACK, BLANK, \
                '\0'};

  char t2[] = { BLACK, WHITE, WHITE, \
                BLACK, WHITE, BLANK, \
                BLACK, BLACK, BLANK, \
                '\0'};

  char t3[] = { BLANK, WHITE, WHITE, \
                BLANK, WHITE, BLANK, \
                BLANK, BLACK, BLANK, \
                '\0'};

  TicTacToe t;
  assert(t.whowin(t1) == WHITE);
  assert(t.whowin(t2) == BLACK);
  assert(t.whowin(t3) == BLANK);
  return 0;
}
