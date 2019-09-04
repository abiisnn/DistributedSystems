#include "fecha.h"
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
Fecha::Fecha(int dd,int mm,int aaaa){
	mes = mm;
	dia = dd;
	anio = aaaa;
}

void Fecha::inicializaFecha(int dd,int mm, int aaaa){
	anio = aaaa;
	mes = mm;
	dia = dd;
	return;
}

void Fecha::muestraFecha(){
	cout << "La fecha es(dia-mes-anio) " << dia<< "-" << mes << "-" << anio << endl;
	return;
}

int Fecha::convierte(){
	return anio*10000+mes*100+dia;
}

int Fecha::leapyr(){
	int ans = 0;
	for(int i =1; i <= 2019; i++){
		int anio = i;	
		if(anio%400 == 0)
			ans++;;
		if(anio%4 == 0 && anio%100 != 0)
			ans++;
	}
	return ans;
}

