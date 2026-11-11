#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct lista Lista;

Lista* criaLista(void);
void iniciaLista(Lista* lista);

int listaVazia(Lista* lista);
int listaCheia(Lista* lista);

int insereInicio(Lista* lista, int novoDado);
int insereFinal(Lista* lista, int novoDado);
int inserePosicao(Lista* lista, int k, int novoDado);
int insereOrdenado(Lista* lista, int novoDado);

int excluiElemento(Lista* lista, int k);

int acessaElemento(Lista* lista, int k, int* dado);
int alteraElemento(Lista* lista, int k, int novoDado);
int buscaElemento(Lista* lista, int dado);

void imprimeLista(Lista* lista);
void destroiLista(Lista* lista);

#endif