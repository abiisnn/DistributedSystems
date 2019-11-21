#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include <list> 
#include <iterator>
#include <sys/time.h>
#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include "Solicitud.h"
#include "mensaje.h"

using namespace std;

int main(int argc, char* argv[]){

	char buffer[32];
	int nbytes, origen;

	if(argc != 3){
		printf("Forma de uso: ./cliente nombre_del_archivo.txt num_registros\n");
		exit(-1);
	}

	if((origen = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(-1);
	}

	int k[1];
	k[0]= atoi(argv[2]);

	int cont =1;
	int i=0;

	// Enviando al servidor el numero de registros que va a recibir
	//cout << "Enviando al servidor " << k[0] << " registros " << endl;
	Solicitud b;
	int r;
	struct mensaje * m2 =(struct mensaje *)b.doOperation("10.100.65.158", 7200, i, (char*)k);
	i++;

	timeval hora;
	while((nbytes = read(origen, buffer, sizeof buffer)) > 0){
		//cout << "Linea " << cont << ". " << buffer << endl;

		// Enviar cadena al servidor
		Solicitud a;
		struct mensaje * m =(struct mensaje *)a.doOperation("10.100.65.158", 7200, i, buffer);
		memcpy(&hora,m->arguments,sizeof(timeval));
		//printf("Segundos: %ld \n",hora.tv_sec);
		//printf("Microegundos: %ld \n",hora.tv_usec);
		
		//cout << "Respuesta: " << r << endl;


		i++;
		cont++;

	}
	

	cout << "Ya acabe " << endl;
	close(origen);

	

	// SocketDatagrama c(7200);
	// PaqueteDatagrama a(buffer, 31, "10.100.71.110", 7200);
	// int n = c.envia(a);
	//cout << "Tamaño de envio: "<< n << endl;
	
	return 0;
}
