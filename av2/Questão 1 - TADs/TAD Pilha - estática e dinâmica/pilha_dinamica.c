#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"
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
Pilha* pilhaDinCria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));

    if(p==NULL){
        exit(1);
    }

    p->prim=NULL;
    return p;
}

// insere um novo elemento no topo da pilha
void pilhaDinPush(Pilha* p, float v){
    Elemento* n = (Elemento*)malloc(sizeof(Elemento));

    if(n==NULL){
        exit(1);
    }

    n->info=v;
    n->prox=p->prim;
    p->prim=n;
}

// ver se a pilha está vazia
int pilhaDinVazia(Pilha* p){
    if(p->prim == NULL){
        return 1; // vazia
    }

    return 0; // não vazia
}

// remove e retorna o elemento que está no topo da pilha
float pilhaDinPop(Pilha* p){
    Elemento* t;
    float v;

    if(pilhaDinVazia(p)){
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
void pilhaDinLibera(Pilha* p){
    Elemento *t, *q = p->prim;

    while(q!=NULL){
        t=q->prox;
        free(q);
        q=t;
    }

    free(p);
}

// imprime a pilha
void pilhaDinImprime(Pilha* p){
    Elemento* q;

    if(pilhaDinVazia(p)){
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