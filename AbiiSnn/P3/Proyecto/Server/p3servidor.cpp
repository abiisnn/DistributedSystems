#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
	// RECIBIR DOS NUMEROS
	PaqueteDatagrama a(2*sizeof(int));
	SocketDatagrama c(7200);
	int n = c.recibe(a);
	cout << "Tamaño de recibido: " << n << endl;
	int num[2];
	memcpy(num, a.obtieneDatos(), 2*sizeof(int));
	printf("El numero 1: %d \n", num[0]);
	printf("El numero 2: %d \n", num[1]);
	int res = num[0] + num[1];

	// RECIBIR UN NUMERO
	// PaqueteDatagrama a(sizeof(int));
	// SocketDatagrama c(7200);
	// int n = c.recibe(a);
	// cout << "Tamaño de recibido: " << n << endl;
	// int num[1];
	// memcpy(num, a.obtieneDatos(), sizeof(int));
	// printf("El numero es: %d\n", num[0]);

	// // ENVIAR RESULTADO
	char result[sizeof(int)];
	memcpy(result, &res, sizeof(int));
	PaqueteDatagrama b((char*)result, sizeof(int), "192.168.56.1", a.obtienePuerto());
	int p = c.envia(b);
	cout << "Tamaño de envio: "<< p << endl;
	return 0;
}
