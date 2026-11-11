#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#define TAM_MAX 5

typedef struct {
    char nome[50];
    char cpf[15];
} TipoPessoa;

typedef struct FilaCircular TipoFilaCircular;

// operações da fila circular
TipoFilaCircular *inicializarFilaCircular(void);
int filaCircularVazia(TipoFilaCircular *fila);
int filaCircularCheia(TipoFilaCircular *fila);
int enfileirarFilaCircular(TipoFilaCircular *fila, TipoPessoa p);
int desenfileirarFilaCircular(TipoFilaCircular *fila, TipoPessoa *p);
int consultarInicioFilaCircular(TipoFilaCircular *fila, TipoPessoa *p);
int alterarInicioFilaCircular(TipoFilaCircular *fila, TipoPessoa p);
void imprimirFilaCircular(TipoFilaCircular *fila);
void destruirFilaCircular(TipoFilaCircular **fila);

#endif