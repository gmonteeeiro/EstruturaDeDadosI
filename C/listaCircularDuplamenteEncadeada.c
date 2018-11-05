#include <stdio.h>
#include <locale.h>

struct Nodo
{
    int dado;
    struct Nodo *proximo;
    struct Nodo *anterior;
};

///Ponteiro que apontar� para o endere�o do registro que estiver no in�cio da lista
struct Nodo *inicio = NULL;

///Ponteiro que apontar� para o endere�o do registro que estiver no fim da lista
struct Nodo *fim = NULL;

////Ponteiro auxiliar que apontar� para o novo registro
//struct Nodo *novo = NULL;
////ponteiro auxiliar para encontrar o maior elemento da lista
//struct Nodo *ptAux = NULL;

void MostrarCabecalho(){
    system("cls");
}

int EscolherOpcao(){
    MostrarCabecalho();

    printf("1 - Incluir no in�cio da lista\n");
    printf("2 - Incluir no final de lista\n");
    printf("3 - Incluir antes de um valor informado pelo usu�rio\n");
    printf("4 - Excluir do in�cio\n");
    printf("5 - Excluir do final\n");
    printf("6 - Excluir um valor informado\n");
    printf("7 - Imprimir Lista\n");
    printf("0 - Sair\n");
    

    int op;
    do{
        printf("Digite uma op��o: ");
        scanf("%d",&op);

        if(op < 0 || op > 7){
            printf("Op��o inv�lida! ");
        }
    }while(op < 0 || op > 7);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int op = 0;
    
    while ((op = EscolherOpcao()) != 0)
    {
        switch (op)
        {
            case 1:/*incluir no in�cio*/                
                
                //EXERC�CIO
                
                break;

            case 2:/*incluir no final da lista*/
                
                //EXERC�CIO                
                
                break;

            case 3:/*incluir antes de um valor x informado pelo usu�rio*/
            
                /*O SISTEMA DEVER� MOSTRAR TODOS OS DADOS ARMAZENADOS NA LISTA
                * O USU�RIO DEVER� INFORMAR O VALOR QUE DESEJA INSERIR E TAMB�M O VALOR DE x. O SISTEMA DEVER�
                * INSERIR O NOVO ELEMENTO ANTES DE x */
                
                //EXERC�CIO                
                
                break;

            case 4:/*excluir do in�cio da lista*/               

	        //EXERC�CIO	        
		
                break;

            case 5:/*excluir do fim da lista*/
            
                //EXERC�CIO
                
                break;

            case 6:/*excluir um valor x informado pelo usu�rio*/
                
                //EXERC�CIO
                
                break;

            case 7:/*EXIBIR DADOS DA LISTA*/
                
                //EXERC�CIO
                
                break;
        }
    }

    printf("Fechando aplica��o...\n");
    return 0;
}