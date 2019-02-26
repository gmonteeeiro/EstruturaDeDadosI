#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void printa(int num, int ate){
   printf("%d\n", num);

   if(num < ate) printa(++num, ate);
}

int main(){
   setlocale(LC_ALL, "portuguese");
   int ate;
   printf("Contar até: ");
   scanf("%d", &ate);

   printa(0, ate);

   printf("\n");
   system("pause");
}