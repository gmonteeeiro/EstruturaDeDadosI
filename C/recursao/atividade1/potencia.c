/*
 Exercício 3 - Potência
 Bruna e Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float Mult(float n, int vezes){
   if(vezes == 1){
      return n;
   }
   
   return n * Mult(n, --vezes);
   
}

int main(){
   setlocale(LC_ALL, "portuguese");

   float n;
   int p;
   printf("Número: ");
   scanf("%f", &n);

   printf("Potência: ");
   scanf("%d", &p);

   printf("%f", Mult(n, p));

   printf("\n");
   system("pause");
}