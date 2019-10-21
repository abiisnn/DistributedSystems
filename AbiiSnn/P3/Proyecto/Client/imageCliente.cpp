#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	// streampos begin, end;
	// ifstream myfile ("pdfPractica.pdf", ios::binary);
	// begin = myfile.tellg();	
 //    myfile.seekg (0, ios::end);
 //    end = myfile.tellg();
	// cout << "Size is: " << (end - begin) << " bytes.\n";
	// if (myfile.is_open()) {
 //    	cout << "Hi" << endl;
 //    	myfile.close();
 //    }
 //  	else cout << "Unable to open file";

	while(1) {
		// Recibir solicitud de capturar imagen
		SocketDatagrama c(7200);
		PaqueteDatagrama b(sizeof(int));
		int n = c.recibe(b);
		int resolucion[1];
		memcpy(resolucion, b.obtieneDatos(), sizeof(int));
		printf("Resolucion: %d\n", resolucion[0]);
		if(resolucion[0] >= 0) {
			// Capturar imagen por comand.
			cout << "HOLAAAAAA Desde resolucion" << endl;
			// Tomar imagen
			// Guardar imagen
			

		}
	}
	
	// char * memblock;
	// long long int size, enviados;
	// int n, pb, porciento;

	// ifstream file ("pdfPractica.pdf", ios::in|ios::binary|ios::ate);
	// size = file.tellg();
	// memblock = new char [size];
 //    cout << "Size en long long int: " << size << endl;
	
	// if (file.is_open()) {
	//    	cout << "HOLA" << endl; 
	//     file.close();
	//     //delete[] memblock;
	// }
	// else cout << "Unable to open file";
	return 0;
}
