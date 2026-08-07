#include <stdio.h>
 
int main() {
    double S = 0;
    for (int d = 1; d <= 100; d++){
        S += (double) 1/d;
    }
    printf("%.2lf\n", S);
    return 0;
}