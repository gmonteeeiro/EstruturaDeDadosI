#include<stdio.h>
#include<stdlib.h>


struct Adjacente
{
    int a; //campo que armazenar� o dado do v�rtice adjacente (um valor inteiro qualquer)
    struct Adjacente* proximo;//ponteiro para o pr�ximo nodo da lista de adjacentes
};

struct Vertice
{
    int v;//campo que armazenar� o dado do v�rtice (um valor inteiro qualquer)
    struct Vertice* proxV;//ponteiro para o pr�ximo nodo da lista de v�rtices
    struct Adjacente* proxA;//ponteiro para o primeiro nodo da lista de adjacentes
};

struct Vertice *inicio = NULL;//cria um ponteiro que apontar� para o endere�o do registro que estiver no in�cio da lista de vertices
struct Vertice *auxV = NULL;//ponteiro auxiliar para percorrer a lista de V�rtices
struct Vertice *novoV = NULL;//ponteiro com endere�o do novo v�rtice
struct Vertice *antV = NULL;//ponteiro auxiliar para armazenar o endere�o do v�rtice anterior
struct Adjacente *auxA = NULL;//ponteiro auxiliar para percorrer a lista de Adjacentes
struct Adjacente *novoA = NULL;//ponteiro com endere�o do novo v�rtice para a lista de Adjacentes
struct Adjacente *antA = NULL;//ponteiro auxiliar para armazenar o endere�o do v�rtice anterior da lista de Adjacentes

int menu()
{
    int op;
    printf("MENU\n");
    printf("(1)Conectar\n");//conecta dois vertices
    printf("(2)Desconectar\n");//desconecta dois vertices
    printf("(3)Imprimir\n");//mostra todos os dados do grafo
    printf("(4)Sair\n");
    printf("Digite uma op��o:");
    scanf("%d",&op);
    return op;
}

void imprimir()
{
    if (inicio != NULL)
    {
        auxV = inicio;
        while (auxV != NULL)//enquanto n�o chegar no final da lista de vertices
        {
            printf("\nVertice - dado: %d\n", auxV->v);
            printf("Vertice - endere�o: %d\n", (int)auxV);
            printf("Vertice - proxV: %d\n", (int)auxV->proxV);
            printf("Vertice - proxA: %d\n\n", (int)auxV->proxA);

            auxA = auxV->proxA;//para percorrer a lista de adjacentes do vertice mostrado acima
            while (auxA != NULL)
            {
                printf("Adjacente - dado: %d\n", auxA->a);
                printf("Adjacente - endere�o: %d\n", (int)auxA);
                printf("Adjacente - proximo: %d\n\n", (int)auxA->proximo);
                auxA = auxA->proximo;
            }
            auxV = auxV->proxV;//avan�ar para o proximo nodo da lista de vertices
            printf("------------------------------------------------\n");
        }
    }
    else
        printf("\nGrafo Vazio\n\n");
}

/*fun��o que aloca espa�o de mem�ria para um novo registro da lista de adjacentes, atribui NULL ao campo proximo e,
finalmente, retorna em "novo" o endere�o do novo registro para o procedimento conecta.
se a aloca��o de mem�ria n�o for bem sucedida o programa ser� encerrado
*/
struct Adjacente* alocaAdjacente()
{
    struct Adjacente *novo = (struct Adjacente*) malloc (sizeof(struct Adjacente));//aloca mem�ria para armazenar o vertice v2 na lista de adjacentes de v1
    if(novo==NULL)//se deu erro na aloca��o
        exit(1);
    else
        novo->proximo = NULL;
    return novo;
}

/*fun��o que aloca espa�o de mem�ria para um novo registro da lista de v�rtices, atribui NULL aos campos proxV e proxA
do novo registro e, finalmente, retorna em "novo" o endere�o do novo registro para o procedimento conecta
SE A ALOCA��O DE MEM�RIA N�O FOR BEM SUCEDIDA, O PROGRAMA SER� ENCERRADO
*/
struct Vertice* alocaVertice()
{
    struct Vertice *novo = (struct Vertice*) malloc (sizeof(struct Vertice));//aloca mem�ria para armazenar o vertice
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

