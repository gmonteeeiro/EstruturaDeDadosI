#include<stdio.h>
#include<stdlib.h>


struct Adjacente
{
    int a; //campo que armazenará o dado do vértice adjacente (um valor inteiro qualquer)
    struct Adjacente* proximo;//ponteiro para o próximo nodo da lista de adjacentes
};

struct Vertice
{
    int v;//campo que armazenará o dado do vértice (um valor inteiro qualquer)
    struct Vertice* proxV;//ponteiro para o próximo nodo da lista de vértices
    struct Adjacente* proxA;//ponteiro para o primeiro nodo da lista de adjacentes
};

struct Vertice *inicio = NULL;//cria um ponteiro que apontará para o endereço do registro que estiver no início da lista de vertices
struct Vertice *auxV = NULL;//ponteiro auxiliar para percorrer a lista de Vértices
struct Vertice *novoV = NULL;//ponteiro com endereço do novo vértice
struct Vertice *antV = NULL;//ponteiro auxiliar para armazenar o endereço do vértice anterior
struct Adjacente *auxA = NULL;//ponteiro auxiliar para percorrer a lista de Adjacentes
struct Adjacente *novoA = NULL;//ponteiro com endereço do novo vértice para a lista de Adjacentes
struct Adjacente *antA = NULL;//ponteiro auxiliar para armazenar o endereço do vértice anterior da lista de Adjacentes

int menu()
{
    int op;
    printf("MENU\n");
    printf("(1)Conectar\n");//conecta dois vertices
    printf("(2)Desconectar\n");//desconecta dois vertices
    printf("(3)Imprimir\n");//mostra todos os dados do grafo
    printf("(4)Sair\n");
    printf("Digite uma opção:");
    scanf("%d",&op);
    return op;
}

void imprimir()
{
    if (inicio != NULL)
    {
        auxV = inicio;
        while (auxV != NULL)//enquanto não chegar no final da lista de vertices
        {
            printf("\nVertice - dado: %d\n", auxV->v);
            printf("Vertice - endereço: %d\n", (int)auxV);
            printf("Vertice - proxV: %d\n", (int)auxV->proxV);
            printf("Vertice - proxA: %d\n\n", (int)auxV->proxA);

            auxA = auxV->proxA;//para percorrer a lista de adjacentes do vertice mostrado acima
            while (auxA != NULL)
            {
                printf("Adjacente - dado: %d\n", auxA->a);
                printf("Adjacente - endereço: %d\n", (int)auxA);
                printf("Adjacente - proximo: %d\n\n", (int)auxA->proximo);
                auxA = auxA->proximo;
            }
            auxV = auxV->proxV;//avançar para o proximo nodo da lista de vertices
            printf("------------------------------------------------\n");
        }
    }
    else
        printf("\nGrafo Vazio\n\n");
}

/*função que aloca espaço de memória para um novo registro da lista de adjacentes, atribui NULL ao campo proximo e,
finalmente, retorna em "novo" o endereço do novo registro para o procedimento conecta.
se a alocação de memória não for bem sucedida o programa será encerrado
*/
struct Adjacente* alocaAdjacente()
{
    struct Adjacente *novo = (struct Adjacente*) malloc (sizeof(struct Adjacente));//aloca memória para armazenar o vertice v2 na lista de adjacentes de v1
    if(novo==NULL)//se deu erro na alocação
        exit(1);
    else
        novo->proximo = NULL;
    return novo;
}

/*função que aloca espaço de memória para um novo registro da lista de vértices, atribui NULL aos campos proxV e proxA
do novo registro e, finalmente, retorna em "novo" o endereço do novo registro para o procedimento conecta
SE A ALOCAÇÃO DE MEMÓRIA NÃO FOR BEM SUCEDIDA, O PROGRAMA SERÁ ENCERRADO
*/
struct Vertice* alocaVertice()
{
    struct Vertice *novo = (struct Vertice*) malloc (sizeof(struct Vertice));//aloca memória para armazenar o vertice
    if(novo == NULL)//erro ao alocar memoria
        exit(1);
    else
    {
        novo->proxV = NULL;
        novo->proxA = NULL;
    }
    return novo;
}

