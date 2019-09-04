#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;

// Con n = 10 4
int cont = 0;

void t1() {
	for(int i = 0; i < 100000; i++) {
		cont--;
	}
	sleep(1);
}
void t2() {
	for(int i = 0; i < 100000; i++) {
		cont++;
	}
	sleep(1);
}
int main() {
	thread th1(t1), th2(t2);
	printf("Proceso principal espera que los hilos terminen\n");
	th1.join(); th2.join();
	cout << cont << endl;
	printf("EL hilo principal termina\n");
	exit(0);
}
