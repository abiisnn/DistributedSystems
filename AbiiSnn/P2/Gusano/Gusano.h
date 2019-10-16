#ifndef GUSANO_H_
#define GUSANO_H_
#include<bits/stdc++.h>
using namespace std;

class Gusano {
private:
	int longitud;
	int x; 
	int y;	
	int tipo;
	int grados;
	double X;
	double Y;
	vector<double> xCirculo;
	vector<double> yCirculo;
public:
	Gusano(int l, int xx, int yy);
	Gusano(int l, double xx, double yy);
	void dibujarGusano();
	void moverGusano();
	void setTipo(int a);
	void lineaVertical();
	void lineaHorizontal();
	void lineaDiagonalAbajo();
	void circulo();
	void zigzag();
	void moverLineaVertical();
	void moverLineaHorizontal();
	void moverLineaDiagonalAbajo();
	void moverCirculo();
	void moverZigzag();
	void crearGrados();
};
#endif
