#include<stdio.h>
#include<stdlib.h>

struct NoLis
{
    int val;
    struct NoLis *prox;
};
typedef struct NoLis No;

void inic_fil(No *p)
{
    p->prox=NULL;
}

int lista_vazia(No *p)
{
    if(p->prox==NULL)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void no_insere_fim(No *p, int x)
{
    No *q,*pos;
    q=(No*) malloc(sizeof(No));


    q->val=x;
    q->prox=NULL;
    pos=p;
    while(pos->prox!=NULL)
    {
        pos=pos->prox;
    }
    pos->prox=q;
}

void imprimi(No *p)
{
    No *q;
    q=p->prox;
    printf("\n");
    while(q!=NULL)
    {
        printf("[%i]-->",q->val);
        q=q->prox;
    }
    printf("NULL");
}

int main()
{
    struct No *p,*q;
    int valor, op,y;

    inic_fil(&p);
    inic_fil(&q);
    while( 1 )
    {
        printf("\n\nLista Linear Simplesmente Encadeada:\n");
        printf( "0 - Sair\n");
        printf( "1 - Inserir elemento na lista 1\n" );
        printf( "2 - Inserir elemento na lista 2\n" );
        printf( "3 - Mostrar lista 1\n" );
        printf( "Opcao?  " );
        scanf( "%d",&op);
        switch( op )
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf( "Valor? " );
            scanf("%d",&valor);
            no_insere_fim(&p,valor);
            break;
        case 2:
            printf( "Valor? " );
            scanf("%d",&valor);
            no_insere_fim(&q,valor);
            break;
        case 3:
            if (lista_vazia(&p))
            {
                printf("Lista vazia!!\n");
            }
            else
            {
                imprimi(&p);
            }
        case 4:
            if (lista_vazia(&q))
            {
                printf("Lista vazia!!\n");
            }
            else
            {
                imprimi(&q);
            }
        }

    }
    return 0;
}
