#define TAM_MAX_DATA 4000//Definicion de identificadores para operaciones permitidas
#define suma 1// Definicion del formato de mensaje
struct mensaje{
    int messageType; //0= Solicitud, 1 = Respuesta
    unsigned int requestId;   //Identificador del mensaje
    int operationId;          //Identificador de la operación
    char arguments[TAM_MAX_DATA]; 
};
#ifndef Mensaje_H_
#define Mensaje_H_
#define TAM_MAX_DATA 4000
#define suma 1

struct mensaje {
	int messageType; // Solicitud: 0, Respuesta = 1
	unsigned int requestId; // Id mensaje
	int operationId;
	char arguments[TAM_MAX_DATA];
};
#endif
