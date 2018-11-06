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
int ShowItems(int pause){
    if(inicio == NULL){
        printf("A Lista está vazia!\n");

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
    //Verifica se a lista está vazia
    if(inicio == NULL){
        return NULL;
    }

    int find = 0;
    Nodo *ptAux = inicio;
    Nodo *k = NULL;

    //Procura o item informado pelo usuário
    do{
        if(ptAux->dado == userItem){
            k = ptAux;
            find = 1;
        }
        ptAux = ptAux->proximo;
    }while(ptAux != inicio && !find);

    //Se não encontrou o item retorna NULL
    if(!find){
        return NULL;
    }

    return k;
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

void IncBeforeItem(){
    MostrarCabecalho();

    Nodo *novo = NewNodoAddress();

    if(novo == NULL){
        printf("Problema na alocação de memória!\n");

        exit(1);
    }

    if (ShowItems(0) == 0){
        system("pause");
        return;
    }

    int userItem;
    printf("Insira o item a ser que ficará após o novo item: ");
    scanf("%d", &userItem);

    Nodo *k = FindItem(userItem);
    if(k == NULL){
        printf("Item não encontrado!\n");

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
                IncBeforeItem();
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
                ShowItems(1);
                break;
        }
    }

    printf("Fechando aplicação...\n");
    return 0;
}