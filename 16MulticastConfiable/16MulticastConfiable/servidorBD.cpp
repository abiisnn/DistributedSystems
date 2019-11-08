#include <bits/stdc++.h>
#include "PaqueteDatagrama.h"
#include "SocketMulticast.h"
#include "SocketDatagram.h"
#include "mensaje.h"
#include <cstring>
using namespace std;

int main(){

	//char* ip_multicast;
	int puerto;
	int recibe;
	int numeros[1];
	int nbd=0;
	PaqueteDatagrama p(sizeof(int)*1);

	//cin >> puerto;

	SocketMulticast socket_multicast(7200);

	socket_multicast.unirseGrupo("225.0.0.10");
	while (1)
	{
		recibe= socket_multicast.recibeConfiable(p);

		printf("Direccion: %d.%d.%d.%d\n", (unsigned char)p.obtieneDireccion()[0], (unsigned char)p.obtieneDireccion()[1], (unsigned char)p.obtieneDireccion()[2], (unsigned char)p.obtieneDireccion()[3] );
		printf("Puerto: %d\n", p.obtienePuerto());
	struct mensaje m;
		memcpy(&m, p.obtieneDatos(), sizeof(struct mensaje));
		memcpy(numeros,&(m.arguments),sizeof(int));
		printf("Deposito: %d\n",numeros[0]);
		nbd+=numeros[0];
		printf("NBD= %d\n",nbd);
	}
	
	
	return 0;
}