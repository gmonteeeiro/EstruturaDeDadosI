#include <stdio.h>
#include <time.h>
#include <windows.h>

// Método para esperar determinado tempo
void delay(unsigned int mSeconds){
    clock_t goal = mSeconds + clock();
    while (goal > clock());
}

// Thread executada em segundo plano
DWORD WINAPI ThreadFunc(void* data) {

    // Espera um tempo antes de fazer o printf
    delay(700);
    printf("Teste de thread\n");

    return 0;
}

// Código Principal
int main() {
  HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

  printf("Teste depois de chamar o Thread\n");

  // Delay para não finalizar o processo pai antes de terminar a Thread
  delay(800);
}