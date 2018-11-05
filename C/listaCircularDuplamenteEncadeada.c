#include <stdio.h>
#include <locale.h>

struct nodo
{
    int dado;
    struct nodo *proximo;
    struct nodo *anterior;
};
typedef struct nodo Nodo;

///Ponteiro que apontar� para o endere�o do registro que estiver no in�cio da lista
Nodo *inicio = NULL;

///Ponteiro que apontar� para o endere�o do registro que estiver no fim da lista
Nodo *fim = NULL;

///Retorna novo endere�o
Nodo *NewNodoAddress(){
    return (Nodo*)malloc(sizeof(Nodo));
}

////Ponteiro auxiliar que apontar� para o novo registro
//Nodo *novo = NULL;


///Mostra o cabe�alho da aplica��o
void MostrarCabecalho(){
    system("cls");
}

///Pede para o usu�rio escolher uma op��o do menu
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

///Lista todos os itens da Lista
void ShowItems(){
    if(inicio == NULL){
        printf("A Lista est� vazia!\n");
        system("pause");

        return;
    }

    //ponteiro auxiliar para encontrar o maior elemento da lista
    Nodo *ptAux = inicio;

    do{
        printf("%d\n", ptAux->dado);
    }while(ptAux->proximo != inicio);
}

///Adiciona um item no come�o da Lista
void IncInBegin(){

}

int main(){
    setlocale(LC_ALL, "portuguese");

    int op = 0;
    
    while ((op = EscolherOpcao()) != 0)
    {
        switch (op)
        {
            //Incluir no in�cio
            case 1:
                IncInBegin();
                break;

            //Incluir no final da lista
            case 2:
                //EXERC�CIO                
                break;

            //Incluir antes de um valor x informado pelo usu�rio
            case 3:
            
                /*O SISTEMA DEVER� MOSTRAR TODOS OS DADOS ARMAZENADOS NA LISTA
                * O USU�RIO DEVER� INFORMAR O VALOR QUE DESEJA INSERIR E TAMB�M O VALOR DE x. O SISTEMA DEVER�
                * INSERIR O NOVO ELEMENTO ANTES DE x */
                
                //EXERC�CIO
                break;

            //Excluir do in�cio da lista
            case 4:
	            //EXERC�CIO
                break;

            //Excluir do fim da lista
            case 5:
                //EXERC�CIO 
                break;

            //Excluir um valor x informado pelo usu�rio
            case 6: 
                //EXERC�CIO
                break;

            //Exibir dados da Lista
            case 7:
                ShowItems();
                break;
        }
    }

    printf("Fechando aplica��o...\n");
    return 0;
}