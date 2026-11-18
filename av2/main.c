#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1
#include "matriz.h"
#include "fila_dinamica.h"
#include "fila_estatica.h"
#include "fila_circular.h"
#include "pilha_dinamica.h"
#include "pilha_estatica.h"
//2
#include "estatica.h"
#include "encadeada.h"
//3
#include  "spooler.h"
//4
#include "pilha.h"

static int lerOpcaoMenu(void);
static void lerTextoFila(char texto[], size_t tamanho);

void listaEstatica(){
    FuncionarioEst vet[QUANTIDADE];
    int n; //total de funcionários cadastrados

    n = lstEstCria(); //cria a lista vazia
    n = carregarCSVEst(vet, n);

    int decisao, antes;

    do{
        mostrarMenuEst(n);

        decisao = lerInteiroEst();

        antes = n; //para saber se a lista mudou e precisa ser salva
        switch(decisao){
            case 0: printf("Voltando ao menu principal...\n"); break;
            case 1: n = opcaoAdicionarEst(vet, n); break;
            case 2: n = opcaoRemoverEst(vet, n); break;
            case 3: opcaoImprimirEst(vet, n); break;
            case 4: n = lstEstCria(); printf("Todos os funcionários foram excluídos!\n"); break;
            case 5: opcaoListarEst(vet, n); break;
            default: printf("Opção inválida!\n");
        }

        if(n != antes){
            salvarCSVEst(vet, n);
        }
    }
    while(decisao != 0);

    return;
}

void listaEncadeada(){
    Elemento* lst; //primeiro elemento da lista

    lst = lst_cria(); //cria a lista vazia
    lst = carregarCSV(lst);

    int decisao, antes;

    do{
        mostrarMenu(lst);

        decisao = lerInteiroSpooler();

        antes = lst_conta(lst); //para saber se a lista mudou e precisa ser salva
        switch(decisao){
            case 0: printf("Voltando ao menu principal...\n"); break;
            case 1: lst = opcaoAdicionar(lst); break;
            case 2: lst = opcaoRemover(lst); break;
            case 3: opcaoImprimir(lst); break;
            case 4: lst_libera(lst); lst = lst_cria(); printf("Todos os funcionários foram excluídos!\n"); break;
            case 5: opcaoListar(lst); break;
            default: printf("Opção inválida!\n");
        }

        if(lst_conta(lst) != antes){
            salvarCSV(lst);
        }
    }
    while(decisao != 0);

    lst_libera(lst);

    return;
}

