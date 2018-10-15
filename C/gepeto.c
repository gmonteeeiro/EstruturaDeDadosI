#include <stdio.h>
#include <locale.h>

void menu();

int main(){
    setlocale(LC_ALL, "portuguese");


    float valor = 100;
    char nome[50];
    int comprimento;
    int largura;
    int madeira;
    int gavetas;

    menu();
    printf("Nome do Cliente: ");
    scanf("%s", nome);

    menu();
    printf("Comprimento da mesa (em cm): ");
    scanf("%d", &comprimento);

    menu();
    printf("Largura da mesa (em cm): ");
    scanf("%d", &largura);

    menu();
    printf("Madeiras dispon�veis:\n");
    printf("   1 - Mogno\n");
    printf("   2 - Carvalho\n");
    printf("   3 - Pinho\n");
    printf("Informe o tipo de madeira desejada: ");
    scanf("%d", &madeira);

    menu();
    printf("Informe o n�mero de gavetas: ");
    scanf("%d", &gavetas);

    // Valida acr�scimo no valor referente ao tamanho
    valor += comprimento * largura > 900 ? 20 : 0;

    // Valida acr�scimos referentes aos tipos de madeira
    valor += madeira == 1 ? 50 : 0; // mogno
    valor += madeira == 2 ? 30 : 0; // carvalho

    // Acr�scimo refente �s gavetas
    valor += gavetas * 15;

    menu();
    printf(" ----------------------------------------\n");
    printf("| Cliente: %-30s|\n", nome);
    printf("| Comprimento: %-3d                       |\n", comprimento);
    printf("| Largura: %-3d                           |\n", largura);
    printf("| Madeira: %-30s|\n", (madeira == 1 ? "Mogno" : (madeira == 2 ? "Carvalho" : "Pinho")));
    printf("| N� de Gavetas: %-2d                      |\n", gavetas);
    printf("|                          Total: %5.2f |\n", valor);
    printf(" ----------------------------------------\n");


    printf("\n");
    return 0;
}

void menu(){
    system("cls");
    printf("**********************************************************\n");
    printf("*                  Gepeto's Carpintaria                  *\n");
    printf("*                                    by Gabriel Monteiro *\n");
    printf("**********************************************************\n\n");
}