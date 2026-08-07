#include <bits/stdc++.h>

/*ACEITO*/

using namespace std;

int main(){
    int N, num, raiz;
    bool primo;
    scanf("%d\n", &N);
    while (N--){
        scanf("%d\n", &num);
        primo = true;
        if(!(num % 2 == 0)){
            raiz = sqrt(num) + 1;
            for(int c = 3; c <= raiz; c+=2){
                if(num % c == 0){
                    primo = false;
                    break;
                }
            }
        } else {
            if(num == 2) primo = true;
            else primo = false;
        }
        if(!primo){
            cout << "Not Prime" << endl;
        } else cout << "Prime" << endl;
    }
    return 0;
}