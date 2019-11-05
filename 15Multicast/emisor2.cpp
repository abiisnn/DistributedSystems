#include "SocketMulticast.h"
#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
	string ipMulticast, cadena;
	int puerto, ttl;
	//cin >> ipMulticast >> puerto >> ttl >> cadena;
	int datos[2];
	datos[0] = 4;
	datos[1] = 5;
	puerto = 7200; ttl = 1;
	SocketMulticast s(puerto);
	PaqueteDatagrama a((char *)datos, 2 * sizeof(int), "224.0.0.1", puerto);
	cout << "HOLA" << endl;
	while(s.envia(a, ttl) > 0) {
		cout << "Enviando datos ..." << endl;
		
		char result[sizeof(int)];
		int num[1];
		PaqueteDatagrama d(sizeof(int));
		SocketDatagrama c(8080);

		int n = c.recibe(d);
		cout <<"Tamaño de recibido: "<< n << endl;
		memcpy(num, d.obtieneDatos(), sizeof(int));
		printf("La suma es:: %d \n",num[0]);
	}
	return 0;
}