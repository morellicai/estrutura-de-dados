#include <stdio.h>
#include <string.h>

int main(void) {
  char s[256];
  char *quebra_linha;

  printf("Senha? ");

  fgets(s, sizeof(s), stdin);

  quebra_linha = strchr(s, '\n');
  if (quebra_linha != NULL) {
    *quebra_linha = '\0';
  }

  if (strcmp(s, "abracadabra") == 0) {
    puts("Ok!");
  } else {
    puts("Senha Invalida!");
  }
  return 0;
}
