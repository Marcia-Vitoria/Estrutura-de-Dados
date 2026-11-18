#ifndef ENCADEADA_H
#define ENCADEADA_H

//TAD Lista encadeada de funcionários, ordenada por matrícula
#define QUANTIDADE 15
#define ARQUIVO "funcionarios.csv"

//struct com as informações do funcionário para o preenchimento de sua ficha
struct fichaFuncionario{
    char nome[50];
    int matricula;
    int idade;
    float salario;
};
typedef struct fichaFuncionario Funcionario;

//o campo info é um ponteiro para a ficha, em lugar da ficha
struct elemento{
    Funcionario* info;
    struct elemento* prox;
};
typedef struct elemento Elemento;

//funções responsáveis pela leitura de dados digitados pelo usuário

//repete a pergunta até o usuário digitar um número inteiro
int lerInteiro(void);

//repete a pergunta até o usuário digitar um número decimal
float lerDecimal(void);

//a vírgula é o separador do CSV, então não pode aparecer dentro do nome
void limparVirgulas(char texto[]);

//operações da lista encadeada

//retorna uma lista vazia
Elemento* lst_cria(void);

//retorna 1 se vazia ou 0 se não vazia
int lst_vazia(Elemento* lst);

//retorna quantos elementos a lista possui
int lst_conta(Elemento* lst);

//retorna o nó do funcionário com essa matrícula, ou NULL se não achou
Elemento* lst_busca(Elemento* lst, int matricula);

//insere elemento em ordem de matrícula, retorna a lista atualizada
Elemento* lst_insere_ordenado(Elemento* lst, Funcionario f);

//retira elemento da lista, retorna a lista atualizada
Elemento* lst_retira(Elemento* lst, int matricula);

//imprime valores dos elementos
void lst_imprime(Elemento* lst);

//libera todos os elementos alocados
void lst_libera(Elemento* lst);

//funções responsáveis pelo gerenciamento do CSV

//grava a lista inteira no CSV e retorna 1 caso dê certo, e 0 caso não dê certo
int salvarCSV(Elemento* lst);

//lê o arquivo e retorna a lista atualizada
Elemento* carregarCSV(Elemento* lst);

//menu e opções

//mostra o menu principal, que ficará visível para o usuário
void mostrarMenu(Elemento* lst);

//cada opção que altera a lista retorna a lista atualizada
Elemento* opcaoAdicionar(Elemento* lst);
Elemento* opcaoRemover(Elemento* lst);

void opcaoImprimir(Elemento* lst);
void opcaoListar(Elemento* lst);

#endif