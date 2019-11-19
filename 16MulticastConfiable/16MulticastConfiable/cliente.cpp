#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
	string ipMulticast, cadena;
	int puerto, ttl;
	//cin >> ipMulticast >> puerto >> ttl >> cadena;
	int dep=10;
	puerto = 7200;
	ttl = 1;
	int max=10;
	printf("Introduce el numero de depositos a realizar: ");
	cin>>max;
	srand(time(NULL));
	SocketMulticast s(puerto);
	for(int i=0;i<max;i++)
	{
		dep=rand()%10+1;
		struct mensaje m;
		m.messageType=0;
		m.requestId=i;
		memcpy(&(m.arguments),&dep,sizeof(int));
		memcpy(&dep,&(m.arguments),sizeof(int));
		printf("Deposito: %d\n",dep);
		PaqueteDatagrama a((char*)&m,sizeof(struct mensaje), "225.0.0.10", puerto);
		if(s.enviaConfiable(a, ttl,3) > 0) {
			cout << "----------------Enviado: "<< m.requestId << endl;
		}
		else
		{
			printf("ERROR, no se pudo enviar confiable\n");
			exit(0);
		}
		
	}
}