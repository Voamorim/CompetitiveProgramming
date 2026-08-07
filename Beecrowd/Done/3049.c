#include <stdio.h>

int main(){
    int B, T;
    scanf("%d %d", &B, &T);
    int area_e, area_d;
    area_e = ((B + T)*70)/2;
    area_d = 160 * 70 - area_e;
    if(area_d == area_e){
        printf("0\n");
    } else if (area_e > area_d){
        printf("1\n");
    } else printf("2\n");
    return 0;
}