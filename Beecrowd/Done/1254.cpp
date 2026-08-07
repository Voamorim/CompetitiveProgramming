#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define endl '\n'
#define all(vet) (vet).begin, (vet).end()
#define MOD 1000000007


// Defines


// Variables
string troca;
string subs;
string msg;

void changee( int i, int j, int msgiinit){
    int k = 0;
    while(k < troca.size()){
        msg.insert(msgiinit, troca[k]);
        k++;
    }
}

// Functions
void change(int init, int end){
    int j = 0;

    int msgiinit = 0; bool msgi = false;

    for(int i = init; i < end; i++){
        char c = msg[i];
        if(subs[j] == c){
            if(not msgi){ msgiinit = i; msgi = true;}
            j++;
            if(j >= subs.size()){

                changee( i, j, msgiinit);
                j = 0;
            }
        } else {
            msgiinit = 0;
            msgi = false;
        }
    }

}


int main(){

    while(cin >> subs){


        cin >> troca;
        char wjj;
        cin >> wjj;
        getline(cin, msg);

        cout << subs << endl;
        cout << troca << endl;
        cout << msg << endl;

        bool abriu = 0; int init = 0, end = 0;
        string cdg;
        for(int i = 0; i < msg.size(); i++){
            char c = msg[i];

            if(c == '<'){
                if(abriu){
                    cdg.clear();
                    init = i;
                }
                abriu = true;
                init = i;
            }

            if(c == '>' and abriu){
                abriu = false;
                end = i;
                change( init, end);
            }
        }
        cout << msg.size() << endl;
        cout << msg << endl;
    }
	return 0;
}
