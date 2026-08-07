#include <stdio.h>
 
int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);
    if (X > Y){
        for (int c = Y + 1; c < X; c++){
            if (c % 5 == 2 || c % 5 == 3){
                printf("%d\n", c);
            }
        }
    }else {
        for (int c = X + 1; c < Y; c++){
            if (c % 5 == 2 || c % 5 == 3){
                printf("%d\n", c);
            }
        }
    }
    return 0;
}