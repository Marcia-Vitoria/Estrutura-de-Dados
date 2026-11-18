#ifndef PILHA_H
#define PILHA_H

#define N 50

typedef struct pilha {
    int n;
    float vet[N];
} PilhaNPI;

void pilhaCriaNPI(PilhaNPI *p);
int pilhaVaziaNPI(PilhaNPI *p);
int pilhaCheiaNPI(PilhaNPI *p);
int pilhaPushNPI(PilhaNPI *p, float valor);
int pilhaPopNPI(PilhaNPI *p, float *valor);

#endif