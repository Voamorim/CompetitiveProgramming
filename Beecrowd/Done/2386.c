/*ACEITO*/

#include <stdio.h>

/*
    -> Para que nosso cérebro consiga interpretar que existe um objeto ali, porém, ele precisa receber 40.000.000 fótons por segundo.
*/

// estr: 40.000
// olho: 400.000
// teles 100: 400.000.000

int main(){
    long long int area_cobertura_telescopio = 0;
    scanf ("%lld", &area_cobertura_telescopio);
    int quant_estrelas = 0;
    scanf("%d", &quant_estrelas);
    long long int fotons_estrela = 0; int quant_visiveis = 0;
    for(int estrela = 0; estrela < quant_estrelas; estrela++){
        scanf("%lld", &fotons_estrela);
        if(fotons_estrela * area_cobertura_telescopio >= 40000000){
            quant_visiveis += 1;
        }
    }
    printf("%d\n", quant_visiveis);
    return 0;
}