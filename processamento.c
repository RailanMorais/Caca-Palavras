#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processamento.h"

// Direções possíveis: N, NE, E, SE, S, SW, W, NW
static int direcoes[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    { 0, -1},          { 0, 1},
    { 1, -1}, { 1, 0}, { 1, 1}
};


// Verifica se a palavra está na matriz a partir da posição (lin, col) na direção (dx, dy).
// dx = variação na linha, dy = variação na coluna
// Se encontrada, preenche o array posicoes com as posições da palavra e retorna 1. Caso contrário, retorna 0.
static int verificar_direcao(char **mat, int N, const char *pal, int lin, int col, int dx, int dy, Posicao *posicoes) {
    int tam = strlen(pal);
    for (int k = 0; k < tam; k++) {
        int nova_lin = lin + k * dx;
        int nova_col = col + k * dy;
        if (nova_lin < 0 || nova_lin >= N || nova_col < 0 || nova_col >= N){
            return 0;
        }
        if (mat[nova_lin][nova_col] != pal[k]){
            return 0;
        }
        posicoes[k].linha = nova_lin;
        posicoes[k].coluna = nova_col;
    }
    return 1;
}

// Busca uma única palavra na matriz.
// Retorna um ResultadoBusca com as posições encontradas ou vazio se não encontrada.
ResultadoBusca buscar_palavra(char **matriz, int N, const char *palavra) {
    ResultadoBusca resultado;
    resultado.encontrado = 0;
    resultado.tam = 0;
    resultado.pos = NULL;

    int tam = strlen(palavra);

    if (tam == 0 || tam > N) {
        return resultado;
    }

    Posicao *tmp = malloc(sizeof(Posicao) * tam);
    if (tmp == NULL){
        printf("Erro de alocação da posição temporária\n");
        return resultado;
    } 

    for (int i = 0; i < N && !resultado.encontrado; i++) {
        for (int j = 0; j < N && !resultado.encontrado; j++) {

            if (matriz[i][j] != palavra[0]){
                continue;
            }

            for (int d = 0; d < 8; d++) {

                int dx = direcoes[d][0];
                int dy = direcoes[d][1];

                if (verificar_direcao(matriz, N, palavra, i, j, dx, dy, tmp)) {
                    resultado.encontrado = 1;
                    resultado.tam = tam;
                    resultado.pos = malloc(sizeof(Posicao) * tam);

                    if (resultado.pos == NULL) {
                        resultado.encontrado = 0;
                        resultado.tam = 0;
                        free(tmp);
                        return resultado;
                    }

                    for (int k = 0; k < tam; k++) {
                        resultado.pos[k] = tmp[k];
                    }
                    break;
                }
            }
        }
    }
    free(tmp);
    return resultado;
}

// Para cada palavra chama buscar_palavra e guarda resultado.
ResultadoBusca* buscar_todas_as_palavras(char **matriz, int N, char **palavras, int M) {

    ResultadoBusca *res = malloc(sizeof(ResultadoBusca) * M);

    if (res == NULL){
        printf("Erro de alocação de memória dos resultados\n");
        exit(1);
    }

    for (int i = 0; i < M; i++) {
        res[i] = buscar_palavra(matriz, N, palavras[i]);
    }
    return res;
}

// Libera a memória alocada para os resultados da busca.
void liberar_resultados(ResultadoBusca *res, int M) {
    if (res == NULL){
        printf("Erro: ja liberado ou nulo\n");
        exit(1);
    }
    for (int i = 0; i < M; i++) {
        if (res[i].pos) free(res[i].pos);
    }
    free(res);
}
