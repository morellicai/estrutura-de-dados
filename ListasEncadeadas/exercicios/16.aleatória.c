#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Lista rnd(int n, int m) {
  if (n == 0) {
    return NULL;
  }

  int valor = rand() % m;
  return no(valor, rnd(n - 1, m));
}

int main(void) {
  srand(time(NULL));

  int n = 5, m = 10;
  Lista L = rnd(n, m);

  printf("Lista aleatória com %d itens em [0, %d]: ", n, m);
  exibe2(L);

  destroi(&L);
  return 0;
}
