#ifndef PILHA_H
#define PILHA_H

#define N 50

typedef struct pilha {
    int n;
    float vet[N];
} Pilha;

void pilha_cria(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
int pilha_push(Pilha *p, float valor);
int pilha_pop(Pilha *p, float *valor);

#endif