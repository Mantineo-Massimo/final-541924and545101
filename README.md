# 🚀 Server HTTP Concorrente - Prenotazione Aule Studio

Implementazione avanzata di un server HTTP concorrente progettato per la gestione ad alte prestazioni delle prenotazioni di aule studio. Realizzato per il corso di **Laboratorio di Reti e Sistemi Distribuiti** (A.A. 2024/2025) presso l'Università degli Studi di Messina.

---

##  Autori
*   **Massimo Mantineo** - *Matricola: 541924*
*   **Pierluca Tino Castorina** - *Matricola: 545101*

---

##  Caratteristiche Architetturali

| Caratteristica | Implementazione |
| :--- | :--- |
| **Modello di Concorrenza** | Architettura **Thread Pool** ad alte prestazioni |
| **Strategia di I/O** | I/O sincrono con worker thread pre-allocati |
| **Sincronizzazione** | Protezione robusta delle risorse tramite **POSIX Mutex** e **Semafori** |
| **Architettura API** | Principi RESTful per la gestione delle prenotazioni |
| **Sicurezza Memoria** | Gestione rigorosa della memoria e dei segnali (SIGINT/SIGTERM) |

---

##  Struttura del Progetto
```bash
.
├── server_http/       # Codice sorgente core in C
│   ├── src/           # Implementazione (.c)
│   ├── include/       # Header (.h)
│   ├── obj/           # Oggetti compilati (.o)
│   ├── bin/           # Binari eseguibili
│   └── test.sh        # Script di test automatizzato
├── report/            # Relazione tecnica (LaTeX)
├── presentation/      # Slide di presentazione (LaTeX Beamer)
└── assets/            # Diagrammi e asset architetturali
```

---

##  Iniziare

### Prerequisiti
- Compilatore GCC
- Ambiente conforme a POSIX (Linux/macOS)
- Utility `make`

### Installazione ed Esecuzione

1. **Entra nella directory del server:**
   ```bash
   cd server_http
   ```

2. **Compila il progetto:**
   ```bash
   make
   ```

3. **Avvia l'eseguibile:**
   ```bash
   ./bin/server
   ```
   *Il server sarà disponibile all'indirizzo:* `http://localhost:8080`

---

##  Endpoint API e Utilizzo

Il server implementa un'API RESTful con **Basic Authentication** (`admin:password`).

| Metodo | Endpoint | Descrizione | Payload (Form Data) |
| :--- | :--- | :--- | :--- |
| **GET** | `/reservations` | Lista tutte le prenotazioni | N/A |
| **POST** | `/reservations` | Crea una nuova prenotazione | `room`, `student`, `time` |
| **PUT** | `/reservations/{id}` | Aggiorna una prenotazione esistente | `room`, `student`, `time` |
| **DELETE** | `/reservations/{id}` | Elimina una prenotazione | N/A |

###  Esempi con `curl`

**Lista tutte le prenotazioni:**
```bash
curl -u admin:password http://localhost:8080/reservations
```

**Crea una nuova prenotazione:**
```bash
curl -u admin:password -X POST \
     -d "room=AulaA&student=Massimo&time=10-12" \
     http://localhost:8080/reservations
```

**Aggiorna una prenotazione (es. ID 0):**
```bash
curl -u admin:password -X PUT \
     -d "room=AulaB&student=Pierluca&time=14-16" \
     http://localhost:8080/reservations/0
```

**Elimina una prenotazione (es. ID 0):**
```bash
curl -u admin:password -X DELETE http://localhost:8080/reservations/0
```

---

##  Test Automatizzati

È fornito uno script di test per verificare rapidamente le funzionalità del server:

1. **Esegui il test automatizzato:**
   ```bash
   chmod +x test.sh
   ./test.sh
   ```

##  Performance e Stress Test
Il server è stato ampiamente testato sotto carico utilizzando **Apache Bench (ab)** per garantirne la stabilità.

**Esempio di comando per il test:**
```bash
ab -n 1000 -c 100 http://localhost:8080/
```

I risultati dettagliati e l'analisi del throughput sono disponibili nella [Relazione Tecnica](report/Report.pdf).

---

##  Documentazione
Per un approfondimento sui dettagli implementativi e l'analisi delle performance:
- **[Relazione Tecnica](report/Report.pdf)**: Spiegazione dettagliata dell'architettura e dei test.
- **[Slide di Presentazione](presentation/Presentation.pdf)**: Panoramica visiva del progetto.

---
