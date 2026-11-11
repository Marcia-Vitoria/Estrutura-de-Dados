#include <stdio.h>
#include <stdlib.h>
#include "fila_circular.h"

typedef struct No {
    TipoPessoa pessoa;
    struct No *prox;
} No;

struct FilaCircular {
    No *inicio;
    No *fim;
    int qtde;
};

// inicializar fila circular
TipoFilaCircular *inicializarFilaCircular(void) {
    TipoFilaCircular *fila = malloc(sizeof(TipoFilaCircular));

    if (fila == NULL) {
        return NULL;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtde = 0;

    return fila;
}

// verificar se a fila está vazia
int filaCircularVazia(TipoFilaCircular *fila) {
    return (fila == NULL || fila->qtde == 0);
}

// verificar se a fila está cheia
int filaCircularCheia(TipoFilaCircular *fila) {
    return (fila == NULL);
}

// enfileirar
int enfileirarFilaCircular(TipoFilaCircular *fila, TipoPessoa p) {
    if (fila == NULL) {
        return 0;
    }

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("ERRO: memoria insuficiente.\n");
        return 0;
    }

    novo->pessoa = p;

    if (filaCircularVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
        novo->prox = novo;
    } else {
        novo->prox = fila->inicio;
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    fila->qtde++;

    return 1;
}

// desenfileirar
int desenfileirarFilaCircular(TipoFilaCircular *fila, TipoPessoa *p) {
    if (filaCircularVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    No *aux = fila->inicio;

    *p = aux->pessoa;

    if (fila->qtde == 1) {
        fila->inicio = NULL;
        fila->fim = NULL;
    } else {
        fila->inicio = aux->prox;
        fila->fim->prox = fila->inicio;
    }

    fila->qtde--;

    free(aux);

    return 1;
}

// consultar o primeiro elemento
int consultarInicioFilaCircular(TipoFilaCircular *fila, TipoPessoa *p) {
    if (filaCircularVazia(fila) || p == NULL) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    *p = fila->inicio->pessoa;

    return 1;
}

// alterar o primeiro elemento
int alterarInicioFilaCircular(TipoFilaCircular *fila, TipoPessoa p) {
    if (filaCircularVazia(fila)) {
        printf("ERRO: fila vazia.\n");
        return 0;
    }

    fila->inicio->pessoa = p;

    return 1;
}

// imprimir fila circular
void imprimirFilaCircular(TipoFilaCircular *fila) {
    if (filaCircularVazia(fila)) {
        printf("ERRO: fila vazia.\n");
        return;
    }

    No *aux = fila->inicio;

    printf("\nFILA CIRCULAR\n");

    for (int i = 0; i < fila->qtde; i++) {
        printf("Nome: %s | CPF: %s\n",
               aux->pessoa.nome,
               aux->pessoa.cpf);

        aux = aux->prox;
    }
}

// destruir fila circular
void destruirFilaCircular(TipoFilaCircular **fila) {
    if (fila == NULL || *fila == NULL) {
        return;
    }

    No *aux;
    No *atual = (*fila)->inicio;

    while ((*fila)->qtde > 0) {
        aux = atual;
        atual = atual->prox;
        free(aux);
        (*fila)->qtde--;
    }

    free(*fila);
    *fila = NULL;
}