#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 55 

char s[MAX];

int main(){
    int n; scanf("%d\n", &n);
    while(n--){
        int l; scanf("%d\n",&l);
        int total = 0;
        for(int i = 0; i < l; i++){
            gets(s); int tam = strlen(s);
            for(int c = 0; c < tam; c++){
                total += (s[c] - 'A') + i + c; 
            }
        }
        printf("%d\n", total);
    }
    return 0;
}