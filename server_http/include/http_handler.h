#ifndef HTTP_HANDLER_H 
#define HTTP_HANDLER_H

// Includiamo il parser per capire le richieste e il manager per accedere/modificare le prenotazioni
#include "http_parser.h"
#include "resource_manager.h"

// Questa è la funzione principale che useranno i thread worker.
// Prende il file descriptor del socket client e il database in memoria condivisa (rm).
void handle_client(int client_socket, resource_manager_t* rm);

#endif