#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include <list> 
#include <iterator> 
#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include "Solicitud.h"
#include "mensaje.h"

using namespace std;

int main(int argc, char* argv[]){

	char buffer[32];
	int nbytes, origen;

	if(argc != 2){
		printf("Forma de uso: ./cliente nombre_del_archivo.txt\n");
		exit(-1);
	}

	if((origen = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(-1);
	}

	int cont =1;
	int i=0;

	while((nbytes = read(origen, buffer, sizeof buffer)) > 0 ){
		cout << "Linea " << cont << ". " << buffer;

		// Enviar cadena al servidor
		Solicitud a;
		int r;
		struct mensaje * m =(struct mensaje *)a.doOperation("10.100.74.163", 7200, i, buffer);
		memcpy(&r,m->arguments,sizeof(int));



		cont++;

	}

	close(origen);

	

	SocketDatagrama c(7200);
	PaqueteDatagrama a(buffer, 31, "10.100.71.110", 7200);
	int n = c.envia(a);
	cout << "Tamaño de envio: "<< n << endl;
	
	return 0;
}