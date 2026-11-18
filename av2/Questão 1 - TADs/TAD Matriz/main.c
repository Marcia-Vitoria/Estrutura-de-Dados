
#include <stdio.h>
#include "matriz.h"

int main() {

    int matriz1[9];
    int matriz2[9];
    int resultado[9];

    // dimensionar as matrizes para 3x3
    dimensionaMatriz(3, 3);

    // matriz 1
    zeraMatriz(matriz1);
    printf("Matriz 1 zerada:\n");
    imprimeMatriz(matriz1);

    adicionaElemento(matriz1, 15, 1, 1);
    adicionaElemento(matriz1, 25, 2, 2);
    adicionaElemento(matriz1, 35, 3, 3);

    printf("\nMatriz 1 preenchida:\n");
    imprimeMatriz(matriz1);

    // matriz 2 para teste de soma
    zeraMatriz(matriz2);
    printf("\nMatriz 2 zerada:\n");
    imprimeMatriz(matriz2);

    adicionaElemento(matriz2, 5, 1, 1);
    adicionaElemento(matriz2, 5, 2, 2);
    adicionaElemento(matriz2, 5, 3, 3);

    printf("\nMatriz 2 preenchida:\n");
    imprimeMatriz(matriz2);

    // buscar elemento
    printf("\nO elemento que esta na linha 2 e coluna 2 da matriz 1 eh: %d\n",
           buscaElemento(matriz1, 2, 2));

    // somar matrizes
    somaMatriz(matriz1, matriz2, resultado);

    printf("\nSoma das matrizes:\n");
    imprimeMatriz(resultado);

    return 0;
}