#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
	// ENVIAR DOS NUMEROS
	SocketDatagrama c(7200);
	int num[2];
	num[0] = 10;
	num[1] = 5;
	char envia[2*sizeof(int)];
	memcpy(envia, &num, 2*sizeof(int));
	PaqueteDatagrama a((char*)envia, 2*sizeof(int), "192.168.56.1", 7200);
	int p = c.envia(a);
	cout << "Tamaño de envio: " << p << endl;

	// ENVIAR UN NÚMERO
	// PaqueteDatagrama a(sizeof(int));
	// int res = 250000;
	// char result[sizeof(int)];
	// cout << "Enviando... " << res << endl;
	// memcpy(result, &res, sizeof(int));
	// PaqueteDatagrama b((char*)result, sizeof(int), "192.168.56.1", 7200);
	// int p = c.envia(b);
	
	// RECIBIR RESULTADO:
	PaqueteDatagrama b(sizeof(int));
	int n = c.recibe(b);
	cout << "Tamaño de recibido: " << n << endl;
	int resultado[1];
	memcpy(resultado, b.obtieneDatos(), sizeof(int));
	printf("Resultado: %d\n", resultado[0]);
	return 0;
}
