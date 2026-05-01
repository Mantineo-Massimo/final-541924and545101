#ifndef RESOURCE_MANAGER_H 
#define RESOURCE_MANAGER_H

#include <pthread.h> 

// Definiamo i limiti massimi per l'array statico in memoria e le stringhe
#define MAX_RESERVATIONS 100 // Limite fisico della capienza del nostro database in-memory
#define MAX_STR_LEN 128      // Limite di caratteri per i singoli campi di testo

// Struttura che rappresenta i dati di una singola prenotazione (Il record)
typedef struct {
    int id;                                 // ID numerico univoco (
    char room_name[MAX_STR_LEN];            // Nome dell'aula prenotata
    char student_name[MAX_STR_LEN];         // Nome dello studente che effettua la prenotazione
    char time_slot[MAX_STR_LEN];            // Orario della prenotazione
} reservation_t;

// Struttura del gestore del db: contiene l'array di prenotazioni e il mutex per la sincronizzazione
typedef struct {
    reservation_t reservations[MAX_RESERVATIONS]; // L'array allocato in RAM che fa da "database"
    int count;                                    // Indice logico: quante prenotazioni abbiamo al momento (max 100)
    int next_id;                                  // Contatore auto-incrementante per assegnare l'ID univoco
    pthread_mutex_t mutex;                        // Lucchetto fondamentale per evitare le race conditions sui dati
} resource_manager_t;

// Firme delle funzioni pubbliche per la gestione CRUD del database
resource_manager_t* rm_init();
int rm_create(resource_manager_t* rm, const char* room, const char* student, const char* time);
int rm_read_all(resource_manager_t* rm, char* buffer, int buffer_size);
int rm_update(resource_manager_t* rm, int id, const char* room, const char* student, const char* time);
int rm_delete(resource_manager_t* rm, int id);
void rm_destroy(resource_manager_t* rm);

#endif