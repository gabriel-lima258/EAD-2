#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char A[1000]; // nome do airport
    char S[4]; // sigla

    scanf("%s", A);
    scanf("%s", S);

    // tamanho do array de string
    int tamanhoNome = strlen(A);\
    int tamanhoSigla = 3;

    // se a sigla terminar em x, consideramos apenas os dois primeiros
    if (S[2] == 'X') {
      tamanhoSigla = 2;
    }

    int j = 0;

    for (int i = 0; i < tamanhoSigla; i++) {
      // procurando o char do nome igual na sigla
      while (j < tamanhoNome && toupper(A[j]) != S[i] ) {
        j++;
      }
      // caso nao encontre, sigla invalida
      if (j == tamanhoNome) {
        printf("Nao\n");
        return 0;
      }
      // percorrendo o nome do aeroporto
      j++;
    }

    // caso todas as letras da sigla forem encontradas
    printf("Sim\n");

    return 0;
}