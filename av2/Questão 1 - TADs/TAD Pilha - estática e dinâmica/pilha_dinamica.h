#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

// pilha de valores reais
typedef struct pilha Pilha;

Pilha* pilhaDinCria(void);
void pilhaDinPush(Pilha* p, float v);
float pilhaDinPop(Pilha* p);
int pilhaDinVazia(Pilha* p);
void pilhaDinLibera(Pilha* p);
void pilhaDinImprime(Pilha* p);

#endif