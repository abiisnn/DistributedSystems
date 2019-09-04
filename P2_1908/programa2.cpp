#include "fecha.h"
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
   Fecha a,b,c(21,9,1973);
   b.inicializaFecha(17,6,2000);
   a.muestraFecha();
   b.muestraFecha();
   c.muestraFecha();
   cout << "La conversion de C da "<< c.convierte() << endl;
   //string siono = (b.leapyr())? "SI" : "NO";
   cout << "La cantidad de anios bisiestos entre 1 y 2019 son: " << b.leapyr() << endl;
	return 0;
 }


