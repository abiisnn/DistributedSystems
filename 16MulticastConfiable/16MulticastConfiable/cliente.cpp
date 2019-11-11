#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
	string ipMulticast, cadena;
	int puerto, ttl;
	//cin >> ipMulticast >> puerto >> ttl >> cadena;
	int dep=10;
	puerto = 7205;
	ttl = 1;
	SocketMulticast s(puerto);
	struct mensaje m;
	memcpy(&(m.arguments),&dep,sizeof(mensaje));
	PaqueteDatagrama a((char*)&m,sizeof(int), "225.0.0.10", puerto);
	while(s.enviaConfiable(a, ttl,1) > 0) {
		cout << "Enviado" << endl;
	}
}