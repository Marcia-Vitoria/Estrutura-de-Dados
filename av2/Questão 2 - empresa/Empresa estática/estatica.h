#ifndef ESTATICA_H
#define ESTATICA_H

//TAD Lista estática de funcionários, ordenada por matrícula

#define QUANTIDADE 15
#define ARQUIVO "funcionarios.csv"

//struct com as informações do funcionário para o preenchimento de sua ficha
struct fichaFuncionarioEst{
    char nome[50];
    int matricula;
    int idade;
    float salario;
};
typedef struct fichaFuncionarioEst FuncionarioEst;

//funções responsáveis pela leitura de dados digitados pelo usuário

//repete a pergunta até o usuário digitar um número inteiro
int lerInteiroEst(void);

//repete a pergunta até o usuário digitar um número decimal
float lerDecimalEst(void);

//a vírgula é o separador do CSV, então não pode aparecer dentro do nome
void limparVirgulasEst(char texto[]);

//operações da lista estática

//retorna uma lista vazia
int lstEstCria(void);

//retorna 1 se vazia ou 0 se não vazia
int lstEstVazia(int n);

//retorna 1 se não há mais espaço no vetor ou 0 se ainda há
int lstEstCheia(int n);

//busca binária, retorna a posição do funcionário ou -1 se não achou
int lstEstBusca(FuncionarioEst vet[], int n, int matricula);

//insere o funcionário em ordem de matrícula, retorna o total atualizado
int lstEstInsereOrdenado(FuncionarioEst vet[], int n, FuncionarioEst f);

//retira o funcionário pela matrícula, retorna o total atualizado
int lstEstRetira(FuncionarioEst vet[], int n, int matricula);

//imprime uma linha por funcionário com suas informações
void lstEstImprime(FuncionarioEst vet[], int n);

//funções responsáveis pelo gerenciamento do CSV

//grava a lista inteira no CSV e retorna 1 caso dê certo, e 0 caso não dê certo
int salvarCSVEst(FuncionarioEst vet[], int n);

//lê o arquivo para a lista e retorna o total atualizado
int carregarCSVEst(FuncionarioEst vet[], int n);

//menu e opções

//mostra o menu principal, que ficará visível para o usuário
void mostrarMenuEst(int n);

//cada opção que altera a lista retorna o n atualizado
int opcaoAdicionarEst(FuncionarioEst vet[], int n);
int opcaoRemoverEst(FuncionarioEst vet[], int n);

void opcaoImprimirEst(FuncionarioEst vet[], int n);
void opcaoListarEst(FuncionarioEst vet[], int n);

#endif
