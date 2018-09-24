#include <stdio.h>
#include <locale.h>
#define CAPACIDADE 10

int MostraMenu();
void Insert(int * filme, int * topo);
void Remove(int * filme, int * topo);
void View(int * filme, int topo);

int main()
{
	setlocale(LC_ALL, "portuguese");

	int minhaPilha[CAPACIDADE];
	int topo = -1;

	int opc;

	do
	{
		opc = MostraMenu();
		switch (opc)
		{
		case 1:
			Insert(minhaPilha, &topo);
			break;

		case 2:
			Remove(minhaPilha, &topo);
			break;

		case 3:
			View(minhaPilha, topo);
			break;

		default:
			break;
		}

	} while (opc);

	return 0;
}

int MostraMenu()
{
	system("clear");
	printf("1 - Adicionar\n");
	printf("2 - Remover\n");
	printf("3 - Visualizar\n");
	printf("0 - Sair\n");

	int opc;

	do {
		printf("Selecionar opção: ");
		scanf("%d", &opc);

		if (opc < 0 || opc > 3)
		{
			printf("Opção inválida! ");
		}
	} while ((opc < 0 || opc > 3));

	return opc;
}

void Insert(int * pilha, int * topo)
{
	//Pilha tem espaço livre
	if (*topo < CAPACIDADE)
	{
		int valor;
		printf("Insira o valor a ser inserido: ");
		scanf("%d", &valor);

		(*topo)++;
		pilha[*topo] = valor;

		printf("Valor inserido com sucesso! ");
		system("pause");
	}
}

void Remove(int * pilha, int * topo)
{
	// Pilha não está vazia
	if (*topo >= 0)
	{
		(*topo)--;

		printf("Valor removido com sucesso! ");
	}
	else
	{
		printf("A Pilha está vazia! ");
	}
	system("pause");

}

void View(int * pilha, int topo)
{
	//Pilha não está vazia
	if (topo >= 0)
	{
		printf("Último item: %d. ", pilha[topo]);
	}
	system("pause");
}