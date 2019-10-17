#include "Solicitud.h"
#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
#include <iostream>
#include <cstring>
using namespace std;

#define TAM_MAX_DATA 4000
Solicitud::Solicitud()
{
    socketlocal= new SocketDatagrama(0);  
}
char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{
    //printf("hola\n");
    struct mensaje m;
    memcpy(m.arguments,arguments,TAM_MAX_DATA);
    m.messageType=0;
    m.requestId=operationId;
    PaqueteDatagrama b((char *)&m,sizeof(struct mensaje),IP, puerto);
    //printf("hola\n");
    int n=socketlocal->envia(b);
    printf("Enviados: %d\n",n);
    PaqueteDatagrama c(sizeof(struct mensaje));
    //printf("arme\n");
    socketlocal->recibe(c);
    //printf("recibi\n");
    return c.obtieneDatos();
}
