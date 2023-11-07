#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome_arquivo_entrada[100];
    char nome_arquivo_saida[100];
    char caractere;
    
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome_arquivo_entrada);
    
    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "r");

    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");

    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(arquivo_entrada); // Fechar o arquivo de entrada
        return 1;
    }

    while ((caractere = fgetc(arquivo_entrada)) != EOF) {
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' ||
            caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U') {
            fputc('*', arquivo_saida);
        } else {
            fputc(caractere, arquivo_saida);
        }
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Arquivo de saída criado com as vogais substituídas por '*'.\n");

}
