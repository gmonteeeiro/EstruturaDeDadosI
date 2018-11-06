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
int ShowItems(int pause){
    if(inicio == NULL){
        printf("A Lista est� vazia!\n");

        if(pause) system("pause");
        return;
    }

    //ponteiro auxiliar para percorrer a Lista
    Nodo *ptAux = inicio;

    int count = 0;

    do{
        printf("%d\n", ptAux->dado);
        ptAux = ptAux->proximo;

        count++;
    }while(ptAux != inicio);
    
    if(pause) system("pause");

    return count;
}

///Procura um determinado item
Nodo *FindItem(int userItem){
    //Verifica se a lista est� vazia
    if(inicio == NULL){
        return NULL;
    }

    int find = 0;
    Nodo *ptAux = inicio;
    Nodo *k = NULL;

    //Procura o item informado pelo usu�rio
    do{
        if(ptAux->dado == userItem){
            k = ptAux;
            find = 1;
        }
        ptAux = ptAux->proximo;
    }while(ptAux != inicio && !find);

    //Se n�o encontrou o item retorna NULL
    if(!find){
        return NULL;
    }

    return k;
}

///Adiciona um item no come�o da Lista
void IncInBegin(){
    MostrarCabecalho();

    Nodo *novo = NewNodoAddress();

    if(novo == NULL){
        printf("Problema na aloca��o de mem�ria!\n");

        exit(1);
    }

    printf("Digite o valor a ser inserido no in�cio da Lista: ");
    scanf("%d", &novo->dado);

    //Verifica se � o primeiro item da Lista
    if(inicio == NULL){
        fim = novo;
        novo->proximo = novo;
        novo->anterior = novo;
    }
    else{
        fim->proximo = novo; //Aponta para o novo nodo, que � o primeiro (Lista Circular)
        novo->proximo = inicio; //Aponta para o pr�ximo item, antigo in�cio
        novo->anterior = fim; //Aponta para o �ltimo item (Lista Circular)
        inicio->anterior = novo; //Antigo inicio aponta para o novo inicio
    }
    inicio = novo;
}

///Adiciona um item no fim da Lista
void IncInEnd(){
    MostrarCabecalho();

    Nodo *novo = NewNodoAddress();

    if(novo == NULL){
        printf("Problema na aloca��o de mem�ria!\n");

        exit(1);
    }

    printf("Digite o valor a ser inserido no final da Lista: ");
    scanf("%d", &novo->dado);

    //Verifica se a Lista est� vazia
    if(fim == NULL){
        inicio = novo;
        novo->proximo = novo;
        novo->anterior = novo;
    }
    else{
        fim->proximo = novo; //Aponta para o novo nodo, que � o �ltimo
        novo->proximo = inicio; //Aponta para o pr�ximo item, o in�cio (Lista Circular)
        novo->anterior = fim; //Aponta para o �ltimo item
        inicio->anterior = novo; //Inicio aponta para o novo �ltimo (Lista Circular)
    }
    fim = novo;
}

void IncBeforeItem(){
    MostrarCabecalho();

    Nodo *novo = NewNodoAddress();

    if(novo == NULL){
        printf("Problema na aloca��o de mem�ria!\n");

        exit(1);
    }

    if (ShowItems(0) == 0){
        system("pause");
        return;
    }

    int userItem;
    printf("Insira o item a ser que ficar� ap�s o novo item: ");
    scanf("%d", &userItem);

    Nodo *k = FindItem(userItem);
    if(k == NULL){
        printf("Item n�o encontrado!\n");

        system("pause");
        return;
    }

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &novo->dado);

    novo->proximo = k;
    novo->anterior = k->anterior;
    k->anterior->proximo = novo;
    k->anterior = novo;

    if(k == inicio){
        inicio = novo;
    }
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
                IncInEnd();
                break;

            //Incluir antes de um valor x informado pelo usu�rio
            case 3:
                IncBeforeItem();
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
                ShowItems(1);
                break;
        }
    }

    printf("Fechando aplica��o...\n");
    return 0;
}