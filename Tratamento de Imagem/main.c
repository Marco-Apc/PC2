#include <stdlib.h>
#include <stdio.h>

/*
    PROGRAMA LE UMA MATRIZ E CRIA UMA COPIA COM FILTRO LBP (Local Binary Patterns)
    O FILTRO LBP É UM DESCRITOR DE TEXTURA MUITO UTILIZADO EM ALGORIMOS DE RECONHECIMENTO DE IMAGENS.
    O FUNICIONAMENTO DESSE FILTRO É SIMPLES: PARA CADA PIXEL DE UMA IMAGEM DE 256 NÍVEIS DE CINZA,
    SELECIONA-SE UMA VIZINHANÇA DE 8 PIXELS.
    O VALOR LBP É ENTÃO CALCULADO PARA O PIXEL CENTRAL E ARMAZENADO NA IMAGEM DESTINO,
    QUE POSSUI AS MESMAS DIMENSÕES DA IMAGEM ORIGINAL.

    PARA O CÁLCULO DO LBP DE UM PIXEL, USA-SE UMA MÁSCARA COM VALORES 2^N, COM N = {0, ..., 7},
    OU SEJA: 1, 2, 4, 8, 16, 32, 64 e 128.

    NOTE QUE ESSA CODIFICAÇÃO GARANTE VALORES LBP SOMENTE ENTRE 0 e 255.
*/

/*
    problemas do código até agora:
    1 - não sei como ler comentário no arquivo original (if com condição igual a # ????)
    2 - implementar a variante P5 pra ganhar 3pontos extras
    3 - o código atualmente so consegue executar perfeitamente com o exemplo.pgm
    (achoq o problema pra ler outros arquivos esta nas quebra de linha da matriz original)
    4 - criar uma função para teste de leitura do arquivo
    (o código repete um bloco 2vezes, não há necessidade se for uma função externa)
*/

