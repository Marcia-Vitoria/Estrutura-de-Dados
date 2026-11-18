#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

struct Fila {
    int inicio;
    int fim;
    TipoPessoaEst elemt[TAM_MAX];
};

// inicializar fila
TipoFilaEst *inicializarFila(void) {
    TipoFilaEst *fila = malloc(sizeof(TipoFilaEst));

    if (fila == NULL) {
        return NULL;
    }

    fila->inicio = 0;
    fila->fim = -1;

    return fila;
}

// verificar se a fila está vazia
int filaVazia(TipoFilaEst *fila) {
    return (fila == NULL || fila->inicio > fila->fim);
}

// verificar se a fila está cheia
int filaCheia(TipoFilaEst *fila) {
    return (fila == NULL || fila->fim + 1 == TAM_MAX);
}

// enfileirar
int enfileirar(TipoFilaEst *fila, TipoPessoaEst p) {
    if (fila == NULL || filaCheia(fila)) {
        printf("ERRO: fila cheia.\n");
        return 0;
    }

    fila->fim++;
    fila->elemt[fila->fim] = p;

    printf("Elemento adicionado com sucesso.\n");
    return 1;
}

// desenfileirar
int desenfileirar(TipoFilaEst *fila, TipoPessoaEst *p) {
    if (filaVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    *p = fila->elemt[fila->inicio];
    fila->inicio++;

    return 1;
}

// consultar o primeiro elemento
int consultarInicio(TipoFilaEst *fila, TipoPessoaEst *p) {
    if (filaVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    *p = fila->elemt[fila->inicio];

    return 1;
}

// alterar o primeiro elemento
int alterarInicio(TipoFilaEst *fila, TipoPessoaEst p) {
    if (filaVazia(fila)) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    fila->elemt[fila->inicio] = p;

    return 1;
}

// destruir fila
void destruirFila(TipoFilaEst **fila) {
    if (fila != NULL && *fila != NULL) {
        free(*fila);
        *fila = NULL;
    }
}