#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    char frase1[30], frase2[30], aux[30];
    int valorFrase1 = 0, valorFrase2 = 0;
    int tamanhoFrase1 = 0, tamanhoFrase2 = 0, max = 0;
    printf("Digite duas frases para organiza-las em ordem alfabetica: \n");
    gets(frase1);
    gets(frase2);
    // Obtém o tamanho das frases
    tamanhoFrase1 = strlen(frase1);
    tamanhoFrase2 = strlen(frase2);
    // Descobre qual a maior frase
    if (tamanhoFrase1 > tamanhoFrase2)
        max = tamanhoFrase1;
    else
        max = tamanhoFrase2;
    // Obtém o "valor" das frases
    valorFrase1 = strncmp(frase1, frase2, max);
    valorFrase2 = strncmp(frase2, frase1, max);
    // Organiza as frases em ordem alfabética por "valor"
    if (valorFrase1 > valorFrase2)
    {
        strcpy(aux, frase1);
        strcpy(frase1, frase2);
        strcpy(frase2, aux);
    }
    else if (valorFrase1 == valorFrase2)
        printf("As frases sao iguais.\n");
    printf("\nFrases organizadas: ");
    printf("\n%s, ", frase1);
    printf("%s\n", frase2);

    system("pause");
    return 0;
}
