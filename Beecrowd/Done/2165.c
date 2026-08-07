#include <stdio.h>

int main(){
    char texto[300];
    int c = 0;
    fgets(texto, 300, stdin);
    for (c = 0; texto[c] != '\n' && c < 299; c++){

    }
    if (c > 140){
        printf("MUTE\n");
    } else {
        printf("TWEET\n");
    }
    return 0;
}