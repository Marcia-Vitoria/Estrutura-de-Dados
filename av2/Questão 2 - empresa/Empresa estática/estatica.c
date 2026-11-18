/*
    Estrutura de Dados:

    Lista estática de funcionários, ordenada por matrícula,
    usando struct e vetor com alocação estática de memória.
    As operações seguem o modelo visto em aula.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estatica.h"

//impede que o usuário digite caracteres ao tentar acessar a matrícula ou a idade
int lerInteiroEst(void){
    int valor;
    while(scanf("%d", &valor) != 1){
        while(getchar() != '\n');
        printf("Entrada invalida! Digite um numero: ");
    }

    return valor;
}

//mesma ideia do lerInteiro, mas para o salário
float lerDecimalEst(void){
    float valor;
    while(scanf("%f", &valor) != 1){
        while(getchar() != '\n');
        printf("Entrada invalida! Digite um numero: ");
    }

    return valor;
}

//a vírgula é o separador do CSV, então não pode aparecer dentro do nome
void limparVirgulasEst(char texto[]){
    for(int k = 0; texto[k] != '\0'; k++){
        if(texto[k] == ','){
            texto[k] = ' ';
        }
    }
}

//retorna uma lista vazia
int lstEstCria(void){
    return 0;
}

//retorna 1 se vazia ou 0 se não vazia
int lstEstVazia(int n){
    return (n == 0);
}

//retorna 1 se não há mais espaço no vetor ou 0 se ainda há
int lstEstCheia(int n){
    return (n >= QUANTIDADE);
}

//busca binária, retorna a posição do funcionário ou -1 se não achou
int lstEstBusca(FuncionarioEst vet[], int n, int matricula){
    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;

        if(vet[meio].matricula == matricula){
            return meio;
        }
        if(vet[meio].matricula < matricula){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }

    return -1;
}

//insere elemento em ordem de matrícula, retorna o n atualizado
int lstEstInsereOrdenado(FuncionarioEst vet[], int n, FuncionarioEst f){
    if(lstEstCheia(n)){
        return n;
    }

    //procura posição de inserção
    int pos = 0;
    while(pos < n && vet[pos].matricula < f.matricula){
        pos++;
    }

    //abre espaço deslocando os seguintes uma posição para frente
    for(int k = n; k > pos; k--){
        vet[k] = vet[k - 1];
    }

    vet[pos] = f;
    return n + 1;
}

//retira elemento da lista, retorna o n atualizado
int lstEstRetira(FuncionarioEst vet[], int n, int matricula){
    int pos = lstEstBusca(vet, n, matricula);

    if(pos == -1){
        return n;
    }

    //desloca os seguintes uma posição para trás
    for(int k = pos; k < n - 1; k++){
        vet[k] = vet[k + 1];
    }

    return n - 1;
}

//imprime valores dos elementos
void lstEstImprime(FuncionarioEst vet[], int n){
    for(int k = 0; k < n; k++){
        printf("%d | %s | %d anos | R$ %.2f\n", vet[k].matricula, vet[k].nome, vet[k].idade, vet[k].salario);
    }
}

int salvarCSVEst(FuncionarioEst vet[], int n){
    FILE *arquivo = fopen(ARQUIVO, "w");
    if(arquivo == NULL){
        printf("ERRO: nao foi possivel salvar em %s!\n", ARQUIVO);
        return 0;
    }

    fprintf(arquivo, "matricula,nome,idade,salario\n");
    for(int k = 0; k < n; k++){
        fprintf(arquivo, "%d,%s,%d,%.2f\n", vet[k].matricula, vet[k].nome, vet[k].idade, vet[k].salario);
    }

    fclose(arquivo);
    return 1;
}

//lê o arquivo e retorna o n atualizado
int carregarCSVEst(FuncionarioEst vet[], int n){
    FILE *arquivo = fopen(ARQUIVO, "r");
    char linha[128];
    int ignoradas = 0;

    if(arquivo == NULL){
        return n;
    }

    fgets(linha, sizeof(linha), arquivo); //descarta o cabeçalho

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        if(linha[0] == '\n' || linha[0] == '\r'){
            continue; //linha em branco
        }

        FuncionarioEst f;
        int valida = sscanf(linha, "%d,%49[^,],%d,%f", &f.matricula, f.nome, &f.idade, &f.salario) == 4
                     && !lstEstCheia(n)
                     && lstEstBusca(vet, n, f.matricula) == -1;

        if(valida){
            n = lstEstInsereOrdenado(vet, n, f);
        }
        else{
            ignoradas++;
        }
    }

    if(ignoradas > 0){
        printf("AVISO: %d linha(s) do arquivo foram ignoradas (formato invalido, matricula repetida ou lista cheia).\n", ignoradas);
    }

    fclose(arquivo);
    return n;
}

//mostra o menu principal
void mostrarMenuEst(int n){
    printf("----------------------------------\n");
    printf("%d de %d FuncionarioEsts cadastrados (arquivo: %s)\n", n, QUANTIDADE, ARQUIVO);
    printf("----------------------------------\n");
    printf("1 - Adicionar funcionario\n");
    printf("2 - Remover funcionario\n");
    printf("3 - Imprimir ficha de funcionario\n");
    printf("4 - Excluir todos\n");
    printf("5 - Listar todos\n");
    printf("0 - Voltar ao menu principal\n");
}

int opcaoAdicionarEst(FuncionarioEst vet[], int n){
    //verifica se a lista já está cheia
    if(lstEstCheia(n)){
        printf("Limite de funcionários atingido!\n");
        return n;
    }

    printf("Matrícula: ");
    int matricula = lerInteiroEst();

    if(lstEstBusca(vet, n, matricula) != -1){ //se a busca encontrou uma posição
        printf("Já existe um funcionário com essa matrícula!\n");
        return n;
    }

    FuncionarioEst f;
    f.matricula = matricula;

    printf("Nome: ");
    scanf(" %49[^\n]", f.nome); //lê até 49 caracteres e também permite espaços
    limparVirgulasEst(f.nome);

    printf("Idade: ");
    f.idade = lerInteiroEst();

    printf("Salario: ");
    f.salario = lerDecimalEst();

    return lstEstInsereOrdenado(vet, n, f);
}

int opcaoRemoverEst(FuncionarioEst vet[], int n){
    printf("Matrícula do funcionário que será removido: ");
    int matricula = lerInteiroEst();

    //não encontrou o funcionário na busca
    if(lstEstBusca(vet, n, matricula) == -1){
        printf("Funcionário não encontrado!\n");
        return n;
    }

    n = lstEstRetira(vet, n, matricula);
    printf("Funcionário removido!\n");
    return n;
}

void opcaoImprimirEst(FuncionarioEst vet[], int n){
    printf("Matricula do funcionário: ");
    int matricula = lerInteiroEst();

    int pos = lstEstBusca(vet, n, matricula);
    //não encontrou o funcionário na busca
    if(pos == -1){
        printf("Funcionário não encontrado!\n");
        return;
    }

    printf("Matrícula: %d\nNome: %s\nIdade: %d\nSalário: %.2f\n", vet[pos].matricula, vet[pos].nome, vet[pos].idade, vet[pos].salario);
}

void opcaoListarEst(FuncionarioEst vet[], int n){
    if(lstEstVazia(n)){
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    lstEstImprime(vet, n);
}
