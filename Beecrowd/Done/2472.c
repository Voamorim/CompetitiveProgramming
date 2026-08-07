/*ACEITO*/

#include <stdio.h>

int main(){
    long long int comprimento_tubo, quant_tapetes, area = 0;
    scanf("%lld %lld", &comprimento_tubo, &quant_tapetes);
    while(quant_tapetes != 1){
        comprimento_tubo -= 1;
        quant_tapetes -= 1;
        area += 1;
    }
    area += comprimento_tubo * comprimento_tubo;
    printf("%lld\n", area);

    return 0;
}