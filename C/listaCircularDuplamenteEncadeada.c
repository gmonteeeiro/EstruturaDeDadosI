#include <stdio.h>
#include <locale.h>

struct nodo
{
    int dado;
    struct nodo *proximo;
    struct nodo *anterior;
};
typedef struct nodo Nodo;

///Ponteiro que apontará para o endereço do registro que estiver no início da lista
Nodo *inicio = NULL;

///Ponteiro que apontará para o endereço do registro que estiver no fim da lista
Nodo *fim = NULL;

///Retorna novo endereço
Nodo *NewNodoAddress(){
    return (Nodo*)malloc(sizeof(Nodo));
}

////Ponteiro auxiliar que apontará para o novo registro
//Nodo *novo = NULL;


///Mostra o cabeçalho da aplicação
void MostrarCabecalho(){
    system("cls");
}

///Pede para o usuário escolher uma opção do menu
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

///Lista todos os itens da Lista
void ShowItems(){
    if(inicio == NULL){
        printf("A Lista está vazia!\n");
        system("pause");

        return;
    }

    //ponteiro auxiliar para percorrer a Lista
    Nodo *ptAux = inicio;

    do{
        printf("%d\n", ptAux->dado);
        ptAux = ptAux->proximo;
    }while(ptAux != inicio);
    system("pause");
}

///Adiciona um item no começo da Lista
void IncInBegin(){
    MostrarCabecalho();

    Nodo *novo = NewNodoAddress();

    if(novo == NULL){
        printf("Problema na alocação de memória!\n");

        exit(1);
    }

    printf("Digite o valor a ser inserido no início da Lista: ");
    scanf("%d", &novo->dado);

    //Verifica se é o primeiro item da Lista
    if(inicio == NULL){
        fim = novo;
        novo->proximo = novo;
        novo->anterior = novo;
    }
    else{
        fim->proximo = novo; //Aponta para o novo nodo, que é o primeiro (Lista Circular)
        novo->proximo = inicio; //Aponta para o próximo item, antigo início
        novo->anterior = fim; //Aponta para o último item (Lista Circular)
        inicio->anterior = novo; //Antigo inicio aponta para o novo inicio
    }
    inicio = novo;
}

///Adiciona um item no fim da Lista
void IncInEnd(){
    MostrarCabecalho();

    Nodo *novo = NewNodoAddress();

    if(novo == NULL){
        printf("Problema na alocação de memória!\n");

        exit(1);
    }

    printf("Digite o valor a ser inserido no final da Lista: ");
    scanf("%d", &novo->dado);

    //Verifica se a Lista está vazia
    if(fim == NULL){
        inicio = novo;
        novo->proximo = novo;
        novo->anterior = novo;
    }
    else{
        fim->proximo = novo; //Aponta para o novo nodo, que é o último
        novo->proximo = inicio; //Aponta para o próximo item, o início (Lista Circular)
        novo->anterior = fim; //Aponta para o último item
        inicio->anterior = novo; //Inicio aponta para o novo último (Lista Circular)
    }
    fim = novo;
}

int main(){
    setlocale(LC_ALL, "portuguese");

    int op = 0;
    
    while ((op = EscolherOpcao()) != 0)
    {
        switch (op)
        {
            //Incluir no início
            case 1:
                IncInBegin();
                break;

            //Incluir no final da lista
            case 2:
                IncInEnd();
                break;

            //Incluir antes de um valor x informado pelo usuário
            case 3:
            
                /*O SISTEMA DEVERÁ MOSTRAR TODOS OS DADOS ARMAZENADOS NA LISTA
                * O USUÁRIO DEVERÁ INFORMAR O VALOR QUE DESEJA INSERIR E TAMBÉM O VALOR DE x. O SISTEMA DEVERÁ
                * INSERIR O NOVO ELEMENTO ANTES DE x */
                
                //EXERCÍCIO
                break;

            //Excluir do início da lista
            case 4:
	            //EXERCÍCIO
                break;

            //Excluir do fim da lista
            case 5:
                //EXERCÍCIO 
                break;

            //Excluir um valor x informado pelo usuário
            case 6: 
                //EXERCÍCIO
                break;

            //Exibir dados da Lista
            case 7:
                ShowItems();
                break;
        }
    }

    printf("Fechando aplicação...\n");
    return 0;
}