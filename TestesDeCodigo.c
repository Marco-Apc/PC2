#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// fatorial recursivo
int fatorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * fatorial(n - 1);
  }
}
// arranjos em probabilidade
int arranjo(int n, int k) {
  return fatorial(n) / (fatorial(n - k));
}
// combinacao em probabilidade
int main(int argc, char *argv[])
{
    int f, n, k, fat, arr, comb;
    printf("Digite um numero: ");
    scanf("%d", &f);
    fat = fatorial(f);
    // printf("Digite dois numeros: ");
    // scanf("%d", &n);
    // scanf("%d", &k);
    // arr = arranjo(n, k);
    // comb = combinacao(n, k);
    printf("O fatorial de %d eh %d\n", f, fat);
    // printf("O arranjo de %d e %d eh %d\n", n, k, arr);
    // printf("A combinacao de %d e %d eh %d\n", n, k, comb);
}
