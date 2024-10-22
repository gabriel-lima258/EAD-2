#include <stdio.h>

// Função para resolver o sistema de equações e determinar as caixas
void calcularCaixas(int a, int b, int c) {
    // Declaração das variáveis para representar as quantidades de caixas de cada tipo
    int x, y, z;

    // Resolvemos a primeira equação 150x + 50y + 50z = a, simplificada para 3x + y + z = a / 50
    for (x = 0; x <= a / 150; x++) {
        for (y = 0; y <= (a - 150 * x) / 50; y++) {
            z = (a - 150 * x - 50 * y) / 50;
            
            // Verificamos se os valores de y e z são válidos
            if (150 * x + 50 * y + 50 * z == a) {
                // Verificamos se as outras duas equações também são satisfeitas
                if (750 * x + 750 * y + 500 * z == b && 600 * x + 700 * y + 950 * z == c) {
                    // Encontramos uma solução
                    printf("%d %d %d\n", x, y, z);
                    return;
                }
            }
        }
    }

    // Caso não haja solução válida
    printf("Sem solução válida.\n");
}

int main() {

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    calcularCaixas(a, b, c);

    return 0;
}
