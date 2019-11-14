#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

	int dest;
	if((dest = open(argv[1],  O_WRONLY | O_APPEND)) == -1){
		perror(argv[1]);
		exit(-1);
	}

	PaqueteDatagrama a(31);
	a.inicializaPuerto(8080);
	SocketDatagrama c(7200);
	int n=c.recibe(a);
	cout<<"Tamaño de recibido: "<<n << endl;
	cout<<"Datos Recibidos: "<<a.obtieneDatos()<<endl;

	write(dest, a.obtieneDatos(), 31);
	write(dest, "\n", 1);
	close(dest);

	return 0;
}