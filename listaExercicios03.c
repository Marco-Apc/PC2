#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define tam 7 // use para testes
//  1. Escreva um algoritmo que solicite ao usuário a entrada de 10 números, e que exiba
//     o somatório desses números na tela. Após exibir a soma, o programa deve mostrar
//     também os números que o usuário digitou, um por linha0.
void Question01()
{
    int entrada10[tam], somaAux = 0;
    printf("Digite 10 numeros inteiros: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d%*c", &entrada10[i]);
        somaAux += entrada10[i];
    }
    printf("Soma total: %d.\n", somaAux);
    printf("Numeros digitados pelo usuario:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", entrada10[i]);
    }
}
//  2. Escreva um algoritmo que solicite ao usuário a entrada de 10 nomes, e que exiba a
//      lista desses nomes na tela. Após exibir essa lista, o programa deve mostrar também
//      os nomes na ordem inversa em que o usuário os digitou, um por linha.
void Question02()
{
    char entrada10[tam][61];
    printf("Digite 10 nomes: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%s%*c", entrada10[i]);
    }
    printf("Nomes digitados pelo usuario:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%s\n", entrada10[i]);
    }
    printf("Nomes digitados pelo usuario em ordem inversa:\n");
    for (int i = tam-1; i >= 0; i--)
    {
        printf("%s\n", entrada10[i]);
    }
}
//  3. Declare um vetor de 10 posições e o preencha com os 10 primeiros números
//      ímpares e o escreva.
void Question03()
{
    int vetor[tam];
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = i*2+1;
    }
    printf("Vetor com os 10 primeiros numeros impares:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", vetor[i]);
    }
}
//  4. Crie um programa que solicite a entrada de 10 números pelo usuário,
//      armazenando-os em um vetor, e então monte outro vetor com os valores do primeiro
//      multiplicados por 5. Exiba os valores dos dois vetores na tela, simultaneamente, em
//      duas colunas (um em cada coluna), uma posição por linha.
void Question04()
{
    int entrada10[tam], entrada5[tam];
    printf("Digite 10 numeros inteiros: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d%*c", &entrada10[i]);
    }
    printf("Numeros digitados pelo usuario:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", entrada10[i]);
    }
    for (int i = 0; i < tam; i++)
    {
        entrada5[i] = entrada10[i] * 5;
    }
    printf("Numeros digitados pelo usuario multiplicados por 5:\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", entrada5[i]);
    }
}
//  5. Leia um vetor de 20 posições e em seguida um valor X qualquer. Seu programa
//      deverá fazer uma busca do valor de X no vetor lido e informar a posição em que foi
//      encontrado ou se não foi encontrado.
void Question05()
{
    int entrada20[tam], x = 0, posicao = NULL;
    printf("Digite 20 numeros inteiros: ");
    for (int i = 0; i <tam; i++)
        scanf("%d%*c", &entrada20[i]);
    printf("Digite um numero inteiro: ");
    scanf("%d%*c", &x);
    for (int i = 0; i <tam; i++)
    {
        if (entrada20[i] == x)
            posicao = i;
    }
    if (posicao == NULL)
        printf("O numero nao foi encontrado.\n");
    else
        printf("O numero foi encontrado na posicao %d.\n", posicao);
}
//  6. Leia um vetor de 10 posições. Contar e escrever quantos valores pares ele possui.
void Question06()
{
    int vetor10[tam], aux = 0;
    printf("Digite 10 numeros inteiros: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor10[i]);
        if (vetor10[i] % 2 == 0)
            aux += 1;
    }
    printf("Quantidade de numeros pares: %d", aux);
}
//  7. Fazer um programa para ler um vetor (array unidimensional) de 8 números inteiros.
//     Imprimir na tela os conteúdos do vetor lido, a soma de seus elementos e apresentar
//     quantos deles são positivos.
void Question07()
{
    int vetor8[tam], soma = 0, positivo = 0;
    printf("Digite 8 numeros inteiros: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor8[i]);
        if (vetor8[i] >= 0)
            positivo += 1;
        soma += vetor8[i];
    }
    printf("\nSoma de todos os numeros: %d", soma);
    printf("\nQuantidade de numeros positivos: %d", positivo);
    printf("\nVetor: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor8[i]);
    }
}
//  8. Faça um algoritmo que carregue um vetor com 15 posições, calcule e mostre o
//      maior elemento do vetor e em que posição esse elemento se encontra e o menor
//      elemento do vetor e em que posição esse elemento se encontra.
void Question08()
{
    int vetor15[tam], maior = 0, menor = 0, aux = 0, posicaoMaior = 0, posicaoMenor = 0;
    printf("Digite 15 numeros inteiros: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor15[i]);
        if (vetor15[i] > maior)
        {
            maior = vetor15[i];
            posicaoMaior = i;
        }
    }
    aux = maior;
    for (int i = 0; i < tam; i++)
    {
        if (vetor15[i] > NULL && vetor15[i] < aux)
        {
            menor = vetor15[i];
            aux = vetor15[i];
            posicaoMenor = i;
        }
    }
    printf("\nMaior elemento: %d", maior);
    printf("\nPosicao do maior elemento: %d", posicaoMaior);
    printf("\nMenor elemento: %d", menor);
    printf("\nPosicao do menor elemento: %d", posicaoMenor);
}
//  9. Ler um vetor com 20 números inteiros e apresentar o resultado da multiplicação
//      dos valores pelos seus índices.
void Question09()
{
    int vetor20[tam];
    printf("Digite 20 numeros inteiros: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d%*c", &vetor20[i]);
        vetor20[i] = vetor20[i] * i;
    }
    printf("Resultado: ");
    for (int i = 0; i < tam; i++)
        printf("\n%d", vetor20[i]);
}

//  10. Gerar 100 números aleatórios e armazená-los em um vetor. Exibir o vetor.
void Question10()
{
    int vetor100[tam];
    for (int i = 0; i < tam; i++)
        vetor100[i] = rand() % 100;
    printf("Vetor: ");
    for (int i = 0; i < tam; i++)
        printf("%d ", vetor100[i]);
}
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    // Question01();
    // Question02();
    Question03();
    // Question04();
    // Question05();
    // Question06();
    // Question07();
    // Question08();
    // Question09();
    // Question10();
    return 0;
}