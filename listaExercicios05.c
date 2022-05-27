#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tan 3
//  1. Assumindo que o endereço da variável x foi atribuído a um ponteiro px, escreva
//      uma expressão que não usa x e sim um ponteiro e divida x por 5.

void questao01()
{
    int x = 0, *px;
    printf("Digite um numero para dividir por 5: ");
    scanf("%d%*c", &x);
    px = &x;
    *px /= 5;
    printf("%d", *px);
}
//  2. Escreva um programa que declare um inteiro, um real e um char, e ponteiros
//      para inteiro, real, e char. Associe as variáveis aos ponteiros (use &). Modifique
//      os valores de cada variável usando os ponteiros. Imprima os valores das
//      variáveis antes e após a modificação.
void questao02()
{
    char caracter, *p_caracter;
    int inteiro, *p_inteiro;
    float real, *p_real;
    p_caracter = &caracter;
    p_inteiro = &inteiro;
    p_real = &real;
    printf("Digite um caracter: ");
    scanf("%c%*c", p_caracter);
    printf("Digite um inteiro: ");
    scanf("%d%*c", p_inteiro);
    printf("Digite um real: ");
    scanf("%f%*c", p_real);
    printf("Antes da modificacao: \n");
    printf("Caracter: %c\n", caracter);
    printf("Inteiro: %d\n", inteiro);
    printf("Real: %.2f\n", real);
    *p_caracter += 5;
    *p_inteiro += 5;
    *p_real += 5;
    printf("Depois da modificacao (Adicionado 5 em todas as variaveis): \n");
    printf("Caracter: %c\n", *p_caracter);
    printf("Inteiro: %d\n", *p_inteiro);
    printf("Real: %.2f\n", *p_real);
}
//  3. Crie um programa que contenha um vetor de inteiros contendo 5 elementos.
//      Utilizando apenas aritmética de ponteiros, leia esse vetor do teclado e imprima
//      o dobro de cada valor lido.
void questao03()
{
    int vetor5[tan], *p_vetor5;
    p_vetor5 = &vetor5;
    printf("Digite 5 numeros: ");
    for (int i = 0; i < tan; i++)
        scanf("%d%*c", p_vetor5 + i);
    printf("\nO dobro de cada numero digitado: ");
    for (int i = 0; i < tan; i++)
        printf("%d ", *(p_vetor5 + i) * 2);
}
//  4. Crie um programa que contenha uma matriz de float contendo 3 linhas e 3
//      colunas. Imprima o endereço de cada posição dessa matriz.
void questao04()
{
    float matriz[tan][tan];
    for (int i = 0; i < tan; i++)
    {
        for (int j = 0; j < tan; j++)
            printf("%p ", &matriz[i][j]);
        printf("\n");
    }
}
//  5. Escreva uma função que dado um número real passado como parâmetro,
//      retorne a parte inteira e a parte fracionária deste número. Escreva um
//      programa que chama esta função.
//      Protótipo: void frac(float num, int* inteiro, float* frac);
void fract(float num, int *inteiro, float *frac)
{
    *inteiro = (int)num;
    *frac = num - *inteiro;
}
void questao05()
{
    float num, *p_num;
    int inteiro, *p_inteiro;
    float frac, *p_frac;
    p_num = &num;
    p_inteiro = &inteiro;
    p_frac = &frac;
    printf("Digite um numero real: ");
    scanf("%f%*c", p_num);
    fract(*p_num, p_inteiro, p_frac);
    printf("Parte inteira: %d\nParte fracionaria: %.2f\n", inteiro, frac);
}
//  6. Faça um programa que controla o consumo de energia dos eletrodomésticos
//      de uma casa e:
//      • Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potência
//      (real, em kW) e tempo ativo por dia (real, em horas).
//      • Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o
//      consumo relativo de cada eletrodoméstico (consumo/consumo total) nesse
//      período de tempo. Apresente este último dado em porcentagem.
void questao06()
{
    int t = 0, *p_t;
    float potencia, *p_potencia, tempo, *p_tempo, consumo, *p_consumo, consumo_total, *p_consumo_total;
    char nome[tan], *p_nome;
    p_t = &t;
    p_nome = &nome;
    p_tempo = &tempo;
    p_consumo = &consumo;
    p_potencia = &potencia;
    p_consumo_total = &consumo_total;
    for (int i = 0; i < tan; i++)
    {
        printf("Digite o nome do eletrodomestico: ");
        scanf("%s%*c", p_nome + i);
        printf("Digite a potencia do eletrodomestico: ");
        scanf("%f%*c", p_potencia + i);
        printf("Digite o tempo ativo por dia: ");
        scanf("%f%*c", p_tempo + i);
    }
    printf("Digite o tempo em dias: ");
    scanf("%f%*c", p_t);

}
//  7. Faça um programa contendo os serviços que uma oficina mecânica pode
//      realizar: Ordem de serviço (número da OS, data, valor, serviço realizado,
//      cliente). Leia as informações sobre várias OS e determine, ao final, a média dos
//      valores, o nome do cliente que realizou o serviço mais caro, juntamente com a
//      descrição desse serviço e sua data de realização.
void questao07()
{
    int numero_os = 0, *p_numero_os;
    float valor = 0, *p_valor;
    char servico[tan], *p_servico;
    p_numero_os = &numero_os;
    p_servico = &servico;
    p_valor = &valor;
    for (int i = 0; i < tan; i++)
    {
        printf("Digite o numero da OS: ");
        scanf("%d%*c", p_numero_os + i);
        printf("Digite o valor do servico: ");
        scanf("%f%*c", p_valor + i);
        printf("Digite o servico realizado: ");
        scanf("%s%*c", p_servico + i);
    }
}
//  8. Faça um programa que armazene em um registro de dados (estrutura
//      composta) os da dos de um funcionário de uma empresa, compostos de: Nome,
//      Idade, Sexo (M/F), CPF, Data de Nascimento, Código do Setor onde trabalha (0-99),
//      cargo que ocupa (string de até 30 caracteres) e Salário. Os dados devem
//      ser digitados pelo usuário, armazenados na estrutura e exibidos na tela.
//  9. Gerar e imprimir uma matriz de tamanho 10x10, onde seus elementos são da
//
//  forma:
//  A[i][j] = 2 ∗ i + 7 ∗ j + 2 se i < j;
//  A[i][j] = 3 ∗ i
//
//  2 + 1 se i = j;
//
//  A[i][j] = 4 ∗ i
//  3 + 5 ∗ j
//  2 + 1 se i > j.
//
//  10.Faça um programa que carregue uma matriz 5x5 (números aleatórios inteiros)
//      e crie dois vetores de cinco posições cada um, que contenham,
//      respectivamente, as somas das linhas e das colunas da matriz. Escreva a matriz
//      e os vetores criados.
void questao10(){
    int matriz = 0, *p_matriz;
    int linha = 0, *p_linha;
    int coluna = 0, *p_coluna;
    p_matriz = &matriz;
    p_linha = &linha;
    p_coluna = &coluna;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Digite o valor da matriz: ");
            scanf("%d%*c", (p_matriz + i + j));
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i < j)
                *(p_linha + i) += *(p_matriz + i + j);
            else if (i == j)
                *(p_linha + i) += *(p_matriz + i + j);
            else
                *(p_linha + i) += *(p_matriz + i + j);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i < j)
                *(p_coluna + i) += *(p_matriz + i + j);
            else if (i == j)
                *(p_coluna + i) += *(p_matriz + i + j);
            else
                *(p_coluna + i) += *(p_matriz + i + j);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%d ", *(p_matriz + i + j));
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // questao01();
    // questao02();
    // questao03();
    // questao04();
    // questao05();
    // questao06();
    questao10();
    return 0;
}