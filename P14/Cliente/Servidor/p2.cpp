#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"

#include <iostream>
using namespace std;

int main(void)
{
	char *datos="HOLA MUNDO";
	PaqueteDatagrama a(11);
	a.inicializaPuerto(8080);
	SocketDatagrama c;
	int n=c.recibe(a);
	cout<<"Tamaño de recibido: "<<n << endl;
	cout<<"Datos Recibidos: "<<a.obtieneDatos()<<endl;
	return 0;
}
