#include <stdio.h>

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

void somaMatriz (int vet1[], int vet2[], int vetResultado[]) {
	int linha, coluna, acesso;
	for(linha = 1; linha <= linhas; linha++){
		for(coluna = 1; coluna <= colunas; coluna++){
			acesso = calculaIndiceMatrizBaseUm(linha, coluna);
			vetResultado[acesso] = vet1[acesso] + vet2[acesso];
		}
	}
}

// Questão 1
// i. cidades isoladas, isto é, as que não têm ligação com nenhuma outra
int contarEntradas(int vetor[], int cidade){
    int cont = 0;
    int k;

    for(k = 0; k < colunas; k++){
        if(k != cidade && buscaElementoBaseZero(vetor, k, cidade) == 1){
            cont++;
        }
    }

    return cont;
}

int contarSaidas(int vetor[], int cidade){
    int cont = 0;
    int k;

    for(k = 0; k < colunas; k++){
        if(k != cidade && buscaElementoBaseZero(vetor, cidade, k) == 1){
            cont++;
        }
    }

    return cont;
}

void cidadesIsoladas(int vetor[]){
    int encontrada = 0;
    int k;

    for(k = 0; k < colunas; k++){
        if(contarSaidas(vetor, k) == 0 && contarEntradas(vetor, k) == 0){
            printf("Cidade %d isolada\n", k);
            encontrada = 1;
        }
    }

    if(encontrada == 0){
        printf("Nenhuma cidade isolada\n");
    }
}


// ii. cidades das quais não há saída, apesar de haver entrada
void semSaidaComEntrada(int vetor[]){
    int encontrada = 0;
    int k;

    for(k = 0; k < colunas; k++){
        if(contarSaidas(vetor, k) == 0 && contarEntradas(vetor, k) > 0){
            printf("Cidade %d nao ha saida apesar de haver entrada\n", k);
            encontrada = 1;
        }
    }

    if(encontrada == 0){
        printf("Nenhuma cidade sem saida e que possua entrada\n");
    }
}


// iii. cidades das quais há saída sem haver entrada
void comSaidaSemEntrada(int vetor[]){
    int encontrada = 0;
    int k;

    for(k = 0; k < colunas; k++){
        if(contarSaidas(vetor, k) > 0 && contarEntradas(vetor, k) == 0){
            printf("Cidade %d ha saida e nao ha entrada\n", k);
            encontrada = 1;
        }
    }

    if(encontrada == 0){
        printf("Nenhuma cidade com saida e que nao possua entrada\n");
    }
}


// iv. qual das cidades chega o maior número de estradas
int cidadeMaiorEntrada(int vetor[]){
    int cidade = 0;
    int maior = 0;
    int entradas;
    int j;

    for(j = 0; j < colunas; j++){
        entradas = contarEntradas(vetor, j);

        if(entradas > maior){ // em caso de empate, retorna a primeira cidade encontrada
            maior = entradas;
            cidade = j;
        }
    }

    return cidade;
}


// v. relacionar as cidades que possuem saídas diretas para a cidade k
void saidasDiretasParaK(int vetor[], int k){
    int i;

    printf("\nCidade(s) que possuem saidas diretas para a cidade %d:\n", k);

    for(i = 0; i < linhas; i++){
        if(i != k && buscaElementoBaseZero(vetor, i, k) == 1){ // não considera a própria cidade como uma cidade que possui saída para ela mesma
            printf("Cidade %d\n", i);
        }
    }
}

/* vi. dada uma sequência de m inteiros cujos valores estão entre 0 e n-1, verificar se é 
possível realizar o roteiro correspondente. No exemplo dado, o roteiro representado pela 
sequência (m=5) 2 3 2 1 0 é impossível.*/
void verificaRoteiro(int vetor[], int roteiro[], int m){
	int i;
	int possivel = 1;
	for(i = 0; i < m - 1; i++){
		if(buscaElementoBaseZero(vetor, roteiro[i], roteiro[i+1]) == 0){
			possivel = 0;
		}
	}
	
	if(possivel == 1){
		printf("\nRoteiro possivel\n");
	}
	else{
		printf("\nRoteiro impossivel\n");
	}
}

