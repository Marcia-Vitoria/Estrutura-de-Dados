#include "pilha.h"

void pilha_cria(Pilha *p) {
    p->n = 0;
}

int pilha_vazia(Pilha *p) {
    return p->n == 0;
}

int pilha_cheia(Pilha *p) {
    return p->n == N;
}

int pilha_push(Pilha *p, float valor) {
    if (pilha_cheia(p)) {
        return 0;
    }

    p->vet[p->n] = valor;
    p->n++;

    return 1;
}

int pilha_pop(Pilha *p, float *valor) {
    if (pilha_vazia(p)) {
        return 0;
    }

    p->n--;
    *valor = p->vet[p->n];

    return 1;
}