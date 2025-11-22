#include "leitura.h"
#include "processamento.h"
#include "saida.h"
#include <stdio.h>

int main(void) {
    Entrada *ent = ler_entrada();
    if (ent == NULL) {
        printf("Erro na leitura da entrada\n");
        return 1;
    }

    ResultadoBusca *res = buscar_todas_as_palavras(ent->matriz, ent->tamanho, ent->palavras, ent->qtd_palavras);
    if (res == NULL) {
        printf("Erro no processamento\n");
        liberar_entrada(ent);
        return 1;
    }

    imprimir_resultados(ent->palavras, res, ent->qtd_palavras);

    liberar_resultados(res, ent->qtd_palavras);
    liberar_entrada(ent);

    return 0;
}