void conecta(int v1, int v2)
{

    if (inicio == NULL)//Testa se lista de vétices está vazia
    {
        inicio = alocaVertice();//chama a função para alocar memoria para um nodo do tipo vertice para armazenar v1
        inicio->v = v1;//guarda o dado v1 no campo v de inicio
        novoV = alocaVertice();  //chama a função para alocar memoria para um nodo do tipo vertice para armazenar v2
        novoV->v = v2;//guarda o dado v2 no campo v
        inicio->proxV = novoV;//conecta o novo registro v1 com v2 na lista de vértices
        novoV->proxV = NULL;//pois é o último nodo da lista de vertices
        //criação da lista de adjacencia
        novoA = alocaAdjacente();//chama a função para alocar memória para um nodo to ti?o adjacente para armazenar v2 na lista de adjacentes de v1
        novoA->a = v2;
        inicio->proxA = novoA;//conecta o nodo adjacente v2 ao nodo v1 da lista de vertices
    }
    else//se lista não estava vazia
    {
        auxV = inicio;//ponteiro auxiliar recebe o endereço do primeiro nodo da lista de vertices
        //procura v1 na lista de vértices, pois se já estiver cadastrado, não é necessário cadastrar novamente
        while(auxV!=NULL && auxV->v!=v1)//enquanto não chegar no final da lista de vértices e o dado guardado no campo v for diferente do v1
        {
            antV = auxV;//guarda o endereço visitado em antV
            auxV = auxV->proxV;//avança para o próximo registro da lista de vértices
        }
        if (auxV == NULL)//se foi até o final da lista de vertices e não encontrou v1 então deve-se cadastrá-lo
        {
            novoV = alocaVertice();//aloca vértice para armazenar v1
            novoV->v = v1;
            novoA = alocaAdjacente();//aloca adjacente para armazenar v2 na lista de adjacentes de v1
            novoA->a = v2;
            novoV->proxA = novoA;//conecta o vértice adjacente ao vértice v1
            antV->proxV = novoV;//conecta o vértice criado ao final da lista de vértices
        }
        else//se encontrou o vértice v1 na lista de vértices, ou seja, ele já está cadastrado na lista de vertices
        {
            if (auxV->proxA == NULL)//se o vértice v1 não possui nodo em sua lista de adjacentes entao é preciso incluir o v2 em sua lista
            {
                novoA = alocaAdjacente();//aloca adjacente
                novoA->a = v2;
                auxV->proxA = novoA;//conecta o nodo criado v2 a lista de adjacentes do vértice v1
            }
            else//se o vértice v1 já possui algum adjacente então é necessario verificar se v2 ja faz parte da sua lista de adjacentes
            {
                auxA = auxV->proxA;//para percorrer a lista de adjacentes
                //procura v2 na lista de adjacentes de v1
                while (auxA != NULL && auxA->a != v2)//enquanto não chegar até o final da lista de adjacentes e não encontrar o vertice v2, o algoritmo continua procurando
                {
                    antA = auxA;//guarda o endereço visitado em antA
                    auxA = auxA->proximo;//avança para o próximo registro da lista de Adjacentes
                }
                if (auxA == NULL)//se chegou até o final da lista de adjacentes e não encontrou v2, então ele precisa ser cadastrado
                {
                    novoA = alocaAdjacente();//aloca adjacente
                    novoA->a = v2;
                    antA->proximo = novoA;//conecta o novo nodo adjacente v2 no final da lista de adjacentes de v1
                }
                else
                    printf("\nV2 já encontra-se na lista de adjacentes de V1\n\n");
            }
        }
        //procura v2 na lista de vértices, se já estiver armazenado, não é necessário cadastra-lo, caso contrario, sera preciso inclui-lo
        auxV = inicio;
        while (auxV != NULL && auxV->v != v2)//enquanto não chegar no final da lista de vértices e não encontrar v2
        {
            antV = auxV;//guarda o endereço visitado em antV
            auxV = auxV->proxV;//avança para o próximo registro da lista de Vértices
        }
        if (auxV == NULL)//se foi até o final e não encontrou v2 na lista de vértices
        {
            novoV = alocaVertice();//aloca vértice
            novoV->v = v2;
            antV->proxV = novoV;//conecta o vértice criado ao final da lista de vértices
        }
    }
}

int main()
{
    int op = 0, v1,v2;
    while (op != 4)
    {
        op = menu();//chama função para mostrar menu e solicitar opção do usuário
        switch (op)
        {
        case 1://conectar v1 em v2 (v2 será adjacente a v1, v1 ---> v2)
            printf("Digite o valor do vértice V1:");
            scanf("%d",&v1);
            printf("Digite o valor do vértice V2:");
            scanf("%d",&v2);
            conecta(v1, v2);//chama o procedimento para conectar os vertices v1 e v2
            break;
        case 2://desconectar
            printf("Digite o valor do vértice V1:");
            scanf("%d",&v1);
            printf("Digite o valor do vértice V2:");
            scanf("%d",&v2);
            desconecta(v1, v2);
            break;
        case 3://imprimir
            imprimir();
            break;
        case 4://sair
            printf("Saindo.....\n\n");
            break;
        default:
            printf("Opção invalida!\n\n");
            break;
        }
    }
    return 0;
}


void desconecta(int v1, int v2)
{
//           TG2
}