// Copyright (c) 2015 Cesanta Software Limited
// All rights reserverd

#include "mongoose.h"

// Especifica el puerto
static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;
static void ev_handler(struct mg_connection *nc, int ev, void *p) { 
	// Valida si existe el evento MG_EV_HTTP_REQUEST
	if (ev == MG_EV_HTTP_REQUEST) { 
		// Implementa un servidor de archivos estaticos
		mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
	}
}

int main(void) {
	struct mg_mgr mgr;
	struct mg_connection *nc;
	// Inicializa manejador de eventos
	mg_mgr_init(&mgr, NULL);
	printf("Starting web server on port %s\n", s_http_port); 
	// Crea una conexion de escucha
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("Failed to create listener\n");
		return 1;
	}
	// Set up HTTP server parameters 
	// Adjunta un manejador de eventos HTTP a la conexion
	mg_set_protocol_http_websocket(nc);
	s_http_server_opts.document_root = "."; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	for (;;) { 
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);
	return 0;
}