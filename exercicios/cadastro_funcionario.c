// Exercício para praticar estrutura heterogênea
// Funcionários e empresa

#include <stdio.h>
#include <string.h>

#define TAM 15

struct ficha_funcionario{
    char nome[50];
    char matricula[12];
    int idade;
    float salario;
};

// cria vetor
void criaVetor(struct ficha_funcionario vetor[]){
    int i;

    for(i = 0; i < TAM; i++){
        vetor[i].matricula[0] = '\0'; // indicar que a posição tá vazia
    }
}

// adiciona funcionario
int adicionaFuncionario(struct ficha_funcionario vetor[]){
    int i;

    for(i = 0; i < TAM; i++){
        // verifica se a posição tá vazia
        if(vetor[i].matricula[0] == '\0'){
            printf("\n   CADASTRO DE FUNCIONARIO    \n");

            printf("Nome: ");
            scanf(" %49[^\n]", vetor[i].nome); // permite ler até 49 caracteres e também permite espaços
			// não usei fgets porque normalmente guarda também o \n (quando o usuário aperta Enter)
			
            printf("Matricula: ");
            scanf(" %11s", vetor[i].matricula);

            printf("Idade: ");
            scanf("%d", &vetor[i].idade);

            printf("Salario: ");
            scanf("%f", &vetor[i].salario);

            printf("\nFuncionario cadastrado com sucesso!\n");

            return 1;
        }
    }

    printf("\nNao ha vagas para novos funcionarios.\n");

    return 0;
}

// busca funcionario
int buscaFuncionario(struct ficha_funcionario vetor[], char matricula[]){
    int i;

    for(i = 0; i < TAM; i++){
        if(vetor[i].matricula[0] != '\0'){
            if(strcmp(vetor[i].matricula, matricula) == 0){ // compara as duas matrículas
                return i;
            }
        }
    }

    return -1;
}

// imprime funcionario
void imprimeFuncionario(struct ficha_funcionario funcionario){
    printf("\nNome: %s", funcionario.nome);
    printf("\nMatricula: %s", funcionario.matricula);
    printf("\nIdade: %d", funcionario.idade);
    printf("\nSalario: R$ %.2f\n", funcionario.salario);
}

// imprime todos os funcionarios
void imprimeFuncionarios(struct ficha_funcionario vetor[]){
    int i;
    int encontrou = 0;

    printf("\n   FUNCIONARIOS CADASTRADOS   \n");

    for(i = 0; i < TAM; i++){
        if(vetor[i].matricula[0] != '\0'){
            printf("\nFuncionario %d:", i + 1);
            imprimeFuncionario(vetor[i]);
            encontrou = 1;
        }
    }

    if(encontrou == 0){
        printf("\nNenhum funcionario cadastrado.\n");
    }
}

// remove funcionario
int removeFuncionario(struct ficha_funcionario vetor[], char matricula[]){
    int posicao;
    int i;

    posicao = buscaFuncionario(vetor, matricula); 

    if(posicao == -1){
        return 0;
    }

    // desloca os funcionarios seguintes uma posição para trás
    for(i = posicao; i < TAM - 1; i++){
        vetor[i] = vetor[i + 1]; // não precisa copiar campo por campo
    }

    // limpa a última posição
    vetor[TAM - 1].matricula[0] = '\0';

    return 1;
}

// salva os funcionarios no arquivo CSV
// memória -> arquivo
void salvaCSV(struct ficha_funcionario vetor[]){
    FILE *arquivo; // variável que representa o arquivo .csv
    int i;

    arquivo = fopen("funcionarios.csv", "w"); // write

    if(arquivo == NULL){
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    // cabecalho
    fprintf(arquivo, "nome;matricula;idade;salario\n");

	// salvando os dados dos funcionários
    for(i = 0; i < TAM; i++){
        if(vetor[i].matricula[0] != '\0'){
            fprintf(arquivo, "%s;%s;%d;%.2f\n", vetor[i].nome, vetor[i].matricula, vetor[i].idade, vetor[i].salario);
        }
    }

    fclose(arquivo);

    printf("\nDados salvos no arquivo funcionarios.csv.\n");
}

// carrega os funcionarios do arquivo CSV
// arquivo -> memória
void carregaCSV(struct ficha_funcionario vetor[]){
    FILE *arquivo;
    int i = 0;

    arquivo = fopen("funcionarios.csv", "r"); // read

    if(arquivo == NULL){ // útil na primeira execução
        return;
    }

    // ignorando o cabecalho
    fscanf(arquivo, "%*[^\n]\n"); // ler tudo até o Enter, mas não guarda

	// enquanto houver espaço no vetor e os dados do funcionario forem lidos corretamente
    while(i < TAM && fscanf(arquivo, " %49[^;];%11[^;];%d;%f", // ler qualquer caractere, menos o ponto e vírgula
		vetor[i].nome, vetor[i].matricula,
		&vetor[i].idade, &vetor[i].salario) == 4){
        i++; // passa para a próxima posição
    }

    fclose(arquivo);
}

// menu
void menu(){
    printf("\n+--------------------------+\n");
    printf("       FUNCIONARIOS\n");
    printf("+--------------------------+\n");
    printf("1 - Adicionar funcionario\n");
    printf("2 - Remover funcionario\n");
    printf("3 - Buscar funcionario\n");
    printf("4 - Imprimir funcionarios\n");
    printf("5 - Salvar no CSV\n");
    printf("0 - Sair\n");
    printf("+--------------------------+\n");
    printf("Escolha: ");
}

int main(){

    struct ficha_funcionario funcionarios[TAM];

    int opcao;
    char matricula[12];
    int posicao;

    // cria o vetor
    criaVetor(funcionarios);

    // carrega os dados que estavam salvos
    carregaCSV(funcionarios);

    do{

        menu();
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                adicionaFuncionario(funcionarios);
                break;

            case 2:

                printf("\nDigite a matricula do funcionario: ");
                scanf(" %11s", matricula);

                if(removeFuncionario(funcionarios, matricula)){
                    printf("\nFuncionario removido com sucesso!\n");

                    // salva automaticamente depois da remocao
                    salvaCSV(funcionarios);
                }
                else{
                    printf("\nFuncionario nao encontrado.\n");
                }

                break;

            case 3:

                printf("\nDigite a matricula do funcionario: ");
                scanf(" %11s", matricula);

                posicao = buscaFuncionario(funcionarios, matricula);

                if(posicao != -1){
                    printf("\nFuncionario encontrado.\n");
                    imprimeFuncionario(funcionarios[posicao]);
                }
                else{
                    printf("\nFuncionario nao encontrado.\n");
                }

                break;

            case 4:
                imprimeFuncionarios(funcionarios);
                break;

            case 5:
                salvaCSV(funcionarios);
                break;

            case 0:
                salvaCSV(funcionarios);
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    }while(opcao != 0);

    return 0;
}

/* 
obs.
- armazena os dados em um arquivo .csv
- abre e fecha o arquivo para manter os dados armazenados
- ao remover um funcionário, reorganiza os demais no vetor,
mantendo os funcionários em sequência para aproveitar
o máximo possível do espaço disponível no vetor 
*/