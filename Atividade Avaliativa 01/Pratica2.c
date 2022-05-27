#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 12
//  PRÁTICA 2
//
//  ENUNCIADO: Escreva um algoritmo em linguagem C que atenda os seguintes requisitos:
//  ✓ Crie um vetor com a quantidade de dígitos da sua matrícula.
//  ✓ Solicite que usuário digite sua matrícula, cada digito digitado deve ser armazenado em
//  uma posição de um vetor.
//  ✓ Utilizando ponteiro para o vetor verifique qual o maior e menor número contido neste
//  vetor e imprima na tela.
//
//  Para demonstrar o funcionamento faça as capturas de tela do terminal utilizando sua ma-
//  trícula.
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    int matricula[tam], maior = 0, menor = 0;
    int *pMatricula = &matricula;
    printf("Digite a sua matricula: \n");
    for (int i = 0; i < tam; i++)
        scanf("%d", &pMatricula[i]);
    for (int i = 0; i < tam; i++)
    {
        if (pMatricula[i] > maior)
            maior = pMatricula[i];
    }
    for (int i = 0; i < tam; i++)
    {
        if (pMatricula[i] <= menor)
            menor = pMatricula[i];
    }
    printf("Maior: %d\nMenor: %d\n", maior, menor);
    system("pause");
    return 0;
}