#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int last(Lista L) {
  if (L == NULL)
    return -1;

  if (L->prox == NULL) {
    int ultimo = L->item;
    return ultimo;
  }

  return last(L->prox);
}

int main(void) {
  srand(time(NULL));

  Lista L = aleatoria(5, 10);
  printf("O ultimo item é: %d\n", last(L));
  exibe2(L);

  destroi(&L);
  return 0;
}
