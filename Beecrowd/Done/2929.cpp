#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
    stack<int> st;
    
    cin >> n;

    while(n--){
        string s;  
        cin >> s;

        if(s == "PUSH"){
            int v; cin >> v;
            
            if(st.empty()) st.push(v);
            else if(v > st.top()) st.push(st.top());
            else st.push(v);
        } else if (s == "MIN"){
            if(st.empty()){
                cout << "EMPTY" << endl;
                continue;
            }

            cout << st.top() << endl;
        } else {
            if(st.empty()){
                cout << "EMPTY" << endl;
                continue;
            }

            st.pop();
        }
    }

    return 0;
}
