#ifndef LEITURA_H
#define LEITURA_H

// Estrutura para armazenar os dados de entrada
typedef struct Entrada{
    int tamanho;
    int qtd_palavras;
    char **palavras;
    char **matriz;
} Entrada;

void ler_tamanho(int *N, int *M);

char** ler_palavras(int M);

char** ler_matriz(int N);

Entrada* ler_entrada(void);

void liberar_entrada(Entrada *ent);

#endif