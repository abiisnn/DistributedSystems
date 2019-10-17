#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
using namespace std;
char buffer[BUFSIZ];
int main(int argc, char *argv[]){
	int destino;
	string linea;
	if(argc != 2){
		cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
		exit(0);
	}
	//cout << "Introduce texto para guardar en el archivo y ENTER para terminar. Longitud máxima de caracteres = " << BUFSIZ << endl;
	//getline(cin, linea);
	linea = "";
	int n = 26*26*26*100;
	for(int i =0; i < n; i++){
		//string aux = "";
		for(int j =0; j < 3; j++){
			linea += (char)(rand()%26)+'A';
			//aux+= (c);
		}
		if(i != n-1)
			linea+=" ";
		//linea+=aux;
	}
	//strcpy(buffer, linea.c_str( ));
	//Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
	if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
		perror(argv[1]);
		exit(-1);
	}
	for(int i =0; i < linea.size();i+=4){
		write(destino,linea.c_str()+i,4);
	}
	//write(destino, buffer, strlen(buffer));
	fsync(destino);
	close(destino);
}