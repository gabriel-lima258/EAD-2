#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 101  // Tamanho máximo da string
#define MAX_EDITS 1000  // Número máximo de edições

int main() {
    char *pilha[MAX_EDITS];  // Vetor de ponteiros para strings
    int topo = -1;  // Índice do topo da pilha
    char comando[10];  // Comando ("inserir" ou "desfazer")
    char str[MAX_STR];  // String temporária para armazenar a alteração

    // Lê a entrada até EOF
    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "inserir") == 0) {
            getchar();  // Consumir o espaço após o comando
            fgets(str, MAX_STR, stdin);  // Lê a string

            str[strcspn(str, "\n")] = '\0';  // Remove a nova linha
            
            topo++;  // Incrementa o topo da pilha
            pilha[topo] = malloc(strlen(str) + 1);  // Aloca espaço para a string
            strcpy(pilha[topo], str);  // Copia a string para a pilha
        } else if (strcmp(comando, "desfazer") == 0) {
            if (topo == -1) {
                printf("NULL\n");  // Se a pilha está vazia
            } else {
                printf("%s\n", pilha[topo]);  // Mostra o topo da pilha
                free(pilha[topo]);  // Libera a memória alocada para a string
                topo--;  // Remove o topo
            }
        }
    }

    // Libera memória alocada restante (caso o programa termine sem desfazer tudo)
    while (topo >= 0) {
        free(pilha[topo]);
        topo--;
    }

    return 0;
}
