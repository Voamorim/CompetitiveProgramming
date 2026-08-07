#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t[101][201];

int main(){
    int n; scanf("%d\n", &n);
    while(n--){
        int m, c; scanf("%d %d\n", &m, &c);
        for(int i = 0; i < c; i++){
            int val; scanf("%d", &val);
            int end = val % m;
            int j = 0;
            while(1){
                if(t[end][j] == 0){ 
                    t[end][j] = val; break;
                } else {
                    j++;
                }
            }
            
        }
        for(int l = 0; l < m; l++){
            printf("%d -> ", l);
            for(int k = 0; k < c; k++){
                if(t[l][k] == 0) break;
                else {
                    printf("%d -> ", t[l][k]);
                    t[l][k] = 0;
                }
            }
            printf("\\\n");
        }
        if(n>=1)  printf("\n");
    }
    return 0;
}