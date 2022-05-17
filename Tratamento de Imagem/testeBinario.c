#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int calcula_ponta(int referencia, int pixel_referencia, int v1, int v2, int v3);
int calcula_beirada(int referencia, int pixel_referencia, int v1, int v2, int v3, int v4, int v5);
int calcula_meio(int pixel_referencia, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8);
void ignoraComentario(FILE *arq);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    FILE *arq;
    char tipo_arquivo[3];
    int linhas, colunas, escala;

    arq = fopen("mona_lisa.pgm", "rb");

    ignoraComentario(arq);
    fscanf(arq, "%s", tipo_arquivo);
    printf("\n %s", tipo_arquivo);

    ignoraComentario(arq);
    fscanf(arq, "%d %d", &colunas, &linhas);
    printf("\n %d %d", linhas, colunas);

    ignoraComentario(arq);
    fscanf(arq, "%d", &escala);
    printf("\n %d", escala);
    escala = 255;

    unsigned char matriz[linhas][colunas];

    fread(matriz, sizeof(unsigned char), linhas * colunas, arq);
    // printf(matriz);

    fclose(arq);

    FILE *arq_saida;
    arq_saida = fopen("mona_lisa_saida.pgm", "wb");

    fprintf(arq_saida, "%s\n", tipo_arquivo);
    fprintf(arq_saida, "%d %d\n", colunas, linhas);
    fprintf(arq_saida, "%d\n", escala);

    int referencia = 0;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if ((i == 0 || i == linhas - 1) && (j == 0 || j == colunas - 1))
            {
                if (i == 0 && j == 0)
                {
                    referencia = 7;
                    matriz[i][j] = calcula_ponta(referencia, matriz[i][j], matriz[i][j + 1], matriz[i + 1][j], matriz[i + 1][j + 1]);
                }
                else if (i == 0 && j == colunas - 1)
                {
                    referencia = 9;
                    matriz[i][j] = calcula_ponta(referencia, matriz[i][j], matriz[i][j - 1], matriz[i + 1][j - 1], matriz[i + 1][j]);
                }
                else if (i == linhas - 1 && j == 0)
                {
                    referencia = 1;
                    matriz[i][j] = calcula_ponta(referencia, matriz[i][j], matriz[i - 1][j], matriz[i - 1][j + 1], matriz[i][j + 1]);
                }
                else if (i == linhas - 1 && j == colunas - 1)
                {
                    referencia = 3;
                    matriz[i][j] = calcula_ponta(referencia, matriz[i][j], matriz[i - 1][j - 1], matriz[i - 1][j], matriz[i][j - 1]);
                }
            }
            else if ((i == 0 || i == linhas - 1) || (j == 0 || j == colunas - 1))
            {
                if (i == 0)
                {
                    referencia = 8;
                    matriz[i][j] = calcula_beirada(referencia, matriz[i][j], matriz[i][j - 1], matriz[i][j + 1], matriz[i + 1][j - 1], matriz[i - 1][j], matriz[i + 1][j + 1]);
                }
                else if (i == linhas - 1)
                {
                    referencia = 2;
                    matriz[i][j] = calcula_beirada(referencia, matriz[i][j], matriz[i - 1][j - 1], matriz[i - 1][j], matriz[i - 1][j + 1], matriz[i][j - 1], matriz[i][j + 1]);
                }
                else if (j == 0)
                {
                    referencia = 4;
                    matriz[i][j] = calcula_beirada(referencia, matriz[i][j], matriz[i - 1][j], matriz[i - 1][j + 1], matriz[i][j + 1], matriz[i + 1][j], matriz[i + 1][j + 1]);
                }
                else if (j == colunas - 1)
                {
                    referencia = 6;
                    matriz[i][j] = calcula_beirada(referencia, matriz[i][j], matriz[i - 1][j - 1], matriz[i - 1][j], matriz[i][j - 1], matriz[i + 1][j - 1], matriz[i + 1][j]);
                }
            }
            else
                matriz[i][j] = calcula_meio(matriz[i][j], matriz[i - 1][j - 1], matriz[i - 1][j], matriz[i - 1][j + 1], matriz[i][j - 1], matriz[i][j + 1], matriz[i + 1][j - 1], matriz[i + 1][j], matriz[i + 1][j + 1]);
        }
    }

    fwrite(matriz, sizeof(unsigned char), linhas * colunas, arq_saida);

    fclose(arq_saida);
    return 0;
}

