#ifndef MATRIZ_H
#define MATRIZ_H

void dimensionaMatriz(int i, int j);
int calculaIndiceMatrizBaseUm(int i, int j);
int calculaIndiceMatrizBaseZero(int i, int j);
void adicionaElemento(int vetor[], int num, int i, int j);
void zeraMatriz(int vetor[]);
int buscaElemento(int vetor[], int i, int j);
int buscaElementoBaseZero(int vetor[], int i, int j);
void imprimeMatriz(int vetor[]);
void imprimeMatrizBaseZero(int vetor[]);
void somaMatriz (int vet1[], int vet2[], int vetResultado[]);

#endif