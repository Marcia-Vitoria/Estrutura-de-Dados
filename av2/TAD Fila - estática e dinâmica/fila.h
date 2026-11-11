#ifndef FILA_H
#define FILA_H

#define TAM_MAX 5

typedef struct {
    char nome[50];
    char cpf[15];
} TipoPessoa;

typedef struct Fila TipoFila;

// operações da fila
TipoFila *inicializarFila(void);
int filaVazia(TipoFila *fila);
int filaCheia(TipoFila *fila);
int enfileirar(TipoFila *fila, TipoPessoa p);
int desenfileirar(TipoFila *fila, TipoPessoa *p);
int consultarInicio(TipoFila *fila, TipoPessoa *p);
int alterarInicio(TipoFila *fila, TipoPessoa p);
void destruirFila(TipoFila **fila);

#endif