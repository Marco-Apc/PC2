#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// 01 - Faça um programa que receba dois números e mostre o menor deles.
void Question01()
{
    int num1, num2;
    printf("Digite dois numeros para saber o menos deles: ");
    scanf("%d%*c%d%*c", &num1, &num2);
    if (num1 < num2)
    {
        printf("\nO numero %d é o menor.", num1);
    }
    else
    {
        printf("\nO numero %d é o menor.", num2);
    }
}
// 02 - Faça um programa que receba um dia da semana de entrada, como número, e escreva esse dia por extenso.
void Question02()
{
    int num;
    printf("Digite um numero de 1 a 7 para saber seu dia correspondente: ");
    scanf("%d%*c", &num);
    switch (num)
    {
    case 1:
        printf("Domingo.");
        break;
    case 2:
        printf("Segunda-Feira.");
        break;
    case 3:
        printf("Terca-Feira.");
        break;
    case 4:
        printf("Quarta-Feira.");
        break;
    case 5:
        printf("Quinta-Feira.");
        break;
    case 6:
        printf("Sexta-Feira.");
        break;
    case 7:
        printf("Sabado.");
        break;
    default:
        printf("Esse numero nao corresponde a um dia valido.");
        break;
    }
}
// 03 - Elabore um programa a ler 4 notas de um aluno (de 1 a 10). Após calcular a média
//      das notas, apresentar a mensagem “Aprovada” se o aluno tiver obtido média maior
//      ou igual a 6, caso contrário, apresentar “Reprovado”.
void Question03()
{
    float nota1, nota2, nota3, nota4, aux;
    printf("Digite as 4 notas do aluno: ");
    scanf("%f%*c%f%*c%f%*c%f%*c", &nota1, &nota2, &nota3, &nota4);
    aux = nota1 + nota2 + nota3 + nota4;
    aux = aux / 4;
    if (aux >= 6)
        printf("Aprovado com %.2f pontos.", aux);
    else
        printf("Reprovado com %.2f pontos.", aux);
}
// 04 - Faça um programa que leia um número e mostre uma mensagem indicando se
//      este número é par ou ímpar e se é positivo ou negativo.
void Question04()
{
    int num;
    printf("Digite um numero: ");
    scanf("%d%*c", &num);
    if (num % 2 == 0)
    {
        printf("O numero %d eh par.", num);
    }
    else
    {
        printf("O numero %d eh impar.", num);
    }
    if (num >= 0)
    {
        printf("\nO numero %d eh positivo.", num);
    }
    else
    {
        printf("\nO numero %d eh negativo.", num);
    }
}
//  5 - Dados 3 valores, X, Y e Z, faça um programa que verifique se eles podem ser os
//  comprimentos dos lados de um triângulo e, se forem, verifique que tipo de triângulo.
//  Se eles não formarem um triângulo, escreva uma mensagem. Considere que: O
//  comprimento de cada lado de um triângulo é menor que a soma dos outros dois lados.
//  Chama-se equilátero o triângulo que tem os 3 lados iguais. Denomina-se isósceles, o
//  triângulo que tem o comprimento de dois lados iguais. Recebe o nome de escaleno o
//  triângulo que tem os 3 lados diferentes.
void Question05()
{
    float x, y, z, aux;
    printf("Digite os 3 lados do triangulo: ");
    scanf("%f%*c%f%*c%f%*c", &x, &y, &z);
    aux = x + y;
    if (aux > z)
    {
        aux = aux - z;
        if (aux == y)
        {
            printf("O triangulo e equilatero.");
        }
        else
        {
            printf("O triangulo e isosceles.");
        }
    }
    else
    {
        printf("Nao e um triangulo.");
    }
}
//  6 - Faça um programa que leia dois valores inteiros e positivos X e Y. Calcule e mostre
//  a potência de XY utilizando estrutura de repetição.
void Question06()
{
    int x, y, aux;
    printf("Digite dois numeros inteiros positivos: ");
    scanf("%d%*c%d%*c", &x, &y);
    aux = x;
    for (int i = 1; i < y; i++)
    {
        x = x * aux;
    }
    printf("%d elevado a %d = %d.", aux, y, x);
}
//  7 - Faça um programa que mostre os 10 primeiros números da seqüência de Fibonacci
//  (números Fibonacci são números obtidos da soma dos seus dois antecessores: 0 – 1
//  – 1 – 2 – 3 – 5 – 8 – 13 ...)
void Question07()
{
    int x, y, aux;
    printf("Os 10 primeiros numeros da sequencia de Fibonacci sao: ");
    x = 0;
    y = 1;
    for (int i = 0; i < 10; i++)
    {
        aux = x + y;
        printf("%d ", aux);
        x = y;
        y = aux;
    }
}
// 08 - Faça um programa que calcule a soma dos 50 primeiros números inteiros pares.
//      Esse algoritmo não receberá nenhum valor pelo teclado.
void Question08()
{
    int num;
    for (int i = 0; i <= 100; i++)
    {
        num += i;
        ++i;
    }
    printf("%d", num);
}
//  9 - A conversão de Farenheight para Celsius é obtida pela fórmula: C = 5/9 * (F– 32).
//  Faça um programa que calcule e escreva uma tabela de Celsius e Farenheight cujos
//  graus variam de 40° F a 80° F, de 1 em 1.
void Question09()
{
    float faren, celsius;
    printf("Farenheit\tCelsius\n");
    for (int i = 40; i <= 80; i++)
    {
        faren = i;
        celsius = 5 * (faren - 32) / 9;
        printf("%.0f\t\t%.2f\n", faren, celsius);
    }
}
//  10 - Faça um programa mostrando a tabuada dos números de 1 a 10.
void Question10()
{
    int num;
    printf("Tabuada de 1 a 10\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("\nTabuada de %d\n", i);
        for (int j = 1; j <= 10; j++)
        {
            num = i * j;
            printf("%d x %d = %d\n", i, j, num);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "");
    Question01();
    Question02();
    Question03();
    Question04();
    Question05();
    Question06();
    Question07();
    Question08();
    Question09();
    Question10();
    return 0;
}