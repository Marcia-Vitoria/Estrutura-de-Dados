#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

#define TAM_MAX 5

typedef struct {
    char nome[50];
    char cpf[15];
} TipoPessoaEst;

typedef struct Fila TipoFilaEst;

// operações da fila
TipoFilaEst *inicializarFila(void);
int filaVazia(TipoFilaEst *fila);
int filaCheia(TipoFilaEst *fila);
int enfileirar(TipoFilaEst *fila, TipoPessoaEst p);
int desenfileirar(TipoFilaEst *fila, TipoPessoaEst *p);
int consultarInicio(TipoFilaEst *fila, TipoPessoaEst *p);
int alterarInicio(TipoFilaEst *fila, TipoPessoaEst p);
void destruirFila(TipoFilaEst **fila);

#endif