#ifndef ESTATICA_H
#define ESTATICA_H

//TAD Lista estática de funcionários, ordenada por matrícula

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

//funções responsáveis pela leitura de dados digitados pelo usuário

//repete a pergunta até o usuário digitar um número inteiro
int lerInteiro(void);

//repete a pergunta até o usuário digitar um número decimal
float lerDecimal(void);

//a vírgula é o separador do CSV, então não pode aparecer dentro do nome
void limparVirgulas(char texto[]);

//operações da lista estática

//retorna uma lista vazia
int lst_cria(void);

//retorna 1 se vazia ou 0 se não vazia
int lst_vazia(int n);

//retorna 1 se não há mais espaço no vetor ou 0 se ainda há
int lst_cheia(int n);

//busca binária, retorna a posição do funcionário ou -1 se não achou
int lst_busca(Funcionario vet[], int n, int matricula);

//insere o funcionário em ordem de matrícula, retorna o total atualizado
int lst_insere_ordenado(Funcionario vet[], int n, Funcionario f);

//retira o funcionário pela matrícula, retorna o total atualizado
int lst_retira(Funcionario vet[], int n, int matricula);

//imprime uma linha por funcionário com suas informações
void lst_imprime(Funcionario vet[], int n);

//funções responsáveis pelo gerenciamento do CSV

//grava a lista inteira no CSV e retorna 1 caso dê certo, e 0 caso não dê certo
int salvarCSV(Funcionario vet[], int n);

//lê o arquivo para a lista e retorna o total atualizado
int carregarCSV(Funcionario vet[], int n);

//menu e opções

//mostra o menu principal, que ficará visível para o usuário
void mostrarMenu(int n);

//cada opção que altera a lista retorna o n atualizado
int opcaoAdicionar(Funcionario vet[], int n);
int opcaoRemover(Funcionario vet[], int n);

void opcaoImprimir(Funcionario vet[], int n);
void opcaoListar(Funcionario vet[], int n);

#endif
