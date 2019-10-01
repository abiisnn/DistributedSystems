#include<bits/stdc++.h>
#define tam 100
using namespace std;

int main() {
	int n = 10;
//	cin >> n;
	vector<Gusano> g;
	for(int i = 0; i < n; i++) {
		// Hacer random para elegir que tipo de movimiento
		g.push_back(Gusano(tam, 1));
	}
	
	while(true) {
		gfx_clear();
		for(int i = 0; i < g.size(); i++) {
			// Poner color (1-255)
			gfx_color(255, 255, 255);
			// Dibujar gusano -----------
			gfx_flush();
			// Dar punto para el siguiente punto
			gusano.movimiento();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}
