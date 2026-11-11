#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main(void){
    Lista* lista;
    int opcao;
    int valor;
    int posicao;
    int resultado;

    lista = criaLista();

    do{
        printf("\n===== MENU LISTA =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir em uma posicao\n");
        printf("4 - Excluir elemento\n");
        printf("5 - Acessar elemento\n");
        printf("6 - Alterar elemento\n");
        printf("7 - Buscar elemento\n");
        printf("8 - Imprimir lista\n");
        printf("9 - Verificar se a lista esta vazia ou cheia\n");
        printf("10 - Inserir em ordem crescente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);

                if(insereInicio(lista, valor)){
                    printf("Elemento inserido com sucesso!\n");
                }
                break;

            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);

                if(insereFinal(lista, valor)){
                    printf("Elemento inserido com sucesso!\n");
                }
                break;

            case 3:
                printf("Digite a posicao: ");
                scanf("%d", &posicao);

                printf("Digite o valor: ");
                scanf("%d", &valor);

                if(inserePosicao(lista, posicao, valor)){
                    printf("Elemento inserido com sucesso!\n");
                }
                break;

            case 4:
                printf("Digite a posicao que deseja excluir: ");
                scanf("%d", &posicao);

                if(excluiElemento(lista, posicao)){
                    printf("Elemento excluido com sucesso!\n");
                }
                break;

            case 5:
                printf("Digite a posicao que deseja acessar: ");
                scanf("%d", &posicao);

                if(acessaElemento(lista, posicao, &valor)){
                    printf("Elemento encontrado: %d\n", valor);
                }
                break;

            case 6:
                printf("Digite a posicao que deseja alterar: ");
                scanf("%d", &posicao);

                printf("Digite o novo valor: ");
                scanf("%d", &valor);

                if(alteraElemento(lista, posicao, valor)){
                    printf("Elemento alterado com sucesso!\n");
                }
                break;

            case 7:
                printf("Digite o valor que deseja buscar: ");
                scanf("%d", &valor);

                resultado = buscaElemento(lista, valor);

                if(resultado == -1){
                    printf("Elemento nao encontrado.\n");
                }
                else{
                    printf("Elemento encontrado na posicao %d.\n", resultado);
                }
                break;

            case 8:
                imprimeLista(lista);
                break;

            case 9:
                if(listaVazia(lista)){
                    printf("A lista esta vazia.\n");
                }
                else if(listaCheia(lista)){
                    printf("A lista esta cheia.\n");
                }
                break;
                
            case 10:
                printf("Digite o valor: ");
                scanf("%d", &valor);
            
                if(insereOrdenado(lista, valor)){
                    printf("Elemento inserido em ordem crescente!\n");
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    destroiLista(lista);

    return 0;
}