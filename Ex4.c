#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontrar_cidade_mais_populosa(const char *nome_arquivo_entrada, const char *nome_arquivo_saida) {
    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "r");

    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    char nome_cidade[41]; 
    int populacao;
    char cidade_mais_populosa[41] = ""; 
    int populacao_mais_populosa = 0;

    while (fscanf(arquivo_entrada, "%40s %d", nome_cidade, &populacao) == 2) {
        if (populacao > populacao_mais_populosa) {
            strcpy(cidade_mais_populosa, nome_cidade);
            populacao_mais_populosa = populacao;
        }
    }

    fclose(arquivo_entrada);

    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");

    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return;
    }

    fprintf(arquivo_saida, "Cidade mais populosa: %s\n", cidade_mais_populosa);
    fprintf(arquivo_saida, "População: %d\n", populacao_mais_populosa);

    fclose(arquivo_saida);

    printf("Processo concluído. Resultados salvos em %s\n", nome_arquivo_saida);
}

int main() {
    char nome_arquivo_entrada[100];
    char nome_arquivo_saida[100];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome_arquivo_entrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    encontrar_cidade_mais_populosa(nome_arquivo_entrada, nome_arquivo_saida);

    return 0;
}
