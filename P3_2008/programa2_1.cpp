#include <iostream>
#include<time.h>
#include<stdlib.h>


using namespace std;

class Fecha{
	private:
		int dia;
		int mes;
		int anio;
		long long int hola[1000];

	public:
		Fecha(int=3, int=4, int=2014);
		void inicializaFecha(int, int, int);
		void muestraFecha();

		// Agregadas para la parte 3
		int convierte();
		int masVieja(Fecha fecha1, Fecha fecha2);
		int masVieja(Fecha &fecha1, Fecha& fecha2);
};


Fecha::Fecha(int dd, int mm, int aaaa){
	mes= mm;
	dia= dd;
	anio= aaaa;
	for(int i =0; i < 100; i++){
		hola[i] = 100000000000000000ll;
	}
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
	anio= aaaa;
	mes= mm;
	dia= dd;
	return;
}

void Fecha::muestraFecha(){
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	return;
}

// Metodos aregados para la parte 3

int Fecha::convierte(){
	return anio*10000+mes*100+dia;
}

int masVieja(int fecha1, int fecha2){
	if(fecha1> fecha2)
		return 0;
	else if(fecha1 == fecha2)
		return 0;
	else if(fecha2 > fecha1)
		return -1;
}

int masVieja(Fecha &fecha1, Fecha &fecha2){
	if(fecha1.convierte() > fecha2.convierte())
		return 0;
	else if(fecha1.convierte() == fecha2.convierte())
		return 0;
	else if(fecha2.convierte() > fecha1.convierte())
		return -1;
}

int main(){
	srand(time(NULL));

	int n=10000000, dia, mes, anio;
	while(n--){
		dia= rand()%31+1;
		mes= rand()%12+1;
		anio= rand()%2019+1;

		Fecha fecha1 (dia, mes, anio);
		int uno = fecha1.convierte();

		dia= rand()%31+1;
		mes= rand()%12+1;
		anio= rand()%2019+1;

		Fecha fecha2 (dia, mes, anio);
		int dos= fecha2.convierte();
		
		masVieja(fecha1, fecha2);
	}



}
