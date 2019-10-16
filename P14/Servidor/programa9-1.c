#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

int main(void)
{
   printf("IMprime porfas\n");
   printf("Uno: %x\n",puerto);
   char inet[4];
   int num[2];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);// Dominio: AF_INET, Dominio del internet; Tipo: Datagram; Se deja en manos del sistema
   
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr)); //Limpia la estructura 
   server_addr.sin_family = AF_INET; //Ponemos la familia 
   server_addr.sin_addr.s_addr = INADDR_ANY;

   
   
   server_addr.sin_port = htons(puerto);// Se almancena el puerto en formato Big endian
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   
   printf("Dos: %x\n",htons(puerto));
   
   while(1) {
      recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      res = num[0] + num[1];

      memcpy(inet, &msg_to_client_addr.sin_addr.s_addr, 4);
      printf("msg_to_server_addr.sin_addr.s_addr: ");
      for(int i = 0; i < 4; i++) {
         printf("%d ", inet[i]);
      }
      printf("\n");
      printf("PUERTO: %d\n", ntohs(msg_to_client_addr.sin_port));
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
      sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}

