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
    int cont=0;
    int n = -1;
    PaqueteDatagrama c(sizeof(struct mensaje));
    do
    {
        n = socketlocal->envia(b);
        //printf("Enviados: %d\n",n);
        //printf("arme\n");

        //PaqueteDatagrama c(sizeof(struct mensaje));
        n = socketlocal->recibeTimeout(c,2,500000);
        //printf("recibi\n");
        cont++;
    }while(cont<7 && n==-1);
    if(cont==7){
    	exit(0);
    }
    char aux[4000];
    int aux2;
    //memcpy(&aux2,c.obtieneDatos(),sizeof(int));
    struct mensaje m2;
    memcpy(&m2,c.obtieneDatos(),sizeof(struct mensaje));
    struct mensaje* aux3;
    aux3 = &m2;
    //printf("%d\n",aux2);
    return(char *) aux3;
}
