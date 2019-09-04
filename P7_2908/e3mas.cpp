#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forn(i,a,n) for(int i =a; i < n; i++)
int main(){
	srand (time(NULL));
	int n = 1000000;
	//cin >> n;
	string s= "";
	for(int i =0; i < n; i++){
		string aux = "";
		for(int j =0; j < 3; j++){
			char c = (char)(rand()%26)+'A';
			aux+= (c);
		}
		if(i != n-1)
			aux+=" ";
		s+=aux;
	}
	string ipn = "IPN";
	int cont =0;
	for(int i =0 ; i < n-2; i++){
		bool flag = true;
		for(int j =0; j < 3; j++){
			if(s[i+j] != ipn[j]){
				flag = false;
				break;
			}	
		}
		if(flag) cont++;
	}
	cout << cont << endl;
	return 0;
}

