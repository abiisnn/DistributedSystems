#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <unistd.h>
#include <thread>

using namespace std;

#define numeroElementos 100000000


void DD1(){
	system("./DD nombre1");
}

void DD2(){
	system("./DD nombre2");
}

void RAM(){
	system("./RAM");
}

void CPU(){
	system("./CPU");
}

int main(int argc, char*argv[]){

	int n= stoi(argv[1]);

	/*cout << "Ejercicio 4 \n\n";
	cout << "Opciones disponibles:\n";

	cout << "1) En un hilo ejecute el programa del inciso A en el ejercicio 1 al cual llamaremos DD.cpp, y en otro hilo ejecute el mismo programa pero que almacene la cadenota en un archivo distinto.\n";
	cout << "2) En un hilo ejecute el programa RAM y en otro hilo el mismo programa\n";
	cout << "3) En un hilo ejecute el programa CPU y en otro hilo el mismo programa.\n";
	cout << "4) En un hilo ejecute el programa DD y en otro hilo ejecute el programa CPU\n";
	cout << "5) En un hilo ejecute el programa DD y en otro hilo ejecute el programa RAM\n";
	cout << "6) En un hilo ejecute el programa CPU y en otro hilo ejecute el programa RAM\n";
	cout << "7) En un hilo ejecute el programa CPU, en otro hilo ejecute el programa DD, y en otro hilo ejecute el programa RAM.\n";

	cout << "Ingresa una opcion: ";*/

	//n=1;

	switch(n){
		case 1:{
			thread th1(DD1), th2(DD2);
			th1.join();
			th2.join();
			break;
		}
		case 2:{
			thread th1(RAM), th2(RAM);
			th1.join();
			th2.join();
			break;
		}
		case 3:{
			thread th1(CPU), th2(CPU);
			th1.join();
			th2.join();
			break;
		}
		case 4:{
			thread th1(DD1), th2(CPU);
			th1.join();
			th2.join();
			break;
		}
		case 5:{
			thread th1(DD1), th2(RAM);
			th1.join();
			th2.join();
			break;
		}
		case 6:{
			thread th1(CPU), th2(RAM);
			th1.join();
			th2.join();
			break;
		}
		case 7:{
			thread th1(CPU), th2(RAM), th3(DD1);
			th1.join();
			th2.join();
			th3.join();
			break;
		}
	}
	return 0;
}