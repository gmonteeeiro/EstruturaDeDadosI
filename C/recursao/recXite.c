#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Método Recursivo
int MetRec(long long n){
   if(n == 1) return 1;

   return n * MetRec(n-1);
}

//Método Iterativo
int MetIte(long long n){
   long long fat;
   for(fat = 1; n > 1; n = n - 1)
      fat = fat * n;
   
   return fat;
}

int main(){
   setlocale(LC_ALL, "portuguese");
   int fim = 0;

   while(!fim){
      long long n, result;

      printf("1 - Método Recursivo\n");
      printf("2 - Método Iterativo\n");
      printf("0 - Sair\n");
      printf("Método desejado: ");
      int opc;
      scanf("%d", &opc);
      
      if(opc == 0) break;

      printf("Calcular fatorial do nº: ");
      scanf("%lld", &n);

      clock_t Ticks[2];

      switch (opc)
      {
         case 1:
            Ticks[0] = clock(); //Inicia o timer
            result = MetRec(n);
            Ticks[1] = clock(); //Finaliza o timer
            break;

         case 2:
            Ticks[0] = clock(); //Inicia o timer
            result = MetIte(n);
            Ticks[1] = clock(); //Finaliza o timer
            break;

         case 3:
         default:
            break;
      }
      
      double tempo = (Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC;

      printf("Resultado: %lld\n", result);
      printf("Tempo gasto pra calcular: %f\n\n", tempo);
   }

   return 0;
}