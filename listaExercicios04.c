#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//  1. Supondo que as variáveis NT, NMAT, CPF e SX sejam utilizadas para armazenar,
//      respectivamente, a nota do aluno, o número da matrícula, cpf e o sexo, declare-
//      as corretamente, associando o tipo adequado ao dado que será armazenado.
void questao01()
{
}
//  2. Faça um programa que carregue um vetor com 15 elementos inteiros e
//      verifique a existência de elementos iguais a 30, mostrando as posições em que
//      esses elementos apareceram.
//  3. Faça um programa que tenha funções que sejam capazes de receber dois
//      valores como parâmetros e realizem as operações de soma, subtração,
//      multiplicação e divisão.
//  4. Faça um programa que tenha um procedimento (“função” sem retorno) que
//      seja capaz de receber três diferentes valores em reais parâmetros e os converta
//      para dólar R$ 2,0357, Euro R$ 2,7149 e Libra R$ 3,2722. Utilize passagem por
//      referência.
//  5. Faça um procedimento que calcule e mostre a área de um trapézio. A área do
//      trapézio é dado por A = (b + B) ∗ h/2 , onde b é base menor, B é base maior e h
//      é altura do trapézio.
//  6. Elabore um algoritmo que dados dois lados de um triângulo retângulo, calcule
//      a respectiva hipotenusa.
//  7. Escreva um programa que leia 10 inteiros da entrada padrão, armazene-os em
//      um vetor e os escreva na saída padrão na ordem contrária; todos os acessos ao
//      vetor devem ser feitos usando somente ponteiros, sem usar índices (vet[i], etc).
void questao07(){
    int *vetor = malloc(sizeof(int));
    
}
//  8. Escreva um programa para calcular o tamanho de uma string usando somente
//      ponteiros.
//  9. Escreva um programa para concatenar duas strings usando somente ponteiros.
void questao09()
{
    char *str01 = malloc(sizeof(char));
    char *str02 = malloc(sizeof(char));
    printf("Digite a primeira frase: ");
    gets(str01);
    printf("Digite a segunda frase: ");
    gets(str02);
    str01 = strcat(str01, str02);
    printf("Frases concatenadas: %s.", str01);
    free(str01);
    free(str02);
}
//  10.Escreva um programa para trocar dois valores usando uma função e ponteiros.
void trocaValores(char *str01, char *str02){
    char *aux = malloc(sizeof(char));
    strcpy(aux, str01);
    strcpy(str01, str02);
    strcpy(str02, aux);
}
void questao10()
{
    char *str01 = malloc(sizeof(char));
    char *str02 = malloc(sizeof(char));
    printf("Digite a primeira frase: ");
    gets(str01);
    printf("Digite a segunda frase: ");
    gets(str02);
    trocaValores(str01, str02);
    printf("Frases \"trocadas\":\n");
    printf("%s\n", str01);
    printf("%s\n", str02);
    free(str01);
    free(str02);
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    // questao09();
    // questao10();
    return 0;
}