void ignoraComentario(FILE *arq)
{
    int ch;
    char line[100];
    while ((ch = fgetc(arq)) != EOF && isspace(ch))
        ;
    if (ch == '#')
    {
        fgets(line, sizeof(line), arq);
        ignoraComentario(arq);
    }
    else
        fseek(arq, -1, SEEK_CUR);
}

int calcula_ponta(int referencia, int pixel_referencia, int v1, int v2, int v3)
{
    // CONDICAO 1: VARIAVEL ESTA NA PONTA DA MATRIZ
    // (soma 3casas)
    int valorPixel = 0;

    if (referencia == 7) // SUPERIOR ESQUERDA
    {
        if (v1 >= pixel_referencia)
            valorPixel += 16;
        if (v2 >= pixel_referencia)
            valorPixel += 64;
        if (v3 >= pixel_referencia)
            valorPixel += 128;
    }

    if (referencia == 9) // SUPERIOR DIREITA
    {
        if (v1 >= pixel_referencia)
            valorPixel += 8;
        if (v2 >= pixel_referencia)
            valorPixel += 32;
        if (v3 >= pixel_referencia)
            valorPixel += 64;
    }

    if (referencia == 1) // INFERIOR ESQUERDA
    {
        if (v1 >= pixel_referencia)
            valorPixel += 2;
        if (v2 >= pixel_referencia)
            valorPixel += 4;
        if (v3 >= pixel_referencia)
            valorPixel += 16;
    }

    if (referencia == 3) // INFERIOR DIREITA
    {
        if (v1 >= pixel_referencia)
            valorPixel += 1;
        if (v2 >= pixel_referencia)
            valorPixel += 2;
        if (v3 >= pixel_referencia)
            valorPixel += 8;
    }

    return valorPixel;
}

int calcula_beirada(int referencia, int pixel_referencia, int v1, int v2, int v3, int v4, int v5)
{
    // CONDICAO 2: VARIAVEL NA BEIRADA MAS N�O NA PONTA
    // (soma 5casas)
    int valorPixel = 0;

    if (referencia == 8) // linhas DE CIMA
    {
        if (v1 >= pixel_referencia)
            valorPixel += 8;
        if (v2 >= pixel_referencia)
            valorPixel += 16;
        if (v3 >= pixel_referencia)
            valorPixel += 32;
        if (v4 >= pixel_referencia)
            valorPixel += 64;
        if (v5 >= pixel_referencia)
            valorPixel += 128;
    }

    if (referencia == 2) // linhas DE BAIXO
    {
        if (v1 >= pixel_referencia)
            valorPixel += 1;
        if (v2 >= pixel_referencia)
            valorPixel += 2;
        if (v3 >= pixel_referencia)
            valorPixel += 4;
        if (v4 >= pixel_referencia)
            valorPixel += 8;
        if (v5 >= pixel_referencia)
            valorPixel += 16;
    }

    if (referencia == 4) // linhas DA ESQUERDA
    {
        if (v1 >= pixel_referencia)
            valorPixel += 2;
        if (v2 >= pixel_referencia)
            valorPixel += 4;
        if (v3 >= pixel_referencia)
            valorPixel += 16;
        if (v4 >= pixel_referencia)
            valorPixel += 64;
        if (v5 >= pixel_referencia)
            valorPixel += 128;
    }

    if (referencia == 6) // linhas DA DIREITA
    {
        if (v1 >= pixel_referencia)
            valorPixel += 1;
        if (v2 >= pixel_referencia)
            valorPixel += 2;
        if (v3 >= pixel_referencia)
            valorPixel += 8;
        if (v4 >= pixel_referencia)
            valorPixel += 32;
        if (v5 >= pixel_referencia)
            valorPixel += 64;
    }

    return valorPixel;
}

int calcula_meio(int pixel_referencia, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8)
{
    // CONDICAO 3: VARIAVEL NO MEIO DA MATRIZ
    // (soma 8casas)
    int valorPixel = 0;
    if (v1 >= pixel_referencia)
        valorPixel += 1;
    if (v2 >= pixel_referencia)
        valorPixel += 2;
    if (v3 >= pixel_referencia)
        valorPixel += 4;
    if (v4 >= pixel_referencia)
        valorPixel += 8;
    if (v5 >= pixel_referencia)
        valorPixel += 16;
    if (v6 >= pixel_referencia)
        valorPixel += 32;
    if (v7 >= pixel_referencia)
        valorPixel += 64;
    if (v8 >= pixel_referencia)
        valorPixel += 128;

    return valorPixel;
}
