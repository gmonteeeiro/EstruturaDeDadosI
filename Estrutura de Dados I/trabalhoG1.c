//Trabalho Gabriel e Mathias

#include <stdio.h>
#include <locale.h>

//---- Struct
struct nodo{
    int codigo;
    char paragrafo[100];
    struct nodo *proximo;
};
typedef struct nodo texto;

//---- Métodos
int showMenu();
texto *NewAddressTexto();
void adicionaNodo();
//void adicionaNoFim();
void limpaBuffer();
void menu();
void mostrarFrases();

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
                //função para remover
                break;

            case 3:
                mostrarFrases();
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
    printf("-------------- Trabalho G1 --------------\n");
    printf("----------- Mathias e Monteiro ----------\n");
    printf("-----------------------------------------\n\n");
}

int showMenu(){
    menu();

    int opc;

    printf("1 - Inserir frase\n");
    printf("2 - Remover frase\n");
    printf("3 - Mostrar frases\n");
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

    printf("Informe o código da frase: ");
    scanf("%d", &novo->codigo);
    limpaBuffer();

    printf("Escreva a frase: ");
    gets(novo->paragrafo);

    novo->proximo = NULL;

    //Verifica se é a primeira inclusão
    if(inicio == NULL){
        //Tanto ponteiro de início como de fim são iguais ao novo nodo
        inicio = novo;
        fim = novo;
    }
    else{
        //preciso saber os 2 vizinhos

        //Procurando o anterior
        texto *k = inicio;
        texto *ant = NULL;

        while((k != NULL) && (novo->codigo > k->codigo)){
            ant = k;
            k = k->proximo;
        }

        if(k == NULL){
            ant->proximo = novo;
            fim = novo;
        }
        else if(ant == NULL){
            novo->proximo = inicio;
            inicio = novo;
        }
        else{
            novo->proximo = k;
            ant->proximo = novo;
        }        
    }
}

/*
void adicionaNoFim(){
    menu();

    texto *novo = NewAddressTexto();

    printf("Informe o código da frase: ");
    scanf("%d", &novo->codigo);
    limpaBuffer();

    printf("Escreva a frase: ");
    gets(novo->paragrafo);
    
    novo->proximo = NULL;

    if(inicio == NULL)
        inicio = novo;
    else
        fim->proximo = novo;

    fim = novo;
}
*/

void mostrarFrases(){
    menu();

    texto *aux = inicio;

    while(aux != NULL){
        printf("Código %d\nFrase: %s\n\n", aux->codigo, aux->paragrafo);
        aux = aux->proximo;
    }
    printf("Não há mais frases a serem exibidas! ");
    system("pause");
}