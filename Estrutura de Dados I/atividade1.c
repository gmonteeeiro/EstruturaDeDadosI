/* O código abaixo apresenta uma implementação de uma estrutura de dados do tipo Deque capaz de armazenar somente valores inteiros.
* Para fins didáticos, o código está implementado praticamente sem o uso de funções.
* A tarefa consiste em complementar a implementação das funcionalidades do programa.
* Recomenda-se que os alunos, após resolverem a tarefa, reestruturem o código em subprogramas para melhorar sua legibilidade.
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
			if (n>0)/*se tem conteúdo pra acessar*/
			{
				printf("Acesso:\n ");
				op = subMenu();
				if (op == 1)/*acesso ao início*/
				{
					printf("Nodo do início: %d\n", deque[inicioDeque]);
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
				printf("Elemento do início do deque = %d\n", deque[inicioDeque]);
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
	if (*n < M)//se tem espaço no deque
	{
		int valor;
		printf("Informe valor a ser incluído: ");
		scanf("%d", &valor);
		int op = subMenu(); //para escolher inclusão no inicio ou fim
		switch (subMenu())
		{
			//Inserir no início
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
		(*n)++; //variável controla a quantidade de elementos
		ShowMsg("Nodo inserido com sucesso!");
	}
	else
	{
		printf("Deque cheio!\n");
	}
}

void Remover(int * deque, int * n, int * inicioDeque, int * fimDeque) {
	if (*n > 0)//se deque tem conteúdo
	{
		printf("Exclusão:\n ");
		switch (subMenu())
		{
			//Remover do início
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

		if (n == 0)/*se deque ficou vazio após a exclusão*/
		{

			//exercício

		}
	}
	else
	{
		printf("Deque vazio, impossível remover!\n");
	}
}


int subMenu(){
	int op;
	do
	{
		printf("Escolha a opção (1) Início  (2) Fim\n");
		scanf("%d", &op);
		if (op != 1 && op != 2)
			printf("Opção inválida! Tente novamente!\n");
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
	printf("Escolha uma opção: ");
	scanf("%d", &op);
	return op;
}
