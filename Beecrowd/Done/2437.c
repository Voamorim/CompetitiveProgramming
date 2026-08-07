/*ACEITO*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int Xm, Ym, Xr, Yr;
    scanf("%d %d %d %d", &Xm, &Ym, &Xr, &Yr);
    int dist = fabs(Xm - Xr) + fabs(Ym - Yr); 
    printf("%d\n", dist);
    return 0;
}