void pilhaEstatica(){
    Pilha* p;
    int opcao;
    float valor;

    p = pilha_cria();

    do{
        printf("\n===== MENU PILHA ESTATICA =====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Imprimir pilha\n");
        printf("4 - Verificar se a pilha esta vazia\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        opcao = lerOpcaoMenu();

        switch(opcao){

            case 1:
                printf("Digite o valor: ");
                scanf("%f", &valor);

                pilha_push(p, valor);

                printf("Elemento inserido com sucesso!\n");
                break;

            case 2:
                if(pilha_vazia(p)){
                    printf("Pilha vazia. Nao ha elementos para remover.\n");
                }
                else{
                    valor = pilha_pop(p);
                    printf("Elemento removido: %.2f\n", valor);
                }
                break;

            case 3:
                pilha_imprime(p);
                break;

            case 4:
                if(pilha_vazia(p)){
                    printf("A pilha esta vazia.\n");
                }
                else{
                    printf("A pilha possui elementos.\n");
                }
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    pilha_libera(p);
}

void pilhaDinamica(){
    Pilha* p;
    int opcao;
    float valor;

    p = pilhaDinCria();

    do{
        printf("\n===== MENU PILHA DINAMICA =====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Imprimir pilha\n");
        printf("4 - Verificar se a pilha esta vazia\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        opcao = lerOpcaoMenu();

        switch(opcao){

            case 1:
                printf("Digite o valor: ");
                scanf("%f", &valor);

                pilhaDinPush(p, valor);

                printf("Elemento inserido com sucesso!\n");
                break;

            case 2:
                if(pilhaDinVazia(p)){
                    printf("Pilha vazia. Nao ha elementos para remover.\n");
                }
                else{
                    valor = pilhaDinPop(p);
                    printf("Elemento removido: %.2f\n", valor);
                }
                break;

            case 3:
                pilhaDinImprime(p);
                break;

            case 4:
                if(pilhaDinVazia(p)){
                    printf("A pilha esta vazia.\n");
                }
                else{
                    printf("A pilha possui elementos.\n");
                }
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    pilhaDinLibera(p);

    return;
}

void matriz(){
    int matriz1[9];
    int matriz2[9];
    int resultado[9];

    // dimensionar as matrizes para 3x3
    dimensionaMatriz(3, 3);

    // matriz 1
    zeraMatriz(matriz1);
    printf("Matriz 1 zerada:\n");
    imprimeMatriz(matriz1);

    adicionaElemento(matriz1, 15, 1, 1);
    adicionaElemento(matriz1, 25, 2, 2);
    adicionaElemento(matriz1, 35, 3, 3);

    printf("\nMatriz 1 preenchida:\n");
    imprimeMatriz(matriz1);

    // matriz 2 para teste de soma
    zeraMatriz(matriz2);
    printf("\nMatriz 2 zerada:\n");
    imprimeMatriz(matriz2);

    adicionaElemento(matriz2, 5, 1, 1);
    adicionaElemento(matriz2, 5, 2, 2);
    adicionaElemento(matriz2, 5, 3, 3);

    printf("\nMatriz 2 preenchida:\n");
    imprimeMatriz(matriz2);

    // buscar elemento
    printf("\nO elemento que esta na linha 2 e coluna 2 da matriz 1 eh: %d\n",
           buscaElemento(matriz1, 2, 2));

    // somar matrizes
    somaMatriz(matriz1, matriz2, resultado);

    printf("\nSoma das matrizes:\n");
    imprimeMatriz(resultado);

    return;
}
//Tad Fila estática e dinâmica
void filaEstatica(){
    TipoFilaEst *fila = inicializarFila();
    TipoPessoaEst pessoa, consulta;
    int opcao;

    if (fila == NULL) {
        printf("Erro ao inicializar fila.\n");
        return;
    }

    do{
        printf("\n===== MENU FILA ESTATICA =====\n");
        printf("1 - Enfileirar pessoa\n");
        printf("2 - Desenfileirar pessoa\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Alterar inicio\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");

        opcao = lerOpcaoMenu();

        switch(opcao){
            case 1:
                printf("Nome: ");
                lerTextoFila(pessoa.nome, sizeof(pessoa.nome));
                printf("CPF: ");
                lerTextoFila(pessoa.cpf, sizeof(pessoa.cpf));
                enfileirar(fila, pessoa);
                break;
            case 2:
                if(desenfileirar(fila, &consulta)){
                    printf("Removido: %s - %s\n", consulta.nome, consulta.cpf);
                }
                break;
            case 3:
                if(consultarInicio(fila, &consulta)){
                    printf("Inicio: %s - %s\n", consulta.nome, consulta.cpf);
                }
                break;
            case 4:
                printf("Novo nome: ");
                lerTextoFila(pessoa.nome, sizeof(pessoa.nome));
                printf("Novo CPF: ");
                lerTextoFila(pessoa.cpf, sizeof(pessoa.cpf));
                if(alterarInicio(fila, pessoa)){
                    printf("Inicio alterado.\n");
                }
                break;
            case 5:
                printf("Fila vazia: %s\n", filaVazia(fila) ? "Sim" : "Nao");
                break;
            case 6:
                printf("Fila cheia: %s\n", filaCheia(fila) ? "Sim" : "Nao");
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao != 0);

    // destruir fila
    destruirFila(&fila);
    printf("\nFila destruida: %s\n",
           fila == NULL ? "Sim" : "Nao");

    return;
}

static int lerOpcaoMenu(void){
    int opcao;
    int caractere;

    if(scanf("%d", &opcao) != 1){
        while((caractere = getchar()) != '\n' && caractere != EOF){
        }
        return -1;
    }

    while((caractere = getchar()) != '\n' && caractere != EOF){
    }

    return opcao;
}

static void lerTextoFila(char texto[], size_t tamanho){
    size_t comprimento;
    int caractere;

    if(fgets(texto, (int)tamanho, stdin) == NULL){
        texto[0] = '\0';
        return;
    }

    comprimento = strcspn(texto, "\n");
    if(texto[comprimento] == '\n'){
        texto[comprimento] = '\0';
        return;
    }

    while((caractere = getchar()) != '\n' && caractere != EOF){
    }
}

void filaDinamica(){
    TipoFila *fila = inicializarFilaDin();
    TipoPessoa pessoa, consulta;
    int opcao;

    if (fila == NULL) {
        printf("Erro ao inicializar fila.\n");
        return;
    }

    do{
        printf("\n===== MENU FILA DINAMICA =====\n");
        printf("1 - Enfileirar pessoa\n");
        printf("2 - Desenfileirar pessoa\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Alterar inicio\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");

        opcao = lerOpcaoMenu();

        switch(opcao){
            case 1:
                printf("Nome: ");
                lerTextoFila(pessoa.nome, sizeof(pessoa.nome));
                printf("CPF: ");
                lerTextoFila(pessoa.cpf, sizeof(pessoa.cpf));
                enfileirarDin(fila, pessoa);
                break;
            case 2:
                if(desenfileirarDin(fila, &consulta)){
                    printf("Removido: %s - %s\n", consulta.nome, consulta.cpf);
                }
                break;
            case 3:
                if(consultarInicioDin(fila, &consulta)){
                    printf("Inicio: %s - %s\n", consulta.nome, consulta.cpf);
                }
                break;
            case 4:
                printf("Novo nome: ");
                lerTextoFila(pessoa.nome, sizeof(pessoa.nome));
                printf("Novo CPF: ");
                lerTextoFila(pessoa.cpf, sizeof(pessoa.cpf));
                if(alterarInicioDin(fila, pessoa)){
                    printf("Inicio alterado.\n");
                }
                break;
            case 5:
                printf("Fila vazia: %s\n", filaDinVazia(fila) ? "Sim" : "Nao");
                break;
            case 6:
                printf("Fila cheia: %s\n", filaDinCheia(fila) ? "Sim" : "Nao");
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao != 0);

    // destruir fila
    destruirFilaDin(&fila);
    printf("\nFila destruida: %s\n",
           fila == NULL ? "Sim" : "Nao");

    return;
}

//Tad Fila circular

void filaCircular() {
    TipoFilaCircular *fila = inicializarFilaCircular();
    TipoPessoaCirc p, consulta;
    int opcao;

    if (fila == NULL) {
        printf("Erro ao inicializar fila.\n");
        return;
    }

    do {
        printf("\n===== MENU FILA CIRCULAR =====\n");
        printf("1 - Enfileirar pessoa\n");
        printf("2 - Desenfileirar pessoa\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Alterar inicio\n");
        printf("5 - Verificar fila vazia\n");
        printf("6 - Verificar fila cheia\n");
        printf("7 - Imprimir fila\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        opcao = lerOpcaoMenu();

        switch (opcao) {

            case 1:
                printf("\nENFILEIRAR\n");

                printf("Nome: ");
                fgets(p.nome, sizeof(p.nome), stdin);
                p.nome[strcspn(p.nome, "\n")] = '\0';

                printf("CPF: ");
                fgets(p.cpf, sizeof(p.cpf), stdin);
                p.cpf[strcspn(p.cpf, "\n")] = '\0';

                if (enfileirarFilaCircular(fila, p)) {
                    printf("Pessoa adicionada!\n");
                }
                break;

            case 2:
                printf("\nDESENFILEIRAR\n");

                if (desenfileirarFilaCircular(fila, &consulta)) {
                    printf("Pessoa removida: %s\n", consulta.nome);
                    printf("CPF: %s\n", consulta.cpf);
                }
                break;

            case 3:
                printf("\nCONSULTAR INICIO\n");

                if (consultarInicioFilaCircular(fila, &consulta)) {
                    printf("Nome: %s\n", consulta.nome);
                    printf("CPF: %s\n", consulta.cpf);
                }
                break;

            case 4:
                printf("\nALTERAR INICIO\n");

                if (!filaCircularVazia(fila)) {
                    printf("Novo nome: ");
                    fgets(p.nome, sizeof(p.nome), stdin);
                    p.nome[strcspn(p.nome, "\n")] = '\0';

                    printf("Novo CPF: ");
                    fgets(p.cpf, sizeof(p.cpf), stdin);
                    p.cpf[strcspn(p.cpf, "\n")] = '\0';

                    if (alterarInicioFilaCircular(fila, p)) {
                        printf("Pessoa alterada!\n");
                    }
                } else {
                    printf("ERRO: fila vazia.\n");
                }
                break;

            case 5:
                printf("\nFila vazia: %s\n",
                       filaCircularVazia(fila) ? "Sim" : "Nao");
                break;

            case 6:
                printf("\nFila cheia: %s\n",
                       filaCircularCheia(fila) ? "Sim" : "Nao");
                break;
                
            case 7:
                imprimirFilaCircular(fila);
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    destruirFilaCircular(&fila);

    printf("Fila destruida. Voltando ao menu principal.\n");

    return;
}

void filadePrioridade() {

    TipoSpooler *spooler = inicializarSpooler();
    int decisao;

    if (spooler == NULL) {
        printf("Sem memoria!\n");
        return;
    }

    do {
        printf("\n===== MENU IMPRESSORA =====\n");
        printf("1 - Enviar documento para impressao\n");
        printf("2 - Imprimir proximo documento\n");
        printf("3 - Mostrar fila de impressao\n");
        printf("0 - Voltar ao menu principal\n");

        decisao = lerInteiroSpooler();

        switch (decisao) {
            case 0: printf("Voltando ao menu principal...\n"); break;
            case 1: opcaoEnviarDocumento(spooler); break;
            case 2: opcaoImprimirProximo(spooler); break;
            case 3: imprimirSpooler(spooler); break;
            default: printf("Opção inválida!\n");
        }
    } while (decisao != 0);

    destruirSpooler(&spooler);

    return;
}

void polaca() {
    PilhaNPI p;
    char expressao[256];
    char *token;
    char *fim;

    float numero;
    float a, b, resultado;

    pilhaCriaNPI(&p);

    printf("Digite a expressao em NPI:\n");
    fgets(expressao, sizeof(expressao), stdin);

    // separar os elementos da expressao
    token = strtok(expressao, " ,\t\n");

    while (token != NULL) {

        // verificar se o elemento e um numero
        numero = strtof(token, &fim);

        if (*fim == '\0' && fim != token) {

            if (!pilhaPushNPI(&p, numero)) {
                printf("Erro: pilha cheia!\n");
                return;
            }

        } else {

            // verificar se existem dois operandos
            if (!pilhaPopNPI(&p, &b) || !pilhaPopNPI(&p, &a)) {
                printf("Erro: expressao invalida!\n");
                return;
            }

            // executar a operacao
            switch (token[0]) {

                case '+':
                    resultado = a + b;
                    break;

                case '-':
                    resultado = a - b;
                    break;

                case '*':
                    resultado = a * b;
                    break;

                case '/':
                    if (b == 0) {
                        printf("Erro: divisao por zero!\n");
                        return;
                    }

                    resultado = a / b;
                    break;

                default:
                    printf("Erro: operador desconhecido: %s\n", token);
                    return;
            }

            // empilhar o resultado
            if (!pilhaPushNPI(&p, resultado)) {
                printf("Erro: pilha cheia!\n");
                return;
            }
        }

        token = strtok(NULL, " ,\t\n");
    }

    // verificar se restou apenas um resultado
    if (p.n != 1) {
        printf("Erro: expressao NPI invalida!\n");
        return;
    }

    pilhaPopNPI(&p, &resultado);

    printf("Resultado: %.2f\n", resultado);
}

int main() {

    int op;

    do {

        printf("\n=================================\n");
        printf("         MENU PRINCIPAL\n");
        printf("=================================\n");

        printf("1 - Matriz\n");
        printf("2 - Fila Estatica\n");
        printf("3 - Fila Dinamica\n");
        printf("4 - Fila Circular\n");
        printf("5 - Pilha Estatica\n");
        printf("6 - Pilha Dinamica\n");
        printf("7 - Empresa Estatica\n");
        printf("8 - Empresa Dinamica\n");
        printf("9 - Impressora\n");
        printf("10 - NPI\n");
        printf("0 - Encerrar programa\n");

        printf("Opcao: ");
        op = lerOpcaoMenu();

        switch(op) {

            case 1: matriz(); break;
            case 2: filaEstatica(); break;
            case 3: filaDinamica(); break;
            case 4: filaCircular(); break;
            case 5: pilhaEstatica(); break;
            case 6: pilhaDinamica(); break;
            case 7: listaEstatica(); break;
            case 8: listaEncadeada(); break;
            case 9: filadePrioridade(); break;
            case 10: polaca(); break;
            case 0: printf("\nEncerrando programa...\n"); break;
            default: printf("\nOpcao invalida.\n");
        }

    } while(op != 0);

    return 0;
}