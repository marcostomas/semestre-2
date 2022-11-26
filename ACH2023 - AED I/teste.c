#include <stdio.h>
#include <stdlib.h>

// Selection Sort. Eu que fiz :) !
int *ordenacaoCrescente(int *vetor, int numeroDeElementos)
{
    int aux;

    if (numeroDeElementos > 0)
    {
        for (int a = 0; a < numeroDeElementos; a++)
        {
            for (int b = a + 1; b < numeroDeElementos; b++)
            {
                if (vetor[a] > vetor[b])
                {
                    aux = vetor[a];
                    vetor[a] = vetor[b];
                    vetor[b] = aux;
                }
            }
        }
    }
}

int main()
{
    int *arr = (int *)malloc(50 * sizeof(int));

    for (int i = 0; i < 50; i++)
    {
        arr[i] = rand() % 100;
        printf("Posicao: %i, Valor de i: %i \n", i, arr[i]);
    }

    ordenacaoCrescente(arr, 50);

    printf("\n\n\n\n\n\n\n\n");
    for (int i = 0; i < 50; i++)
    {
        printf("Posicao: %i, Valor de i: %i \n", i, arr[i]);
    }
}