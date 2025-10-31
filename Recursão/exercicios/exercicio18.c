#include <ctype.h>
#include <stdio.h>
#include <string.h>

int pal(char s[], int p, int u) {
  while (p < u && s[p] == ' ')
    p++;
  while (u > p && s[u] == ' ')
    u--;

  if (p >= u)
    return 1;

  if (tolower(s[p]) != tolower(s[u]))
    return 0;

  return pal(s, p + 1, u - 1);
}

int main() {
  char s[100];
  printf("Digite uma frase: ");
  fgets(s, sizeof(s), stdin);

  int tamanho = strlen(s);
  if (s[tamanho - 1] == '\n')
    s[tamanho - 1] = '\0';

  if (pal(s, 0, strlen(s) - 1))
    printf("É palíndromo!\n");
  else
    printf("Não é palíndromo.\n");

  return 0;
}
