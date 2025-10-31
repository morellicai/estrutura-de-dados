#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int count(int x, Lista L) {
  if (L == NULL)
    return 0;

  if (x == L->item) {
    return 1 + count(x, L->prox);
  }

  return count(x, L->prox);
}

int main() {
  srand(time(NULL));
  Lista L = aleatoria(20, 10);

  int num;

  printf("Qual o número quer procurar? ");
  scanf("%d", &num);

  int conta = count(num, L);

  printf("A quantidade que o item %d aparece na lista é: %d.\nLista: ", num,
         conta);
  exibe2(L);

  destroi(&L);
  return 0;
}
