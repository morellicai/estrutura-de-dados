#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main(void) {
  char frase[256];
  printf("Digite uma frase \n");
  fgets(frase, sizeof(frase), stdin);
  frase[strcspn(frase, "\n")] = '\0';

  Pilha P = pilha(strlen(frase));

  for (int i = 0; frase[i] != '\0'; i++) {
    if (frase[i] != ' ') {
      empilha((void *)(long)frase[i], P);
    } else {
      while (!vaziap(P))
        printf("%c", (char)(long)desempilha(P));
      printf(" ");
    }
  }
  while (!vaziap(P))
    printf("%c", (char)(long)desempilha(P));

  printf("\n");
  destroip(&P);
  return 0;
}
