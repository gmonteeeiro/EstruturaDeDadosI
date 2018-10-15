/* O c�digo abaixo apresenta uma implementa��o de uma estrutura de dados do tipo Deque capaz de armazenar somente valores inteiros.
* Para fins did�ticos, o c�digo est� implementado praticamente sem o uso de fun��es.
* A tarefa consiste em complementar a implementa��o das funcionalidades do programa.
* Recomenda-se que os alunos, ap�s resolverem a tarefa, reestruturem o c�digo em subprogramas para melhorar sua legibilidade.
*/


#include <stdio.h>
#include <stdlib.h>
#define M 5

int menu();
int subMenu();
void Inserir(int * deque, int * n, int * inicioDeque, int * fimDeque);
void Remover(int * deque, int * n, int * inicioDeque, int * fimDeque);

void ShowMsg(char * msg) {
	printf("\n%s\n", msg);
	system("pause");
}

int main()
{
	int deque[M];
	int inicioDeque = -1;
	int fimDeque = -1;
	int n = 0;
	int valor;
	int valorRemovido;
	int op;
	int x;

	do
	{
		op = menu();
		switch (op)
		{
		case 1://inserir
			Inserir(deque, &n, &inicioDeque, &fimDeque);
			break;
		case 2://remover
			Remover(deque, &n, &inicioDeque, &fimDeque);
			break;
		case 3://acessar
			if (n>0)/*se tem conte�do pra acessar*/
			{
				printf("Acesso:\n ");
				op = subMenu();
				if (op == 1)/*acesso ao in�cio*/
				{
					printf("Nodo do in�cio: %d\n", deque[inicioDeque]);
				}
				else if (op == 2)/*acesso ao fim*/
				{
					printf("Nodo do final: %d\n", deque[fimDeque]);
				}
			}
			else
				printf("Deque vazio!\n");
			break;
		case 4://mostrar o deque
			if (n>0)
			{
				x = 0;
				while (x<n)
				{
					printf("%d ", deque[(inicioDeque + x) % M]);
					x++;
				}
				printf("\n");
				printf("Elemento do in�cio do deque = %d\n", deque[inicioDeque]);
				printf("Elemento do final do deque = %d\n", deque[fimDeque]);
			}
			else
				printf("Deque vazio!\n");
			break;
		case 5:
			printf("Saindo.\n");
			break;
		default:
			printf("Opcao Invalida. Digite novamente!\n");
			break;
		}
	} while (op != 5);
	return 0;
}

void Inserir(int * deque, int * n, int * inicioDeque, int * fimDeque) {
	if (*n < M)//se tem espa�o no deque
	{
		int valor;
		printf("Informe valor a ser inclu�do: ");
		scanf("%d", &valor);
		int op = subMenu(); //para escolher inclus�o no inicio ou fim
		switch (subMenu())
		{
			//Inserir no in�cio
			case 1:
				if (n == 0) //Primeiro item
				{
					*inicioDeque = 0;
					*fimDeque = 0;

					deque[*inicioDeque] = valor;
				}
				else
				{
					if (*inicioDeque == 0)
					{
						*inicioDeque = (M - 1);
						deque[*inicioDeque] = valor;
					}
				}

				break;

			//Inserir no final
			case 2:
				if (n == 0) //Primeiro item
				{
					*inicioDeque = 0;
					*fimDeque = 0;

					deque[*fimDeque] = valor;

				}
				else
				{
					*fimDeque = (*fimDeque + 1) % M;
					deque[*fimDeque] = valor;
				}

				break;

			default:
				break;
		}
		(*n)++; //vari�vel controla a quantidade de elementos
		ShowMsg("Nodo inserido com sucesso!");
	}
	else
	{
		printf("Deque cheio!\n");
	}
}

void Remover(int * deque, int * n, int * inicioDeque, int * fimDeque) {
	if (*n > 0)//se deque tem conte�do
	{
		printf("Exclus�o:\n ");
		switch (subMenu())
		{
			//Remover do in�cio
			case 1:
				if (*n != 1) {
					if (*inicioDeque == (M - 1))
					{
						*inicioDeque = 0;
					}
					else
					{
						(*inicioDeque)++;
					}
				}
				else
				{
					*inicioDeque = -1;
					*fimDeque = -1;
				}
				break;

			//Remover do fim
			case 2:
				if (*n != 1) {
					if (*fimDeque == 0)
					{
						*fimDeque = (M - 1);
					}
					else
					{
						(*fimDeque)--;
					}
				}
				else
				{
					*inicioDeque = -1;
					*fimDeque = -1;
				}
				break;
			default:
				break;
		}

		n--;
		printf("Valor removido com sucesso!\n");

		if (n == 0)/*se deque ficou vazio ap�s a exclus�o*/
		{

			//exerc�cio

		}
	}
	else
	{
		printf("Deque vazio, imposs�vel remover!\n");
	}
}


int subMenu(){
	int op;
	do
	{
		printf("Escolha a op��o (1) In�cio  (2) Fim\n");
		scanf("%d", &op);
		if (op != 1 && op != 2)
			printf("Op��o inv�lida! Tente novamente!\n");
	} while (op != 1 && op != 2);
	return op;
}

int menu(){
	int op;
	printf("1 - Inserir Nodo\n");
	printf("2 - Remover Nodo\n");
	printf("3 - Acessar Nodo\n");
	printf("4 - Mostrar deque\n");
	printf("0 - Sair\n");
	printf("Escolha uma op��o: ");
	scanf("%d", &op);
	return op;
}
