#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int equals(Lista A, Lista B) {
  if (A == NULL && B == NULL)
    return 1;

  if (A == NULL || B == NULL)
    return 0;

  if (A->item != B->item)
    return 0;

  return equals(A->prox, B->prox);
}

int main(void) {
  // srand(time(NULL));
  Lista L1 = no(1, no(2, no(3, NULL)));
  Lista L2 = no(1, no(2, no(3, NULL)));

  printf("Lista 1: ");
  exibe2(L1);

  printf("\nLista 2: ");
  exibe2(L2);

  if (equals(L1, L2))
    printf("\nAs listas são iguais");
  else
    printf("\nAs listas são diferentes");

  destroi(&L1);
  destroi(&L2);

  return 0;
}
