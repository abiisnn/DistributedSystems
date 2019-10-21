#include "Solicitud.h"
#include <iostream>
#include <cstring>
#include "mensaje.h"
using namespace std;
int main ()
{
    //printf("hola\n");
    int num[2];
    num[0]=150;
    num[1]=7;
    //scanf("%d", &num[0]);
    //scanf("%d",&num[1]);
    Solicitud a;
    char * res;
    int r;
    struct mensaje * m =(struct mensaje *)a.doOperation("10.100.79.131",7200,0, (char*)num);
    memcpy(&r,m->arguments,sizeof(int));
    printf("%d\n",r);
	return 0;

}
