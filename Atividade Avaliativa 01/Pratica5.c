#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 10
//  PRÁTICA 5
//
//  ENUNCIADO: Crie um programa, em linguagem C, que receba 10 registros contendo:
//  Nome, matrícula, telefone e e-mail. Solicite que sejam digitados todos os dados de todos os
//  registros e ao final salve-os em um arquivo com a extensão CSV, utilize o ; (ponto e vírgula)
//  para separador e campo. O nome do arquivo deve ser o seu número de matrícula.
struct Pratica5
{
    char Nome[60];
    long int Matricula;
    char Telefone[15];
    char Email[60];
};
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    FILE *arquivo;
    struct Pratica5 registro[tam];
    arquivo = fopen("153742576501.csv", "w+");
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o nome: ");
        scanf("%s", &registro[i].Nome);
        printf("Digite a matricula: ");
        scanf("%li", &registro[i].Matricula);
        printf("Digite o telefone: ");
        scanf("%s", &registro[i].Telefone);
        printf("Digite o email: ");
        scanf("%s", &registro[i].Email);
        fprintf(arquivo, "%s;%li;%s;%s;\n", registro[i].Nome, registro[i].Matricula, registro[i].Telefone, registro[i].Email);
    }
    fclose(arquivo);
    printf("\n");
    system("pause");
    return 0;
}