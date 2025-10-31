#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char o) 
{
    switch( o ) 
    {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return -1; // operador inválido!
}

char *prefixa(char *e) 
{
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    
    // Inverte a string de entrada
    int len = strlen(e);
    char entrada_invertida[256];
    int k = 0;
    for(int i = len-1; i >= 0; i--) {
        if(e[i] == '(') entrada_invertida[k++] = ')';
        else if(e[i] == ')') entrada_invertida[k++] = '(';
        else entrada_invertida[k++] = e[i];
    }
    entrada_invertida[k] = '\0';
    
    // Processa a string invertida
    for(int i = 0; entrada_invertida[i]; i++) {
        if( entrada_invertida[i]=='(' ) {
            empilha('(', P);
        }
        else if( isdigit(entrada_invertida[i]) ) {
            s[j++] = entrada_invertida[i];
        }
        else if( strchr("+-/*", entrada_invertida[i]) ) {
            while( !vaziap(P) && prio(topo(P)) > prio(entrada_invertida[i]) ) {
                s[j++] = desempilha(P);
            }
            empilha(entrada_invertida[i], P);
        }
        else if( entrada_invertida[i] == ')' ) {
            while( topo(P) != '(' ) {
                s[j++] = desempilha(P);
            }
            desempilha(P); // remove '('
        }
    }
    
    while( !vaziap(P) ) {
        s[j++] = desempilha(P);
    }
    s[j] = '\0';
    
    // Inverte o resultado final
    for(int i = 0; i < j/2; i++) {
        char temp = s[i];
        s[i] = s[j-1-i];
        s[j-1-i] = temp;
    }
    
    destroip(&P);
    return s;
}

char *posfixa(char *e) 
{
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    for(int i=0; e[i]; i++)
        if( e[i]=='(' ) empilha('(',P);
        else if( isdigit(e[i]) ) s[j++] = e[i];
        else if( strchr("+-/*",e[i]) ) 
        {
            while( !vaziap(P) && prio(topo(P))>=prio(e[i]) )
                s[j++] = desempilha(P);
            empilha(e[i],P);
        }
        else if( e[i] == ')' ) 
        {
            while( topo(P)!='(' )
                s[j++] = desempilha(P);
            desempilha(P);
        }
    while( !vaziap(P) )
        s[j++] = desempilha(P);
    s[j] = '\0';
    destroip(&P);
    return s;
}

int valpre(char *e) 
{
    Pilha P = pilha(256);
    int len = strlen(e);
    
    // Processa a expressão prefixa da direita para a esquerda
    for(int i = len-1; i >= 0; i--) {
        if( isdigit(e[i]) ) {
            empilha(e[i]-'0', P);
        }
        else if( strchr("+-/*", e[i]) ) {
            int x = desempilha(P);
            int y = desempilha(P);
            switch( e[i] ) {
                case '+': empilha(x + y, P); break;
                case '-': empilha(x - y, P); break;
                case '*': empilha(x * y, P); break;
                case '/': empilha(x / y, P); break;
            }
        }
        // Ignora espaços
        else if( e[i] == ' ' ) {
            continue;
        }
    }
    int resultado = desempilha(P);
    destroip(&P);
    return resultado;
}

int valor(char *e) 
{
    Pilha P = pilha(256);
    for(int i=0; e[i]; i++)
        if( isdigit(e[i]) ) empilha(e[i]-'0',P);
        else 
        {
            int y = desempilha(P);
            int x = desempilha(P);
            switch( e[i] ) 
            {
                case '+': empilha(x+y,P); break;
                case '-': empilha(x-y,P); break;
                case '*': empilha(x*y,P); break;
                case '/': empilha(x/y,P); break;
            }
        }
    int z = desempilha(P);
    destroip(&P);
    return z;
}

int main(void)
{
    char expressao[513];
    
    printf("Infixa? ");
    fgets(expressao, sizeof(expressao), stdin);
    
    // Remove newline do fgets
    expressao[strcspn(expressao, "\n")] = '\0';
    
    char *e_posfixa = posfixa(expressao);
    char *e_prefixa = prefixa(expressao);
    
    printf("Infixa: %s\n", expressao);
    printf("Prefixa: %s\n", e_prefixa);
    printf("Posfixa: %s\n", e_posfixa);
    printf("Valor numerico (prefixa): %d\n", valpre(e_prefixa));
    printf("Valor numerico (posfixa): %d\n", valor(e_posfixa));
    
    return 0;
}
