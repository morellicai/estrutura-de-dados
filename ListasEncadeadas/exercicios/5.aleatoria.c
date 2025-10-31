#include "listaEncadeada.h"
#include <stdlib.h>
#include <time.h>

Lista aleatoria(int n, int m) {
  Lista L = NULL;
  while (n > 0) {
    L = no(rand() % m, L);
    n--;
  }
  return L;
}

int main(void) {
  srand(time(NULL));
  Lista A = aleatoria(10, 100);
  exibe2(A);
  return 0;
}
