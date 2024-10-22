#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
  celula *novo;
  novo = malloc(sizeof(celula));
  novo->dado = x;
  novo->prox = le->prox;
  le->prox = novo;
}

void insere_antes(celula *le, int x, int y) {
  celula *p, *q, *novo;
  novo = malloc(sizeof(celula));
  novo->dado = x;
  p = le; // no atual
  q = le->prox; // proximo no 
  // enquanto o ponteiro nao for ultimo e o valor for diferente de y
  while (q != NULL && q->dado != y) {
    p = q; // p vai receber a posicao de q
    q = q->prox; // q vai avanca uma casa
  }
  novo->prox = q; // novo no recebe q
  p->prox = novo;
}