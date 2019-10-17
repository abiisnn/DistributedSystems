#include<bits/stdc++.h>
using namespace std;

int main() {
	double max;
	double i = 0;
	double seno, coseno, tangente, logaritmo, raiz;
	max = 26*26*26*100;
	while(i < max) {
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log(i);
		raiz += sqrt(i);
		i++;		
	}
}