/*-------------------------------------------------------*/
/*     FATEC-São Caetano do Sul Estrutura de Dados       */
/*             Atividade Calculadora RPN                 */
/*       Objetivo: Simular uma calculadora               */
/*                                                       */
/*           Autores: Vicente                            */
/*                                        Data:22/04/2024*/
/*-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define capArr 1500

typedef struct{
  float operacao[capArr];
  char aritme[capArr];
  int topo;
}Pilha;

Pilha * criaPilha(){
  Pilha * pilha = (Pilha *) malloc(sizeof(Pilha));
  pilha -> topo = -1;
  return pilha;
}

int pilhaVazia(Pilha * pilha){
  return pilha -> topo == -1;
}

int pilhaLot(Pilha * pilha){
  return pilha -> topo == capArr -1;
}

// ---------------------------------------------

int Num(char *elemento){
    if (*elemento >= '0' && *elemento <= '9') return 1;
    else return 0;
}

void push(Pilha * pilha, float * valor){

  if(pilhaLot(pilha)){ 
    printf("Lista lotada!");
  }
  else{
      pilha->topo++;
      pilha->operacao[pilha->topo] = *valor;
  }
}

void pushAritme(Pilha * pilha, char strCalculo[]){

  if(pilhaLot(pilha)) printf("Lista lotada!");
  else{
    pilha->topo++;
    strcpy(&pilha->aritme[pilha->topo], strCalculo);
  }
}

float pop(Pilha * pilha){
  if(pilhaVazia(pilha)){
    printf("Lista vazia!");
    return -1;
  }
  else{

    float valor = pilha->operacao[pilha->topo];
    pilha -> topo--;
    return valor;
  }
}

void calculoAritm(float * a, float * b, char * operador){
  char strCalc[50];
  sprintf(strCalc, "%.2f %c %.2f", *b, *operador, *a);

  printf("\nPasso à passo operação aritmética: %s\n", strCalc);

}

char * funcUnica(Pilha * pilha, float * a, float * b, char * operador, char strCalc[]){

  static int chamada = 0;

  if(chamada == 0){
  sprintf(strCalc, "%.2f %c %.2f", *b, *operador, *a);
  pushAritme(pilha,strCalc);
  chamada = 1;
  return strCalc;
  }
  else return strCalc;

}

void operaAritm(Pilha * pilha, float * a, float * b, char * operador, int * count){

  char strCalc[capArr];
  char opNaLista[capArr];
  char novoCalc[capArr];

  funcUnica(pilha, a, b, operador, strCalc);

      if (*count > 0){
        strcpy(opNaLista, &pilha->aritme[pilha->topo]);
        sprintf(novoCalc, "%c %.2f", *operador, *a);

        sprintf(strCalc, "(%s) %s", opNaLista, novoCalc);
        pushAritme(pilha,strCalc);
  }

}

float calculo(float * operado1, float * operado2, char * operador) {

  calculoAritm(operado1,operado2,operador);

    switch (*operador) {
        case '+':
            return *operado1 + *operado2;
        case '-':
            return -*operado1 + *operado2;
        case '*':
            return *operado1 * *operado2;
        case '/':
            return *operado1 / *operado2;

        default:
            printf("Este operador é inválido\n");
          return 0;
    }

}

void separar(Pilha * pilha, char RPN[]) {

  float oper1;
  float oper2;
  char operador;

  int count = 0;

  char * simb = strtok(RPN, " ");

  while (simb != NULL){
    if(Num(&simb[0])){
      float func = atof(simb);
      push(pilha, &func);
    }
    else{
      oper1 = pop(pilha);
      oper2 = pop(pilha);
      operador = simb[0];

      float result = calculo(&oper1, &oper2, &simb[0]);
      operaAritm(pilha, &oper1,&oper2,&operador, &count);
      push(pilha, &result);

      count++;
    }
    simb = strtok(NULL, " ");
  }
  float resultadoF = pop(pilha);

  printf("\nResultado da operação aritmética: %s\n", &pilha->aritme[pilha->topo]);

  printf("\nResultado Final: %.2f\n",resultadoF);

}

int main(void){

  Pilha * pilha;

  pilha = criaPilha();

  char RPN[capArr];

  printf("Digite a sua operação(separe seus elementos por caracteres):\n");

  printf("\nR: "); scanf("%[^\n]s",RPN);

  separar(pilha,RPN);

}
