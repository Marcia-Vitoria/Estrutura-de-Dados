#include <stdio.h>
#include <stdlib.h>
#include "spooler.h"

struct FilaCircular {
    TipoPessoa elemt[TAM_MAX];
    int inicio;
    int fim;
    int quantidade;
};

// Inicializar fila
TipoFilaCircular *inicializarFilaCircular(void) {
    TipoFilaCircular *fila = malloc(sizeof(TipoFilaCircular));

    if (fila == NULL) {
        return NULL;
    }

    fila->inicio = 0;
    fila->fim = -1;
    fila->quantidade = 0;

    return fila;
}

// Verificar se está vazia
int filaCircularVazia(TipoFilaCircular *fila) {
    if (fila == NULL) {
        return 1;
    }

    return fila->quantidade == 0;
}

// Verificar se está cheia
int filaCircularCheia(TipoFilaCircular *fila) {
    if (fila == NULL) {
        return 0;
    }

    return fila->quantidade == TAM_MAX;
}

// Inserir pessoa na fila
int enfileirarFilaCircular(TipoFilaCircular *fila, TipoPessoa p) {
    if (fila == NULL || filaCircularCheia(fila)) {
        return 0;
    }

    fila->fim = (fila->fim + 1) % TAM_MAX;

    fila->elemt[fila->fim] = p;

    fila->quantidade++;

    return 1;
}

// Remover pessoa da fila
int desenfileirarFilaCircular(TipoFilaCircular *fila, TipoPessoa *p) {
    if (filaCircularVazia(fila) || p == NULL) {
        return 0;
    }

    *p = fila->elemt[fila->inicio];

    fila->inicio = (fila->inicio + 1) % TAM_MAX;

    fila->quantidade--;

    return 1;
}

// Consultar primeiro elemento
int consultarInicioFilaCircular(TipoFilaCircular *fila, TipoPessoa *p) {
    if (filaCircularVazia(fila) || p == NULL) {
        return 0;
    }

    *p = fila->elemt[fila->inicio];

    return 1;
}

// Alterar primeiro elemento
int alterarInicioFilaCircular(TipoFilaCircular *fila, TipoPessoa p) {
    if (filaCircularVazia(fila)) {
        return 0;
    }

    fila->elemt[fila->inicio] = p;

    return 1;
}

// Imprimir a fila do primeiro ao último, sem remover ninguém
void imprimirFilaCircular(TipoFilaCircular *fila) {
    if (filaCircularVazia(fila)) {
        printf("   (vazia)\n");
        return;
    }

    for (int i = 0; i < fila->quantidade; i++) {
        // a fila é circular: a posição volta ao começo do vetor ao passar do fim
        int pos = (fila->inicio + i) % TAM_MAX;

        printf("   %d. %s - CPF: %s\n", i + 1, fila->elemt[pos].nome, fila->elemt[pos].cpf);
    }
}

// Destruir fila
void destruirFilaCircular(TipoFilaCircular **fila) {
    if (fila != NULL && *fila != NULL) {
        free(*fila);
        *fila = NULL;
    }
}

struct Spooler {
    TipoFilaCircular *filas[NUM_PRIORIDADES];
};

const char *nomePrioridade(int prioridade) {
    switch (prioridade) {
        case DIRETOR:     return "Diretor";
        case COORDENADOR: return "Coordenador";
        case FUNCIONARIO: return "Funcionário";
        default:          return "Desconhecido";
    }
}

static int prioridadeValida(int prioridade) {
    return prioridade >= DIRETOR && prioridade <= FUNCIONARIO;
}

TipoSpooler *inicializarSpooler(void) {
    TipoSpooler *spooler = malloc(sizeof(TipoSpooler));

    if (spooler == NULL) {
        return NULL;
    }

    for (int i = 0; i < NUM_PRIORIDADES; i++) {
        spooler->filas[i] = inicializarFilaCircular();

        if (spooler->filas[i] == NULL) {
            // faltou memória: desfaz o que já foi criado
            for (int j = 0; j < i; j++) {
                destruirFilaCircular(&spooler->filas[j]);
            }
            free(spooler);
            return NULL;
        }
    }

    return spooler;
}

int spoolerVazio(TipoSpooler *spooler) {
    if (spooler == NULL) {
        return 1;
    }

    for (int i = 0; i < NUM_PRIORIDADES; i++) {
        if (!filaCircularVazia(spooler->filas[i])) {
            return 0;
        }
    }

    return 1;
}

int prioridadeCheia(TipoSpooler *spooler, int prioridade) {
    if (spooler == NULL || !prioridadeValida(prioridade)) {
        return 0;
    }

    return filaCircularCheia(spooler->filas[prioridade - 1]);
}

