#include <stdio.h>
#include <locale.h>

struct Nodo
{
    int dado;
    struct Nodo *proximo;
    struct Nodo *anterior;
};

///Ponteiro que apontará para o endereço do registro que estiver no início da lista
struct Nodo *inicio = NULL;

///Ponteiro que apontará para o endereço do registro que estiver no fim da lista
struct Nodo *fim = NULL;

////Ponteiro auxiliar que apontará para o novo registro
//struct Nodo *novo = NULL;
////ponteiro auxiliar para encontrar o maior elemento da lista
//struct Nodo *ptAux = NULL;

void MostrarCabecalho(){
    system("cls");
}

int EscolherOpcao(){
    MostrarCabecalho();

    printf("1 - Incluir no início da lista\n");
    printf("2 - Incluir no final de lista\n");
    printf("3 - Incluir antes de um valor informado pelo usuário\n");
    printf("4 - Excluir do início\n");
    printf("5 - Excluir do final\n");
    printf("6 - Excluir um valor informado\n");
    printf("7 - Imprimir Lista\n");
    printf("0 - Sair\n");
    

    int op;
    do{
        printf("Digite uma opção: ");
        scanf("%d",&op);

        if(op < 0 || op > 7){
            printf("Opção inválida! ");
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
            case 1:/*incluir no início*/                
                
                //EXERCÍCIO
                
                break;

            case 2:/*incluir no final da lista*/
                
                //EXERCÍCIO                
                
                break;

            case 3:/*incluir antes de um valor x informado pelo usuário*/
            
                /*O SISTEMA DEVERÁ MOSTRAR TODOS OS DADOS ARMAZENADOS NA LISTA
                * O USUÁRIO DEVERÁ INFORMAR O VALOR QUE DESEJA INSERIR E TAMBÉM O VALOR DE x. O SISTEMA DEVERÁ
                * INSERIR O NOVO ELEMENTO ANTES DE x */
                
                //EXERCÍCIO                
                
                break;

            case 4:/*excluir do início da lista*/               

	        //EXERCÍCIO	        
		
                break;

            case 5:/*excluir do fim da lista*/
            
                //EXERCÍCIO
                
                break;

            case 6:/*excluir um valor x informado pelo usuário*/
                
                //EXERCÍCIO
                
                break;

            case 7:/*EXIBIR DADOS DA LISTA*/
                
                //EXERCÍCIO
                
                break;
        }
    }

    printf("Fechando aplicação...\n");
    return 0;
}