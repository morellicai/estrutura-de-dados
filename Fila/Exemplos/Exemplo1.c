#include "fila.h"
#include "pilha.h"
#include <ctype.h>
#include <stdio.h>

int main(void) {
  char s[256];
  Fila F = fila(256);
  Pilha P = pilha(256);
  printf("Digite uma expressao: ");
  fgets(s, 256, stdin);
  for (int i = 0; s[i]; i++) {
    if (isalpha(s[i])) {
      enfileira(s[i], F);
      empilha(s[i], P);
    }
  }
  while (!vaziaf(F) && desenfileira(F) == desempilha(P))
    ;
  if (vaziaf(F))
    puts("A frase é palindroma");
  else
    puts("A frase não é palindroma");
  destroif(&F);
  destroip(&P);
  return 0;
}
