#include <stdlib.h>
#include <stdio.h>

/*
    PROGRAMA LE UM ARQUIVO .PGM E CRIA UMA COPIA COM FILTRO LBP (Local Binary Patterns)
    O FILTRO LBP É UM DESCRITOR DE TEXTURA MUITO UTILIZADO EM ALGORIMOS DE RECONHECIMENTO DE IMAGENS.
    O FUNCIONAMENTO DESSE FILTRO É SIMPLES: PARA CADA PIXEL DE UMA IMAGEM DE 256 NÍVEIS DE CINZA,
    SELECIONA-SE UMA VIZINHANÇA DE 8 PIXELS.
    O VALOR LBP É ENTÃO CALCULADO PARA O PIXEL CENTRAL E ARMAZENADO NA IMAGEM DESTINO,
    QUE POSSUI AS MESMAS DIMENSÕES DA IMAGEM ORIGINAL.
    PARA O CÁLCULO DO LBP DE UM PIXEL, USA-SE UMA MÁSCARA COM VALORES 2^N, COM N = {0, ..., 7},
    OU SEJA: 1, 2, 4, 8, 16, 32, 64 e 128.
    NOTE QUE ESSA CODIFICAÇÃO GARANTE VALORES LBP SOMENTE ENTRE 0 e 255.
*/

int calcula_ponta(int referencia, int pixel_referencia, int v1, int v2, int v3)
{
    // QTD DE PIXLELS CALCULADOS COM ESSA FUNÇÃO: 4

    // CONDIÇÃO 1: VARIAVEL ESTA NA PONTA DA MATRIZ
    // (soma 3casas)
    int valorPixel=0;

    if(referencia==7)   // SUPERIOR ESQUERDA
    {
    if(v1>=pixel_referencia) valorPixel+=16;
    if(v2>=pixel_referencia) valorPixel+=64;
    if(v3>=pixel_referencia) valorPixel+=128;
    }

    if(referencia==9)   // SUPERIOR DIREITA
    {
    if(v1>=pixel_referencia) valorPixel+=8;
    if(v2>=pixel_referencia) valorPixel+=32;
    if(v3>=pixel_referencia) valorPixel+=64;
    }
    
    if(referencia==1)   // INFERIOR ESQUERDA
    {
    if(v1>=pixel_referencia) valorPixel+=2;
    if(v2>=pixel_referencia) valorPixel+=4;
    if(v3>=pixel_referencia) valorPixel+=16;
    }
    
    if(referencia==3)   // INFERIOR DIREITA
    {
    if(v1>=pixel_referencia) valorPixel+=1;
    if(v2>=pixel_referencia) valorPixel+=2;
    if(v3>=pixel_referencia) valorPixel+=8;
    }

    return valorPixel;
}

int calcula_beirada(int referencia, int pixel_referencia, int v1, int v2, int v3, int v4, int v5)
{
    // QTD DE PIXLELS CALCULADOS COM ESSA FUNÇÃO: LINHA*2 + COLUNA*2 - 4

    // CONDIÇÃO 2: VARIAVEL NA BEIRADA MAS NÃO NA PONTA
    // (soma 5casas)
    int valorPixel=0;

    if(referencia==8)   // LINHA DE CIMA
    {
    if(v1>=pixel_referencia) valorPixel+=8;
    if(v2>=pixel_referencia) valorPixel+=16;
    if(v3>=pixel_referencia) valorPixel+=32;
    if(v4>=pixel_referencia) valorPixel+=64;
    if(v5>=pixel_referencia) valorPixel+=128;
    }

    if(referencia==2)   // LINHA DE BAIXO
    {
    if(v1>=pixel_referencia) valorPixel+=1;
    if(v2>=pixel_referencia) valorPixel+=2;
    if(v3>=pixel_referencia) valorPixel+=4;
    if(v4>=pixel_referencia) valorPixel+=8;
    if(v5>=pixel_referencia) valorPixel+=16;
    }

    if(referencia==4)   // LINHA DA ESQUERDA
    {
    if(v1>=pixel_referencia) valorPixel+=2;
    if(v2>=pixel_referencia) valorPixel+=4;
    if(v3>=pixel_referencia) valorPixel+=16;
    if(v4>=pixel_referencia) valorPixel+=64;
    if(v5>=pixel_referencia) valorPixel+=128;
    }

    if(referencia==6)   // LINHA DA DIREITA
    {
    if(v1>=pixel_referencia) valorPixel+=1;
    if(v2>=pixel_referencia) valorPixel+=2;
    if(v3>=pixel_referencia) valorPixel+=8;
    if(v4>=pixel_referencia) valorPixel+=32;
    if(v5>=pixel_referencia) valorPixel+=64;
    }

    return valorPixel;
}

int calcula_meio(int pixel_referencia, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8)
{   
    // QTD DE PIXLELS CALCULADOS COM ESSA FUNÇÃO: 
    // LINHA * COLUNA - VALOR CALCULADO NAS OUTRAS FUNÇÕES
    // OU (LINHA - 2) * (COLUNA - 2)

    // CONDIÇÃO 3: VARIAVEL NO MEIO DA MATRIZ
    // (soma 8casas)
    int valorPixel=0;
    if(v1>=pixel_referencia) valorPixel+=1;
    if(v2>=pixel_referencia) valorPixel+=2;
    if(v3>=pixel_referencia) valorPixel+=4;
    if(v4>=pixel_referencia) valorPixel+=8;
    if(v5>=pixel_referencia) valorPixel+=16;
    if(v6>=pixel_referencia) valorPixel+=32;
    if(v7>=pixel_referencia) valorPixel+=64;
    if(v8>=pixel_referencia) valorPixel+=128;
    
    return valorPixel;
}

