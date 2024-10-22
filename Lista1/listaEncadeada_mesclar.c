#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
  celula *p1 = l1->prox; // ponteiro para primeira lista
  celula *p2 = l2->prox;
  celula *p3 = l3;

  // enquanto houver elementos na l1 e l2
  // ordenando em ordem crescente
  while (p1 != NULL && p2 != NULL) {
    if (p1->dado <= p2->dado) {
      p3->prox = p1; // aponta o menor elemento
      p1 = p1->prox;
    } else {
      p3->prox = p2; // aponta o menor elemento
      p2 = p2->prox;
    }
    p3 = p3->prox; // avanca a lista
  }
  // Se ainda restarem elementos na lista l1, adiciona-os
  if (p1 != NULL) {
    p3->prox = p1;
  }

  if (p2 != NULL) {
    p3->prox = p2;
  }
}