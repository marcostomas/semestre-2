#include <stdio.h>
#include <stdlib.h>

// Exercício 1
typedef struct aux
{
    int id;
    struct aux *mae;
    struct aux *pai;
} PESSOA;

// Exercício 2
PESSOA *inicializar(int id)
{
    PESSOA *p1 = (PESSOA *)malloc(sizeof(PESSOA));
    p1->id = id;
    p1->mae = NULL;
    p1->pai = NULL;

    return p1;
}

// Exercício 3
void registrar(PESSOA *filho, PESSOA *mae, PESSOA *pai)
{
    filho->mae = mae;
    filho->pai = pai;
}

int main()
{
    PESSOA *p1 = inicializar(1);
    PESSOA *p2 = inicializar(2);
    PESSOA *p3 = inicializar(3);

    registrar(p3, p2, p1);

    printf("Endereco de filho: %p, \nEndereco da mae: %p, \nEndereco do pai: %p", p3, p3->mae, p3->pai);
    return 0;
}