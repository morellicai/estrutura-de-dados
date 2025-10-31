#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int sum(Lista L) {
  if (L == NULL) {
    return 0;
  }
  return L->item + sum(L->prox);
}

int main(void) {
  srand(time(NULL));
  Lista L = aleatoria(5, 10);

  printf("A soma de todos os números da lista é: %d\n", sum(L));
  exibe2(L);

  destroi(&L);
  return 0;
}
