#include <bits/stdc++.h>
#include "PaqueteDatagrama.h"

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char* data, unsigned int longi,char* ip_envio, int puerto_envio){
	datos= new char[longi];
	strcpy(ip, ip_envio);
	memcpy(datos, data,longi);
	puerto= puerto_envio;
    longitud = longi;

}


PaqueteDatagrama::PaqueteDatagrama(unsigned int longi){
	longitud= longi;
	datos= new char[longitud];
}

PaqueteDatagrama::~PaqueteDatagrama(){
	delete [] datos;
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

char* PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

char* PaqueteDatagrama::obtieneDatos(){
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int p){
	puerto= p;
}

void PaqueteDatagrama::inicializaIp(char* ip_envio){
	strcpy(ip, ip_envio);
}

void PaqueteDatagrama::inicializaDatos(char* data){
	memcpy(datos, data,longitud);
}



