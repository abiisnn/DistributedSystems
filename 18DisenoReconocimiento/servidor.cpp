#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include "respuesta.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
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
	int num[1];
	N = r.getRequest();
	if(N != NULL) {
		memcpy(num, N->arguments, sizeof(int) * 1);
		cout << "Número de paquetes: " << (int)num[0] << endl;
		acuse = 1;
		r.sendReply((char *)&acuse);
		//num[0]++;
		set<string> celulares;
		//num[0]=1000;
		while(num[0]--) {
			timeval hora;
			gettimeofday(&hora,NULL);
			m = r.getRequest();
			printf("segundos: %ld\n",hora.tv_sec);
			printf("microsegundos: %ld\n",hora.tv_usec);
			int reply = 0;
			cout << "Recibí cadena " << i << endl;
			if(m != NULL) {
				char datos[31];
				memcpy(datos, m->arguments, sizeof(char) * 31);
				//printf("%s\n",datos);
				string aux="";	
				for(int i =0; i < 10; i++){
					aux+=datos[i];
					
				}
				cout<<aux<<endl;

				if(celulares.find(aux) != celulares.end()){
					//poner hora en cero
					//contestar
					hora.tv_sec=0;
					hora.tv_usec=0;
					r.sendReply((char *)&hora);
					printf("---------------------TELEFONO REPETIDO----------------------\n");
					
					continue;
				}
				else{
					celulares.insert(aux);
				}
				
				//char aux[]="";
				
				write(dest, datos, 31);
				write(dest, " ", 1);
				write(dest,to_string(hora.tv_sec).c_str(),strlen(to_string(hora.tv_sec).c_str()));
				write(dest, " ", 1);
				write(dest,to_string(hora.tv_usec).c_str(),strlen(to_string(hora.tv_usec).c_str()));
				write(dest, "\n", 1);
				fsync(dest);
				reply = 1;
				r.sendReply((char *)&hora);
				
			}
			i++;
		}
		close(dest);
	}	
	
	return 0;
}