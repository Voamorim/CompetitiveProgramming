#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

int main(){
    long a, b, cont = 0, sum = 1;
    int aux = 0;
    int t;
    scanf("%d\n", &t);
    while(t--){
        cont = 0; sum = 1;
        
        scanf("%ld %ld\n", &a, &b);
        if(a > b && not(a % b == 0)){
            aux = a/b + 1;
            cont += fabs(b*aux - a);
        } else {
            
            while(not(a % b == 0)){
                if (a*a > b){
                     cont += fabs(b-a);
                     break;
                }
                cont+= sum;
                a += sum;
            } 
        }
        cout << cont << endl;
    }
    return 0;
}