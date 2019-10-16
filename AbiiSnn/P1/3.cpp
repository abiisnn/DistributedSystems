#include <bits/stdc++.h>
using namespace std;

int main() {
	double segundos, horas, minutos, aux;
	cin >> segundos;
	horas = floor(segundos / 3600);
	aux = horas * 60;
	minutos = floor(segundos / 60) - aux;
	aux = (horas * 60 * 60) + (minutos * 60);
	segundos -= aux; 
	cout << horas << " horas, ";
	cout << minutos << " minutos, ";
	cout << segundos << " segundos" << endl;
}