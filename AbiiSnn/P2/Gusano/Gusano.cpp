#include "Gusano.h"
#include "gfx.h"
#include<bits/stdc++.h>
using namespace std;

Gusano::Gusano(int l, int xx, int yy) {
	longitud = l;
	x = xx;
	y = yy;
}
Gusano::Gusano(int l, double xx, double yy) {
	longitud = l;
	X = xx;
	Y = yy;
	grados = 0;
}
void Gusano::setTipo(int a) {
	if(a == 0) tipo = 0;
	if(a == 1) tipo = 1;
	if(a == 2) tipo = 2;
	if(a == 3) { tipo = 3; crearGrados(); }
	if(a == 4) tipo = 4;
}
void Gusano::dibujarGusano() {
	if(tipo == 0) lineaVertical();
	if(tipo == 1) lineaHorizontal();
	if(tipo == 2) lineaDiagonalAbajo();
	if(tipo == 3) circulo();
	if(tipo == 4) zigzag();
}
void Gusano::moverGusano() {
	if(tipo == 0) moverLineaVertical();
	if(tipo == 1) moverLineaHorizontal();
	if(tipo == 2) moverLineaDiagonalAbajo();
	if(tipo == 3) moverCirculo();
	if(tipo == 4) moverZigzag();	
}
/******************************************
		LINEA DIAGONAL HACIA ABAJO
*******************************************/
void Gusano::lineaDiagonalAbajo() {
	for(int i = 0; i < longitud; i++) 
		gfx_point(1+x+i, 1+y+i);
}
void Gusano::moverLineaDiagonalAbajo() {
	x++; y++;
	x %= 800; y %= 800;
}

/******************************************
			   LINEA VERTICAL
*******************************************/
void Gusano::lineaVertical() {
	for(int i = 0; i < longitud; i++)
		gfx_point(x+1, y+1+i);
}
void Gusano::moverLineaVertical() {
	y++; y %= 800;
}

/******************************************
			   LINEA HORIZONTAL
*******************************************/
void Gusano::lineaHorizontal() {
	for(int i = 0; i < longitud; i++) {
		gfx_point(x+1+i, y+1);
	}
}
void Gusano::moverLineaHorizontal() {
	x++; x %= 800;
}

/******************************************
			   	 CIRCULO
*******************************************/
void Gusano::crearGrados() {
	double auxX, auxY;
	srand(time(NULL));
	int radio = rand() % 100;
	for(int i = 0; i < 362; i++) {
		double rad = (i * 3.16) / 180.0;
		auxX = radio * cos(rad) - radio * sin(rad);
		auxY = radio * sin(rad) + radio * cos(rad);
		xCirculo.push_back(auxX);
		yCirculo.push_back(auxY);	
	}

}
void Gusano::circulo() {
	double auxX, auxY;
	for(double i = grados; i < grados + longitud; i++) {
		gfx_point(X+xCirculo[i], Y+yCirculo[i]);
	}
}
void Gusano::moverCirculo() {
	grados++; grados %= 361;
}

/******************************************
			   	 ZIGZAG
*******************************************/
void Gusano::zigzag() {
	double auxX, auxY;
	for(int i = 0; i < longitud; i++) {
		auxY = sin(x+1+i);
		gfx_point(x+1+i, y + auxY+1);
	}
}
void Gusano::moverZigzag() {
	x++; x %= 800;
}