    if (inicio == NULL)//Testa se lista de v�tices est� vazia
    {
        inicio = alocaVertice();//chama a fun��o para alocar memoria para um nodo do tipo vertice para armazenar v1
        inicio->v = v1;//guarda o dado v1 no campo v de inicio
        novoV = alocaVertice();  //chama a fun��o para alocar memoria para um nodo do tipo vertice para armazenar v2
        novoV->v = v2;//guarda o dado v2 no campo v
        inicio->proxV = novoV;//conecta o novo registro v1 com v2 na lista de v�rtices
        novoV->proxV = NULL;//pois � o �ltimo nodo da lista de vertices
        //cria��o da lista de adjacencia
        novoA = alocaAdjacente();//chama a fun��o para alocar mem�ria para um nodo to ti?o adjacente para armazenar v2 na lista de adjacentes de v1
        novoA->a = v2;
        inicio->proxA = novoA;//conecta o nodo adjacente v2 ao nodo v1 da lista de vertices
    }
    else//se lista n�o estava vazia
    {
        auxV = inicio;//ponteiro auxiliar recebe o endere�o do primeiro nodo da lista de vertices
        //procura v1 na lista de v�rtices, pois se j� estiver cadastrado, n�o � necess�rio cadastrar novamente
        while(auxV!=NULL && auxV->v!=v1)//enquanto n�o chegar no final da lista de v�rtices e o dado guardado no campo v for diferente do v1
        {
            antV = auxV;//guarda o endere�o visitado em antV
            auxV = auxV->proxV;//avan�a para o pr�ximo registro da lista de v�rtices
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
        else//se encontrou o v�rtice v1 na lista de v�rtices, ou seja, ele j� est� cadastrado na lista de vertices
        {
            if (auxV->proxA == NULL)//se o v�rtice v1 n�o possui nodo em sua lista de adjacentes entao � preciso incluir o v2 em sua lista
            {
                novoA = alocaAdjacente();//aloca adjacente
                novoA->a = v2;
                auxV->proxA = novoA;//conecta o nodo criado v2 a lista de adjacentes do v�rtice v1
            }
            else//se o v�rtice v1 j� possui algum adjacente ent�o � necessario verificar se v2 ja faz parte da sua lista de adjacentes
            {
                auxA = auxV->proxA;//para percorrer a lista de adjacentes
                //procura v2 na lista de adjacentes de v1
                while (auxA != NULL && auxA->a != v2)//enquanto n�o chegar at� o final da lista de adjacentes e n�o encontrar o vertice v2, o algoritmo continua procurando
                {
                    antA = auxA;//guarda o endere�o visitado em antA
                    auxA = auxA->proximo;//avan�a para o pr�ximo registro da lista de Adjacentes
                }
                if (auxA == NULL)//se chegou at� o final da lista de adjacentes e n�o encontrou v2, ent�o ele precisa ser cadastrado
                {
                    novoA = alocaAdjacente();//aloca adjacente
                    novoA->a = v2;
                    antA->proximo = novoA;//conecta o novo nodo adjacente v2 no final da lista de adjacentes de v1
                }
                else
                    printf("\nV2 j� encontra-se na lista de adjacentes de V1\n\n");
            }
        }
        //procura v2 na lista de v�rtices, se j� estiver armazenado, n�o � necess�rio cadastra-lo, caso contrario, sera preciso inclui-lo
        auxV = inicio;
        while (auxV != NULL && auxV->v != v2)//enquanto n�o chegar no final da lista de v�rtices e n�o encontrar v2
        {
            antV = auxV;//guarda o endere�o visitado em antV
            auxV = auxV->proxV;//avan�a para o pr�ximo registro da lista de V�rtices
        }
        if (auxV == NULL)//se foi at� o final e n�o encontrou v2 na lista de v�rtices
        {
            novoV = alocaVertice();//aloca v�rtice
            novoV->v = v2;
            antV->proxV = novoV;//conecta o v�rtice criado ao final da lista de v�rtices
        }
    }
}

int main()
{
    int op = 0, v1,v2;
    while (op != 4)
    {
        op = menu();//chama fun��o para mostrar menu e solicitar op��o do usu�rio
        switch (op)
        {
        case 1://conectar v1 em v2 (v2 ser� adjacente a v1, v1 ---> v2)
            printf("Digite o valor do v�rtice V1:");
            scanf("%d",&v1);
            printf("Digite o valor do v�rtice V2:");
            scanf("%d",&v2);
            conecta(v1, v2);//chama o procedimento para conectar os vertices v1 e v2
            break;
        case 2://desconectar
            printf("Digite o valor do v�rtice V1:");
            scanf("%d",&v1);
            printf("Digite o valor do v�rtice V2:");
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
            printf("Op��o invalida!\n\n");
            break;
        }
    }
    return 0;
}


void desconecta(int v1, int v2)
{
//           TG2
}