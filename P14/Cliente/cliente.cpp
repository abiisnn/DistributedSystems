#include "Solicitud.h"
#include <iostream>
#include <cstring>
#include "mensaje.h"
using namespace std;
int main(int argc, char * argv[])
{
    //printf("hola\n");
    int num[1];
    int n = stoi(argv[1]);
    int i = 0;
    int monto = 0;
    srand (time(NULL));
    while(i  < n){
        //scanf("%d", &num[0]);
        //scanf("%d",&num[1]);
        Solicitud a;
        char * res;
        int r;
        num[0] = rand() % 9 + 1;
        //printf("Envio: %d\n", num[0]);
        struct mensaje * m =(struct mensaje *)a.doOperation("10.100.79.131",7200,i, (char*)num);
        // Recibir
        memcpy(&r,m->arguments,sizeof(int));
        //printf("%d\n",r);
        monto += num[0];
        //printf("respuesta: %d\n",r);
        //printf("monto: %d\n",monto);  

        if(r != monto) {
            printf("ERROR\n");
            exit(0);
        }
        i++;
    }
    printf("Num: %d\n", n);
    printf("MONTO: %d\n", monto);
    return 0;

}
