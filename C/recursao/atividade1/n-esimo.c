/*
 Exerc�cio 14 - n-�simo
 Bruna e Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int func(int n){
   if (n <= 2) {
      return 1;
   }

   return func(n - 2) + func(n - 3);
   
}

int seq(int atual, int total){
   int i = func(atual);

   printf("%d ", i);

   if(atual < total){
      i = seq(++atual, total);
   }

   return i;
}

int main(){
   setlocale(LC_ALL, "portuguese");

   int n;
   printf("Informe quantos n�meros mostrar: ");
   scanf("%d", &n);

   printf("Lista de valores: ");
   int nesimo = seq(0, n - 1);

   printf("\nO %d� valor � %d", n, nesimo);

   printf("\n");
   system("pause");
}