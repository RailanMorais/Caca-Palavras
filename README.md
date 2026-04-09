
# Projeto Caça-Palavras

## Progama que acha palavras informadas pelo usuário em 8 direções (horizontal, vertical e diagonais), em uma matriz de letras também informada e retorna a palavra e as posições em que ela se encontra.
Esse projeto foi construído em C, para avaliação da matéria Progamação de computadores 1.

## Instrução de uso:
Com a ferramenta make instalada, utilize o terminal

### Na pasta do projeto, para criar os arquivos objetos e o executável:
```bash
make
```

### Após criar os arquivos, execute o progama.  
Entre com o tamanho da matriz quadrada e o número de palavras,  
então, digite as palavras que quer encontrar, respeitando o número dado anteriormente,  
em seguida, entre com o caça-palavras do tamanho da matriz.  

### Exemplo:
```bash
10 6
MACARRAO
CARRO
ARVORE
ROEMOS
POSTE
OVO
FWSOQAPOAV
YEOYCCSEVW
TRMACARRAO
PLESAXMSNE
EROVRALTZL
NSRORPBVZW
JAJCOCCPDO
HAJSKQVIHU
PTTPFXTZBP
BEPQNZPIII
```
### Saída:
```bash
MACARRAO (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8) (2,9)
CARRO (2,4) (3,4) (4,4) (5,4) (6,4)
ARVORE (4,0) (4,1) (4,2) (4,3) (4,4) (4,5)
ROEMOS (0,2) (1,2) (2,2) (3,2) (4,2) (5,2)
POSTE (5,5) (6,4) (7,3) (8,2) (9,1)
OVO (0,7) (1,8) (2,9)
```

### Para remover os arquivos criados:
```bash
make clean
```

## Autor
- [@RailanMorais](https://www.github.com/RailanMorais)

