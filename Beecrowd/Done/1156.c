#include <stdio.h>
 
int main() {
    double S = 0;
    for (int s = 1, d = 1; s <= 39; s += 2, d *= 2){
        S += (double)s/d;
    }
    printf("%.2lf\n", S);
    return 0;
}