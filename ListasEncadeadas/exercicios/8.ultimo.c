#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

Lista ultimo(Lista L) {
  if (L == NULL)
    return NULL;

  while (L->prox != NULL) {
    L = L->prox;
  }

  return L;
}

int main(void) {
  srand(time(NULL));
  Lista A = aleatoria(10, 100);
  Lista final = ultimo(A);

  if (final == NULL) {
    printf("ERROR FATAL");
    return 0;
  }
  printf("O ultimo item da lista é: ");
  exibe(final);
  exibe2(A);
  destroi(&A);
  return 0;
}
