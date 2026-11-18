#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char cidade[50];
    char bairro[50];
} Endereco;

typedef struct {
    char cpf[20];
    int idade;
} DadosPessoais;

typedef struct {
    char cargo[30];
    float salario;
} DadosProfissionais;

typedef struct Funcionario {
    char nome[50];
    Endereco end;
    DadosPessoais dp;
    DadosProfissionais prof;
    struct Funcionario *prox;
} Funcionario;


void atualizarFuncionario(Funcionario *lista);

#endif