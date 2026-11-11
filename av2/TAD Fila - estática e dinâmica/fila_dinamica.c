#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct No {
    TipoPessoa pessoa;
    struct No *prox;
} No;

struct Fila {
    No *inicio;
    No *fim;
};

// inicializar fila
TipoFila *inicializarFila(void) {
    TipoFila *fila = malloc(sizeof(TipoFila));

    if (fila == NULL) {
        return NULL;
    }

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

// verificar se a fila está vazia
int filaVazia(TipoFila *fila) {
    return (fila == NULL || fila->inicio == NULL);
}

// verificar se a fila está cheia
int filaCheia(TipoFila *fila) {
    return 0;
}

// enfileirar
int enfileirar(TipoFila *fila, TipoPessoa p) {
    if (fila == NULL) {
        return 0;
    }

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("ERRO: memoria insuficiente.\n");
        return 0;
    }

    novo->pessoa = p;
    novo->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }

    fila->fim = novo;

    printf("Elemento adicionado com sucesso.\n");
    return 1;
}

// desenfileirar
int desenfileirar(TipoFila *fila, TipoPessoa *p) {
    if (filaVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    No *aux = fila->inicio;

    *p = aux->pessoa;
    fila->inicio = aux->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(aux);

    return 1;
}

// consultar o primeiro elemento
int consultarInicio(TipoFila *fila, TipoPessoa *p) {
    if (filaVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    *p = fila->inicio->pessoa;

    return 1;
}

// alterar o primeiro elemento
int alterarInicio(TipoFila *fila, TipoPessoa p) {
    if (filaVazia(fila)) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    fila->inicio->pessoa = p;

    return 1;
}

// destruir fila
void destruirFila(TipoFila **fila) {
    if (fila == NULL || *fila == NULL) {
        return;
    }

    No *aux;

    while ((*fila)->inicio != NULL) {
        aux = (*fila)->inicio;
        (*fila)->inicio = aux->prox;
        free(aux);
    }

    free(*fila);
    *fila = NULL;
}