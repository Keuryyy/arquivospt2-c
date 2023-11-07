#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome_arquivo[100];
    char caractere;
    int contador = 0;

    printf("Digite o nome do arquivo de texto: ");
    scanf("%s", nome_arquivo);

    printf("Digite o caractere a ser contado: ");
    scanf(" %c", &caractere);

    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == caractere) {
            contador++;
        }
    }

    fclose(arquivo);

    printf("O caractere '%c' ocorre %d vezes no arquivo.\n", caractere, contador);

    return 0;
}
