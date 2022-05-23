#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int calcula_ponta(int referencia, int pixel_referencia, int v1, int v2, int v3);
int calcula_beirada(int referencia, int pixel_referencia, int v1, int v2, int v3, int v4, int v5);
int calcula_meio(int pixel_referencia, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8);
void ignoraComentario(FILE *arq);
void testeArquivo(FILE *arquivo);
void p2();
void p5();

int main()
{
    setlocale(LC_ALL, "");
    int verificacao = 0;
    printf("\nQual o tipo do arquivo:\n[1] - P2\n[2] - P5\n");
    scanf("%d%*c", &verificacao);
    do{
        if(verificacao == 1)
            p2();
        else if(verificacao == 2)
            p5();
        else
            printf("\nOpcao invalida! Tente novamente.\n");
        printf("\n\nQual o tipo do arquivo:\n[1] - P2\n[2] - P5\n");
        scanf("%d%*c", &verificacao);
    } while(verificacao < 1 || verificacao > 2);
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

void testeArquivo(FILE *arquivo){
    
    if(!arquivo){
        printf("ERRO AO ABRIR ARQUIVO");
        exit(1);
    }
}

void p2()
{
    FILE *arquivo;
    arquivo = fopen("C:\\Users\\marco\\Documents\\Faculdade\\PC2\\Tratamento de Imagem\\imagens\\lena.pgm", "r");

    // função para teste de leitura do arquivo
    testeArquivo(arquivo);

    // criação de variaveis
    char tipo[3];
    int linha, coluna;
    int MAX_ORIGINAL;
    // MAX_ORIGINAL não serve pra nada no codigo porque vMAX é uma constante quando usamos o filtro LBP

    // vMAX é uma constante em todos arquivos no filtro LBP porque (2^8) - 1 == 255
    const int vMAX = 255;

    // leitura de variaveis
    fscanf(arquivo, "%s", &tipo);
    tipo[3] = '\0';
    fscanf(arquivo, "%d %d", &coluna, &linha);
    fscanf(arquivo, "%d", &MAX_ORIGINAL);

    /*
     As duas matrizes são do tipo unsigned char para economizar memoria.
     Criando as matrizes do tipo inteiro inicialmente funciona com aruivos pequenos
     porque o programa não aloca tanto espaço.
     O problema ocorre quando usamos arquivos muito grandes, consumindo ( coluna*linha*4 ) bytes.
     Usando unsigned char consegui diminuir esse número 4 vezes.
    */
    unsigned char Orig[linha][coluna];
    unsigned char *Copia = malloc(linha * coluna * sizeof(char));
    // Único motivo para Copia ser um ponteiro é para poder mostrar a matriz no terminal.
    // O programa funcionaria igual se fosse uma variavel char primitiva para coleta e atribuição direta.

    if (!Copia)
    {
        printf("\nNAO CONSEGUI ALOCAR O PONTEIRO PARA A MATRIZ");
        exit(1);
    }

    // ponteiro com o endereço original da matriz copia.
    char *comecoCopia = Copia;

    // criação dos índices.
    int i, j;

    // variavel referencia serve como parametro na definição do pixel nas condições 1 e 2,
    // funciona com base no teclado númerico.

    int referencia;

    // leitura da matriz original
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            fscanf(arquivo, "%d ", &Orig[i][j]);
        }
    }

    int mostraNoTerminal = 0; // variável opcional para mostrar as matrizes no terminal
    if (mostraNoTerminal)     // mostrando a matriz original no terminal
    {
        printf("\ntipo: %s", tipo);
        printf("\ncoluna: %d linha: %d", coluna, linha);
        printf("\nMAX ORIGINAL: %d\n", MAX_ORIGINAL);
        for (i = 0; i < linha; i++)
        {
            for (j = 0; j < coluna; j++)
            {
                printf("%d ", Orig[i][j]);
            }
            printf("\n");
        }
    }

    // fechando o arquivo
    fclose(arquivo);
    // criando um novo arquivo
    arquivo = fopen("C:\\Users\\marco\\Documents\\Faculdade\\PC2\\Tratamento de Imagem\\imagens\\lenaCopia.pgm", "w");

    // teste de leitura do arquivo
    testeArquivo(arquivo);

    // escrita da variante, linhas e colunas e valor maximo do pixel no arquivo.pgm
    fprintf(arquivo, "%s\n", tipo);
    fprintf(arquivo, "%d %d\n", coluna, linha);
    fprintf(arquivo, "%d\n", vMAX);

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
                    *Copia = calcula_ponta(referencia, Orig[i][j], Orig[i][j + 1], Orig[i + 1][j], Orig[i + 1][j + 1]);
                }
                else if (i == 0 && j == coluna - 1) // SUPERIOR DIREITA
                {
                    referencia = 9;
                    *Copia = calcula_ponta(referencia, Orig[i][j], Orig[i][j - 1], Orig[i + 1][j - 1], Orig[i + 1][j]);
                }
                else if (i == linha - 1 && j == 0) // INFERIOR ESQUERDA
                {
                    referencia = 1;
                    *Copia = calcula_ponta(referencia, Orig[i][j], Orig[i - 1][j], Orig[i - 1][j + 1], Orig[i][j + 1]);
                }
                else if (i == linha - 1 && j == coluna - 1) // INFERIOR DIREITA
                {
                    referencia = 3;
                    *Copia = calcula_ponta(referencia, Orig[i][j], Orig[i - 1][j - 1], Orig[i - 1][j], Orig[i][j - 1]);
                }
            }

            // CONDIÇÃO 2: VARIAVEL NA BEIRADA MAS NÃO NA PONTA
            else if ((i == 0 || i == linha - 1) || (j == 0 || j == coluna - 1))
            {
                if (i == 0) // LINHA DE CIMA
                {
                    referencia = 8;
                    *Copia = calcula_beirada(referencia, Orig[i][j], Orig[i][j - 1], Orig[i][j + 1], Orig[i + 1][j - 1], Orig[i - 1][j], Orig[i + 1][j + 1]);
                }
                else if (i == linha - 1) // LINHA DE BAIXO
                {
                    referencia = 2;
                    *Copia = calcula_beirada(referencia, Orig[i][j], Orig[i - 1][j - 1], Orig[i - 1][j], Orig[i - 1][j + 1], Orig[i][j - 1], Orig[i][j + 1]);
                }
                else if (j == 0) // COLUNA DA ESQUERDA
                {
                    referencia = 4;
                    *Copia = calcula_beirada(referencia, Orig[i][j], Orig[i - 1][j], Orig[i - 1][j + 1], Orig[i][j + 1], Orig[i + 1][j], Orig[i + 1][j + 1]);
                }
                else if (j == coluna - 1) // COLUNA DA DIREITA
                {
                    referencia = 6;
                    *Copia = calcula_beirada(referencia, Orig[i][j], Orig[i - 1][j - 1], Orig[i - 1][j], Orig[i][j - 1], Orig[i + 1][j - 1], Orig[i + 1][j]);
                }
            }

            // CONDIÇÃO 3: VARIAVEL NO MEIO DA MATRIZ
            // condição 3 não precisa passar a variavel referencia porque todos os pontos em volta estão preenchidos
            else
                *Copia = calcula_meio(Orig[i][j], Orig[i - 1][j - 1], Orig[i - 1][j], Orig[i - 1][j + 1], Orig[i][j - 1], Orig[i][j + 1], Orig[i + 1][j - 1], Orig[i + 1][j], Orig[i + 1][j + 1]);

            // colocando o pixel no arquivo
            fprintf(arquivo, "%d ", *Copia);
            // subindo o ponteiro para a nova posição
            Copia++;
        }
        fprintf(arquivo, "\n");
    }

    Copia = comecoCopia; // voltando o ponteiro para a posição orginal

    if (mostraNoTerminal) // mostrando a matriz copia no terminal
    {
        printf("\n\nMATRIZ NO FILTRO LBP:");
        printf("\n%s", tipo);
        printf("\n%d %d", coluna, linha);
        printf("\n%d\n", vMAX);

        for (i = 0; i < linha; i++)
        {
            for (j = 0; j < coluna; j++)
            {
                printf("%d ", *Copia);
                Copia++;
            }
            printf("\n");
        }

        Copia = comecoCopia; // voltando o ponteiro para a posição orginal
    }

    // desalocando o ponteiro
    free(Copia);

    // fechando o arquivo
    fclose(arquivo);

    // fim do programa :)
    return 0;
}

void p5()
{
    FILE *arq;
    char tipo_arquivo[3];
    int linhas, colunas, escala;

    arq = fopen("C:\\Users\\marco\\Documents\\Faculdade\\PC2\\Tratamento de Imagem\\imagens\\bird.pgm", "rb");

    ignoraComentario(arq);
    fscanf(arq, "%s", tipo_arquivo);
    // printf("\n %s", tipo_arquivo);

    ignoraComentario(arq);
    fscanf(arq, "%d %d", &colunas, &linhas);
    // printf("\n %d %d", linhas, colunas);

    ignoraComentario(arq);
    fscanf(arq, "%d", &escala);
    // printf("\n %d", escala);
    escala = 255;

    unsigned char matriz[linhas][colunas];

    fread(matriz, sizeof(unsigned char), linhas * colunas, arq);
    // printf(matriz);

    fclose(arq);

    FILE *arq_saida;
    arq_saida = fopen("C:\\Users\\marco\\Documents\\Faculdade\\PC2\\Tratamento de Imagem\\imagens\\birdSaida.pgm", "wb");

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