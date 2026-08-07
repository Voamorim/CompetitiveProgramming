#include <stdio.h>

int main() {
    char caracteres[50] = {"AMO FAZER EXERCICIO NO URI"};
    printf("<%s>\n", caracteres);
    printf("<%30s>\n", caracteres);
    printf("<%.20s>\n", caracteres);
    printf("<%-20s>\n", caracteres);
    printf("<%-30s>\n", caracteres);
    printf("<%.30s>\n", caracteres);
    printf("<%30.20s>\n", caracteres);
    printf("<%-30.20s>\n", caracteres);
    return 0;
}