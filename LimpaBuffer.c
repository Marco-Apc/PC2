#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limpaBufferWhile()
{
    char c;
    while (((c = getchar()) != '\n') && c != EOF)
        ;
}
void limpaBufferDoWhile()
{
    char c;
    do
    {
        c = getchar();
    } while ((c != '\n') && (c != EOF));
}
void limpaBufferScanf()
{
    scanf("%*[^\n]");
    getchar();
}
void limpaBufferSetbuf()
{
    setbuf(stdin, NULL);
}