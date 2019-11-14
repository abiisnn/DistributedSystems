#include "respuesta.h"
#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>
using namespace std;
int main() {
	char result[sizeof(int)];
	int num[1];
	int nbd = 0;
	
	struct mensaje *m;
	Respuesta r(7200);
	int p = 1;

	while(true){
		m = r.getRequest();
		if(m != NULL)
		{
		memcpy(num ,m->arguments, sizeof(int)*1);
		nbd += num[0];
		//cout << "Numero 1: " << num[0] << '\n';
		//cout << nbd << endl;
		}
		r.sendReply((char *)&nbd);

		cout << nbd << endl;

	}
	
	return 0;
}