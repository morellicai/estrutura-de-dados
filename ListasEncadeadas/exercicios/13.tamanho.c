#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int len(Lista L) {
  if (L == NULL) {
    return 0;
  }

  return 1 + len(L->prox);
}

int main(void) {
  srand(time(NULL));
  Lista L = aleatoria(10, 100);

  printf("O tamanho da lista é: %d\n", len(L));
  exibe2(L);

  destroi(&L);
  return 0;
}
