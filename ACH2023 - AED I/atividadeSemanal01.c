#include <stdio.h>

int main()
{
    // Exercício 1
    int nusp = 13747950;
    printf("Imprimindo inteiro: %i\n", nusp);                 // Imprimindo inteiro: 13747950
    printf("Imprimindo numero: %d\n", nusp);                  // Imprimindo numero: 13747950
    printf("Imprimindo float (com cast): %f\n", (float)nusp); // Imprimindo float (com cast): 13747950.000000
    printf("Imprimindo quociente: %i\n", nusp / 2);           // Imprimindo quociente: 6873975
    printf("Imprimindo resto: %d\n", nusp % 2);               // Imprimindo resto: 0
    printf("Imprimindo quadrado: %d\n", nusp * nusp);         // Imprimindo quadrado: 1798374724

    // Exercício 2
    int x = 7;
    int y = 13;
    int *z = &x;
    printf("x: %i y: %i z: %p\n", x, y, z);       // x: 7 y: 13 z: 000000e5fb5ffa58
    printf("&x: %p &y: %p &z: %p\n", &x, &y, &z); //&x: 000000e5fb5ffa58 &y: 000000e5fb5ffa54 &z: 000000e5fb5ffa48
    *z = x + y;
    printf("Novo valor de x: %i\n", x); // Novo valor de x: 20
    // Ao executar duas vezes o mesmo programa de uma mesma compilação, os endereços de memória mudam!
    return 0;
}