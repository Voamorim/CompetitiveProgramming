/*ACEITO*/

#include <stdio.h>

int main(){
    int qnt_letras;
    while(scanf("%d", &qnt_letras) != EOF){
        qnt_letras++;
        char codigo [qnt_letras][100];
        for(int l = 0; l < qnt_letras; l++){
            fgets(codigo[l], 100, stdin);
        }
        for (int l = 0; l < qnt_letras; l++){
            int cont3p = 0;
            int cont2p = 0;
            int cont1p = 0;
            if (codigo[l][1] == '.'){
                if(codigo[l][2] == '.'){
                    //Sequências de "..."
                    for(int cont = 0; codigo[l][cont] != '\n'; cont++){
                        cont3p++;
                    }
                } else { //Sequências de ".."
                    for(int cont = 0; codigo[l][cont] != '\n'; cont++){
                        cont2p++;
                    }
                }
            } else { //Sequências de "."
                for(int cont = 0; codigo[l][cont] != '\n'; cont++){
                        cont1p++;
                    }
            }
            if (cont1p > 0){
                switch(cont1p){
                    case 1:
                        printf("a\n");
                        break;
                    case 3:
                        printf("d\n");
                        break;
                    case 5:
                        printf("g\n");
                        break;
                    case 7:
                        printf("j\n");
                        break;
                    case 9:
                        printf("m\n");
                        break;
                    case 11:
                        printf("p\n");
                        break;
                    case 13:
                        printf("s\n");
                        break;
                    case 15:
                        printf("v\n");
                        break;
                    case 17:
                        printf("y\n");
                        break;
                }
            }
            if (cont2p > 0){
                switch(cont2p){
                    case 2:
                        printf("b\n");
                        break;
                    case 5:
                        printf("e\n");
                            break;
                    case 8:
                        printf("h\n");
                        break;
                    case 11:
                        printf("k\n");
                        break;
                    case 14:
                        printf("n\n");
                        break;
                    case 17:
                        printf("q\n");
                        break;
                    case 20:
                        printf("t\n");
                        break;
                    case 23:
                        printf("w\n");
                        break;
                    case 26:
                        printf("z\n");
                        break;
                }
            }
            if (cont3p > 0){
                switch(cont3p){
                    case 3:
                        printf("c\n");
                        break;
                    case 7:
                        printf("f\n");
                        break;
                    case 11:
                        printf("i\n");
                        break;
                    case 15:
                        printf("l\n");
                        break;
                    case 19:
                        printf("o\n");
                        break;
                    case 23:
                        printf("r\n");
                        break;
                    case 27:
                        printf("u\n");
                        break;
                    case 31:
                        printf("x\n");
                        break;
                }
            }       
        }
    }
    return 0;
}