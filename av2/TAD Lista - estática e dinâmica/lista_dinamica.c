#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

// LISTA ENCADEADA (DINAMICA)

// nó da lista
struct elemento{
    int info;
    struct elemento* prox;
};

typedef struct elemento Elemento;

// estrutura da lista
struct lista{
    Elemento* prim;
    int qtde;
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
    lista->prim = NULL;
    lista->qtde = 0;
}

// verifica se a lista esta vazia
int listaVazia(Lista* lista){
    return lista->prim == NULL;
}

// verifica se a lista esta cheia
int listaCheia(Lista* lista){
    return 0;
}

// insere um elemento no inicio
int insereInicio(Lista* lista, int novoDado){
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));

    if(novo == NULL){
        return 0;
    }

    novo->info = novoDado;
    novo->prox = lista->prim;
    lista->prim = novo;

    lista->qtde++;

    return 1;
}

// insere um elemento no final
int insereFinal(Lista* lista, int novoDado){
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    Elemento* p;

    if(novo == NULL){
        return 0;
    }

    novo->info = novoDado;
    novo->prox = NULL;

    if(listaVazia(lista)){
        lista->prim = novo;
    }
    else{
        p = lista->prim;

        while(p->prox != NULL){
            p = p->prox;
        }

        p->prox = novo;
    }

    lista->qtde++;

    return 1;
}

// insere um elemento em qualquer posicao
int inserePosicao(Lista* lista, int k, int novoDado){
    Elemento* novo;
    Elemento* p;
    int i;

    if(k < 1 || k > lista->qtde + 1){
        printf("ERRO: Indice fora dos limites!\n");
        return 0;
    }

    if(k == 1){
        return insereInicio(lista, novoDado);
    }

    novo = (Elemento*)malloc(sizeof(Elemento));

    if(novo == NULL){
        return 0;
    }

    p = lista->prim;

    for(i=1; i<k-1; i++){
        p = p->prox;
    }

    novo->info = novoDado;
    novo->prox = p->prox;
    p->prox = novo;

    lista->qtde++;

    return 1;
}

// insere um elemento em ordem crescente
int insereOrdenado(Lista* lista, int novoDado){
    Elemento* novo;
    Elemento* a = NULL;
    Elemento* p = lista->prim;

    while(p != NULL && p->info < novoDado){
        a = p;
        p = p->prox;
    }

    novo = (Elemento*)malloc(sizeof(Elemento));

    if(novo == NULL){
        return 0;
    }

    novo->info = novoDado;

    if(a == NULL){
        novo->prox = lista->prim;
        lista->prim = novo;
    }
    else{
        novo->prox = a->prox;
        a->prox = novo;
    }

    lista->qtde++;

    return 1;
}

// exclui um elemento pela posicao
int excluiElemento(Lista* lista, int k){
    Elemento* p;
    Elemento* a = NULL;
    int i;

    if(k < 1 || k > lista->qtde){
        printf("ERRO: Indice fora dos limites!\n");
        return 0;
    }

    p = lista->prim;

    for(i=1; i<k; i++){
        a = p;
        p = p->prox;
    }

    if(a == NULL){
        lista->prim = p->prox;
    }
    else{
        a->prox = p->prox;
    }

    free(p);
    lista->qtde--;

    return 1;
}

// acessa um elemento pela posicao
int acessaElemento(Lista* lista, int k, int* dado){
    Elemento* p;
    int i;

    if(k < 1 || k > lista->qtde){
        printf("ERRO: Indice fora dos limites!\n");
        return 0;
    }

    p = lista->prim;

    for(i=1; i<k; i++){
        p = p->prox;
    }

    *dado = p->info;

    return 1;
}

// altera um elemento pela posicao
int alteraElemento(Lista* lista, int k, int novoDado){
    Elemento* p;
    int i;

    if(k < 1 || k > lista->qtde){
        printf("ERRO: Indice fora dos limites!\n");
        return 0;
    }

    p = lista->prim;

    for(i=1; i<k; i++){
        p = p->prox;
    }

    p->info = novoDado;

    return 1;
}

// busca um elemento pelo conteudo
int buscaElemento(Lista* lista, int dado){
    Elemento* p;
    int posicao = 1;

    for(p=lista->prim; p!=NULL; p=p->prox){
        if(p->info == dado){
            return posicao;
        }

        posicao++;
    }

    return -1;
}

// imprime todos os elementos da lista
void imprimeLista(Lista* lista){
    Elemento* p;
    int i = 1;

    if(listaVazia(lista)){
        printf("Lista vazia.\n");
        return;
    }

    printf("\n+-- LISTA --+\n");

    for(p=lista->prim; p!=NULL; p=p->prox){
        printf("[%d] %d\n", i, p->info);
        i++;
    }

    printf("+-----------+\n");
}

// destroi a lista
void destroiLista(Lista* lista){
    Elemento* p = lista->prim;

    while(p != NULL){
        Elemento* t = p->prox;
        free(p);
        p = t;
    }

    free(lista);
}