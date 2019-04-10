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
    novo = (Vertice*)malloc(sizeof(Vertice));/*aloca memória necessária para um novo registro*/
    if(novo != NULL)//se conseguiu alocar
    {
        novo->chave = chave;/*adiciona a chave digitada pelo usuário ao campo chave do novo vértice*/
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;//retorna o endereço de memória alocado ou NULL se não conseguir alocar espaço
}

int menu(){
    int op;
    printf("(1)Inserir\n");
    printf("(2)Imprimir\n");
    printf("(3)Excluir folha\n");
    printf("(4)Sair\n");
    printf("Digite uma opção: ");
    scanf("%d",&op);
    return op;
}

Vertice* gPai;

// função para procurar um nodo
Vertice* search(Vertice* root, Vertice* pai, int chave)
{ 
    // Verifica se não está na raiz
    if (root == NULL || root->chave == chave){
       gPai = pai;
       return root;
    }
     
    // Chave é maior que a raiz
    if (root->chave < chave)
       return search(root->direito, root, chave);
  
    // Chave é menor que a raiz
    return search(root->esquerdo, root, chave);
} 

void procura(Vertice* root, int chave){
   Vertice* proc = search(root, NULL, chave);
   if(proc == NULL){
      printf("nao encontrado");
   }
   else
   {
      printf("Meu endereço = %d\t", (int)proc);
      printf("Endereço pai = %d\t", (int)gPai);
   }
}

//Insere um vértice na BST
Vertice* insert(Vertice* nodo, int chave) { 
    //Se a árvore está vazia, retorna um novo nodo
    if (nodo == NULL) return alocaVertice(chave);
  
    //Se não, desce a árvore
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
        printf("Meu endereço = %d\t", (int)ptAux);
        printf("Filho Esquerdo = %d\t", (int)ptAux->esquerdo);
        printf("Filho Direito = %d\t", (int)ptAux->direito);
        printf("Chave = %d ", ptAux->chave);
        printf("\n");
        imprimir(ptAux->esquerdo); //chamada recursiva
        imprimir(ptAux->direito); //chamada recursiva
    }
}

void excluirFolha(Vertice** raiz, int chave){
    /*EXERCÍCIO*/
}

int main(){
   setlocale(LC_ALL, "portuguese");
   int op = 0, chave;
   Vertice* ptRaiz = NULL;/*cria um ponteiro para armazenar o endereço da raiz da árvore*/
   while (op != 4)
   {
      //op = menu();
      op = 3;
      switch (op)
      {
         case 1: //inserir vértice
         printf("Digite o valor do vértice: ");
         scanf("%d",&chave);
           
         if (ptRaiz == NULL) //se árvore está vazia
            ptRaiz = insert(ptRaiz, chave);
         else
            insert(ptRaiz, chave);
         
         break;

       case 2:/*imprimir*/
           printf("\n");
           if(ptRaiz!=NULL)//se árvore tem conteúdo
               imprimir(ptRaiz);
           else
               printf("\nÁrvore Vazia\n\n");
           break;
       
       case 3: //procura
           ptRaiz = insert(ptRaiz, 4);
           
           insert(ptRaiz, 5);
           imprimir(ptRaiz);
           procura(ptRaiz, 4);

           op = 4;
           break;

       default:
           printf("\nOpção inválida\n\n");
           break;
       }
   }
   system("pause");
   return 0;
}