void testeArquivo(FILE *arquivo){
    
    if(!arquivo){
        printf("ERRO AO ABRIR ARQUIVO");
        exit(1);
    }
}

int main()
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
    unsigned char *Copia = malloc( linha * coluna * sizeof(char));
    // Único motivo para Copia ser um ponteiro é para poder mostrar a matriz no terminal.
    // O programa funcionaria igual se fosse uma variavel char primitiva para coleta e atribuição direta.

    if(!Copia){
        printf("\nNAO CONSEGUI ALOCAR O PONTEIRO PARA A MATRIZ");
        exit(1);
    }
    
    // ponteiro com o endereço original da matriz copia.
    char *comecoCopia = Copia;
    
    // criação dos índices.
    int i,j;

    // variavel referencia serve como parametro na definição do pixel nas condições 1 e 2,
    // funciona com base no teclado númerico.
    
    int referencia;   

    // leitura da matriz original
    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
        {
            fscanf(arquivo, "%d ", &Orig[i][j]);
        }
    }

    int mostraNoTerminal = 0; // variável opcional para mostrar as matrizes no terminal
    if(mostraNoTerminal)    // mostrando a matriz original no terminal
    {
        printf("\ntipo: %s", tipo);
        printf("\ncoluna: %d linha: %d", coluna, linha);
        printf("\nMAX ORIGINAL: %d\n", MAX_ORIGINAL);
        for(i=0; i<linha; i++)
        {
            for(j=0; j<coluna; j++) 
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
    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++) 
        {
            // DIVIDIDO EM 3 CONDIÇÕES

            // CONDIÇÃO 1: VARIAVEL ESTA NA PONTA DA MATRIZ
            if( (i==0||i==linha-1) && (j==0||j==coluna-1) )
            {
                if(i==0&&j==0)                     //SUPERIOR ESQUERDA
                {
                    referencia = 7;
                    *Copia = calcula_ponta( referencia,Orig[i][j],Orig[i][j+1],Orig[i+1][j],Orig[i+1][j+1]);
                }
                else if(i==0&&j==coluna-1)         //SUPERIOR DIREITA
                {
                    referencia = 9;
                    *Copia = calcula_ponta( referencia,Orig[i][j],Orig[i][j-1],Orig[i+1][j-1],Orig[i+1][j]);
                }
                else if(i==linha-1&&j==0)          //INFERIOR ESQUERDA
                {
                    referencia = 1;
                    *Copia = calcula_ponta( referencia,Orig[i][j],Orig[i-1][j],Orig[i-1][j+1],Orig[i][j+1]);
                }
                else if(i==linha-1&&j==coluna-1)   //INFERIOR DIREITA
                {
                    referencia = 3;
                    *Copia = calcula_ponta( referencia,Orig[i][j],Orig[i-1][j-1],Orig[i-1][j],Orig[i][j-1]);
                }
            }

            // CONDIÇÃO 2: VARIAVEL NA BEIRADA MAS NÃO NA PONTA
            else if( (i==0||i==linha-1) || (j==0||j==coluna-1) )
                {
                if(i==0)                            //LINHA DE CIMA
                {
                    referencia = 8;
                    *Copia=calcula_beirada(referencia,Orig[i][j],Orig[i][j-1],Orig[i][j+1],Orig[i+1][j-1],Orig[i-1][j],Orig[i+1][j+1]);
                }
                else if(i==linha-1)                 //LINHA DE BAIXO
                {
                    referencia = 2;
                    *Copia = calcula_beirada(referencia,Orig[i][j],Orig[i-1][j-1],Orig[i-1][j],Orig[i-1][j+1],Orig[i][j-1],Orig[i][j+1]);
                }
                else if(j==0)                       //COLUNA DA ESQUERDA
                    {
                    referencia = 4;
                    *Copia = calcula_beirada(referencia,Orig[i][j],Orig[i-1][j],Orig[i-1][j+1],Orig[i][j+1],Orig[i+1][j],Orig[i+1][j+1]);
                    }
                else if(j==coluna-1)                //COLUNA DA DIREITA
                    {
                        referencia = 6;
                        *Copia = calcula_beirada(referencia,Orig[i][j],Orig[i-1][j-1],Orig[i-1][j],Orig[i][j-1],Orig[i+1][j-1],Orig[i+1][j]);
                    }
                }

            // CONDIÇÃO 3: VARIAVEL NO MEIO DA MATRIZ
            //condição 3 não precisa passar a variavel referencia porque todos os pontos em volta estão preenchidos
            else *Copia = calcula_meio(Orig[i][j],Orig[i-1][j-1],Orig[i-1][j],Orig[i-1][j+1],Orig[i][j-1],Orig[i][j+1],Orig[i+1][j-1],Orig[i+1][j],Orig[i+1][j+1]);
            
            // colocando o pixel no arquivo
            fprintf(arquivo, "%d ", *Copia);
            // subindo o ponteiro para a nova posição
            Copia++;
        }
        fprintf(arquivo, "\n");
    }

    Copia = comecoCopia;    // voltando o ponteiro para a posição orginal

    if(mostraNoTerminal)    // mostrando a matriz copia no terminal
    {
        printf("\n\nMATRIZ NO FILTRO LBP:");
        printf("\n%s", tipo);
        printf("\n%d %d", coluna, linha);
        printf("\n%d\n", vMAX);
        
        for(i=0; i<linha; i++)
        {
            for(j=0; j<coluna; j++) 
            {
                printf("%d ", *Copia);
                Copia++;
            }
            printf("\n");
        }

        Copia = comecoCopia;    // voltando o ponteiro para a posição orginal
    }    
    
    // desalocando o ponteiro
    free(Copia);

    // fechando o arquivo
    fclose(arquivo);

    // fim do programa :)
    return 0;
}