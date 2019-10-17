#include "respuesta.h"
#include "SocketDatagram.h"
#include "mensaje.h"
#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>

using namespace std;

Respuesta::Respuesta(int p1) {
	socketlocal = (new SocketDatagrama(p1));
}

void Respuesta::sendReply(char *respuesta) {
	struct mensaje m;
	memcpy(m.arguments, respuesta, 4000);
	//&m.arguments = &respuesta;
	m.messageType = 1;
	m.requestId = 1; 
	m.operationId = 1;
	printf("puerto: %d \n",puerto);
	printf("ip: %s\n",ip);

	PaqueteDatagrama a((char *) &m, 4000, ip, puerto);
	socketlocal->envia(a);
	//m->
}

struct mensaje* Respuesta::getRequest(void) {
	PaqueteDatagrama a(sizeof(struct mensaje));
	socketlocal->recibe(a);
	struct mensaje *m;
	//cout << "antes\n";
	//cout << a.obtieneDireccion() << endl;
	//cout << a.obtienePuerto() << endl;
	//memcpy(&m, a.obtieneDatos(), sizeof(struct mensaje));
	//cout << "muero\n";
	//recibido = a;
	char *ip3 = a.obtieneDireccion();

	printf("ip igual a %d\n",ip3[0]);
	string aux = "";
	for(int i=0; i < 4; i++){
		if(ip3[i] >= 0){
			cout << "ponemos a " << to_string(ip3[i]) << endl;
			aux+=(to_string(ip3[i]));
		}
		else{
			cout << "ponemos a " << to_string(ip3[i]+255+1) << endl;
			aux+=(to_string(ip3[i]+255+1));
		}
		if(i != 3)
			aux+='.';
	}
	cout << "saleeeeeee " << aux << endl;
	//ip = aux;
	//ip[0] = aux[0];
	//memset(ip,' ',aux.size());
	char ip2[aux.size()+1];
	strcpy(ip2,aux.c_str());
	ip = ip2;

	//AQUI HACEMOS UNA HARDCODEADA PARA LA IP

	printf("%s\n",ip2 );
	printf("original %s\n",ip );
	//for(int i =0; i < aux.size();i++) ip[i] = aux[i];
	//strcpy(ip,aux);
	//cout << ip << endl;
	puerto = a.obtienePuerto();
	//cout << puerto << endl;
	return (struct mensaje *)a.obtieneDatos();
}
