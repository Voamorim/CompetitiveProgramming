#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

int n;

bool isLess(int a, int b){
    cout << "? " << a << " " << b << endl;
    fflush(stdin);

    string ans;
    cin >> ans;
    fflush(stdin);

    if(ans == "YES") return true;
    return false;
}

void merge(vector<int> &v, int low, int mid, int high){
    vector<int> tmp; // array temporário ordenado
    int l = low;
    int r = mid + 1;

    // insere os elementos no array temporário de forma ordenada
    while(l <= mid and r <= high){
        if(isLess(v[l], v[r])){
            tmp.PB(v[l]);
            l++;
        } else {
            tmp.PB(v[r]);
            r++;
        }
    }

    // insere o restante da parte da esquerda
    while(l <= mid){
        tmp.PB(v[l]);
        l++;
    }

    // insere o restante da parte da direita
    while(r <= high){
        tmp.PB(v[r]);
        r++;
    }

    // reordena o vetor principal com o array temporário ordenado
    for(int i = low; i <= high; ++i){
        v[i] = tmp[i-low];
    }
}

void mergeSort(vector<int> &v, int low, int high){
    if(low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);

    merge(v, low, mid, high);
}

int main(){
    cin >> n;

    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    mergeSort(v, 0, n-1);

    vector<int> ans(n+1);
    for(int i = n - 1; i >= 0; --i){
        ans[v[i]] = i+1;
    }

    cout << "! " << ans[1];
    for(int i = 2; i < ans.size(); ++i){
        cout << " " << ans[i];
    }
    cout << endl;

	return 0;
}
