#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

typedef struct No {
    TipoPessoa pessoa;
    struct No *prox;
} No;

struct Fila {
    No *inicio;
    No *fim;
};

// inicializar fila
TipoFila *inicializarFilaDin(void) {
    TipoFila *fila = malloc(sizeof(TipoFila));

    if (fila == NULL) {
        return NULL;
    }

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

// verificar se a fila está vazia
int filaDinVazia(TipoFila *fila) {
    return (fila == NULL || fila->inicio == NULL);
}

// verificar se a fila está cheia
int filaDinCheia(TipoFila *fila) {
    return 0;
}

// enfileirar
int enfileirarDin(TipoFila *fila, TipoPessoa p) {
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

    if (filaDinVazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }

    fila->fim = novo;

    printf("Elemento adicionado com sucesso.\n");
    return 1;
}

// desenfileirar
int desenfileirarDin(TipoFila *fila, TipoPessoa *p) {
    if (filaDinVazia(fila) || p == NULL) {
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
int consultarInicioDin(TipoFila *fila, TipoPessoa *p) {
    if (filaDinVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    *p = fila->inicio->pessoa;

    return 1;
}

// alterar o primeiro elemento
int alterarInicioDin(TipoFila *fila, TipoPessoa p) {
    if (filaDinVazia(fila)) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    fila->inicio->pessoa = p;

    return 1;
}

// destruir fila
void destruirFilaDin(TipoFila **fila) {
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