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
void questao01()
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
void questao02()
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
void questao03()
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
    FILE *arqSaida = fopen("arqSaida.txt", "w");
    while ((caracter = fgetc(arq)) != EOF)
    {
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')
            caracter = '*';
        fputc(caracter, arqSaida);
    }
    fclose(arq);
    fclose(arqSaida);
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
void questao04()
{
    // tentativa de implementar a agenda
    FILE *arq = fopen("agenda.bin", "r+b");
    char nome[20];
    long long int telefone = 0;
    int dia = 0, mes = 0;
    if (!arq)
    {
        arq = fopen("agenda.bin", "w+b");
        fclose(arq);
        arq = fopen("agenda.bin", "r+b");
    }
    while (1)
    {
        printf("\n1 - Inserir contato\n2 - Remover contato\n3 - Pesquisar contato\n4 - Listar todos os contatos\n5 - Listar contatos que iniciam com uma letra\n6 - Listar aniversariantes do mes\n7 - Sair\n");
        int opcao = 0;
        do
        {
            printf("Digite uma opcao: ");
            scanf("%d", &opcao);
            if (opcao < 1 || opcao > 7)
                printf("Opcao invalida.\n");
        } while (opcao < 1 || opcao > 7);
        switch (opcao)
        {
        case 1:
            printf("Digite o nome: ");
            scanf("%s", &nome);
            printf("Digite o telefone: ");
            scanf("%ld", &telefone);
            printf("Digite o aniversario (dia/mes): ");
            scanf("%d%*c%d", &dia, &mes);
            fwrite(&nome, sizeof(char), 20, arq);
            fwrite(&telefone, sizeof(char), 20, arq);
            fwrite(&dia, sizeof(int), 1, arq);
            fwrite(&mes, sizeof(int), 1, arq);
            break;
        case 2:
            printf("Digite o nome: ");
            scanf("%s", &nome);
            if (strcmp(nome, "") == 0)
                printf("Nome invalido.\n");
            else if (strcmp(nome, fread(&nome, sizeof(char), 20, arq)) != 0)
                printf("Nome nao encontrado.\n");
            fseek(arq, 0, SEEK_SET);
            while (fread(&nome, sizeof(char), 20, arq))
            {
                if (strcmp(nome, nome) == 0)
                {
                    fseek(arq, -20, SEEK_CUR);
                    fwrite("", sizeof(char), 20, arq);
                    break;
                }
            }
            break;
        case 3:
            printf("Digite o nome: ");
            scanf("%s", &nome);
            fseek(arq, 0, SEEK_SET);
            while (fread(&nome, sizeof(char), 20, arq))
            {
                if (strcmp(nome, nome) == 0)
                {
                    printf("Nome: %s\n", nome);
                    telefone = fread(&telefone, sizeof(char), 20, arq);
                    printf("Telefone: %d\n", telefone);
                    dia = fread(dia, sizeof(int), dia, arq);
                    mes = fread(mes, sizeof(int), mes, arq);
                    printf("Aniversario: %d/%d\n", dia, mes);
                }
                else
                    printf("Nome nao encontrado.\n");
                break;
            }
            break;
        case 4:
            while (fread(&nome, sizeof(char), 20, arq))
            {
                printf("Nome: %s\n", nome);
                printf("Telefone: %d\n", telefone);
                printf("Aniversario: %d/%d\n", dia, mes);
            }
            break;
            // listar contatos que iniciam com uma dada letra
        case 5:
            printf("Digite a letra: ");
            scanf("%s", &nome);
            fseek(arq, 0, SEEK_SET);
            while (fread(&nome, sizeof(char), 20, arq))
            {
                if (nome[0] == nome[0])
                {
                    printf("Nome: %s\n", nome);
                    printf("Telefone: %d\n", telefone);
                    printf("Aniversario: %d/%d\n", dia, mes);
                }
                else
                    printf("Nome nao encontrado.\n");
                break;
            }
            break;
        case 6:
            printf("Digite o mes: ");
            scanf("%d", &mes);
            while (fread(mes, sizeof(char), 20, arq) == mes)
            {
                printf("Nome: %s\n", fread(nome, sizeof(char), 20, arq));
                printf("Telefone: %i\n", (int)telefone);
                printf("Aniversario: %d/%d\n", dia, mes);
            }
            break;
        case 7:
            fclose(arq);
            return;
        default:
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // questao01();
    // questao02();
    // questao03();
    questao04();
    return 0;
}