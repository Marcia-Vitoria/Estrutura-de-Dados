#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

#define TAM_MAX 5

typedef struct {
    char nome[50];
    char cpf[15];
} TipoPessoa;

typedef struct Fila TipoFila;

// operações da fila
TipoFila *inicializarFilaDin(void);
int filaDinVazia(TipoFila *fila);
int filaDinCheia(TipoFila *fila);
int enfileirarDin(TipoFila *fila, TipoPessoa p);
int desenfileirarDin(TipoFila *fila, TipoPessoa *p);
int consultarInicioDin(TipoFila *fila, TipoPessoa *p);
int alterarInicioDin(TipoFila *fila, TipoPessoa p);
void destruirFilaDin(TipoFila **fila);

#endif