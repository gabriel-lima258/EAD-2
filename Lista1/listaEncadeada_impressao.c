#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura 'celula'
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função iterativa para imprimir a lista encadeada
void imprime(celula *le) {
    celula *p = le->prox; // Começa do primeiro elemento após o nó cabeça
    if (p == NULL) {
        printf("NULL\n");
    } else {
        while (p != NULL) {
            printf("%d", p->dado);
            if (p->prox != NULL) {
                printf(" -> ");
            }
            p = p->prox;
        }
        printf(" -> NULL\n");
    }
}

// Função recursiva para imprimir a lista encadeada
void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    
    // Imprime o dado do nó atual
    printf("%d", le->prox->dado);
    
    // Se ainda houver próximo nó, imprime o separador " -> "
    if (le->prox->prox != NULL) {
      printf(" -> "); 
      imprime_rec(le->prox);  
    } else {
      printf(" -> NULL");   
    }
}
