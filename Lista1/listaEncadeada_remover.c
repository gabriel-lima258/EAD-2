#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função que remove o elemento imediatamente após o ponteiro 'p'
void remove_depois(celula *le) {
    if (le == NULL || le->prox == NULL) {
        return 0; // Não é possível remover, pois não há próximo
    }
    celula *remover = le->prox;  // Elemento a ser removido
    le->prox = remover->prox;    // Ajusta o ponteiro para pular o nó removido
    free(remover);              // Libera a memória do nó removido
}

// Função que remove todas as ocorrências de 'x' da lista encabeçada por 'le'
void remove_todos_elementos(celula *le, int x) {
    celula *p = le;
    while (p->prox != NULL) {
        if (p->prox->dado == x) { // Encontrou o elemento
            remove_depois(p);     // Remove o próximo elemento
        } else {
            p = p->prox;          // Avança somente se não for o elemento a ser removido
        }
    }
}

void remove_elemento(celula *le, int x) {
    celula *p, *q; // ponteiros
    p = le;
    q = le->prox;
    while (q != NULL && q->dado != x) {
        p = q;
        q = q->prox;
    }
    // achou o elemento
    if (q != NULL) {
      p->prox = q->prox;
      free(q);
    }
}