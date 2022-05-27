#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//  PRÁTICA 4
//
//  ENUNCIADO: Faça, em linguagem C, uma função recursiva para o cálculo potenciação.
//  Sabe-se que o cálculo pode ser feito através de multiplicações sucessivas. Para demonstrar o
//  funcionamento utilize o primeiro digito do sua matrícula como base e o último digito como
//  expoente.
int potencia(int base, int expoente)
{
    if (expoente == 0)
        return 1;
    else
        return base * potencia(base, expoente - 1);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    int base, expoente;
    printf("Matricula: 15374257650-1\n");
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    printf("\n%d", potencia(base, expoente));
    printf("\n");
    system("pause");
    return 0;
}