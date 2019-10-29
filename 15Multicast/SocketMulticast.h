#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include "PaqueteDatagrama.h"

#ifndef SocketMulticast_H_
#define SocketMulticast_H_

class SocketMulticast{
public:
	SocketMulticast(int);
	~SocketMulticast();
	int recibe(PaqueteDatagrama &p);
	int envia(PaqueteDatagrama &p, unsigned char ttl);
	//Se une a un grupo multicast, recibe la IP multicast
	void unirseGrupo(char *);
	//Se sale de un grupo multicast, recibe la IP multicast
	void salirseGrupo(char *);
private:
	int s;//ID socket
	struct sockaddr_in direccionLocal;

	struct sockaddr_in direccionForanea;
};

#endif