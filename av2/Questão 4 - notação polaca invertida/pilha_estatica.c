#include "pilha.h"

void pilhaCriaNPI(PilhaNPI *p) {
    p->n = 0;
}

int pilhaVaziaNPI(PilhaNPI *p) {
    return p->n == 0;
}

int pilhaCheiaNPI(PilhaNPI *p) {
    return p->n == N;
}

int pilhaPushNPI(PilhaNPI *p, float valor) {
    if (pilhaCheiaNPI(p)) {
        return 0;
    }

    p->vet[p->n] = valor;
    p->n++;

    return 1;
}

int pilhaPopNPI(PilhaNPI *p, float *valor) {
    if (pilhaVaziaNPI(p)) {
        return 0;
    }

    p->n--;
    *valor = p->vet[p->n];

    return 1;
}