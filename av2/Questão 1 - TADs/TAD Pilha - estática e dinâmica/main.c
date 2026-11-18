#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
    Pilha* p;
    int opcao;
    float valor;

    p = pilha_cria();

    do{
        printf("\n===== MENU PILHA =====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Verificar se a pilha esta vazia\n");
        printf("4 - Imprimir pilha\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("Digite o valor: ");
                scanf("%f", &valor);

                pilha_push(p, valor);

                printf("Elemento inserido com sucesso!\n");
                break;

            case 2:
                if(pilha_vazia(p)){
                    printf("Pilha vazia. Nao ha elementos para remover.\n");
                }
                else{
                    valor = pilha_pop(p);
                    printf("Elemento removido: %.2f\n", valor);
                }
                break;

            case 3:
                if(pilha_vazia(p)){
                    printf("A pilha esta vazia.\n");
                }
                else{
                    printf("A pilha possui elementos.\n");
                }
                break;

            case 4:
                pilha_imprime(p);
                break;

            case 5:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 5);

    pilha_libera(p);

    return 0;
}