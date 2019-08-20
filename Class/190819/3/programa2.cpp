#include "Fecha.h"
#include<iostream>
using namespace std;

int main() {
	Fecha a, b, c(21, 9, 2000);
	//a.dia = 31;
	b.inicializaFecha(1, 4, 2014);
	b.muestraFecha();
	cout << "Convierte: " << b.convierte() << endl;

}