/*
    Estrutura de Dados:

    Spooler de impressão de uma empresa com uma única impressora.
    Prioridades: Diretor (1), Coordenador (2) e Funcionário (3).
    O TAD usado é a Fila estática circular (spooler.h / spooler.c).
*/
#include <stdio.h>
#include "spooler.h"

int main() {

    TipoSpooler *spooler = inicializarSpooler();
    int decisao;

    if (spooler == NULL) {
        printf("Sem memoria!\n");
        return 1;
    }

    do {
        printf("\n----------------------------------\n");
        printf("0 = Encerrar\n1 = Enviar documento para impressao\n");
        printf("2 = Imprimir proximo documento\n3 = Mostrar fila de impressao\n");

        decisao = lerInteiro();

        switch (decisao) {
            case 0: printf("Encerrando...\n"); break;
            case 1: opcaoEnviarDocumento(spooler); break;
            case 2: opcaoImprimirProximo(spooler); break;
            case 3: imprimirSpooler(spooler); break;
            default: printf("Opção inválida!\n");
        }
    } while (decisao != 0);

    destruirSpooler(&spooler);

    return 0;
}