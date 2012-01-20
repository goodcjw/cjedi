/*
 *
 */

#include <stdlib.h>
#include <stdio.h>

void** my2DAlloc(size_t row, size_t col, size_t size) {
  void** head = (void**) malloc(sizeof(void*) * row);
  if (head == NULL)
    return NULL;
  void* base = malloc(size * col * row);
  if (base == NULL) {
    free(head);
    return NULL;
  }
  size_t i;
  for (i = 0; i < row; i++) {
    head[i] = (char*) base + size * col * i;
  }
  return head;
}

void my2DFree(void* head) {
  void* base;
  if (head != NULL) {
    base = *((void**)head);
    if (base != NULL) {
      printf("free base\n");
      free(base);
    }
    free(head);
    printf("free head\n");
  }
}

int main(int argc, const char** argv) {
  const int ROW = 10;
  const int COL = 20;

  int** int_matrix = (int**) my2DAlloc(ROW, COL, sizeof(int));
  int i, j;
  int k = 0;

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      int_matrix[i][j] = (k++) % 10;
    }
  }

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      printf("%d ", int_matrix[i][j]);
    }
    printf("\n");
  }
  
  my2DFree(int_matrix);
  return 0;
}
