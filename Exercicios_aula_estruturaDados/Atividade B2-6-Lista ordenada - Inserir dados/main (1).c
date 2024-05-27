/*-------------------------------------------------------*/
/*     FATEC-São Caetano do Sul Estrutura de Dados       */
/*             Atividade Ordernar array                  */
/*       Objetivo: Adicionar elemento no meio do array   */
/*                                                       */
/*           Autores: Vinicius e Vicente                 */
/*                                        Data:21/05/2024*/
/*-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//Contar tempo do programa

int main(void) {
clock_t t;
  t = clock();
  
  int array[4] = {10, 25, 40, 80};

  int num = 35;

  for(int i = 0; i < 5; i++)
    {
      if(num < array[i])
      {
        int aux = array[i];
        int aux2 = array[i+1];
        array[i] = num;
        array[i+1] = aux;
        array[i+2] = aux2;
        break;
      }
    }

  printf("Array: ");
  printf("[");
  for(int i = 0; i < 5; i++)
    {
      printf("-> %d", array[i]);
    }
  printf("]");

  t = clock() - t;

  printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
  return 0;
}