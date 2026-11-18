#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estatica.h"
#include "encadeada.h"
#include "pilha.h"
#include "matriz.h"

void listaEstatica(){
    Funcionario vet[QUANTIDADE];
    int n; //total de funcionários cadastrados

    n = lst_cria(); //cria a lista vazia
    n = carregarCSV(vet, n);

    int decisao, antes;

    do{
        mostrarMenu(n);

        decisao = lerInteiro();

        antes = n; //para saber se a lista mudou e precisa ser salva
        switch(decisao){
            case 0: printf("Encerrando...\n"); break;
            case 1: n = opcaoAdicionar(vet, n); break;
            case 2: n = opcaoRemover(vet, n); break;
            case 3: opcaoImprimir(vet, n); break;
            case 4: n = lst_cria(); printf("Todos os funcionários foram excluídos!\n"); break;
            case 5: opcaoListar(vet, n); break;
            default: printf("Opção inválida!\n");
        }

        if(n != antes){
            salvarCSV(vet, n);
        }
    }
    while(decisao != 0);

    return 0;
}

void listaEncadeada(){
    Elemento* lst; //primeiro elemento da lista

    lst = lst_cria(); //cria a lista vazia
    lst = carregarCSV(lst);

    int decisao, antes;

    do{
        mostrarMenu(lst);

        decisao = lerInteiro();

        antes = lst_conta(lst); //para saber se a lista mudou e precisa ser salva
        switch(decisao){
            case 0: printf("Encerrando...\n"); break;
            case 1: lst = opcaoAdicionar(lst); break;
            case 2: lst = opcaoRemover(lst); break;
            case 3: opcaoImprimir(lst); break;
            case 4: lst_libera(lst); lst = lst_cria(); printf("Todos os funcionários foram excluídos!\n"); break;
            case 5: opcaoListar(lst); break;
            default: printf("Opção inválida!\n");
        }

        if(lst_conta(lst) != antes){
            salvarCSV(lst);
        }
    }
    while(decisao != 0);

    lst_libera(lst);

    return 0;
}

void pilha(){
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

void matriz(){
    int matriz1[9];
    int matriz2[9];
    int resultado[9];

    // dimensionar as matrizes para 3x3
    dimensionaMatriz(3, 3);

    // matriz 1
    zeraMatriz(matriz1);
    printf("Matriz 1 zerada:\n");
    imprimeMatriz(matriz1);

    adicionaElemento(matriz1, 15, 1, 1);
    adicionaElemento(matriz1, 25, 2, 2);
    adicionaElemento(matriz1, 35, 3, 3);

    printf("\nMatriz 1 preenchida:\n");
    imprimeMatriz(matriz1);

    // matriz 2 para teste de soma
    zeraMatriz(matriz2);
    printf("\nMatriz 2 zerada:\n");
    imprimeMatriz(matriz2);

    adicionaElemento(matriz2, 5, 1, 1);
    adicionaElemento(matriz2, 5, 2, 2);
    adicionaElemento(matriz2, 5, 3, 3);

    printf("\nMatriz 2 preenchida:\n");
    imprimeMatriz(matriz2);

    // buscar elemento
    printf("\nO elemento que esta na linha 2 e coluna 2 da matriz 1 eh: %d\n",
           buscaElemento(matriz1, 2, 2));

    // somar matrizes
    somaMatriz(matriz1, matriz2, resultado);

    printf("\nSoma das matrizes:\n");
    imprimeMatriz(resultado);

    return 0;
}