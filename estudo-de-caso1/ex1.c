// Estudo de caso 1 - Estrutura de Dados
//// abstração e implementação da estrutura de dados matriz utilizando vetor

#include <stdio.h>

int linhas;
int colunas;

//dimensionar a matriz
void dimensionaMatriz(int i, int j){
	linhas = i;
	colunas = j;
}

//zerar a matriz
void zeraMatriz(int vetor[]){
	int i;
	for (i = 0; i < linhas * colunas; i++){
    	vetor[i] = 0;
	}
}

//imprimir a matriz
void imprimeMatriz(int vetor[]){
	int i, j;
	int indice;
	
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			indice = i * colunas + j;
			printf("%d ", vetor[indice]);
		}
		printf("\n");
	}
}

//preencher a matriz
void adicionaElemento(int vetor[], int num, int i, int j){
	int indice;
	indice = (i - 1) * colunas + (j - 1);
	vetor[indice] = num;
}

//buscar o elemento
int buscaElemento(int vetor[], int i, int j){
	int indice = (i - 1) * colunas + (j - 1);
	return vetor[indice];
}

//somar duas matrizes
void somaMatriz(int vetor1[], int vetor2[], int resultado[]) {
    int i;
    
    for (i = 0; i < linhas * colunas; i++) {
        resultado[i] = vetor1[i] + vetor2[i];
    }
}

/* 
fórmula para mapear coordenadas 2D (base 0) em um índice 1D:
k= i*c + j

k = indice
c = tamanho do vetor
i = qtd linhas
j = qtd colunas
*/


/* 
fórmula para mapear coordenadas 2D (base 1) em um índice 1D (base 0):
k = (i - 1) * c + (j - 1)

k = indice do vetor
i = linha desejada (base 1)
j = coluna desejada (base 1)
c = quantidade total de colunas
*/

void main(){
	//dimensiona a matriz
	dimensionaMatriz(3, 3);
	int tam = linhas * colunas;
    int vet1[tam];
    int vet2[tam];
    int vetResultado[tam];
	
	//"zera a matriz"
	zeraMatriz(vet1);
	
	//imprime a matriz "zerada"
	printf("Matriz 1 zerada:\n");
	imprimeMatriz(vet1);
	
	//preenche matriz
	adicionaElemento(vet1, 15, 1, 1);
	adicionaElemento(vet1, 25, 2, 2);
	adicionaElemento(vet1, 35, 3, 3);
	
	//imprime a matriz "preenchida"
	printf("Matriz 1 preenchida:\n");
	imprimeMatriz(vet1);
	
	//"zera a matriz"
	printf("Matriz 2 zerada:\n");
	zeraMatriz(vet2);
	
	//imprime a matriz "zerada"
	imprimeMatriz(vet2);
	
	//preenche a segunda matriz para teste de soma
	adicionaElemento(vet2, 5, 1, 1);
	adicionaElemento(vet2, 5, 2, 2);
	adicionaElemento(vet2, 5, 3, 3);
	
	//imprime a matriz "preenchida"
	printf("Matriz 2 preenchida:\n");
	imprimeMatriz(vet2);
	
	printf("\n");
	printf("O elemento que esta na linha 2 e coluna 2 da matriz 1 eh: %d\n\n", buscaElemento(vet1, 2, 2));
	
	printf("Soma das matrizes:\n");
	//soma as matrizes
	somaMatriz(vet1, vet2, vetResultado);
	//imprime o resultado da soma
	imprimeMatriz(vetResultado);
}