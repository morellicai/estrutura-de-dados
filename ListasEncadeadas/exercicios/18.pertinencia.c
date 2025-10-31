#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int in(int x, Lista L) {
  if (L == NULL)
    return 0;

  if (x == L->item) {
    return 1;
  }
  return in(x, L->prox);
}

int main(void) {
  srand(time(NULL));
  Lista A = aleatoria(10, 20);
  int num;

  printf("Qual o número? ");
  scanf("%d", &num);

  int pert = in(num, A);

  exibe2(A);
  if (pert == 1) {
    printf("\nNúmero %d pertence à lista.", num);
    return 0;
  }
  printf("\nNúmero %d não pertence a lista", num);
  return 0;
}
