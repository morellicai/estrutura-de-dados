#include "pilha.h"
#include <stdio.h>
int main(void) {
  int num;
  Pilha A = pilha(10);
  Pilha B = pilha(10);
  printf("Digite 10 numeros aleatorios:\n");
  for (int i = 0; i < 10; i++) {
    if (scanf("%d", &num) != 1) {
      printf("Erro de leitura.\n");
      break;
    }
    empilha(num, A);
  }
  printf("Vamos ordenar inversamente e garantir a unicidade...\n");
  while (!vaziap(A)) {
    int item_de_A = desempilha(A);

    while (!vaziap(B) && topo(B) < item_de_A) {
      empilha(desempilha(B), A);
    }
    empilha(item_de_A, B);
  }
  printf("Pilha ordenada inversamente (decrescente) e sem repetidos: \n");
  while (!vaziap(B)) {
    int elemento_final = desempilha(B);
    empilha(elemento_final, A);
  }
  printf("\n");
  while (!vaziap(A)) {
    int eEquals = desempilha(A);
    if (!vaziap(A) && eEquals == topo(A)) {
      continue;
    }
    printf("%d ", eEquals);
  }
  destroip(&A);
  destroip(&B);
  return 0;
}
