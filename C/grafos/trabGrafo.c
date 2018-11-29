#include <stdio.h>
#include <locale.h>

struct adjacente{
    struct vertice* vert; //Aponta para o v�rtice

    struct adjacente* proximo; // Aponta para o pr�ximo adjacente 
};
typedef struct adjacente Adjacente;

struct vertice{
    int code; // Informa��o do V�rtice

    struct adjacente* primAdj; // Aponta para o primeiro adjacente desse v�rtice
    struct vertice* proximo;   // Aponta para o pr�ximo v�rtice
};
typedef struct vertice Vertice;

Adjacente* AlocaAdjacente();
Vertice* AlocaVertice();
int EscolherOpc();
void MostrarCabecalho();
void ConectaVertices();
void ImprimirGrafos();
void MsgWaitKey(char* msg);

//Aponta para o endere�o do primeiro v�rtice
Vertice *inicio = NULL;

int main(){
    setlocale(LC_ALL, "portuguese");
    int op;

    //Roda o programa at� o usu�rio desistir
    while((op = EscolherOpc()) != 0){
        switch(op){
            case 1: //Conecta V1 em V2
                ConectaVertices();
                break;

            case 2: //Desconecta
                break;

            case 3: //Imprime
                ImprimirGrafos();
                break;
        }
    }
}

void MsgWaitKey(char* msg){
    printf(msg);
    printf("\n");
    system("pause");
}

///Mostra o cabe�alho da aplica��o
void MostrarCabecalho(){
    system("cls");
}

///Pede para o usu�rio escolher uma op��o do menu
int EscolherOpc(){
    MostrarCabecalho();

    //Quantidade de op��es deste menu
    int numOpc = 3;

    printf("1 - Conectar\n"); //conecta dois vertices
    printf("2 - Desconectar\n"); //desconecta dois vertices
    printf("3 - Imprimir\n"); //mostra todos os dados do grafo
    printf("0 - Sair\n");

    int op;
    do{
        printf("Digite uma op��o: ");
        scanf("%d",&op);

        if(op < 0 || op > numOpc){
            printf("Op��o inv�lida! ");
        }
    }while(op < 0 || op > numOpc);
}

//Aloca um novo endere�o para o v�rtice
Vertice* AlocaVertice(){
    Vertice *novo = (Vertice*)malloc(sizeof(Vertice));
    
    //Verifica se houve erro na aloca��o
    if(novo == NULL){
        exit(1);
    }
    else{
        novo->proximo = NULL;
    }

    return novo;
}

//Aloca um novo endere�o para o adjacente
Adjacente* AlocaAdjacente(){
    Adjacente *novo = (Adjacente*)malloc(sizeof(Adjacente));

    //Verifica se houve erro na aloca��o
    if(novo == NULL){
        exit(1);
    }
    else{
        novo->proximo = NULL;
    }

    return novo;
}

void ConectaVertices(){
    MostrarCabecalho();
    int v1;
    int v2;

    printf("Informe o primeiro v�rtice: ");
    scanf("%d", &v1);
    
    printf("Informe o segundo v�rtice: ");
    scanf("%d", &v2);

    MostrarCabecalho();
    printf("Conectando o v�rtice %d ao %d...\n", v2, v1);

    //Lista estava vazia, cadastrar e conectar os 2 v�rtices
    if(inicio == NULL){
        inicio = AlocaVertice();
        Vertice* novo = AlocaVertice();

        novo->code = v2;

        inicio->code = v1;
        inicio->proximo = novo;

        //Cria o adjacente
        Adjacente* adj = AlocaAdjacente();
        adj->vert = novo;

        inicio->primAdj = adj;

        MsgWaitKey("V�rtices criados e conectados!");
        return;
    }

    Vertice* auxVt = inicio;
    Vertice* antVt = NULL;

    Adjacente* adj = AlocaAdjacente();

    /* Programa primeiro verifica o v�rtice 2 para j� criar o adjacente */

    //---> Verifica se o v�rtice 2 j� foi criado
    while(auxVt != NULL && auxVt->code != v2){
        antVt = auxVt;
        auxVt = auxVt->proximo;
    }

    //Verifica se n�o encontrou ent�o deve cadastralo
    if(auxVt == NULL) {
        Vertice* novo  = AlocaAdjacente();
        novo->code = v2;

        adj->vert = novo;
    }
    else{
        adj->vert = antVt;
    }
    //---<

    //---> Verifica se o v�rtice 1 j� foi criado
    while(auxVt != NULL && auxVt->code != v1){
        antVt = auxVt;
        auxVt = auxVt->proximo;
    }

    //Verifica se n�o encontrou o V1 (ent�o deve cadastra-lo)
    if(auxVt == NULL) {
        Vertice* novo  = AlocaAdjacente();
        novo->code = v1;

        //Adjacente* adj = AlocaAdjacente();
    }



    if (auxV == NULL)//se foi at� o final da lista de vertices e n�o encontrou v1 ent�o deve-se cadastr�-lo
        {
            novoV = alocaVertice();//aloca v�rtice para armazenar v1
            novoV->v = v1;
            novoA = alocaAdjacente();//aloca adjacente para armazenar v2 na lista de adjacentes de v1
            novoA->a = v2;
            novoV->proxA = novoA;//conecta o v�rtice adjacente ao v�rtice v1
            antV->proxV = novoV;//conecta o v�rtice criado ao final da lista de v�rtices
        }


}

void ImprimirGrafos(){
    MostrarCabecalho();

    //Verifica se grafo est� vazio
    if (inicio == NULL){
        MsgWaitKey("O Grafo est� vazio...");
        return;
    }

    Vertice* auxV = inicio;
    Adjacente* auxA = NULL;

    // Enquanto n�o chegar no final da lista de vertices
    while (auxV != NULL){
        printf("\nO Vertice %d est� ligado aos vertices ", auxV->code);

        auxA = auxV->primAdj; //Seta o auxiliar como o primeiro adjacente
        while (auxA != NULL){
            printf("%d, ", auxA->vert->code);
            auxA = auxA->proximo;
        }

        auxV = auxV->proximo;
    }
}