#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tan 5
//  1. Assumindo que o endereço da variável x foi atribuído a um ponteiro px, escreva
//      uma expressão que não usa x e sim um ponteiro e divida x por 5.
void Questao01()
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
void Questao02(){
    char caracter, *p_caracter;
    int inteiro, *p_inteiro;
    float real, *p_real;
    p_caracter = &caracter;
    p_inteiro = &inteiro;
    p_real = &real;
    
}
//  3. Crie um programa que contenha um vetor de inteiros contendo 5 elementos.
//      Utilizando apenas aritmética de ponteiros, leia esse vetor do teclado e imprima
//      o dobro de cada valor lido.
void Questao03(){
    int vetor5[tan], *p_vetor5;
    p_vetor5 = &vetor5;
    printf("Digite 5 numeros: ");
    for(int i = 0; i < tan; i++)
        scanf("%d%*c", p_vetor5 + i);
    printf("\nO dobro de cada numero digitado: ");
    for(int i = 0; i < tan; i++)
        printf("%d ", *(p_vetor5 + i) * 2);
}
//  4. Crie um programa que contenha uma matriz de float contendo 3 linhas e 3
//      colunas. Imprima o endereço de cada posição dessa matriz.
void Questao04(){
    float matriz[tan][tan];
    for(int i = 0; i < tan; i++){
        for(int j = 0; j < tan; j++)
            printf("%p ", &matriz[i][j]);
        printf("\n");
    }
}
//  5. Escreva uma função que dado um número real passado como parâmetro,
//      retorne a parte inteira e a parte fracionária deste número. Escreva um
//      programa que chama esta função.
//      Protótipo: void frac(float num, int* inteiro, float* frac);

//  6. Faça um programa que controla o consumo de energia dos eletrodomésticos
//      de uma casa e:
//      • Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potência
//      (real, em kW) e tempo ativo por dia (real, em horas).
//      • Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o
//      consumo relativo de cada eletrodoméstico (consumo/consumo total) nesse
//      período de tempo. Apresente este último dado em porcentagem.
//  7. Faça um programa contendo os serviços que uma oficina mecânica pode
//      realizar: Ordem de serviço (número da OS, data, valor, serviço realizado,
//      cliente). Leia as informações sobre várias OS e determine, ao final, a média dos
//      valores, o nome do cliente que realizou o serviço mais caro, juntamente com a
//      descrição desse serviço e sua data de realização.
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

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "");
    // Questao01();
    // Questao02();
    // Questao03();
    Questao04();
    return 0;
}