#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include "IP.h"
#include <cstring>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int time, res, last;
	string srt, firstPart, lastNumber;
	// time = 4; 
	// res = 1000;
	// srt = "192.168.56.1";
	cin >> time >> res >> srt;
	IP ip(srt);
	firstPart = ip.getFirst();
	last = ip.getLast();
	cout << "First Part: " << firstPart << endl;
	cout << "Last Number: " << last << endl;
	while(time--) {
		// ENVIAR SOLICITUD
		for(int i = 0, last = ip.getLast(); i < 1; i++, last++) {
			srt = firstPart + to_string(last);
			cout << srt << endl; 			
    		char char_array[srt.length() + 1];   
    		strcpy(char_array, srt.c_str()); 
			
			// Enviar número 1 como solicitud de imagen 
			SocketDatagrama c(7200);
			PaqueteDatagrama a(sizeof(int));
			char resolucion[sizeof(int)];
			cout << "Enviando resolucion... " << res << endl;
			memcpy(resolucion, &res, sizeof(int));
			PaqueteDatagrama b((char*)resolucion, sizeof(int), char_array, 7200);
			int p = c.envia(b);
		
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}
	
	// RECIBIR DOS NUMEROS
	// PaqueteDatagrama a(2*sizeof(int));
	// SocketDatagrama c(7200);
	// int n = c.recibe(a);
	// cout << "Tamaño de recibido: " << n << endl;
	// int num[2];
	// memcpy(num, a.obtieneDatos(), 2*sizeof(int));
	// printf("El numero 1: %d \n", num[0]);
	// printf("El numero 2: %d \n", num[1]);
	// int res = num[0] + num[1];

	// RECIBIR UN NUMERO
	// PaqueteDatagrama a(sizeof(int));
	// SocketDatagrama c(7200);
	// int n = c.recibe(a);
	// cout << "Tamaño de recibido: " << n << endl;
	// int num[1];
	// memcpy(num, a.obtieneDatos(), sizeof(int));
	// printf("El numero es: %d\n", num[0]);

	// ENVIAR RESULTADO
	// char result[sizeof(int)];
	// memcpy(result, &res, sizeof(int));
	// PaqueteDatagrama b((char*)result, sizeof(int), "192.168.56.1", a.obtienePuerto());
	// int p = c.envia(b);
	// cout << "Tamaño de envio: "<< p << endl;
	return 0;
}
