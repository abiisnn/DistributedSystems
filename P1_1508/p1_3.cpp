#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forn(i,a,n) for(int i =a; i < n; i++)
#define se second
#define fi first
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){__
	int n;
	cin >> n;
	int segh = 60*60;
	int segm = 60;
	int horas = n/segh;
	int minutos = (n%segh)/segm;
	int segundos = (n%segh)%segm;
	cout << horas << " horas " << minutos << " minutos y " << segundos << " segundos." <<  endl;
	return 0;
}

