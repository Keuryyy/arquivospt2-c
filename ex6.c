#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int filial;
    double valor_venda;
} Venda;

void calcular_totais_medias(FILE *arquivo_entrada) {
    const int NUM_FILIAIS = 4;
    Venda vendas[NUM_FILIAIS] = {0};  
    int filial;
    double valor;
    int i;

    while (fscanf(arquivo_entrada, "%d,%lf", &filial, &valor) == 2) {
        vendas[filial - 1].filial = filial;
        vendas[filial - 1].valor_venda += valor;
    }

    printf("Filial\tTotal\tMédia\n");

    for (i = 0; i < NUM_FILIAIS; i++) {
        double media = (vendas[i].filial != 0) ? vendas[i].valor_venda / vendas[i].filial : 0;
        printf("%d\t%.2lf\t%.2lf\n", i + 1, vendas[i].valor_venda, media);
    }
}

int main() {
    char nome_arquivo[100];
    FILE *arquivo_entrada;

    printf("Digite o nome do arquivo de vendas: ");
    scanf("%s", nome_arquivo);

    arquivo_entrada = fopen(nome_arquivo, "r");

    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return 1;
    }

    calcular_totais_medias(arquivo_entrada);

    fclose(arquivo_entrada);

    return 0;
}
