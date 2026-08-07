#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cout << #x << " == " << x << endl
#define PB push_back
#define F first
#define S second
#define endl '\n'

// Defines


// Variables
typedef struct No{
	char c;
	struct No *e, *d;
} No;

bool sp = false;

// Functions
No* insert(No* root, char carac){
	if(!root){
		No* no = new No;
		no->e = NULL;
		no->d = NULL;
		no->c = carac;
		return no;
	}

	if(carac > root->c){
		root->d = insert(root->d, carac);
	} else {
		root->e = insert(root->e, carac);
	}
	return root;
}

bool search(No* root, char x){
	if(!root) return false;
	if(root->c == x) return true;

	if(x > root->c){
		return search(root->d, x);
	} else return search(root->e, x);
}

void printInfix(No *root){
	if(!root) return;
	
	printInfix(root->e);

	if(!sp) sp = true;
	else cout << ' ';

	cout << root->c;

	printInfix(root->d);
}

void printPost(No *root){
	if(!root) return;

	printPost(root->e);
	printPost(root->d);
	
	if(!sp) sp = true;
	else cout << ' ';

	cout << root->c;
}

void printPre (No *root){
	if(!root) return;

	if(!sp) sp = true;
	else cout << ' ';
	cout << root->c;

	printPre(root->e);
	printPre(root->d);
}

int main(){ _
	No* root = NULL;

	string o;

	while(cin>>o){
		if(o == "I"){
			char x; cin >> x;
			root = insert(root, x);
		} else if (o == "INFIXA"){
			sp = false;
			printInfix(root);
			cout << endl;
		} else if (o == "PREFIXA"){
			sp = false;
			printPre(root);
			cout << endl;
		} else if (o == "POSFIXA"){
			sp = false;
			printPost(root);
			cout << endl;
		} else {
			char x; cin >> x;
			if(search(root, x)) cout << x << " existe" << endl;
			else cout << x << " nao existe" << endl;			
		}
	}

	return 0;
}
