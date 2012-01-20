/*
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define R 0
#define Y 1
#define G 2
#define B 3

int master_mind_test(const int* g, const int* k, int& hit, int& phit) {
  if (g == NULL && k == NULL) return -1;
  int* g_color = (int*) calloc(4, sizeof(int));
  int* k_color = (int*) calloc(4, sizeof(int));
  hit = 0;
  phit = 0;
  for (int i = 0; i < 4; i++) {
    if (g[i] == k[i]) {
      hit++;
    } else {
      g_color[g[i]]++;
      k_color[k[i]]++;
    }
  }
  for (int i = 0; i < 4; i++) {
    phit += ((g_color[i] < k_color[i]) ? g_color[i] : k_color[i]);
  }
  return 0;
}

void test() {
  int hit, phit;
  int key[] = {Y, G, G, R};
  int gu1[] = {Y, G, G, R};
  master_mind_test(key, gu1, hit, phit);
  assert(hit == 4 && phit == 0);
  int gu2[] = {B, B, B, B};
  master_mind_test(key, gu2, hit, phit);
  assert(hit == 0 && phit == 0);
  int gu3[] = {G, R, Y, G};
  master_mind_test(key, gu3, hit, phit);
  assert(hit == 0 && phit == 4);
  int gu4[] = {Y, R, B, B};
  master_mind_test(key, gu4, hit, phit);
  assert(hit == 1 && phit == 1);
  int gu5[] = {G, G, B, B};
  master_mind_test(key, gu5, hit, phit);
  assert(hit == 1 && phit == 1);

}

int main(int argc, const char** argv) {
  test();
  return 0;
}
