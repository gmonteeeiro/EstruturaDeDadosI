#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dados;
    struct Nodo* proximo;
};

int main()
{
    int op = 0, maior = 0;
    /*ponteiros da lista*/
    struct Nodo* inicio = NULL;/*cria um ponteiro que apontará para o endereço do registro que estiver no início da lista*/
    struct Nodo* fim = NULL;/*cria um ponteiro que apontará para o endereço do registro que estiver no fim da lista*/

    /*abaixo ponteiros auxiliares*/
    struct Nodo* novo = NULL;/*cria um ponteiro auxiliar que apontará para o novo registro*/
    struct Nodo* ptAux = NULL;/*cria um ponteiro auxiliar para encontrar o maior elemento da lista*/
    struct Nodo* k = NULL;/*cria um ponteiro k (para guardar o endereço do maior elemento da lista)*/
    struct Nodo* ptAnt = NULL;/*cria um ponteiro ptAnt para auxiliar a incluir um novo nodo antes de k*/

    while (op != 9)
    {
        printf("(1)INCLUIR no início da lista\n");
        printf("(2)INCLUIR no final de lista\n");
        printf("(3)INCLUIR antes de K\n");
        printf("(4)EXCLUIR do início\n");
        printf("(5)EXCLUIR do final\n");
        printf("(6)EXCLUIR antes de K\n");
        printf("(7)Imprimir Lista\n");
        printf("(8)Deletar lista\n");
        printf("(9)Sair\n");
        printf("Digite uma opção:");
        scanf("%d",&op);
        switch (op)
        {
            case 1:/*inserir no início*/

                novo = (struct Nodo*)malloc(sizeof(struct Nodo));/*aloca memória necessária para um novo registro*/

                printf("Digite o valor a ser inserido no início:");
                scanf("%d",&novo->dados);/*faz a leitura do dado*/

                /*atualiza os ponteiros encadeando o novo registro na lista*/
                novo->proximo = inicio;/*atribui ao campo "proximo" do novo registro, o conteúdo de inicio                     */
                if (inicio == NULL)/*testa se a lista está vazia*/
                    fim = novo;/*atualiza o ponteiro "fim" com o endereço do novo registro         */
                inicio = novo;/*agora a lista tem um novo elemento no início*/
                break;
                
            case 2:/*inserir no final*/
                /*aloca memória para um registro*/
                novo = (struct Nodo*)malloc(sizeof(struct Nodo));

                printf("Digite o valor a ser inserido no fim:");
                scanf("%d",&novo->dados);

                /*atualiza os ponteiros encadeando o novo registro no fim da lista*/
				novo->proximo = NULL;/*atribui null ao campo "proximo" do novo registro, pois ele agora é o último da lista*/
                if (inicio == NULL)/*testa se a lista estava vazia*/
                    inicio = novo;/*atualiza o ponteiro "inicio" com o endereço do novo registro                                    */
                else
                    fim->proximo = novo;/*o último elemento da lista deve apontar para o novo*/
                fim = novo;/*agora a lista tem um novo elemento no fim*/
                break;
                
            case 3:/* inclui um elemento antes de um nodo endereçado por k.
                * Para este exercício determinou-se que k seria o endereço do maior elemento
                * da lista, portanto, o novo nodo deveria ser inserido antes do maior.
                * Assim é necessário primeiramente encontrar o maior elemento e seu endereço de memória
                *
                encontra o maior elemento da lista e seu endereço k*/
                if(inicio!=NULL)/*verifica se lista não está vazia*/
                {
                    ptAux = inicio;
                    maior = ptAux->dados;/*atribui o conteúdo do campo dados do primeiro nodo da lista para a variável maior*/
                    k = ptAux;/*k é um ponteiro para guardar o endereço do maior nodo da lista*/
                    ptAux = ptAux->proximo;
                    while (ptAux != NULL)/*percorre toda a lista para encontrar o maior elemento*/
                    {
                        if (ptAux->dados > maior)/*testa se o dado que está sendo visitado é maior do que o conteúdo da variável "maior"*/
                        {
                            maior = ptAux->dados;/*se for, atribui o dado visitado para a variável "maior"*/
                            k = ptAux;/*atribui o endereço do dado visitado para o ponteiro k*/
                        }
                        ptAux = ptAux->proximo;/*atualiza ptAux para visitar o próximo nodo da lista*/
                    }

                    /*procura k para incluir o novo nodo na lista*/
                    ptAux = inicio;
                    while ((ptAux != NULL) && (ptAux != k))/*percorre a lista procurando k ou até chegar ao seu final*/
                    {
                        ptAnt = ptAux;/*ptAnt armazena o endereço do nodo anteriormente visitado*/
                        ptAux = ptAux->proximo;/*atualiza ptAux para visitar o próximo nodo da lista*/
                    }
                    if (ptAux != NULL)/*se encontrou k*/
                    {
                        /*aloca memória para um novo registro*/
                        novo = (struct Nodo*)malloc(sizeof(struct Nodo));
                        printf("Digite o valor a ser inserido no fim:");
                        scanf("%d",&novo->dados);

                        if (k == inicio)/*se k é o primeiro da lista*/
                        {
                            novo->proximo = inicio;/*atualiza o campo "proximo" do novo registro (que deve apontar para o início da lista)*/
                            inicio = novo;/*atualiza o ponteiro "inicio" pois um novo nodo foi inserido no início da lista*/
                        }
                        else/*se k não é o primeiro da lista*/
                        {
                            /*encadear o novo nodo entre ptAnt e K*/
                            ptAnt->proximo = novo;/*atualiza o campo "proximo" do nodo anterior ao nodo k*/
                            novo->proximo = k;/*atualiza o campo "proximo" do novo registro (pois este deve apontar para o k)*/
                        }
                    }
                    else/*se não encontrou k*/
                    {
                        printf("k não existe");
                    }
                }
                else/*se lista está vazia*/
                    printf("Lista vazia");
                break;
                
            case 4:/*exclui do início da lista*/
                if(inicio==NULL)
                    printf("Lista Vazia!!!!\n");
                else
                {
                    ptAux=inicio;/*atribui inicio para um auxiliar para posterior liberação da memória*/
                    inicio = inicio->proximo;
                    if(inicio==NULL)/*se lista ficou vazia após a remoção*/
                        fim = NULL;
                    free(ptAux);
                    printf("Nodo excluído com sucesso!!!\n");
                }
                break;
                
            case 5:/*exlcuir do fim da lista*/
                if(inicio==NULL)
                    printf("Lista Vazia!!!!\n");
                else
                {
                    if(inicio==fim)/*se tem apenas um nodo na lista*/
                    {
                        ptAux=inicio;
                        inicio = fim = NULL;
                    }
                    else/*se tem mais do que um nodo percorre a lista até encontrar o penúltimo*/
                    {
                        ptAux = inicio;
                        while(ptAux->proximo != NULL)
                        {
                            ptAnt = ptAux;
                            ptAux = ptAux->proximo;
                        }
                        ptAnt->proximo = NULL;
                        fim = ptAnt;
                    }
                    free(ptAux);
                    printf("Nodo excluído com sucesso!!!\n");
                }
                break;
                
            case 6:/*exclui antes de um nodo k (Neste exemplo: k possui o maior elemento da lista)*/
                /*encontra o mairo elemento da lista e seu endereço k*/
                maior = 0;
                if (inicio!=NULL)/*verifica se lista não está vazia*/
                {/*procura nodo maior*/
                    ptAux = inicio;
                    maior = ptAux->dados;
                    k = ptAux;
                    ptAux = ptAux->proximo;
                    while (ptAux != NULL)
                    {
                        if (ptAux->dados > maior)
                        {
                            maior = ptAux->dados;
                            k = ptAux;
                        }
                        ptAux = ptAux->proximo;
                    }/*fim da procura do nodo maior*/
                    if (inicio == k)/*verifica se k é o primeiro da lista*/
                        printf("Não existe nodo antes de k");
                    else
                    {
                        /*procura k para excluir o nodo anterior a ele*/
                        ptAux = inicio;
                        while ((ptAux != NULL) && (ptAux->proximo != k))/*percorre a lista até encontrar o nodo anterior a k ou até o final da lista*/
                        {
                            ptAnt = ptAux;/*atualiza ptAnt (armazena o nodo anteirormente visitado)*/
                            ptAux = ptAux->proximo;/*atualiza ptAux para visitar o próximo nodo da lista*/
                        }
                        if (ptAux == NULL)/*se percorreu toda lista e não encontrou k*/
                            printf("K não foi encontrado");
                        else/*se encontrou k*/
                        {
                            if (inicio == ptAux)/*testa se o nodo a ser excluído é o primeiro da lista*/
                                inicio = k;/*atualiza o ponteiro "inicio" com k pois o nodo do início da lista foi excluído*/
                            else
                                ptAnt->proximo = k;/*atualiza o campo proximo do nodo anterior ao nodo excluído*/
                            free(ptAux);
                            printf("Nodo excluído com sucesso!!!");
                        }
                    }
                }
                else/*se lista vazia*/
                    printf("Lista vazia");
                break;
                
            case 7:/*imprimir lista*/
                ptAux = inicio;
                if (inicio != NULL)
                {
                    while (ptAux != NULL)
                    {
                        printf("Meu endereço: %d ", ptAux);/*imprime o endereço de memória do nodo*/
                        printf("Campo Valor: %d ", ptAux->dados);
                        printf("Campo Proximo: %d\n", ptAux->proximo);
                        ptAux = ptAux->proximo;
                    }
                }
                else
                    printf("Lista Vazia!");
                break;
                
            case 8:/*deletar toda a lista*/
                if(inicio==NULL)
                    printf("Lista vazia!!!");
                else
                {
                    ptAux = inicio;
                    while(ptAux!=NULL)
                    {
                        free(ptAux);
                        ptAux = ptAux->proximo;
                    }
                    inicio = NULL;
                    fim = NULL;
                }
                break;
                
            case 9:
                printf("Saindo");
                break;
                
            default:
                printf("Opção inválida!");
        }
    }
    return 0;
}
