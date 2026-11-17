#include <stdio.h>
#include "matriz.h"

int linhas = 0;
int colunas = 0;

void dimensionaMatriz(int i, int j){
    linhas = i;
    colunas = j;
}

// fórmula de base 1
int calculaIndiceMatrizBaseUm(int i, int j){
    return (i - 1) * colunas + (j - 1);
}

// fórmula de base 0
int calculaIndiceMatrizBaseZero(int i, int j){
    return i * colunas + j;
}

void adicionaElemento(int vetor[], int num, int i, int j){
    vetor[calculaIndiceMatrizBaseUm(i, j)] = num;
}

void zeraMatriz(int vetor[]){
    int linha, coluna;

    for (linha = 1; linha <= linhas; linha++){
        for (coluna = 1; coluna <= colunas; coluna++){
            adicionaElemento(vetor, 0, linha, coluna);
        }
    }
}

int buscaElemento(int vetor[], int i, int j){
    return vetor[calculaIndiceMatrizBaseUm(i, j)];
}

int buscaElementoBaseZero(int vetor[], int i, int j){
	return vetor[calculaIndiceMatrizBaseZero(i, j)];
}

void imprimeMatriz(int vetor[]){
    int linha, coluna;

    for (linha = 1; linha <= linhas; linha++){
        for (coluna = 1; coluna <= colunas; coluna++){
            printf("%d ", buscaElemento(vetor, linha, coluna));
        }
        printf("\n");
    }
}

void imprimeMatrizBaseZero(int vetor[]){
    int linha, coluna;

    for(linha = 0; linha < linhas; linha++){
        for(coluna = 0; coluna < colunas; coluna++){
            printf("%d ", buscaElementoBaseZero(vetor, linha, coluna));
        }
        printf("\n");
    }
}

void somaMatriz (int vet1[], int vet2[], int vetResultado[]){
	int linha, coluna, acesso;
	for(linha = 1; linha <= linhas; linha++){
		for(coluna = 1; coluna <= colunas; coluna++){
			acesso = calculaIndiceMatrizBaseUm(linha, coluna);
			vetResultado[acesso] = vet1[acesso] + vet2[acesso];
		}
	}
}