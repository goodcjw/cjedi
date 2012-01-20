/*
 *
 */

#include <bitset>
#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

#define N 32000

using namespace std;

int main(int argc, const char** argv) {
  int arr[N];
  bitset<N> b32;
  srand(time(0));
  b32.reset();

  for (int i = 0; i < N; i++) {
    arr[i] = rand() % N;
    b32.set(arr[i]);
  }

  int non_exist = -1;
  for (int i = 0; i < N; i++) {
    if (b32[i] == 0) {
      non_exist = i;
      break;
    }
  }

  cout << sizeof(bitset<N>) << endl;
  cout << "non_exist: " << non_exist << endl;

  for (int i = 0; i < N; i++) {
    assert(arr[i] != non_exist);
  }
  
  return 0;
}
