// Ordenação crescente
// Creie um programa que usa duas ílhas A e B para ordenar uma sequência de
// n números dados pelo usuário. A ideia é organizar a pilha A de modo que
// nenhum item seja empilhado sobre outro menor (use a pilha B apenas para
// manobra) e, depois descarregar e exibir os itens da pilha A.

#include "pilha.h"
#include <stdio.h>

int main(void) {
  int num;
  Pilha A = pilha(10);
  Pilha B = pilha(10);

  printf("Digite 10 numeros aleatorios:\n");
  for (int i = 0; i < 10; i++) {
    scanf("%d", &num);
    empilha(num, A);
  }
  printf("Vamos ordenar...\n");

  while (!vaziap(A)) {
    int item_de_A = desempilha(A);

    while (!vaziap(B) && topo(B) > item_de_A) {
      empilha(desempilha(B), A);
    }
    empilha(item_de_A, B);
  }
  while (!vaziap(B)) {
    empilha(desempilha(B), A);
  }

  printf("Pilha ordenada: ");
  while (!vaziap(A)) {
    printf("%d ", desempilha(A));
  }
  printf("\n");

  destroip(&A);
  destroip(&B);
  return 0;
}
