#include <stdio.h>

int main() {
  float dificuldade, maior = -1.0, menor = 11.0;
  float notas[7];

  scanf("%f", &dificuldade);

  float media = 0;

  for (int i = 0; i < 7; i++) {
    scanf("%f", &notas[i]);
    
    if (notas[i] > maior) {
      maior = notas[i];
    }
    if (notas[i] < menor) {
      menor = notas[i];
    }

    media += notas[i];
  }

  media -= maior;
  media -= menor;

  media = (media / 5) * dificuldade;

  printf("%.1f", media);
    
  return 0;
}
