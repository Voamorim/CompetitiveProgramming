#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001
    
vector<int> dsu (MAXN);
vector<int> set_size (MAXN, 1);

int dsufind(int i){
    while(dsu[i] != i){
        i = dsu[i];
    }
    return i;
}

void dsunion(int i, int j){
    int iroot = dsufind(i);
    int jroot = dsufind(j);

    if(set_size[iroot] < set_size[jroot]){
        swap(iroot, jroot);
    }

    dsu[jroot] = iroot;

    set_size[iroot] += set_size[jroot];

}

int main(){
    int n, b; 
    cin >> n >> b;

    iota(dsu.begin(), dsu.end(), 0);

    while(b--){
        char o; int b1, b2; cin >> o >> b1 >> b2;

        if(o == 'C'){
            int irep = dsufind(b1);
            int jrep = dsufind(b2);

            cout << (irep == jrep ? 'S' : 'N') << endl;
        } else {
            dsunion(b1, b2);
        }
    }
    return 0;
}
