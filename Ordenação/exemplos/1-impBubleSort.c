#include <stdio.h>

int troca(int v[], int i, int j) {
  int x = v[i];
  v[i] = v[j];
  v[j] = x;
}

void bsort(int v[], int n) {
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      if (v[j] > v[j + 1]) {
        troca(v, j, j + 1);
      }
    }
  }
}

void exibe(int v[], int n) {}

int main(void) {
  int v[10] = {83, 91, 46, 27, 96, 25, 96, 80};
  bsort(v, 10);
  exibe(v, 10);
  return 0;
}
