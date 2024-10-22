#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCIPLINAS 1000

// Função para processar e imprimir o semestre
void processar_semestre(int ano, int semestre, int disciplinas[][3], int m) {
    int max_reprovacoes = -1;
    int codigos[MAX_DISCIPLINAS];
    int qtd_codigos = 0;

    // Encontra o número máximo de reprovações
    for (int i = 0; i < m; i++) {
        int codigo = disciplinas[i][0];
        int matriculados = disciplinas[i][1];
        int aprovados = disciplinas[i][2];
        int reprovados = matriculados - aprovados;

        if (reprovados > max_reprovacoes) {
            max_reprovacoes = reprovados;
            codigos[0] = codigo;
            qtd_codigos = 1;
        } else if (reprovados == max_reprovacoes) {
            codigos[qtd_codigos++] = codigo;
        }
    }

    // Ordena os códigos das disciplinas em ordem crescente
    for (int i = 0; i < qtd_codigos - 1; i++) {
        for (int j = i + 1; j < qtd_codigos; j++) {
            if (codigos[i] > codigos[j]) {
                int temp = codigos[i];
                codigos[i] = codigos[j];
                codigos[j] = temp;
            }
        }
    }

    // Imprime o semestre e as disciplinas que mais reprovaram
    printf("%d/%d\n", ano, semestre);
    for (int i = 0; i < qtd_codigos; i++) {
        printf("%d ", codigos[i]);
    }
    printf("\n\n");
}

int main() {
    int D; // Número total de disciplinas oferecidas

    // Leitura do número total de disciplinas
    scanf("%d", &D);

    // Leitura dos semestres e das disciplinas até EOF
    int ano, semestre, m;
    while (scanf("%d %d %d", &ano, &semestre, &m) != EOF) {
        int disciplinas[MAX_DISCIPLINAS][3]; // [código, matriculados, aprovados]

        // Leitura das disciplinas do semestre atual
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &disciplinas[i][0], &disciplinas[i][1], &disciplinas[i][2]);
        }

        // Processa o semestre e imprime o resultado
        processar_semestre(ano, semestre, disciplinas, m);
    }

    return 0;
}
