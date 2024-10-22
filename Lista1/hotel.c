#include <stdio.h>

int main() {
    int D, A, N;

    // Leitura dos valores de D (valor inicial da diária), A (aumento diário) e N (dia de chegada)
    scanf("%d", &D);
    scanf("%d", &A);
    scanf("%d", &N);
    
    // Calcula o valor da diária no dia N
    int diaria = D + (N - 1) * A;
    
    // Calcula o número de diárias
    int num_dias = 31 - N + 1;
    
    // Calcula o total a ser pago
    int total = num_dias * diaria;
    
    // Imprime o valor total a ser pago
    printf("%d\n", total);
    
    return 0;
}
