#ifndef SPOOLER_H
#define SPOOLER_H

/*
    Spooler de impressão de uma empresa com uma única impressora.
    Prioridades: Diretor (1), Coordenador (2) e Funcionário (3).
*/

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

#define DIRETOR 1
#define COORDENADOR 2
#define FUNCIONARIO 3
#define NUM_PRIORIDADES 3

typedef struct Spooler TipoSpooler;

TipoSpooler *inicializarSpooler(void);

// 1 se não há nenhum documento esperando
int spoolerVazio(TipoSpooler *spooler);

// 1 se a fila dessa prioridade não aceita mais documentos
int prioridadeCheia(TipoSpooler *spooler, int prioridade);

// coloca o documento na fila da prioridade; retorna 0 se ela estiver cheia ou a prioridade for inválida
int enviarDocumento(TipoSpooler *spooler, TipoPessoa p, int prioridade);

// a impressora pega o próximo documento (o de maior prioridade); retorna 0 se não há nenhum
int imprimirProximo(TipoSpooler *spooler, TipoPessoa *p, int *prioridade);

// consulta qual seria o próximo, sem remover
int consultarProximo(TipoSpooler *spooler, TipoPessoa *p, int *prioridade);

// imprime toda a fila de impressão, na ordem em que será atendida
void imprimirSpooler(TipoSpooler *spooler);

// "Diretor", "Coordenador" ou "Funcionário"
const char *nomePrioridade(int prioridade);

void destruirSpooler(TipoSpooler **spooler);

// repete a pergunta até o usuário digitar um número inteiro de verdade
int lerInteiro(void);

// lê uma linha de texto (aceita espaços); o que passar do tamanho é descartado
void lerTexto(char texto[], int tamanho);

// opção 1 do menu: lê cargo, nome e CPF e coloca o documento na fila
void opcaoEnviarDocumento(TipoSpooler *spooler);

// opção 2 do menu: a impressora atende o próximo da fila
void opcaoImprimirProximo(TipoSpooler *spooler);

#endif