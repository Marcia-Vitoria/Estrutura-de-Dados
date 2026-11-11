#include <stdio.h>
#include <stdlib.h>
#include "fila_circular.h"

struct FilaCircular {
    int inicio;
    int fim;
    int qtde;
    TipoPessoa elemt[TAM_MAX];
};

// inicializar fila circular
TipoFilaCircular *inicializarFilaCircular(void) {
    TipoFilaCircular *fila = malloc(sizeof(TipoFilaCircular));

    if (fila == NULL) {
        return NULL;
    }

    fila->inicio = 0;
    fila->fim = -1;
    fila->qtde = 0;

    return fila;
}

// verificar se a fila está vazia
int filaCircularVazia(TipoFilaCircular *fila) {
    return (fila == NULL || fila->qtde == 0);
}

// verificar se a fila está cheia
int filaCircularCheia(TipoFilaCircular *fila) {
    return (fila == NULL || fila->qtde == TAM_MAX);
}

// enfileirar
int enfileirarFilaCircular(TipoFilaCircular *fila, TipoPessoa p) {
    if (fila == NULL || filaCircularCheia(fila)) {
        printf("ERRO: fila cheia.\n");
        return 0;
    }

    if (fila->fim + 1 == TAM_MAX) {
        fila->fim = 0;
    } else {
        fila->fim++;
    }

    fila->elemt[fila->fim] = p;
    fila->qtde++;

    return 1;
}

// desenfileirar
int desenfileirarFilaCircular(TipoFilaCircular *fila, TipoPessoa *p) {
    if (filaCircularVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    *p = fila->elemt[fila->inicio];

    if (fila->inicio + 1 == TAM_MAX) {
        fila->inicio = 0;
    } else {
        fila->inicio++;
    }

    fila->qtde--;

    return 1;
}

// consultar o primeiro elemento
int consultarInicioFilaCircular(TipoFilaCircular *fila, TipoPessoa *p) {
    if (filaCircularVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    *p = fila->elemt[fila->inicio];

    return 1;
}

// alterar o primeiro elemento
int alterarInicioFilaCircular(TipoFilaCircular *fila, TipoPessoa p) {
    if (filaCircularVazia(fila)) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    fila->elemt[fila->inicio] = p;

    return 1;
}

// imprimir fila circular
void imprimirFilaCircular(TipoFilaCircular *fila) {
    if (filaCircularVazia(fila)) {
        printf("ERRO: fila vazia.\n");
        return;
    }

    int indice;

    printf("\nFILA CIRCULAR\n");

    for (int i = 0; i < fila->qtde; i++) {
        indice = (fila->inicio + i) % TAM_MAX;

        printf("Nome: %s | CPF: %s\n",
               fila->elemt[indice].nome,
               fila->elemt[indice].cpf);
    }
}

// destruir fila circular
void destruirFilaCircular(TipoFilaCircular **fila) {
    if (fila != NULL && *fila != NULL) {
        free(*fila);
        *fila = NULL;
    }
}