#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int minimum(Lista L) {
  if (L == NULL)
    return -1;

  if (L->prox == NULL)
    return L->item;

  int minResto = minimum(L->prox);

  return (L->item < minResto) ? L->item : minResto;
}

int main(void) {
  srand(time(NULL));
  Lista L = aleatoria(5, 10);

  printf("Lista: ");
  exibe2(L);

  printf("\nO menor número da lista é: %d\n", minimum(L));

  destroi(&L);
  return 0;
}
