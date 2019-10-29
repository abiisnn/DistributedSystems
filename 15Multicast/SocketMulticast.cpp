#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

SocketMulticast::SocketMulticast(int puerto) {
	s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
   	int reuse = 1;
   	if(setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1) {
   		printf("Erro al llamar a la función setsockopt\n");
   		exit(0);
   	}

	/* rellena la dirección local */
   	bzero((char *)&direccionLocal, sizeof(direccionLocal));
   	direccionLocal.sin_family = PF_INET;
   	direccionLocal.sin_addr.s_addr = INADDR_ANY;
   	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
	/* rellena la dirección foranea */
   	bzero((char *)&direccionForanea, sizeof(direccionForanea));

}

SocketMulticast::~SocketMulticast() {
	close(s);
}

int SocketMulticast::recibe(PaqueteDatagrama &p) {
	unsigned char inet[4];
	unsigned int clen=sizeof(direccionForanea);
	int res= recvfrom(s, (char *)p.obtieneDatos(),p.obtieneLongitud(), 0,(struct sockaddr *)&direccionForanea,&clen);
	// COPIAR A INET
   	memcpy(inet, &direccionForanea.sin_addr.s_addr, 4);

   	//printf("\n");
	p.inicializaIp((char*)inet);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	
	return res;
}

int SocketMulticast::envia(PaqueteDatagrama &p, unsigned char TTL) {
	direccionForanea.sin_family = PF_INET;
   	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons(p.obtienePuerto());

	int val = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &TTL, sizeof(TTL));
	
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}

void SocketMulticast::unirseGrupo(char *multicastIP) {
	struct ip_mreq multicast;
	multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
	multicast.imr_interface.s_addr = htonl(INADDR_ANY);
	setsockopt(s,IPPROTO_IP,IP_ADD_MEMBERSHIP,(void *)&multicast,sizeof(multicast));
}

void SocketMulticast::salirseGrupo(char *multicastIP) {
	struct ip_mreq multicast;
	multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
	multicast.imr_interface.s_addr = htonl(INADDR_ANY);
	setsockopt(s,IPPROTO_IP,IP_DROP_MEMBERSHIP,(void *)&multicast,sizeof(multicast));
}
