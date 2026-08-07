#include <stdio.h>

int main(){
    char nomes [10][31];
    for(int i = 0; i < 10; i++){
        scanf("%30s", nomes[i]);
    }
    printf("%s\n", nomes[2]);
    printf("%s\n", nomes[6]);
    printf("%s\n", nomes[8]);
    return 0;
}