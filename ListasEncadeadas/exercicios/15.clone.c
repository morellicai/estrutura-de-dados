#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

Lista clone(Lista L) {
  if (L == NULL)
    return NULL;

  return no(L->item, clone(L->prox));
}

int main(void) {
  srand(time(NULL));
  Lista L = aleatoria(5, 10);

  printf("A lista L = ");
  exibe2(L);
  printf("\no Clone da Lista L = ");
  Lista C = clone(L);
  exibe2(C);

  destroi(&L);
  destroi(&C);
  return 0;
}
