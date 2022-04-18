#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
//  PRÁTICA 3
//
//  ENUNCIADO: Faça um programa, em linguagem C, para calcular a área e o perímetro de
//  um hexágono. O programa deve implementar uma função chamada calc_hexa que calcula a
//  área e o perímetro de um hexágono regular de lado L.
//  O programa deve solicitar ao usuário o lado do polígono, calcular e imprimir a área e o
//  perímetro do polígono. O programa termina quando for digitado um valor negativo qualquer
//  para o lado. A função deve obedecer ao seguinte protótipo:
//
//  void calc_hexa(float l, floar *area, float *perimetro);
void calc_hexa(float l, float *area, float *perimetro)
{
    *area = (3 * pow(l, 2) * sqrt(3)) / 2;
    *perimetro = 3 * l;
}
//  Lembrando que a área e o perímetro de um hexágono regular são dados por:
//
//  Para demonstrar o funcionamento faça os print de tela utilizando o primeiro número do sua
//  matrícula como valor para o lado.
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    float lado, area, perimetro;
    printf("Digite o lado do poligono: ");
    scanf("%f", &lado);
    while (lado > 0)
    {
        calc_hexa(lado, &area, &perimetro);
        printf("Area: %.2f\nPerimetro: %.2f\n", area, perimetro);
        printf("Digite o lado do poligono: ");
        scanf("%f", &lado);
    }
    printf("\n");
    system("pause");
    return 0;
}