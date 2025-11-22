#include <stdio.h>
#include <stdlib.h>
#include "saida.h"

// Função para ordenar as posições antes de imprimir
static void ordenar(Posicao *v, int n) {
    if (n <= 1) return;
    for (int i = 0; i < n - 1; i++) {
        int troca = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j].linha > v[j+1].linha ||
               (v[j].linha == v[j+1].linha && v[j].coluna > v[j+1].coluna)) {
                Posicao tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
                troca = 1;
            }
        }
        if (troca == 0) break;
    }
}

// Imprime os resultados da busca das palavras na matriz. 
void imprimir_resultados(char **palavras, ResultadoBusca *resultados, int M) {
    for (int i = 0; i < M; i++) {
        ResultadoBusca *r = &resultados[i];

        if (r->encontrado == 0) {

            printf("%s não encontrado\n", palavras[i]);
            continue;
        }

        ordenar(r->pos, r->tam);


        printf("%s", palavras[i]);
        for (int k = 0; k < r->tam; k++) {
            printf(" (%d,%d)", r->pos[k].linha, r->pos[k].coluna);
        }
        printf("\n");
    }
}
