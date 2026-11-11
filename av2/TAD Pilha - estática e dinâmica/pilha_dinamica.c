#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
// last in, first out
// IMPLEMENTAÇÃO COM ENCADEAMENTO (DINÂMICA)

// nó da lista para armazenar valores reais
struct elemento{
    float info;
    struct elemento *prox;
};

typedef struct elemento Elemento;

// estrutura da pilha
struct pilha{
    Elemento* prim; // aponta para o topo da pilha
};

// cria uma pilha vazia e inicializa sua estrutura
Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));

    if(p==NULL){
        exit(1);
    }

    p->prim=NULL;
    return p;
}

// insere um novo elemento no topo da pilha
void pilha_push(Pilha* p, float v){
    Elemento* n = (Elemento*)malloc(sizeof(Elemento));

    if(n==NULL){
        exit(1);
    }

    n->info=v;
    n->prox=p->prim;
    p->prim=n;
}

// remove e retorna o elemento que está no topo da pilha
float pilha_pop(Pilha* p){
    Elemento* t;
    float v;

    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }

    t=p->prim;
    v=t->info;
    p->prim=t->prox;

    free(t);

    return v;
}

// libera a memória utilizada pela pilha
void pilha_libera(Pilha* p){
    Elemento *t, *q = p->prim;

    while(q!=NULL){
        t=q->prox;
        free(q);
        q=t;
    }

    free(p);
}

// ver se a pilha está vazia
int pilha_vazia(Pilha* p){
    if(p->prim == NULL){
        return 1; // vazia
    }

    return 0; // não vazia
}

// imprime a pilha
void pilha_imprime(Pilha* p){
    Elemento* q;

    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return;
    }

    printf("\n+-- PILHA --+\n");
    printf("Topo\n");

    q=p->prim;

    while(q!=NULL){
        printf("| %.2f |\n", q->info);
        q=q->prox;
    }

    printf("+-----+\n");
    printf("Base\n");
}