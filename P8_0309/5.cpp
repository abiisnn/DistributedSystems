#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
using namespace std;

// Con n = 10 4

void t1(atomic<int>& val) {
	for(int i = 0; i < 1000000; i++) {
		val--;
	}
	sleep(1);
}
void t2(atomic<int>& val) {
	for(int i = 0; i < 1000000; i++) {
		val++;
	}
	sleep(1);
}
int main() {
	atomic<int> var_local(0);
	thread th1(t1, ref(var_local)), th2(t2, ref(var_local));
	printf("Proceso principal espera que los hilos terminen\n");
	th1.join(); th2.join();
	cout << var_local << endl;
	printf("EL hilo principal termina\n");
	exit(0);
}
