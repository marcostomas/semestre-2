#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define ERRO -1
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->nroElem = 0;
}

void ordenar(LISTA *l)
{
    REGISTRO aux;

    for (int a = 0; a < l->nroElem; a++)
    {
        for (int b = a + 1; b < l->nroElem; b++)
        {
            if (l->A[a].chave > l->A[b].chave)
            {
                aux = l->A[a];
                l->A[a] = l->A[b];
                l->A[b] = aux;
            }
        }
    }
}

void exibirLista(LISTA *l)
{
    int i;
    printf("Lista: \" ");

    for (i = 0; i < l->nroElem; i++)
        printf("%i ", l->A[i].chave);

    printf("\"\n");
}

int main()
{
    LISTA *l = (LISTA *)malloc(sizeof(LISTA));
    inicializarLista(l);

    REGISTRO *regs = (REGISTRO *)malloc(50 * sizeof(REGISTRO));

    for (int i = 0; i < 50; i++)
    {

        regs[i].chave = rand() % 100;
        l->A[i] = regs[i];
        printf("Posicao: %i, Valor de i: %i \n", i, l->A[i].chave);
        l->nroElem++;
    }
    ordenar(l);

    printf("\n\n\n\n\n\n\n\n\n\n\n");

    printf("Numero de elementos apos insercao dos valores: %i", l->nroElem);

    printf("\n\n\n\n\n\n\n\n\n\n\n");

    for (int i = 0; i < 50; i++)
    {
        printf("Posicao: %i, Valor de i: %i \n", i, l->A[i].chave);
    }

    return 0;
}