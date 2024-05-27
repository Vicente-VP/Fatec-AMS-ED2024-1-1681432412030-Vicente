/*-------------------------------------------------------*/
/*     FATEC-São Caetano do Sul Estrutura de Dados       */
/*             Atividade Ordernar Lista                  */
/*       Objetivo: Adicionar elemento no meio da lista   */
/*                                                       */
/*           Autores: Vinicius e Vicente                 */
/*                                        Data:27/05/2024*/
/*-------------------------------------------------------*/

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Lista {
  int data;
  struct Lista* prox;
} Lista;

Lista *lista(int n) {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->data = n;
  lista->prox = NULL;
  return lista;
}

void list_print(Lista *List) {
  Lista *atual = List;
  printf("[%d", atual->data);

  for (atual = atual->prox; atual != NULL; atual = atual->prox)
    printf(" -> %d", atual->data);

  printf("]\n");
}

int list_cresc(Lista *List, int n) {
  printf("Começo: ");
  list_print(List);

  for (Lista *temp = List; temp != NULL; temp = temp->prox) {
    if (temp->data > n) {
      Lista improv = *temp;
      *temp = *lista(n);
      temp->prox = &improv;

      printf("Final: ");
      list_print(List);
      return 0;
    }
  }

  List->prox = lista(n);


  printf("Final: ");
  list_print(List);  
  return 0;
}

int main(void) {
  clock_t t;
  t = clock();
  Lista *temp = lista(10);
  temp->prox = lista(25);
  temp->prox->prox = lista(40);
  temp->prox->prox->prox = lista(80);

  list_cresc(temp, 30);

  t = clock() - t;

  printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
  return 0;
}