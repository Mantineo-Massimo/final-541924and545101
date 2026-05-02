#!/bin/bash

# --- Test 1: Verifica lo stato iniziale ---
# Chiediamo al server la lista di tutte le prenotazioni esistenti.
# -u admin:password : Invia le credenziali per l'autenticazione Basic.
echo "--- Test 1: GET iniziale (Lista prenotazioni vuota o esistente) ---"
curl -u admin:password http://localhost:8080/reservations

# --- Test 2: Creazione di una nuova prenotazione ---
# Simuliamo l'invio di un form per prenotare l'AulaA.
# -s : Modalità 'silent' (nasconde la barra di caricamento di curl).
# -X POST : Specifica che vogliamo usare il metodo HTTP POST.
# -d "..." : Invia i dati nel corpo della richiesta (Body).
echo -e "\n\n--- Test 2: POST (Creazione nuova prenotazione) ---"
ID_JSON=$(curl -s -u admin:password -X POST -d "room=AulaA&student=Massimo&time=10-12" http://localhost:8080/reservations)

# Stampiamo la risposta del server (che conterrà l'ID assegnato in formato JSON).
echo "Risposta dal server: $ID_JSON"

# --- Test 3: Verifica finale ---
# Rieseguiamo la GET per vedere se la nuova prenotazione appare nella lista.
echo -e "\n--- Test 3: GET finale (Verifica inserimento) ---"
curl -u admin:password http://localhost:8080/reservations

# Aggiunge una riga vuota finale per pulizia visiva nel terminale
echo -e "\n"
