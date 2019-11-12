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

using namespace std;

int main(int argc, char* argv[]){

	char buffer[BUFSIZ];
	int nbytes, origen;

	if(argc != 2){
		printf("Forma de uso: ./cliente nombre_del_archivo.txt\n");
		exit(-1);
	}

	if((origen = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(-1);
	}

	nbytes = read(origen, buffer, sizeof buffer);
	close(origen);

	cout << buffer << endl;

	SocketDatagrama c(7200);
	PaqueteDatagrama a(buffer, 31, "10.100.71.110", 7200);
	int n = c.envia(a);
	cout << "Tamaño de envio: "<< n << endl;
	
	return 0;
}