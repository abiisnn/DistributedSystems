#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
	string ipMulticast, cadena;
	int puerto, ttl;
	//cin >> ipMulticast >> puerto >> ttl >> cadena;

	puerto = 7200;
	ttl = 1;
	SocketMulticast s(puerto);
	PaqueteDatagrama a("HOLA SOY EMISOR", 16, "224.0.0.1", puerto);
	while(s.envia(a, ttl) > 0) {
		cout << "Enviado" << endl;
	}
}