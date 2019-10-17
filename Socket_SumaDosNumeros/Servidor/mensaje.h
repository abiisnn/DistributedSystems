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