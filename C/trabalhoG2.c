//---- Trabalho G2
//---- Gabriel Monteiro | Mathias Souza
#include <stdio.h>
#include <locale.h>

//---- Struct
struct nodo{
    int valor;
    struct nodo *proximo;
};
typedef struct nodo texto;

//---- Métodos
int showMenu();
texto *NewAddressTexto();
void adicionaNodo();
void limpaBuffer();
void menu();
void mostrarValores();
void removerNodo();

///---- Variáveis Globais
texto *novo;
texto *inicio = NULL;
texto *fim = NULL;

//---- Programa
int main(){
    setlocale(LC_ALL, "portuguese");

    int opc;
    while((opc = showMenu()) != 0){
        switch(opc){
            case 1:
                adicionaNodo();
                break;

            case 2:
                removerNodo();
                break;

            case 3:
                mostrarValores();
                break;

            default:
                break;
        }
    }

    return 0;
}

//Limpa o Buffer do teclado
void limpaBuffer() {
	/*int ch;
	while(ch != EOF && ch != '\n') {
		ch = fgetc(stdin);
	}*/

	setbuf(stdin, NULL);
}

void menu(){
    system("cls");
    printf("-----------------------------------------\n");
    printf("-------------- Trabalho G2 --------------\n");
    printf("----------- Mathias e Monteiro ----------\n");
    printf("-----------------------------------------\n\n");
}

int showMenu(){
    menu();

    int opc;

    printf("1 - Inserir valor\n");
    printf("2 - Remover valor\n");
    printf("3 - Mostrar valores\n");
    printf("0 - Sair\n");

    do{
        printf("Informe uma opção: ");
        scanf("%d", &opc);
        if(opc < 0 || opc > 3){
            printf("Opção inválida. ");
        }
    }while(opc < 0 || opc > 3);

    return opc;
}

///Retorna novo endereço
texto *NewAddressTexto(){
    return (texto*)malloc(sizeof(texto));
}

void adicionaNodo(){
    menu();

    texto *novo = NewAddressTexto();

    printf("Informe o valor: ");
    scanf("%d", &novo->valor);
    limpaBuffer();

    //Verifica se é a primeira inclusão
    if(inicio == NULL){
        //Tanto ponteiro de início como de fim são iguais ao novo nodo
        inicio = novo;
        fim = novo;
        fim->proximo = inicio;
    }
    else{
        //preciso saber os 2 vizinhos

        //Procurando o anterior
        texto *k = inicio;
        texto *ant = NULL;

        int sair = 0;
        while(novo->valor > k->valor && !sair){
            ant = k;
            k = k->proximo;
            if(k == inicio){
                sair = 1;
            }
        }
        
        if(k == inicio && !sair){ //Adiciona no final
            //último item aponta pro primeiro
            novo->proximo = inicio;
            inicio = novo;
            fim->proximo = inicio;
        }
        else if(k == inicio){ //adiciona no fim
            ant->proximo = novo;
            fim = novo;
            fim->proximo = inicio;
        }
        else{ //adiciona no meio
            ant->proximo = novo;
            novo->proximo = k;
        }
    }
}

void removerNodo(){
    menu();
    if(inicio != NULL){
        printf("Valores informados: ");

        //Mostra os valores para o usuário
        texto *mostra = inicio;
        do{
            printf("%d", mostra->valor);
            mostra = mostra->proximo;

            //IF apenas para deixar o programa melhor apresentável ao usuário
            if(mostra != inicio){
                printf(", ");
            }
        }while(mostra != inicio);
        
        printf("\n");

        int val;
        printf("Informe o valor a ser removido: ");
        scanf("%d", &val);

        int excluiu = 0;
        int saiu = 0;

        texto *aux = inicio;
        texto *ant;
        while(!saiu && !excluiu){
            if(aux->valor == val){

                if(aux == inicio){ //deleta o primeiro
                    if(inicio == fim){ //Último item
                        inicio = NULL;
                        fim = NULL;
                    }
                    else{
                        inicio = aux->proximo;
                        fim->proximo = inicio;
                    }
                }
                else if(aux == fim){ //deleta o último
                    fim = ant;
                    fim->proximo = inicio;
                }
                else{ //deleta do meio
                    ant->proximo = aux->proximo;
                }

                excluiu = 1;
                printf("Valor excluído!\n");
            }
            ant = aux;
            aux = aux->proximo;

            if(aux == inicio){
                saiu = 1;
            }
        }
        if(!excluiu){
            printf("Valor não encontrado!\n");
        }
    }
    else{
        printf("Não há nenhum valor para ser excluído!\n");
    }
    system("pause");

}

void mostrarValores(){
    menu();

    if(inicio != NULL){
        texto *aux = inicio;
        printf("Valores informados: ");

        //Mostra os valores para o usuário
        texto *mostra = inicio;
        do{
            printf("%d", mostra->valor);
            mostra = mostra->proximo;

            //IF apenas para deixar o programa melhor apresentável ao usuário
            if(mostra != inicio){
                printf(", ");
            }
        }while(mostra != inicio);

        printf("\n");
    }
    else{
        printf("Não há valores para serem exibidos!\n");
    }

    system("pause");
}
