#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//  1. Escreva um programa que:
//  (a) Crie/abra um arquivo texto de nome "arq.txt".
//  (b) Permita que o usuário grave diversos caracteres nesse arquivo,
//  até que o usuário entre com o caractere ’0’.
//  (c) Feche o arquivo.
//  Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela
//  todos os caracteres armazenados.
void Questao01()
{
    FILE *arq;
    char caracter;
    arq = fopen("arq.txt", "w");
    printf("Digite um caracter: ");
    while ((caracter = getchar()) != '0')
        fputc(caracter, arq);
    fclose(arq);
    arq = fopen("arq.txt", "r");
    while ((caracter = fgetc(arq)) != EOF)
        printf("%c", caracter);
    fclose(arq);
}
//  2. Faça um programa que receba do usuário um arquivo texto e mostre
//  na tela quantas letras são vogais e quantas são consoantes.
void Questao02()
{
    FILE *arq;
    char caracter, nomeArquivo[20];
    int vogais = 0, consoantes = 0;
    printf("Digite o nome do arquivo de texto plano: \n");
    scanf("%s", &nomeArquivo);
    strcat(nomeArquivo, ".txt");
    arq = fopen(nomeArquivo, "r");
    if (!arq)
    {
        printf("Arquivo nao encontrado.\n");
        exit(1);
    }
    while ((caracter = fgetc(arq)) != EOF)
    {
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')
            vogais++;
        else if (caracter == 'b' || caracter == 'c' || caracter == 'd' || caracter == 'f' || caracter == 'g' || caracter == 'h' || caracter == 'j' || caracter == 'k' || caracter == 'l' || caracter == 'm' || caracter == 'n' || caracter == 'p' || caracter == 'q' || caracter == 'r' || caracter == 's' || caracter == 't' || caracter == 'v' || caracter == 'w' || caracter == 'x' || caracter == 'y' || caracter == 'z')
            consoantes++;
    }
    fclose(arq);
    printf("\nVogais: %d\nConsoantes: %d\n", vogais, consoantes);
}
//  3. Faça um programa que receba do usuário um arquivo texto. Crie
//  outro arquivo texto contendo o texto do arquivo de entrada com as
//  vogais substituídas por ’*’.
void Questao03()
{
    FILE *arq;
}
//  4. Faça um programa para gerenciar uma agenda de contatos. Para cada
//  contato armazene o nome, o telefone e o aniversário (dia e mês).
//  programa deve permitir
//  (a) inserir contato.
//  (b) remover contato.
//  (c) pesquisar um contato pelo nome.
//  (d) listar todos os contatos.
//  (e) listar os contatos cujo nome inicia com uma dada letra.
//  (f) imprimir os aniversariantes do mês.
//  Sempre que o programa for encerrado, os contatos devem ser
//  armazenados em um arquivo binário. Quando o programa iniciar, os
//  contatos devem ser inicializados com os dados contidos neste
//  arquivo binário.

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // Questao01();
    Questao02();
    return 0;
}