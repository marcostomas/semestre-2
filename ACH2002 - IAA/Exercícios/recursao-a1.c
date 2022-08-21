#include <stdio.h>

// Parte 1
int fatorial(int a)
{
    if (a < 0)
        return 0;
    else if (a <= 1)
        return 1;
    else
    {
        return (a * fatorial(a - 1));
    }
}

int fibonacci(int a)
{
    if (a <= 0)
        return 0;
    else if (a == 1)
        return 1;
    else
        return (fibonacci(a - 1) + fibonacci(a - 2));
}

int buscaBin(int valorProcurado, int inicio, int fim)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16};

    while (inicio <= fim)
    {
        int meio = (fim + inicio) / 2;
        if (arr[meio] < valorProcurado)
            return buscaBin(valorProcurado, meio + 1, fim);
        else
        {
            if (arr[meio] > valorProcurado)
                return buscaBin(valorProcurado, inicio, meio - 1);
            else
                return meio;
        }
    }
    return -1;
}

/*
    3: O problema não faz sentido quando n = 0. A soma deveria resultar no infinito negativo. Já que o último valor seria o 0, porém não haveria um número inicial.
*/

int somaArr(int arr[], int nPosicoes)
{
    if (nPosicoes < 0)
        return 0;

    if (nPosicoes - 1 == 0)
        return arr[0];
    else
        return (arr[nPosicoes - 1] + somaArr(arr, nPosicoes - 1));
}

// Parte 2
int maxmin(int arr[], int inicio, int fim, int nComparacoes)
{
    if (fim <= inicio)
        return nComparacoes;
    else
    {
        if (arr[inicio] > arr[fim])
            return maxmin(arr, inicio, (fim - 1), (nComparacoes + 1));

        if (arr[inicio] < arr[fim])
            return maxmin(arr, (inicio + 1), fim, (nComparacoes + 1));

        if (arr[inicio] == arr[fim])
            return maxmin(arr, inicio, (fim - 1), (nComparacoes + 1));
    }
}

int somaPositivos(int arr[], int posicao, int tamanho, int soma)
{
    if (posicao > tamanho)
        return soma;
    else
    {
        if (arr[posicao] > 0)
            return somaPositivos(arr, (posicao + 1), tamanho, (soma + arr[posicao]));
        else
            return somaPositivos(arr, (posicao + 1), tamanho, soma);
    }
}

int somaAlgarismos(int valor, int soma)
{
    if (((valor / 10 == 0) && (valor - 1 < 0)) || valor < 0)
        return soma;
    else
    {
        return somaAlgarismos(valor / 10, soma += valor % 10);
    }
}

// Parte 3

int onde(int x, int v[], int n)
{
    if (n < 0)
        return -1;
    else if (v[n] == x)
        return n;
    else
        return onde(x, v, n - 1);
}

int procurandoDori(int x, int v[], int ini, int fim)
{
    if (fim < ini)
        return ini - 1;
    else if (v[fim - 1] == x)
        return fim - 1;
    else
        return procurandoDori(x, v, ini, fim - 1);
}

int main()
{

    printf("O fatorial e: %i \n", fatorial(6));        // Parte 1 - 1.1
    printf("Valor de fibonacci: %i \n", fibonacci(5)); // Parte 1 - 1.2

    // Parte 1 - 1.3 ↓
    if (buscaBin(14, 0, 14) == -1)
        printf("O elemento nao existe no vetor");
    else
        printf("O elemento e: %i \n", buscaBin(14, 0, 14));

    // Parte 1 - 2 Para calcular a complexidade de um algoritmo, é preciso saber quantas vezes a função precisará ser chamada.

    // Parte 1 - 3 ↓
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    printf("Soma dos elementos do array de razao 1: %i \n", somaArr(arr, 9));
    printf("Soma dos elementos do array de razao 2: %i \n", somaArr(arr2, 9));

    // Parte 2 - 1 ↓
    int arrMaxMin[] = {0, 43, 3, 6, 93, -1, 103, 2, 5, 37};
    printf("Numero de comparacoes: %i \n", maxmin(arrMaxMin, 0, 9, 0)); // Faz n-1 comparações, sendo n a quantidade de elementos no vetor.

    int arrSoma[] = {-3, -2, -1, 0, 1, 2, 3};
    printf("Soma = %d \n", somaPositivos(arrSoma, 0, 6, 0));

    printf("Resultado da soma: %i \n", somaAlgarismos(73875, 0));

    int v[] = {0, 3, 6, 9, 10, 11, 17, 21, 23};

    printf("Posicao: %i \n", onde(1, v, 8));

    printf("Posicao: %i \n", procurandoDori(3, v, 3, 9));

    return 0;
}