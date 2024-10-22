#include <stdio.h>

int main() {
    int N;

    // Lê o tamanho do vetor
    scanf("%d", &N);
    
    int vetor[N];
    long long soma = 0; // Usar long long para evitar overflow
    
    // Lê os elementos do vetor e calcula a soma
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }
    
    // Calcula a média aritmética (como inteiro)
    int media = soma / N;
    
    int encontrou = 0; // Para verificar se encontramos elementos maiores que a média

    // Exibe os elementos maiores que a média
    for (int i = 0; i < N; i++) {
        if (vetor[i] > media) {
            if (encontrou) {
                printf(" "); // Imprime espaço antes de outros elementos, mas não no início
            }
            printf("%d", vetor[i]);
            encontrou = 1; // Marca que encontramos pelo menos um elemento
        }
    }
    
    // Se não encontramos elementos maiores que a média, imprime 0
    if (!encontrou) {
        printf("0");
    }

    printf("\n"); // Nova linha ao final da saída
    return 0;
}