int main() {
	// dimensionar a matriz para 3x3
    dimensionaMatriz(3, 3);
    int tam = linhas * colunas;
    
    int vet1[tam];
    int vet2[tam];
    int vetResultado[tam];

    // matriz 1
    zeraMatriz(vet1);
    printf("Matriz 1 zerada:\n");
    imprimeMatriz(vet1);

    adicionaElemento(vet1, 15, 1, 1);
    adicionaElemento(vet1, 25, 2, 2);
    adicionaElemento(vet1, 35, 3, 3);

    printf("\nMatriz 1 preenchida:\n");
    imprimeMatriz(vet1);

    // matriz 2 para teste de soma
    zeraMatriz(vet2);
    printf("\nMatriz 2 zerada:\n");
    imprimeMatriz(vet2);

    adicionaElemento(vet2, 5, 1, 1);
    adicionaElemento(vet2, 5, 2, 2);
    adicionaElemento(vet2, 5, 3, 3);

    printf("\nMatriz 2 preenchida:\n");
    imprimeMatriz(vet2);

    // buscar elemento
    printf("\nO elemento que esta na linha 2 e coluna 2 da matriz 1 eh: %d\n", buscaElemento(vet1, 2, 2));

    // somar matrizes
    somaMatriz(vet1, vet2, vetResultado);
    printf("\nSoma das matrizes:\n");
    imprimeMatriz(vetResultado);

    int matriz[25];
    int roteiro[5];
    int n;
    int i, j;
    int k;
    int m;
    int valor;
    int resultado;

    printf("Digite a ordem da matriz (maximo 5): ");
    scanf("%d", &n);

    if(n < 1 || n > 5) {
        printf("Ordem invalida!\n");
        return 0;
    }

    dimensionaMatriz(n, n);

    printf("\nDigite os valores da matriz:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("L[%d][%d]: ", i, j);
            scanf("%d", &valor);

            matriz[calculaIndiceMatrizBaseZero(i, j)] = valor;
        }
    }

    printf("\nMatriz informada:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", buscaElementoBaseZero(matriz, i, j));
        }

        printf("\n");
    }

    // i. cidades isoladas
    printf("\nITEM I\n");
    cidadesIsoladas(matriz);

    // ii. cidades sem saida, apesar de haver entrada
    printf("\nITEM II\n");
    semSaidaComEntrada(matriz);

    // iii. cidades com saida sem entrada
    printf("\nITEM III\n");
    comSaidaSemEntrada(matriz);

    // iv. cidade que recebe o maior numero de estradas
    printf("\nITEM IV\n");

    resultado = cidadeMaiorEntrada(matriz, n);

    printf("Cidade que recebe o maior numero de estradas: %d\n", resultado);

    // v. cidades que possuem saidas diretas para a cidade k
    printf("\nITEM V\n");

    printf("Digite a cidade k (0 a %d): ", n - 1);
    scanf("%d", &k);

    if(k >= 0 && k < n) {
        saidasDiretasParaK(matriz, k);
    }
    else {
        printf("Cidade invalida!\n");
    }

    // vi. verificar se o roteiro e possivel
    printf("\nITEM VI\n");

    printf("Digite a quantidade de cidades do roteiro (maximo 5): ");
    scanf("%d", &m);

    if(m < 1 || m > 5) {
        printf("Quantidade invalida!\n");
        return 0;
    }

    printf("Digite as cidades do roteiro (0 a %d):\n", n - 1);

    for(i = 0; i < m; i++) {
        printf("Cidade %d: ", i + 1);
        scanf("%d", &roteiro[i]);

        if(roteiro[i] < 0 || roteiro[i] >= n) {
            printf("Cidade invalida!\n");
            return 0;
        }
    }

    verificaRoteiro(matriz, roteiro, m);

    return 0;
}