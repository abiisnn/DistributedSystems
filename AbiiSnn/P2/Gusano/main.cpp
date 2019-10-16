#include "Gusano.h"
#include "gfx.h"
#include<bits/stdc++.h>
#define lon 30
#define r 800
using namespace std;

int main() {
	int n; cin >> n;
	int x, y, t;
	double X, Y;
	vector<Gusano> g;
	gfx_open(800, 800, "Gusanos");
 	gfx_color(0, 200, 100);
 	
 	// Crear gusanos
 	srand(time(NULL));
 	for(int i = 0; i < n; i++) {
		t = rand() % 5;
 		if(t == 3) { // Circulo 
 			X = rand() % r;
 			Y = rand() % r;
 			g.push_back(Gusano(lon, X, Y)); 
 		} else {
 			x = rand() % r;
 	 		y = rand() % r;
 		 	g.push_back(Gusano(lon, x, y));
 		}
 		g[i].setTipo(t);
 	}
	int tc = 500;
	while(true) {
		gfx_clear();
		// Para cada gusano
		for(int i = 0; i < g.size(); i++) {
			gfx_color(255, 255, 255);
			g[i].dibujarGusano();
			gfx_flush();
			g[i].moverGusano();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}