int enviarDocumento(TipoSpooler *spooler, TipoPessoa p, int prioridade) {
    if (spooler == NULL || !prioridadeValida(prioridade)) {
        return 0;
    }

    return enfileirarFilaCircular(spooler->filas[prioridade - 1], p);
}

int imprimirProximo(TipoSpooler *spooler, TipoPessoa *p, int *prioridade) {
    if (spooler == NULL || p == NULL || prioridade == NULL) {
        return 0;
    }

    // percorre da maior prioridade (1) para a menor (3)
    for (int i = 0; i < NUM_PRIORIDADES; i++) {
        if (desenfileirarFilaCircular(spooler->filas[i], p)) {
            *prioridade = i + 1;
            return 1;
        }
    }

    return 0;
}

int consultarProximo(TipoSpooler *spooler, TipoPessoa *p, int *prioridade) {
    if (spooler == NULL || p == NULL || prioridade == NULL) {
        return 0;
    }

    for (int i = 0; i < NUM_PRIORIDADES; i++) {
        if (consultarInicioFilaCircular(spooler->filas[i], p)) {
            *prioridade = i + 1;
            return 1;
        }
    }

    return 0;
}

void imprimirSpooler(TipoSpooler *spooler) {
    TipoPessoa proximo;
    int prioridade;

    printf("\n=========== FILA DE IMPRESSAO ===========\n");

    if (spoolerVazio(spooler)) {
        printf("Nenhum documento aguardando.\n");
        printf("=========================================\n");
        return;
    }

    consultarProximo(spooler, &proximo, &prioridade);
    printf("Proximo a imprimir: %s (%s)\n", proximo.nome, nomePrioridade(prioridade));

    // as filas aparecem na ordem em que a impressora vai atendê-las
    for (int i = 0; i < NUM_PRIORIDADES; i++) {
        printf("\nPrioridade %d - %s:\n", i + 1, nomePrioridade(i + 1));
        imprimirFilaCircular(spooler->filas[i]);
    }

    printf("=========================================\n");
}

void destruirSpooler(TipoSpooler **spooler) {
    if (spooler == NULL || *spooler == NULL) {
        return;
    }

    for (int i = 0; i < NUM_PRIORIDADES; i++) {
        destruirFilaCircular(&(*spooler)->filas[i]);
    }

    free(*spooler);
    *spooler = NULL;
}

int lerInteiro(void) {
    int valor;

    while (scanf("%d", &valor) != 1) {
        while (getchar() != '\n');
        printf("Entrada invalida! Digite um numero: ");
    }

    return valor;
}

void lerTexto(char texto[], int tamanho) {
    int c, i = 0;

    // pula espaços e quebras de linha que sobraram da leitura anterior
    do {
        c = getchar();
    } while (c == ' ' || c == '\t' || c == '\r' || c == '\n');

    while (c != EOF && c != '\n') {
        if (i < tamanho - 1) {
            texto[i++] = (char) c;
        }
        c = getchar();
    }

    texto[i] = '\0';
}

// opção 1 do menu: lê os dados de quem está enviando e coloca o documento na fila da sua prioridade
void opcaoEnviarDocumento(TipoSpooler *spooler) {
    TipoPessoa p;
    int cargo;

    printf("Cargo (1 = Diretor, 2 = Coordenador, 3 = Funcionario): ");
    cargo = lerInteiro();

    if (cargo < DIRETOR || cargo > FUNCIONARIO) {
        printf("Cargo invalido!\n");
        return;
    }

    // verifica antes de pedir os dados, para o usuário não digitar à toa
    if (prioridadeCheia(spooler, cargo)) {
        printf("A fila de %s esta cheia (maximo %d documentos)!\n", nomePrioridade(cargo), TAM_MAX);
        return;
    }

    printf("Nome: ");
    lerTexto(p.nome, sizeof(p.nome));

    printf("CPF: ");
    lerTexto(p.cpf, sizeof(p.cpf));

    if (enviarDocumento(spooler, p, cargo)) {
        printf("Documento de %s enviado para a fila!\n", p.nome);
    }
    else {
        printf("Nao foi possivel enviar o documento!\n");
    }
}

// opção 2 do menu: a impressora atende o próximo da fila
void opcaoImprimirProximo(TipoSpooler *spooler) {
    TipoPessoa p;
    int prioridade;

    if (imprimirProximo(spooler, &p, &prioridade)) {
        printf("Imprimindo documento de %s (%s)...\n", p.nome, nomePrioridade(prioridade));
    }
    else {
        printf("Nenhum documento na fila.\n");
    }
}