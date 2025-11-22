#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

// Estrutura para armazenar a posição de uma letra na matriz
typedef struct Posicao{
    int linha;
    int coluna;
} Posicao;

// Estrutura para armazenar o resultado da busca de uma palavra
typedef struct {
    int encontrado;
    int tam;
    Posicao *pos;
} ResultadoBusca;

ResultadoBusca buscar_palavra(char **matriz, int N, const char *palavra);

ResultadoBusca* buscar_todas_as_palavras(char **matriz, int N, char **palavras, int M);

void liberar_resultados(ResultadoBusca *res, int M);

#endif
