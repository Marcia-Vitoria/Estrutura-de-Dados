#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// IMPLEMENTAÇÃO COM VETOR (ESTÁTICA)
#define N 50

struct pilha{
    int n;
    float vet[N];
};

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if(p==NULL){
        exit(1);
    }

    p->n=0; // inicializa com zero elementos
    return p;
}

int pilha_vazia(Pilha* p){
    return p->n == 0;
}

void pilha_libera(Pilha* p){
    free(p);
}

void pilha_push(Pilha* p, float v){
    if(p->n==N){ // capacidade esgotada
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }

    // insere elemento na próxima posição livre
    p->vet[p->n]=v;
    p->n++;
}

float pilha_pop(Pilha* p){
    float v;

    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }

    v=p->vet[p->n-1];
    p->n--;

    return v;
}

void pilha_imprime(Pilha* p){
    int i;

    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return;
    }

    printf("\n+-- PILHA --+\n");
    printf("Topo\n");

    for(i=p->n-1; i>=0; i--){
        printf("| %.2f |\n", p->vet[i]);
    }

    printf("+-----+\n");
    printf("Base\n");
}