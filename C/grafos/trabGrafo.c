#include <stdio.h>
#include <locale.h>

struct adjacente{
    struct vertice* vert; //Aponta para o vértice

    struct adjacente* proximo; // Aponta para o próximo adjacente 
};
typedef struct adjacente Adjacente;

struct vertice{
    int code; // Informação do Vértice

    struct adjacente* primAdj; // Aponta para o primeiro adjacente desse vértice
    struct vertice* proximo;   // Aponta para o próximo vértice
};
typedef struct vertice Vertice;

Adjacente* AlocaAdjacente();
Vertice* AlocaVertice();
int EscolherOpc();
void MostrarCabecalho();
void ConectaVertices();
void ImprimirGrafos();
void MsgWaitKey(char* msg);

//Aponta para o endereço do primeiro vértice
Vertice *inicio = NULL;

int main(){
    setlocale(LC_ALL, "portuguese");
    int op;

    //Roda o programa até o usuário desistir
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

///Mostra o cabeçalho da aplicação
void MostrarCabecalho(){
    system("cls");
}

///Pede para o usuário escolher uma opção do menu
int EscolherOpc(){
    MostrarCabecalho();

    //Quantidade de opções deste menu
    int numOpc = 3;

    printf("1 - Conectar\n"); //conecta dois vertices
    printf("2 - Desconectar\n"); //desconecta dois vertices
    printf("3 - Imprimir\n"); //mostra todos os dados do grafo
    printf("0 - Sair\n");
    

    int op;
    do{
        printf("Digite uma opção: ");
        scanf("%d",&op);

        if(op < 0 || op > numOpc){
            printf("Opção inválida! ");
        }
    }while(op < 0 || op > numOpc);
}

//Aloca um novo endereço para o vértice
Vertice* AlocaVertice(){
    Vertice *novo = (Vertice*)malloc(sizeof(Vertice));
    
    //Verifica se houve erro na alocação
    if(novo == NULL){
        exit(1);
    }
    else{
        novo->proximo = NULL;
    }

    return novo;
}

//Aloca um novo endereço para o adjacente
Adjacente* AlocaAdjacente(){
    Adjacente *novo = (Adjacente*)malloc(sizeof(Adjacente));

    //Verifica se houve erro na alocação
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

    printf("Informe o primeiro vértice: ");
    scanf("%d", &v1);
    
    printf("Informe o segundo vértice: ");
    scanf("%d", &v2);

    MostrarCabecalho();
    printf("Conectando o vértice %d ao %d...\n", v2, v1);

    //Lista estava vazia, cadastrar os 2 vértices
    if(inicio == NULL){
        inicio = AlocaVertice();
        inicio->code = v1;

        Vertice* novo = AlocaVertice();
        novo->code = v2;

        inicio->proximo = novo;

        //Cria o adjacente
        Adjacente* adj = AlocaAdjacente();
        adj->vert = novo;

        inicio->primAdj = adj;

        MsgWaitKey("Vértices criados e conectados!");
    }
}

void ImprimirGrafos(){
    MostrarCabecalho();

    //Verifica se grafo está vazio
    if (inicio == NULL){
        MsgWaitKey("O Grafo está vazio...");
        return;
    }

    Vertice* auxV = inicio;
    Adjacente* auxA = NULL;

    // Enquanto não chegar no final da lista de vertices
    while (auxV != NULL){
        printf("\nO Vertice %d está ligado aos vertices ", auxV->code);

        auxA = auxV->primAdj; //Seta o auxiliar como o primeiro adjacente
        while (auxA != NULL){
            printf("%d, ", auxA->vert->code);
            auxA = auxA->proximo;
        }

        auxV = auxV->proximo;
    }
}