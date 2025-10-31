#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

void replace(int x, int y, Lista L) {
  if (L == NULL)
    return;

  if (L->item == x) {
    L->item = y;
  }

  return replace(x, y, L->prox);
}

int main() {
  srand(time(NULL));
  Lista L = aleatoria(15, 8);

  exibe2(L);

  int num1, num2;

  printf("\nQual o número quer alterar? ");
  scanf("%d", &num1);
  printf("Qual o número quer colocar no lugar? ");
  scanf("%d", &num2);

  printf("Nova lista: ");
  replace(num1, num2, L);
  exibe2(L);

  destroi(&L);
  return 0;
}
