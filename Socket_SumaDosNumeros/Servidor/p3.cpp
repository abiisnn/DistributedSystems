#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
	char *datos="HOLA MUNDO";
	char result[sizeof(int)];
	int num[2];
	PaqueteDatagrama a(2*sizeof(int));
	SocketDatagrama c;
	int n=c.recibe(a);
	cout<<"Tamaño de recibido: "<<n << endl;
	
	memcpy(num,a.obtieneDatos(),2*sizeof(int));
	
	printf("El numero 1: %d \n",num[0]);
	printf("El numero 2: %d \n",num[1]);
	int res = num[0]+num[1];
	memcpy(result,&res,sizeof(int));
	
	PaqueteDatagrama b((char*)result,sizeof(int),"10.100.79.131", a.obtienePuerto());
	int p=c.envia(b);
	cout<<"Tamaño de envio: "<<p << endl;
	return 0;
}
