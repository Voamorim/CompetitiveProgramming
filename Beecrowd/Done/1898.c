/*ACEITO*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Retirar todos os caracteres não numéricos de cada um dos dois valores disponíveis e somar estes valores. Apenas tome o cuidado de separar da soma os primeiros 11 dígitos do primeiro valor. Eles correspondem ao CPF do corrupto */

/*Desconsiderando os caracteres não numéricos, o número final não deve ter mais de 17 caracteres (incluindo o ponto decimal). Qualquer número após a segunda casa decimal deve ser descartado.*/

/*Imprima o CPF do corrupto, conforme apresentado abaixo e soma dos valores que foram desviados dos cofres públicos, sempre com duas casas decimais.*/

/*

-> 75644969049 - 111.23
-> 42**&774667         

*/

/*
    - As linhas contém entre 1 e 60 caracteres
*/


/*
    -> Basta somar os números da primeira linha da entrada que excederem os 11 dígitos com os valores numéricos da segunda linha. Tudo isso com duas casas decimais (%.2f)
*/

int main(){
    char linha[61], cpf[12], resto_linha[61];
    scanf("%[^\n]\n", linha);
    int tam_linha = strlen(linha), digitos_cpf = 0, cont_linha = 0;
    double valor_linha = 0, valor_linha2 = 0;
    int bol_passou_ponto = 0, digitos_apos_ponto = 0;
    for(int i = 0; i < tam_linha; i++){
        if (digitos_cpf < 11){
            if(linha[i] == '0' || linha[i] == '1' || linha[i] == '2' || linha[i] == '3' || linha[i] == '4' || linha[i] == '5' || linha[i] == '6' || linha[i] == '7' || linha[i] == '8' || linha[i] == '9'){
                cpf[digitos_cpf] = linha[i];
                digitos_cpf += 1;
            }
        } else {
            if((linha[i] == '0' || linha[i] == '1' || linha[i] == '2' || linha[i] == '3' || linha[i] == '4' || linha[i] == '5' || linha[i] == '6' || linha[i] == '7' || linha[i] == '8' || linha[i] == '9' || linha[i] == '.') && digitos_apos_ponto < 3){
                if(linha[i] == '.'){
                    bol_passou_ponto = 1;
                }
                resto_linha[cont_linha] = linha[i];
                cont_linha += 1;
                if(bol_passou_ponto) digitos_apos_ponto += 1;
            }
        }
    }
    bol_passou_ponto  = 0;
    digitos_apos_ponto = 0;
    resto_linha[cont_linha] = '\0';
    valor_linha = atof(resto_linha);
    cont_linha = 0;
    scanf("%[^\n]\n", linha);
    tam_linha = strlen(linha);
    for(int i = 0; i < tam_linha; i++){
        if((linha[i] == '0' || linha[i] == '1' || linha[i] == '2' || linha[i] == '3' || linha[i] == '4' || linha[i] == '5' || linha[i] == '6' || linha[i] == '7' || linha[i] == '8' || linha[i] == '9' || linha[i] == '.') && digitos_apos_ponto < 3){
                if(linha[i] == '.'){
                    bol_passou_ponto = 1;
                }
                resto_linha[cont_linha] = linha[i];
                cont_linha += 1;
                if(bol_passou_ponto) digitos_apos_ponto += 1;
            }
    }
    resto_linha[cont_linha] = '\0';
    valor_linha += atof(resto_linha);
    printf("cpf %s\n", cpf);
    printf("%.2lf\n", valor_linha);
    return 0;
}