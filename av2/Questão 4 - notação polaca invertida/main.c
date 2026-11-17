#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
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