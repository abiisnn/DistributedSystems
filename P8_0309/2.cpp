#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;
int cont = 0;

void t1() {
	cont++;
	sleep(1);
}
void t2() {
	cont++;
	sleep(1);
}
int main() {
	thread th1(t1), th2(t2);
	printf("Proceso principal espera que los hilos terminen\n");
	//cout  << "Proceso principal espera que los hilos terminen\n";
	th1.join(); th2.join();
	cout << cont << endl;
	//cout << "El hilo principal termina\n";
	printf("EL hilo principal termina\n");
	exit(0);
}
