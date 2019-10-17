#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"

#include <iostream>
using namespace std;

int main(void)
{
	
	char *datos="HOLA MUNDO";
	PaqueteDatagrama a(datos, 20,"127.0.0.1", 7200);
	
	SocketDatagrama c;
	int n=c.envia(a);
	cout<<"Tamaño de envio: "<<n << endl;
	c.~SocketDatagrama();
	
	return 0;
}
