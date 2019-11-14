#include "SocketDatagram.h"
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
#include <errno.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int puerto)
{
	s = socket(AF_INET, SOCK_DGRAM, 0);
   	/* rellena la dirección local */
   	bzero((char *)&direccionLocal, sizeof(direccionLocal));
   	direccionLocal.sin_family = AF_INET;
   	direccionLocal.sin_addr.s_addr = INADDR_ANY;
   	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
	/* rellena la dirección foranea */
   	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	
}
SocketDatagrama::~SocketDatagrama()
{
	close(s);
}
//Recibe un paquete tipo datagrama proveniente de este socket
int SocketDatagrama::recibe(PaqueteDatagrama & p)
{
	unsigned char inet[4];
	unsigned int clen=sizeof(direccionForanea);
	int res= recvfrom(s, (char *)p.obtieneDatos(),p.obtieneLongitud(), 0,(struct sockaddr *)&direccionForanea,&clen);
	// COPIAR A INET
   	memcpy(inet, &direccionForanea.sin_addr.s_addr, 4);
   	//printf("IP: ");
   	//for(int i = 0; i < 4; i++) {
      		//printf("%d ", inet[i]);
   	//}
   	//printf("\n");
	p.inicializaIp((char*)inet);
	//printf("PUERTO: %d \n", ntohs(direccionForanea.sin_port));
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	return res;
}
//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(PaqueteDatagrama & p)
{
	direccionForanea.sin_family = AF_INET;
   	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, (char *)p.obtieneDatos(),p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}
int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos)
{
	unsigned char inet[4];
	unsigned int clen=sizeof(direccionForanea);
	//contador
	timeout.tv_sec=segundos;
	timeout.tv_usec=microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
	int res;
	
		res= recvfrom(s, (char *)p.obtieneDatos(),p.obtieneLongitud(), 0,(struct sockaddr *)&direccionForanea,&clen);
		
		if (res < 0) 
		{
			if (errno == EWOULDBLOCK)
			{
				printf("Tiempo para recepción transcurrido\n");
				res=-1;
			}
			else
				printf("Error en recvfrom\n");
		}

	// COPIAR A INET
   	memcpy(inet, &direccionForanea.sin_addr.s_addr, 4);
   	//printf("IP: ");
   	//for(int i = 0; i < 4; i++) {
      	//	printf("%d ", inet[i]);
   	//}
   	//printf("\n");
	p.inicializaIp((char*)inet);
	//printf("PUERTO: %d \n", ntohs(direccionForanea.sin_port));
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	return res;
}

