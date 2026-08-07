#include <stdio.h>

int main(){
    int c = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0;
    scanf("%d", &c);
    int v[c];
    for(int i = 0; i < c; i++){
        scanf("%d", &v[i]);
    }
    for(int i = 0; i < c; i++){
        if(v[i] % 2 == 0){
            m2++;
        }
        if(v[i] % 3 == 0){
            m3++;
        }
        if(v[i] % 4 == 0){
            m4++;
        }
        if(v[i] % 5 == 0){
            m5++;
        }
    }
    printf("%d Multiplo(s) de 2\n"
           "%d Multiplo(s) de 3\n"
           "%d Multiplo(s) de 4\n"
           "%d Multiplo(s) de 5\n", m2, m3, m4, m5);
    return 0;
}