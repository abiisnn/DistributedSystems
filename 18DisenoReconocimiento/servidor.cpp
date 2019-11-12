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
	int i = 0;
	while(true) {
		struct mensaje *m;
		Respuesta r(7200);
		m = r.getRequest();
		cout << "Recibí cadena " << i << endl;
		if(m != NULL) {
			char datos[31];
			memcpy(datos, m->arguments, sizeof(char) * 32);
			write(dest, datos, 31);
			write(dest, "\n", 1);
			close(dest);
		}
		i++;
	}

	return 0;
}