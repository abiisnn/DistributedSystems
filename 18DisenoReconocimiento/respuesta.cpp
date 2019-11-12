#include "respuesta.h"
#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>

using namespace std;

Respuesta::Respuesta(int p1) {
	socketlocal = (new SocketDatagrama(p1));
	sec=-1;
}

void Respuesta::sendReply(char *respuesta) {
	struct mensaje m;
	memcpy(m.arguments, respuesta, 4000);
	//&m.arguments = &respuesta;
	m.messageType = 1;
	m.requestId = sec; 
	m.operationId = 1;
	//printf("puerto: %d \n",puerto);
	//printf("ip: %s\n",ip);

	PaqueteDatagrama a((char *) &m, 4000, ip, puerto);
	socketlocal->envia(a);
	//m->
}

struct mensaje* Respuesta::getRequest(void) {
	PaqueteDatagrama a(sizeof(struct mensaje));
	socketlocal->recibe(a);
	struct mensaje m1;
	struct mensaje *m;
	memcpy(&m1,(struct mensaje *)a.obtieneDatos(),sizeof(struct mensaje));
	m=&m1;
	if(m->requestId!=sec)
		sec=m->requestId;
	else{
		printf("Mensaje repetido\n");
		return NULL;
	}

	int num[2];
	char *ip3 = a.obtieneDireccion();

	//printf("ip igual a %d\n",ip3[0]);
	string aux = "";
	for(int i=0; i < 4; i++){
		if(ip3[i] >= 0){
			//cout << "ponemos a " << to_string(ip3[i]) << endl;
			aux+=(to_string(ip3[i]));
		}
		else{
			//cout << "ponemos a " << to_string(ip3[i]+255+1) << endl;
			aux+=(to_string(ip3[i]+255+1));
		}
		if(i != 3)
			aux+='.';
	}

	char* ipaux= new char[aux.length()+1];
	strcpy(ipaux, aux.c_str());
	ipaux[aux.length()]='\0';

	ip= ipaux;
	puerto = a.obtienePuerto();

	return m;
}

Respuesta::~Respuesta(){
}