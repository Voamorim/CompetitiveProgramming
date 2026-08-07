/*ACEITO*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_S 100010
#define MAX_SUB 105

char s[MAX_S];
char sub[MAX_SUB];

int main(){
    int n; scanf("%d\n", &n);
    while(n--){
        fgets(s, MAX_S, stdin); 
        int tam_s = strlen(s); s[tam_s-1] = '\0';
        int q; scanf("%d\n", &q);
        while(q--){
            gets(sub); 
            int tam_sub = strlen(sub);
            int i = 0, j = 0; int verdadeiro = 0;
            
            while(i < tam_s){
                if(s[i] == sub[j]){
                    i++; j++;
                } 
                else if(s[i] != sub[j]){
                    i++;
                }

                if(j >= tam_sub){
                    verdadeiro = 1; break; 
                }
            }

            if(verdadeiro) printf("Yes\n"); else printf("No\n");
        }
    }   
    return 0;
}