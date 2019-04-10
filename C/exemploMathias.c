
#include<stdio.h>
#include<stdlib.h>
///Usando typedef na struct para encurtar o comando na declaração
struct LIXO {
    int a;
    int b;
};

int main ()
{

    struct LIXO x;
    struct LIXO *p;   ///cria um ponteiro p que aponta para x
    struct LIXO **pt; /// cria um ponteiro para ponteiro pt aponta para p
    struct LIXO ***ptr;
    p = &x;
    pt=&p;
    ptr=&pt;

    p->a = 200; ///da certo
    pt->a=23;   ///da errado ??? POR QUE?


    printf("%d\n", p->a);
    return 0;
}
