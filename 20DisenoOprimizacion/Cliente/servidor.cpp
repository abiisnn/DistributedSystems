#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include "respuesta.h"
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
	int i = 1;
	int acuse = 0;
	Respuesta r(7200);
	
	struct mensaje *m;
	struct mensaje *N;
	char num[1];
	N = r.getRequest();
	if(N != NULL) {
		memcpy(num, N->arguments, sizeof(int) * 1);
		cout << "Número de paquetes: " << (int)num[0] << endl;
		acuse = 1;
		r.sendReply((char *)&acuse);

		while(num[0]--) {
			m = r.getRequest();
			int reply = 0;
			//cout << "Recibí cadena " << i << endl;
			if(m != NULL) {
				char datos[31];
				memcpy(datos, m->arguments, sizeof(char) * 31);
				write(dest, datos, 31);
				write(dest, "\n", 1);
				reply = 1;
				r.sendReply((char *)&reply);
			}

			i++;
		}
		close(dest);
	}	
	
	return 0;
}