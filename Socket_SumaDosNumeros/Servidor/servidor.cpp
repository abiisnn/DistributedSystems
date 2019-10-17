#include "respuesta.h"
#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>
using namespace std;
int main() {
	char result[sizeof(int)];
	int num[2];
	Respuesta r(7200);
	struct mensaje *m;
	cout << "holaaaaaaa\n";
	m = r.getRequest();
	cout << "Aqui si llegue" << endl;
	memcpy(num ,m->arguments, sizeof(int)*2);
	int res = num[0] + num[1];
	cout << num[0] << endl;
	cout << num[1] << endl;
	r.sendReply((char *)&res);
	return 0;
}
