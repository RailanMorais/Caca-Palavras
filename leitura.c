#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

#define tam_max 100

void ler_tamanho(int *N, int *M) {
    scanf("%d %d", N, M);
    getchar();
}

// Lê M palavras e guarda em um vetor de strings.
char** ler_palavras(int M) {
    char linha_temp[tam_max];
    char **vetor = malloc(sizeof(char*) * M);

    for (int i = 0; i < M; i++) {

        fgets(linha_temp, sizeof(linha_temp), stdin);
        linha_temp[strcspn(linha_temp, "\n")] = '\0';

        vetor[i] = malloc(strlen(linha_temp) + 1);

        if (vetor[i] == NULL)
        {
            printf("Erro de alocação de memória do vetor[%d]\n", i);
            exit(1);
        }
        
        strcpy(vetor[i], linha_temp);
    }

    return vetor;
}

// Lê a matriz de tamanho N x N.
char** ler_matriz(int N) {

    char linha_temp[tam_max];
    char **matriz = malloc(sizeof(char*) * N);

    for (int i = 0; i < N; i++) {

        fgets(linha_temp, sizeof(linha_temp), stdin);

        linha_temp[strcspn(linha_temp, "\n")] = '\0';

        matriz[i] = malloc(N + 1);

        strncpy(matriz[i], linha_temp, N);
        
        matriz[i][N] = '\0';
    }

    return matriz;
}

// Lê toda a entrada e retorna uma estrutura Entrada preenchida.
Entrada* ler_entrada(void) {
    Entrada *ent = malloc(sizeof(Entrada));

    ler_tamanho(&ent->tamanho, &ent->qtd_palavras);
    ent->palavras = ler_palavras(ent->qtd_palavras);
    ent->matriz   = ler_matriz(ent->tamanho);

    return ent;
}

// Libera a memória alocada para a estrutura Entrada.
void liberar_entrada(Entrada *ent) {

    for (int i = 0; i < ent->qtd_palavras; i++)
        free(ent->palavras[i]);

    for (int i = 0; i < ent->tamanho; i++)
        free(ent->matriz[i]);

    free(ent->palavras);
    free(ent->matriz);
    free(ent);
}
