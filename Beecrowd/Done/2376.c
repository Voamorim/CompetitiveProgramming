/*ACEITO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char oitavas[17] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
char quartas[9];
char semifinais[5];
char final[3];

int times_quartas, times_semi, times_final;

int atual = 0;

int main(){
    int time_1, time_2;
    
    for(int jogo = 1; jogo <= 15; jogo++){
        scanf("%d %d\n", &time_1, &time_2);
        
        if(jogo <= 8){
            if(time_1 > time_2){
                quartas[times_quartas] = oitavas[atual];
                times_quartas += 1;
                atual += 2;
            } else {
                quartas[times_quartas] = oitavas[atual+1];
                times_quartas += 1;
                atual += 2;
            }
            if (times_quartas == 8){
                atual = 0;
            }
        } 
        
        if(jogo >= 9 && jogo <= 12) {
            if(time_1 > time_2){
                semifinais[times_semi] = quartas[atual];
                times_semi += 1;
                atual += 2;
            } else {
                semifinais[times_semi] = quartas[atual+1];
                times_semi += 1;
                atual += 2;
            }
            if(times_semi == 4){
                atual = 0;
            }
        }
        if(jogo == 13 || jogo == 14){
            if(time_1 > time_2){
                final[times_final] = semifinais[atual];
                times_final += 1;
                atual += 2;
            } else {
                final[times_final] = semifinais[atual + 1];
                times_final += 1;
                atual += 2;
            }
        }

        if(jogo == 15){
            if(time_1 > time_2){
                printf("%c\n", final[0]);
            } else {
                printf("%c\n", final[1]);
            }
        }
    }
    return 0;
}