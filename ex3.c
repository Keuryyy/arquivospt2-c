#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nomeArquivo1[100], nomeArquivo2[100], nomeArquivoSaida[100];
    FILE *arquivo1, *arquivo2, *arquivoSaida;
    char caractere;

    printf("Digite o nome do primeiro arquivo de entrada: ");
    fgets(nomeArquivo1, sizeof(nomeArquivo1), stdin);
    nomeArquivo1[strcspn(nomeArquivo1, "\n")] = '\0';

    printf("Digite o nome do segundo arquivo de entrada: ");
    fgets(nomeArquivo2, sizeof(nomeArquivo2), stdin);
    nomeArquivo2[strcspn(nomeArquivo2, "\n")] = '\0';

    arquivo1 = fopen(nomeArquivo1, "r");

    if (arquivo1 == NULL) {
        printf("Não foi possível abrir o primeiro arquivo de entrada.\n");
        return 1;
    }

    arquivo2 = fopen(nomeArquivo2, "r");

    if (arquivo2 == NULL) {
        printf("Não foi possível abrir o segundo arquivo de entrada.\n");
        fclose(arquivo1);
        return 1;
    }

    printf("Digite o nome do arquivo de saída: ");
    fgets(nomeArquivoSaida, sizeof(nomeArquivoSaida), stdin);
    nomeArquivoSaida[strcspn(nomeArquivoSaida, "\n")] = '\0';

    arquivoSaida = fopen(nomeArquivoSaida, "w");

    if (arquivoSaida == NULL) {
        printf("Não foi possível criar o arquivo de saída.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        return 1;
    }

    while ((caractere = fgetc(arquivo1)) != EOF) {
        fputc(caractere, arquivoSaida);
    }

    while ((caractere = fgetc(arquivo2)) != EOF) {
        fputc(caractere, arquivoSaida);
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivoSaida);

    printf("Os arquivos foram concatenados com sucesso em %s.\n", nomeArquivoSaida);

    return 0;
}
