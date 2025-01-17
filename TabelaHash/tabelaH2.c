#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
    Metodo dobra: N�mero de elemento = 100
    2 * 100 = 200; o primo mais proximo � 199 ou 211
    fc = 100/199 = 0,50 ou 100/211 = 0,47
    parece que vamos ter que testar ambos
    com inser��o aleatoria e timing
*/
#define TAM 15 //apenas pra testes

typedef struct no {
    int key;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void inicializarLista(Lista *l) {
    l->inicio = NULL;
    l->tam = 0;
}

void inserirLista(Lista *l, int num) {
    No *nova = malloc(sizeof(No));
    if(nova) {
        nova->key = num;
        nova->prox = l->inicio;
        l->inicio = nova;
        l->tam++;
    } else {
        printf("\nErro ao alocar");
    }
}

int buscarLista(Lista *l, int num) {
    No *aux = l->inicio;
    while(aux && aux->key != num) {
        aux = aux->prox;
    }
    if(aux) {
        return aux->key;
    }
    return 0;
}

void imprimirLista(Lista *l) {
    No *aux = l->inicio;
    printf(" Tamanho: %d ",l->tam);
    while(aux) {
        printf("%d ",aux->key);
        aux = aux->prox;
    }
}

void inicializarTabela(Lista t[]) {
    for(int i = 0; i < TAM; i++) {
        inicializarLista(&t[i]);
    }
}

/*
estava fazendo com o metodo errado...
int funcaoHash(int key) {
    return key % TAM;
}*/

int funcaoHash(int key) { //dobra
    int num_bit = 10;
    int parte1 = key >> num_bit;
    int parte2 = key & (TAM-1);
    return (parte1^parte2);
}


void inserir(Lista t[], int num) {
    int id = funcaoHash(num);
    inserirLista(&t[id], num);
}

int busca(Lista t[], int num) {
    int id = funcaoHash(num);
    printf("\nIndice gerado: %d\n",id);
    return buscarLista(&t[id],num);
}

void imprimir(Lista t[]) {
    for(int i = 0; i < TAM; i++) {
        printf("%2d = ",i);
        imprimirLista(&t[i]);
        printf("\n");
    }
}

int main() {
    clock_t timing;
    int opcao, retorno, qt=0;
    Lista tabela[TAM];
    srand(time(NULL));
    inicializarTabela(tabela);
    do {
        int valor = 1+rand()%100;
        printf("\n========Tabela Hash=======");
        printf("\n0 - Sair\n1 - Inserir\n2 - Buscar\n3 - Imprimir");
        printf("\nEscolha a opcao: ");
        scanf("%d",&opcao);
        switch(opcao) {
        case 1:
            /*printf("Qual valor dejesa inserir? ");
            scanf("%d",&valor);*/
            inserir(tabela,valor);
            printf("\nQuantidade de numero inserido: %d\n",++qt);
            break;
        case 2:
            printf("Qual valor dejesa buscar? ");
            scanf("%d",&valor);
            timing = clock();
            retorno = busca(tabela,valor);
            if(retorno != 0) {
                printf("Valor encontrado: %d\n",retorno);
            } else {
                printf("Valor nao encontrado!\n");
            }
            timing = clock() - timing;
            printf("O tempo de busca foi: %.4lf",(((double)timing)/(CLOCKS_PER_SEC)));
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while(opcao != 0);
    return 0;
}
