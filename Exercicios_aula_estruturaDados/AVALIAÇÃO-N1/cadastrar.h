#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"

struct produto{
  int id;
  char nome[50];
  int qtd;
  float preco;
  struct produto *prox;
};

typedef struct produto Produto;

Produto *cria(void){
  return NULL;
}

Produto *insere(Produto *lista, int id, char *nome, int qtd, float preco){
  Produto * novo = (Produto *) malloc(sizeof(Produto));
  novo->id = id;
  strcpy(novo->nome, nome);
  novo->qtd = qtd;
  novo->preco = preco;
  novo->prox = lista;
  return novo;
}

