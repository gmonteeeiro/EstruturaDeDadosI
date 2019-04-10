#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct sVertice{
    int chave;
    struct sVertice* esquerdo;
    struct sVertice* direito;
};

typedef struct sVertice Vertice;

Vertice* alocaVertice(int chave){
    Vertice* novo;
    novo = (Vertice*)malloc(sizeof(Vertice));/*aloca mem�ria necess�ria para um novo registro*/
    if(novo != NULL)//se conseguiu alocar
    {
        novo->chave = chave;/*adiciona a chave digitada pelo usu�rio ao campo chave do novo v�rtice*/
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;//retorna o endere�o de mem�ria alocado ou NULL se n�o conseguir alocar espa�o
}

int menu(){
    int op;
    printf("(1)Inserir\n");
    printf("(2)Imprimir\n");
    printf("(3)Excluir folha\n");
    printf("(4)Sair\n");
    printf("Digite uma op��o: ");
    scanf("%d",&op);
    return op;
}

Vertice* gPai;

// fun��o para procurar um nodo
Vertice* search(Vertice* root, Vertice* pai, int chave)
{ 
    // Verifica se n�o est� na raiz
    if (root == NULL || root->chave == chave){
       gPai = pai;
       return root;
    }
     
    // Chave � maior que a raiz
    if (root->chave < chave)
       return search(root->direito, root, chave);
  
    // Chave � menor que a raiz
    return search(root->esquerdo, root, chave);
} 

void procura(Vertice* root, int chave){
   Vertice* proc = search(root, NULL, chave);
   if(proc == NULL){
      printf("nao encontrado");
   }
   else
   {
      printf("Meu endere�o = %d\t", (int)proc);
      printf("Endere�o pai = %d\t", (int)gPai);
   }
}

//Insere um v�rtice na BST
Vertice* insert(Vertice* nodo, int chave) { 
    //Se a �rvore est� vazia, retorna um novo nodo
    if (nodo == NULL) return alocaVertice(chave);
  
    //Se n�o, desce a �rvore
    if (chave < nodo->chave) 
        nodo->esquerdo = insert(nodo->esquerdo, chave);
    else if (chave > nodo->chave)
        nodo->direito = insert(nodo->direito, chave);
  
    //Retorna o ponteiro
    return nodo;
}

void imprimir(Vertice* vertice){
    Vertice* ptAux;
    ptAux = vertice;
    if (ptAux != NULL)
    {
        printf("Meu endere�o = %d\t", (int)ptAux);
        printf("Filho Esquerdo = %d\t", (int)ptAux->esquerdo);
        printf("Filho Direito = %d\t", (int)ptAux->direito);
        printf("Chave = %d ", ptAux->chave);
        printf("\n");
        imprimir(ptAux->esquerdo); //chamada recursiva
        imprimir(ptAux->direito); //chamada recursiva
    }
}

void excluirFolha(Vertice** raiz, int chave){
    /*EXERC�CIO*/
}

int main(){
   setlocale(LC_ALL, "portuguese");
   int op = 0, chave;
   Vertice* ptRaiz = NULL;/*cria um ponteiro para armazenar o endere�o da raiz da �rvore*/
   while (op != 4)
   {
      //op = menu();
      op = 3;
      switch (op)
      {
         case 1: //inserir v�rtice
         printf("Digite o valor do v�rtice: ");
         scanf("%d",&chave);
           
         if (ptRaiz == NULL) //se �rvore est� vazia
            ptRaiz = insert(ptRaiz, chave);
         else
            insert(ptRaiz, chave);
         
         break;

       case 2:/*imprimir*/
           printf("\n");
           if(ptRaiz!=NULL)//se �rvore tem conte�do
               imprimir(ptRaiz);
           else
               printf("\n�rvore Vazia\n\n");
           break;
       
       case 3: //procura
           ptRaiz = insert(ptRaiz, 4);
           
           insert(ptRaiz, 5);
           imprimir(ptRaiz);
           procura(ptRaiz, 4);

           op = 4;
           break;

       default:
           printf("\nOp��o inv�lida\n\n");
           break;
       }
   }
   system("pause");
   return 0;
}