#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//  PRÁTICA 1
//
//  ENUNCIADO: Escreva um algoritmo em linguagem C que atenda os seguintes requisitos:
//  ✓ Crie um registro para armazenar o seu Nome Completo e sua matrícula.
typedef struct pratica1
{
    char NomeCompleto[60];
    char NomeCompletoInvertido[60];
    long int Matricula;
} Pratica1;
//  ✓ Solicite ao usuário que digite o sua matrícula e o seu Nome Completo.
//  ✓ Crie um ponteiro para o registro.
//  ✓ Através do ponteiro para o registro verifique se a matrícula digitado é um número par ou
//  ímpar e informe a resposta na tela.
//  ✓ Através do ponteiro para o registro imprima o Nome Completo informado de traz
//  para frente, invertido.
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    Pratica1 registro, *pRegistro = &registro;
    char aux;
    printf("Digite a sua matricula: ");
    scanf("%li", &pRegistro->Matricula);
    printf("Digite o seu nome completo: ");
    scanf("%s", &pRegistro->NomeCompleto);
    if (pRegistro->Matricula % 2 == 0)
    {
        printf("Matricula par");
    }
    else
    {
        printf("Matricula impar");
    }
    printf("\n");
    system("pause");
    return 0;
}