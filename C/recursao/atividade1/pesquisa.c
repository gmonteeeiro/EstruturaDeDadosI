/*
 Exerc�cio 6 - pesquisa
 Bruna e Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vetor[10] = {1,2,3,4,5,6,7,8,9,10};

int Pesquisa(int valor, int pos){
   if(vetor[pos] == valor) return pos;
   if(pos <= 10) return Pesquisa(valor, ++pos);

   return -1;
}

int main(){
   setlocale(LC_ALL, "portuguese");

   int valor;
   printf("Informe qual valor a pesquisar: ");
   scanf("%d", &valor);

   int pos = Pesquisa(valor, 0);

   if (pos == -1) {
      printf("Valor n�o encontrado!");
   }
   else{
      printf("O valor est� na posi��o %d", pos + 1);
   }
   


   printf("\n");
   system("pause");
}