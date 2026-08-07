#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

/*
    Luta entre dois vampiros, 1 e 2
    Cada um possui uma energia vital (EV1, EV2), força de ataque (AT) e capacidade de dano (D)

    A cada turno um dado é rolado, se o valor < AT, V1 venceu, else V2. D pontos de EV são diminuitdos do perdedor e dados ao vencedor
    Acaba quando um EV for <= 0
*/

int main(){
    int AT, D;
    double EV1, EV2;
    while(1){
        scanf("%lf %lf %d %d", &EV1, &EV2, &AT, &D);
        if(not EV1 and not EV2 and not AT and not D) return 0;
        EV1 = (double) EV1/D; EV1 = ceil(EV1);
        EV2 = (double) EV2/D; EV2 = ceil(EV2);
        double p;
        if(AT == 3){
            p = (double)EV1 / (EV1 + EV2);
        } else {
            p = (double)1 - (6 - AT)/(double)6;
            p = (1-p)/p;
            p = ((1.0 - pow(p, EV1))/(1.0 - pow(p, EV2 + EV1)));
        }
        cout << fixed << setprecision(1) << p*100 << endl;
    }
    return 0;
}