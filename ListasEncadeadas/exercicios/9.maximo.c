#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int maximo(Lista L) {
  int max = L->item;

  if (L == NULL)
    return -1;

  while (L != NULL) {
    if (max < L->item) {
      max = L->item;
    } else {
      L = L->prox;
    }
  }

  return max;
}

int main(void) {
  srand(time(NULL));
  Lista A = aleatoria(10, 100);
  int max = maximo(A);

  if (max == -1) {
    printf("FATAL ERROR");
    return 0;
  }
  exibe2(A);
  printf("\nO maior item na lista é: %d", max);
}
