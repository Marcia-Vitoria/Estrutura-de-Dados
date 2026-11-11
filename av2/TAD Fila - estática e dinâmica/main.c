#include <stdio.h>
#include <string.h>
#include "fila_circular.h"

int main(void) {
    TipoFilaCircular *fila = inicializarFilaCircular();
    TipoPessoa p, consulta;
    int opcao;

    if (fila == NULL) {
        printf("Erro ao inicializar fila.\n");
        return 1;
    }

    do {
        printf("\n========== FILA CIRCULAR ==========\n");
        printf("1 - Enfileirar pessoa\n");
        printf("2 - Desenfileirar pessoa\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Alterar inicio\n");
        printf("5 - Verificar fila vazia\n");
        printf("6 - Verificar fila cheia\n");
        printf("7 - Imprimir fila\n");
        printf("0 - Sair\n");
        printf("==================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {

            case 1:
                printf("\nENFILEIRAR\n");

                printf("Nome: ");
                fgets(p.nome, sizeof(p.nome), stdin);
                p.nome[strcspn(p.nome, "\n")] = '\0';

                printf("CPF: ");
                fgets(p.cpf, sizeof(p.cpf), stdin);
                p.cpf[strcspn(p.cpf, "\n")] = '\0';

                if (enfileirarFilaCircular(fila, p)) {
                    printf("Pessoa adicionada!\n");
                }
                break;

            case 2:
                printf("\nDESENFILEIRAR\n");

                if (desenfileirarFilaCircular(fila, &consulta)) {
                    printf("Pessoa removida: %s\n", consulta.nome);
                    printf("CPF: %s\n", consulta.cpf);
                }
                break;

            case 3:
                printf("\nCONSULTAR INICIO\n");

                if (consultarInicioFilaCircular(fila, &consulta)) {
                    printf("Nome: %s\n", consulta.nome);
                    printf("CPF: %s\n", consulta.cpf);
                }
                break;

            case 4:
                printf("\nALTERAR INICIO\n");

                if (!filaCircularVazia(fila)) {
                    printf("Novo nome: ");
                    fgets(p.nome, sizeof(p.nome), stdin);
                    p.nome[strcspn(p.nome, "\n")] = '\0';

                    printf("Novo CPF: ");
                    fgets(p.cpf, sizeof(p.cpf), stdin);
                    p.cpf[strcspn(p.cpf, "\n")] = '\0';

                    if (alterarInicioFilaCircular(fila, p)) {
                        printf("Pessoa alterada!\n");
                    }
                } else {
                    printf("ERRO: fila vazia.\n");
                }
                break;

            case 5:
                printf("\nFila vazia: %s\n",
                       filaCircularVazia(fila) ? "Sim" : "Nao");
                break;

            case 6:
                printf("\nFila cheia: %s\n",
                       filaCircularCheia(fila) ? "Sim" : "Nao");
                break;
                
            case 7:
                imprimirFilaCircular(fila);
                break;

            case 0:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    destruirFilaCircular(&fila);

    printf("Fila destruida. Programa finalizado.\n");

    return 0;
}