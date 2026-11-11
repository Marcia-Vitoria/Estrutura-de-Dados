#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

// LISTA LINEAR (ESTATICA)

#define TAM_MAX 5

struct lista{
    int qtde;
    int elemt[TAM_MAX];
};

// cria a lista
Lista* criaLista(void){
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    if(lista == NULL){
        exit(1);
    }

    iniciaLista(lista);

    return lista;
}

// inicializa a lista
void iniciaLista(Lista* lista){
    lista->qtde = 0;
}

// verifica se a lista está vazia
int listaVazia(Lista* lista){
    return lista->qtde == 0;
}

// verifica se a lista esta cheia
int listaCheia(Lista* lista){
    return lista->qtde == TAM_MAX;
}

// insere um elemento no início
int insereInicio(Lista* lista, int novoDado){
    int i;

    if(listaCheia(lista)){
        printf("ERRO: Lista ja completa!\n");
        return 0;
    }

    for(i=lista->qtde; i>0; i--){
        lista->elemt[i] = lista->elemt[i-1];
    }

    lista->elemt[0] = novoDado;
    lista->qtde++;

    return 1;
}

// insere um elemento no final
int insereFinal(Lista* lista, int novoDado){
    if(listaCheia(lista)){
        printf("ERRO: Lista ja completa!\n");
        return 0;
    }

    lista->elemt[lista->qtde] = novoDado;
    lista->qtde++;

    return 1;
}

// insere um elemento em qualquer posição
int inserePosicao(Lista* lista, int k, int novoDado){
    int i;

    if(listaCheia(lista) || k < 1 || k > lista->qtde + 1){
        printf("ERRO: Lista cheia ou indice fora dos limites!\n");
        return 0;
    }

    for(i=lista->qtde; i>=k; i--){
        lista->elemt[i] = lista->elemt[i-1];
    }

    lista->elemt[k-1] = novoDado;
    lista->qtde++;

    return 1;
}

// insere um elemento em ordem crescente
int insereOrdenado(Lista* lista, int novoDado){
    int i;

    if(listaCheia(lista)){
        printf("ERRO: Lista ja completa!\n");
        return 0;
    }

    i = lista->qtde;

    while(i > 0 && lista->elemt[i-1] > novoDado){
        lista->elemt[i] = lista->elemt[i-1];
        i--;
    }

    lista->elemt[i] = novoDado;
    lista->qtde++;

    return 1;
}

// exclui um elemento pela posição
int excluiElemento(Lista* lista, int k){
    int i;

    if(k < 1 || k > lista->qtde){
        printf("ERRO: Indice fora dos limites!\n");
        return 0;
    }

    for(i=k-1; i<lista->qtde-1; i++){
        lista->elemt[i] = lista->elemt[i+1];
    }

    lista->qtde--;

    return 1;
}

// acessa um elemento pela posição
int acessaElemento(Lista* lista, int k, int* dado){
    if(k < 1 || k > lista->qtde){
        printf("ERRO: Indice fora dos limites!\n");
        return 0;
    }

    *dado = lista->elemt[k-1];

    return 1;
}

// altera um elemento pela posição
int alteraElemento(Lista* lista, int k, int novoDado){
    if(k < 1 || k > lista->qtde){
        printf("ERRO: Indice fora dos limites!\n");
        return 0;
    }

    lista->elemt[k-1] = novoDado;

    return 1;
}

// busca um elemento pelo conteudo
int buscaElemento(Lista* lista, int dado){
    int i;

    for(i=0; i<lista->qtde; i++){
        if(lista->elemt[i] == dado){
            return i+1;
        }
    }

    return -1;
}

// imprime todos os elementos da lista
void imprimeLista(Lista* lista){
    int i;

    if(listaVazia(lista)){
        printf("Lista vazia.\n");
        return;
    }

    printf("\n+-- LISTA --+\n");

    for(i=0; i<lista->qtde; i++){
        printf("[%d] %d\n", i+1, lista->elemt[i]);
    }

    printf("+-----------+\n");
}

// destrói a lista
void destroiLista(Lista* lista){
    free(lista);
}