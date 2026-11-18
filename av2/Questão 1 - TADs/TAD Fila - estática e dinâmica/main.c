#include <stdio.h>
#include <string.h>
#include "fila.h"

int main(void) {
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