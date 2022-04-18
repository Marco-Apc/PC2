#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// 1 - Faça um algoritmo que receba dois números e exiba o resultado da sua soma.
void Questao01()
{
    int num1 = 0, num2 = 0, soma = 0;
    printf("Digite dois numeros inteiros para saber sua soma: ");
    scanf("%d%*c%d%*c", &num1, &num2);
    soma = num1 + num2;
    printf("\nResultado: %d", soma);
}
// 2 - Faça um algoritmo que receba dois números e ao final mostre a soma, subtração,
//  multiplicação e a divisão dos números lidos.
void Questao02()
{
    int soma, subtracao, multiplicacao, divisao, num1, num2;
    printf("Digite dois numeros: ");
    scanf("%d%*c%d%*c", &num1, &num2);
    soma = num1 + num2;
    subtracao = num1 - num2;
    multiplicacao = num1 * num2;
    divisao = num1 / num2;
    printf("\nSoma: %d", soma);
    printf("\nSubtracao: %d", subtracao);
    printf("\nMultiplicacao: %d", multiplicacao);
    printf("\nDivisao: %d", divisao);
}
// 3 - Faça um algoritmo para determinar o consumo médio de um automóvel sendo
//  fornecida a distância total percorrida pelo automóvel e o total de combustível gasto.
void Questao03()
{
    float distancia, combustivel;
    printf("Digite a distancia percorrida: ");
    scanf("%f%*c", &distancia);
    printf("Digite o total de combustivel gasto: ");
    scanf("%f%*c", &combustivel);
    printf("\nConsumo medio: %.2f", distancia / combustivel);
}
// 4 - Faça um algoritmo que leia o nome do vendedor, o seu salário fixo e o total (valor)
//  de vendas efetuadas por ele no mês. Sabendo que este vendedor ganha 15% de
//  comissão sobre suas vendas efetuadas, informe seu nome, o salário fixo e o salário
//  total no final do mês.
void Questao04()
{
    float salarioFixo, salarioTotal, vendas, comissao;
    char nomeVendedor[50];
    printf("Digite o nome do vendedor: ");
    fgets(nomeVendedor, 50, stdin);
    printf("Digite o salario fixo: ");
    scanf("%f%*c", &salarioFixo);
    printf("Digite o valor total de vendas: ");
    scanf("%f%*c", &vendas);
    comissao = vendas * 0.15;
    salarioTotal = salarioFixo + comissao;
    printf("\nNome: %s", nomeVendedor);
    printf("\nSalario fixo: %.2f", salarioFixo);
    printf("\nSalario total: %.2f", salarioTotal);
}
// 5 - Escreva um algoritmo que leia o nome de um aluno e as notas das três provas que
//  ele obteve no bimestre. No final, informar o nome do aluno e a sua média (aritmética).
void Questao05()
{
    char nomeAluno[50];
    float nota1, nota2, nota3;
    printf("Digite o nome do aluno: ");
    fgets(nomeAluno, 50, stdin);
    printf("Digite as tres notas do aluno: ");
    scanf("%f%*c%f%*c%f%*c", &nota1, &nota2, &nota3);
    printf("\nNome: %s", nomeAluno);
    printf("\nMedia: %.2f", (nota1 + nota2 + nota3) / 3);
}
// 6 - Leia dois valores para as variáveis A e B e efetue as trocas dos valores de forma
//  que a variável A passe a possuir o valor da variável B e a variável B passe a possuir o
//  valor da variável A. Apresentar os valores trocados.
void Questao06()
{
    int a = 0, b = 0, auxiliar = 0;
    printf("Digite dois valores: ");
    scanf("%d%*c%d%*c", &a, &b);
    printf("\nValores antes da troca: %d e %d", a, b);
    auxiliar = b;
    b = a;
    a = auxiliar;
    printf("\nValores depois da troca: %d e %d", a, b);
}
// 7 - Faça um algoritmo que leia a temperatura em graus Celsius e apresente a
//  temperatura convertida em graus Fahrenheit. A fórmula de conversão é:
//  F=(9*C+160)/5, sendo F a temperatura em Fahrenheit e C a temperatura em Celsius.
void Questao07()
{
    float celsius, fahrenheit;
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f%*c", &celsius);
    fahrenheit = (9 * celsius + 160) / 5;
    printf("\nTemperatura em Fahrenheit: %.2f", fahrenheit);
}
// 8 - Elaborar um algoritmo que efetue a apresentação do valor da conversão em real
//  (R$) de um valor lido em dólar (US$). O algoritmo deverá solicitar o valor da cotação
//  do dólar e também a quantidade de dólares disponíveis com o usuário.
void Questao08()
{
    float cotacao, quantidadeDolar, real;
    printf("Digite a cotacao do dolar: ");
    scanf("%f%*c", &cotacao);
    printf("Digite a quantidade de dolar: ");
    scanf("%f%*c", &quantidadeDolar);
    real = cotacao * quantidadeDolar;
    printf("\nValor em real: %.2f", real);
}
// 9 - Faça um algoritmo que recebe um valor que foi depositado e exiba o valor com
//  rendimento da poupança após um mês. Considere fixo o juro da poupança em 0,70%
//  a.m.
void Questao09()
{
    float valorDepositado, rendimento;
    printf("Digite o valor depositado: ");
    scanf("%f%*c", &valorDepositado);
    rendimento = valorDepositado * 0.7;
    printf("\nRendimento: %.2f", rendimento);
}
// 10 - A Loja Mamão com Açúcar está vendendo seus produtos em 5 (cinco) prestações
//  sem juros. Faça um algoritmo que recebe um valor de uma compra e mostre o valor
//  das prestações.
void Questao10()
{
    float valorCompra, prestacoes;
    printf("Digite o valor da compra: ");
    scanf("%f%*c", &valorCompra);
    prestacoes = valorCompra / 5;
    printf("\nPrestacoes: %.2f", prestacoes);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    Questao01();
    Questao02();
    Questao03();
    Questao04();
    Questao05();
    Questao06();
    Questao07();
    Questao08();
    Questao09();
    Questao10();
    return 0;
}