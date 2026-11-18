#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estatica.h"
#include "encadeada.h"

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