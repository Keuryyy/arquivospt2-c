#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcular_idade(const char *nome_arquivo_entrada, const char *nome_arquivo_saida, int ano_corrente) {
    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "r");

    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    char nome_pessoa[41];
    int ano_nascimento;
    char idade_str[50]; 

    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");

    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(arquivo_entrada);
        return;
    }

    while (fscanf(arquivo_entrada, "%40s %d", nome_pessoa, &ano_nascimento) == 2) {
        int idade = ano_corrente - ano_nascimento;

        if (idade < 18) {
            strcpy(idade_str, "menor de idade");
        } else if (idade > 18) {
            strcpy(idade_str, "maior de idade");
        } else {
            strcpy(idade_str, "entrando na maior idade");
        }

        fprintf(arquivo_saida, "%s: %s\n", nome_pessoa, idade_str);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Processo concluído. Resultados salvos em %s\n", nome_arquivo_saida);
}

int main() {
    char nome_arquivo_entrada[100];
    char nome_arquivo_saida[100];
    int ano_corrente;

    printf("Digite o ano corrente: ");
    scanf("%d", &ano_corrente);

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome_arquivo_entrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nome_arquivo_saida);

    calcular_idade(nome_arquivo_entrada, nome_arquivo_saida, ano_corrente);

    return 0;
}
