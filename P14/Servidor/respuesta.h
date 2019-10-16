#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
#include <bits/stdc++.h>

#ifndef Respuesta_H_
#define Respuesta_H_
class Respuesta {
public:
	Respuesta(int);
	struct mensaje *getRequest(void);
	void sendReply(char *);
	~Respuesta();
private:
	SocketDatagrama *socketlocal;
	//PaqueteDatagrama recibido;
	int puerto;
	char * ip;
	int sec;
};
#endif
