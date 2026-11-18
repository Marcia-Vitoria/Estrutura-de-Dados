#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estatica.h"
#include "encadeada.h"
#include "pilha.h"
#include "matriz.h"

void listaEstatica(){
    Funcionario vet[QUANTIDADE];
    int n; //total de funcionários cadastrados

    n = lst_cria(); //cria a lista vazia
    n = carregarCSV(vet, n);

    int decisao, antes;

    do{
        mostrarMenu(n);

        decisao = lerInteiro();

        antes = n; //para saber se a lista mudou e precisa ser salva
        switch(decisao){
            case 0: printf("Encerrando...\n"); break;
            case 1: n = opcaoAdicionar(vet, n); break;
            case 2: n = opcaoRemover(vet, n); break;
            case 3: opcaoImprimir(vet, n); break;
            case 4: n = lst_cria(); printf("Todos os funcionários foram excluídos!\n"); break;
            case 5: opcaoListar(vet, n); break;
            default: printf("Opção inválida!\n");
        }

        if(n != antes){
            salvarCSV(vet, n);
        }
    }
    while(decisao != 0);

    return 0;
}

void listaEncadeada(){
    Elemento* lst; //primeiro elemento da lista

    lst = lst_cria(); //cria a lista vazia
    lst = carregarCSV(lst);

    int decisao, antes;

    do{
        mostrarMenu(lst);

        decisao = lerInteiro();

        antes = lst_conta(lst); //para saber se a lista mudou e precisa ser salva
        switch(decisao){
            case 0: printf("Encerrando...\n"); break;
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

    return 0;
}

void pilha(){
    Pilha* p;
    int opcao;
    float valor;

    p = pilha_cria();

    do{
        printf("\n===== MENU PILHA =====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Verificar se a pilha esta vazia\n");
        printf("4 - Imprimir pilha\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

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
                if(pilha_vazia(p)){
                    printf("A pilha esta vazia.\n");
                }
                else{
                    printf("A pilha possui elementos.\n");
                }
                break;

            case 4:
                pilha_imprime(p);
                break;

            case 5:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 5);

    pilha_libera(p);

    return 0;
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

    return 0;
}
//Tad Fila estática e dinâmica
void Tad_Fila_Estatica_dinamica(){
    TipoFila *fila = inicializarFila();
    TipoPessoa p, consulta;

    if (fila == NULL) {
        printf("Erro ao inicializar fila.\n");
        return 1;
    }

    printf("TESTE DA FILA\n");

    // verificar fila vazia
    printf("Fila vazia: %d\n", filaVazia(fila));
    printf("Fila cheia: %d\n", filaCheia(fila));

    // enfileirar
    strcpy(p.nome, "Ana");
    strcpy(p.cpf, "11111111111");
    enfileirar(fila, p);

    strcpy(p.nome, "Bruno");
    strcpy(p.cpf, "22222222222");
    enfileirar(fila, p);

    strcpy(p.nome, "Carlos");
    strcpy(p.cpf, "33333333333");
    enfileirar(fila, p);

    // consultar início
    printf("\nConsulta\n");
    if (consultarInicio(fila, &consulta)) {
        printf("%s - %s\n", consulta.nome, consulta.cpf);
    }

    // alterar início
    printf("\nAlteracao\n");
    strcpy(p.nome, "Amanda");
    strcpy(p.cpf, "44444444444");
    alterarInicio(fila, p);

    if (consultarInicio(fila, &consulta)) {
        printf("%s - %s\n", consulta.nome, consulta.cpf);
    }

    // desenfileirar
    printf("\nRemocoes\n");
    while (!filaVazia(fila)) {
        if (desenfileirar(fila, &consulta)) {
            printf("Removido: %s - %s\n",
                   consulta.nome, consulta.cpf);
        }
    }

    // verificar fila vazia
    printf("\nFila vazia: %d\n", filaVazia(fila));

    // testar fila cheia (aplicavel para a fila estática)
    printf("Fila cheia: %d\n", filaCheia(fila));

    // testar desenfileiramento em fila vazia
    desenfileirar(fila, &consulta);

    // destruir fila
    destruirFila(&fila);
    printf("\nFila destruida: %s\n",
           fila == NULL ? "Sim" : "Nao");

    return 0;
}

//Tad Fila circular

void Tad_fila_circular() {
    TipoFilaCircular *fila = inicializarFilaCircular();
    TipoPessoa p, consulta;
    int opcao;

    if (fila == NULL) {
        printf("Erro ao inicializar fila.\n");
        return 1;
    }

    do {
        printf("\n========== FILA CIRCULAR ==========\n");
        printf("1 - Enfileirar pessoa\n");
        printf("2 - Desenfileirar pessoa\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Alterar inicio\n");
        printf("5 - Verificar fila vazia\n");
        printf("6 - Verificar fila cheia\n");
        printf("7 - Imprimir fila\n");
        printf("0 - Sair\n");
        printf("==================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

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
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    destruirFilaCircular(&fila);

    printf("Fila destruida. Programa finalizado.\n");

    return 0;
}

void filadePrioridade() {

    TipoSpooler *spooler = inicializarSpooler();
    int decisao;

    if (spooler == NULL) {
        printf("Sem memoria!\n");
        return 1;
    }

    do {
        printf("\n----------------------------------\n");
        printf("0 = Encerrar\n1 = Enviar documento para impressao\n");
        printf("2 = Imprimir proximo documento\n3 = Mostrar fila de impressao\n");

        decisao = lerInteiro();

        switch (decisao) {
            case 0: printf("Encerrando...\n"); break;
            case 1: opcaoEnviarDocumento(spooler); break;
            case 2: opcaoImprimirProximo(spooler); break;
            case 3: imprimirSpooler(spooler); break;
            default: printf("Opção inválida!\n");
        }
    } while (decisao != 0);

    destruirSpooler(&spooler);

    return 0;
}

void polaca() {
    Pilha p;
    char expressao[256];
    char *token;
    char *fim;

    float numero;
    float a, b, resultado;

    pilha_cria(&p);

    printf("Digite a expressao em NPI:\n");
    fgets(expressao, sizeof(expressao), stdin);

    // separar os elementos da expressao
    token = strtok(expressao, " ,\t\n");

    while (token != NULL) {

        // verificar se o elemento e um numero
        numero = strtof(token, &fim);

        if (*fim == '\0' && fim != token) {

            if (!pilha_push(&p, numero)) {
                printf("Erro: pilha cheia!\n");
                return 1;
            }

        } else {

            // verificar se existem dois operandos
            if (!pilha_pop(&p, &b) || !pilha_pop(&p, &a)) {
                printf("Erro: expressao invalida!\n");
                return 1;
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
                        return 1;
                    }

                    resultado = a / b;
                    break;

                default:
                    printf("Erro: operador desconhecido: %s\n", token);
                    return 1;
            }

            // empilhar o resultado
            if (!pilha_push(&p, resultado)) {
                printf("Erro: pilha cheia!\n");
                return 1;
            }
        }

        token = strtok(NULL, " ,\t\n");
    }

    // verificar se restou apenas um resultado
    if (p.n != 1) {
        printf("Erro: expressao NPI invalida!\n");
        return 1;
    }

    pilha_pop(&p, &resultado);

    printf("Resultado: %.2f\n", resultado);

    return 0;
}