int calcula_ponta(int referencia, int pixel_referencia, int v1, int v2, int v3)
{
    // CONDIÇÃO 1: VARIAVEL ESTA NA PONTA DA MATRIZ
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
    // CONDIÇÃO 2: VARIAVEL NA BEIRADA MAS NÃO NA PONTA
    // (soma 5casas)
    int valorPixel = 0;

    if (referencia == 8) // LINHA DE CIMA
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

    if (referencia == 2) // LINHA DE BAIXO
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

    if (referencia == 4) // LINHA DA ESQUERDA
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

    if (referencia == 6) // LINHA DA DIREITA
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
    // CONDIÇÃO 3: VARIAVEL NO MEIO DA MATRIZ
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

void testaArquivo(FILE *arq)
{
    if (!arq)
    {
        printf("ERRO AO ABRIR ARQUIVO");
        exit(1);
    }
}

int main()
{
    FILE *arquivo;
    arquivo = fopen("exemplo.pgm", "r");

    // função para teste de leitura do arquivo
    testaArquivo(arquivo);
    // criação e leitura de variaveis
    char tipo[2];
    int linha, coluna, MAX_ORIGINAL;
    // vMAX é uma em todos arquivos no filtro LBP porque (2^8) - 1 == 255
    const int vMAX = 255;
    fscanf(arquivo, "%s", &tipo);
    printf("\ntipo: %s", tipo);
    fscanf(arquivo, "%d %d", &coluna, &linha);
    printf("\ncoluna: %d linha: %d", coluna, linha);
    fscanf(arquivo, "%d", &MAX_ORIGINAL);
    printf("\nMAX ORIGINAL: %d", MAX_ORIGINAL);

    // criação dos indices e matrizes original e copia
    int Orig[linha][coluna], Copia[linha][coluna];
    int i, j;

    /*
        variavel referencia serve como parametro na definição do pixel nas condições 1 e 2
        funciona com base no teclado númerico
    */
    int referencia = 0;

    // leitura da matriz original
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            fscanf(arquivo, "%d ", &Orig[i][j]);
        }
        fscanf(arquivo, "\n");
    }
    printf("\n");

    // escrita da matriz original no termminal (opcional)
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d ", Orig[i][j]);
        }
        printf("\n");
    }

    // fechando o arquivo
    fclose(arquivo);
    // criando um novo arquivo
    arquivo = fopen("exemplo_copia.pgm", "w+");

    // teste de leitura do arquivo
    if (!arquivo)
    {
        printf("ERRO AO ABRIR ARQUIVO");
        exit(1);
    }

    // preenchimento da matriz
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            // DIVIDIDO EM 3 CONDIÇÕES

            // CONDIÇÃO 1: VARIAVEL ESTA NA PONTA DA MATRIZ
            if ((i == 0 || i == linha - 1) && (j == 0 || j == coluna - 1))
            {
                if (i == 0 && j == 0) // SUPERIOR ESQUERDA
                {
                    referencia = 7;
                    Copia[i][j] = calcula_ponta(referencia, Orig[i][j], Orig[i][j + 1], Orig[i + 1][j], Orig[i + 1][j + 1]);
                }
                else if (i == 0 && j == coluna - 1) // SUPERIOR DIREITA
                {
                    referencia = 9;
                    Copia[i][j] = calcula_ponta(referencia, Orig[i][j], Orig[i][j - 1], Orig[i + 1][j - 1], Orig[i + 1][j]);
                }
                else if (i == linha - 1 && j == 0) // INFERIOR ESQUERDA
                {
                    referencia = 1;
                    Copia[i][j] = calcula_ponta(referencia, Orig[i][j], Orig[i - 1][j], Orig[i - 1][j + 1], Orig[i][j + 1]);
                }
                else if (i == linha - 1 && j == coluna - 1) // INFERIOR DIREITA
                {
                    referencia = 3;
                    Copia[i][j] = calcula_ponta(referencia, Orig[i][j], Orig[i - 1][j - 1], Orig[i - 1][j], Orig[i][j - 1]);
                }
            }

            // CONDIÇÃO 2: VARIAVEL NA BEIRADA MAS NÃO NA PONTA
            else if ((i == 0 || i == linha - 1) || (j == 0 || j == coluna - 1))
            {
                if (i == 0) // LINHA DE CIMA
                {
                    referencia = 8;
                    Copia[i][j] = calcula_beirada(referencia, Orig[i][j], Orig[i][j - 1], Orig[i][j + 1], Orig[i + 1][j - 1], Orig[i - 1][j], Orig[i + 1][j + 1]);
                }
                else if (i == linha - 1) // LINHA DE BAIXO
                {
                    referencia = 2;
                    Copia[i][j] = calcula_beirada(referencia, Orig[i][j], Orig[i - 1][j - 1], Orig[i - 1][j], Orig[i - 1][j + 1], Orig[i][j - 1], Orig[i][j + 1]);
                }
                else if (j == 0) // COLUNA DA ESQUERDA
                {
                    referencia = 4;
                    Copia[i][j] = calcula_beirada(referencia, Orig[i][j], Orig[i - 1][j], Orig[i - 1][j + 1], Orig[i][j + 1], Orig[i + 1][j], Orig[i + 1][j + 1]);
                }
                else if (j == coluna - 1) // COLUNA DA DIREITA
                {
                    referencia = 6;
                    Copia[i][j] = calcula_beirada(referencia, Orig[i][j], Orig[i - 1][j - 1], Orig[i - 1][j], Orig[i][j - 1], Orig[i + 1][j - 1], Orig[i + 1][j]);
                }
            }

            // CONDIÇÃO 3: VARIAVEL NO MEIO DA MATRIZ
            else // condição 3 não precisa passar a variavel referencia porque todos os pontos em volta estão preenchidos
                Copia[i][j] = calcula_meio(Orig[i][j], Orig[i - 1][j - 1], Orig[i - 1][j], Orig[i - 1][j + 1], Orig[i][j - 1], Orig[i][j + 1], Orig[i + 1][j - 1], Orig[i + 1][j], Orig[i + 1][j + 1]);
        }
    }

    // escrita da nova matriz no terminal   (opcional)
    printf("\n\nMATRIZ NO FILTRO LBP:\n");
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d ", Copia[i][j]);
        }
        printf("\n");
    }

    // escrita da variante, linhas e colunas e valor maximo do pixel no arquivo .pgm
    fprintf(arquivo, "%s\n", tipo);
    fprintf(arquivo, "%d %d\n", coluna, linha);
    fprintf(arquivo, "%d\n", vMAX);

    // escrita da matriz no arquivo .pgm
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            fprintf(arquivo, "%d ", Copia[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    // fechando o arquivo
    fclose(arquivo);

    // fim do programa :)
    return 0;
}