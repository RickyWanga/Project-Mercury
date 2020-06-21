# Project-Mercury
Semplice terminal-based game automobilistico scritto in C++.

## Descrizione

### Il gioco
L'obiettivo del gioco è raggiungere il punteggio più alto possible.
Il gioco termina raggiungendo un punteggio negativo.

### Punteggio
Il punteggio aumenta di un'unità ad ogni tick del gioco.
Il punteggio inoltre aumenta raccogliendo boost e diminuisce colpendo ostacoli o andando fuori pista.
Il punteggio permette di aumentare di livello.

### Livelli
Ogni 100 punti (partendo da 0) si aumenta di livello.
Il livello è proporzionale alla difficoltà di gioco: aumentando di livello aumenta la velocità dell'auto e la quantità di danno che si subisce colpendo gli ostacoli. 
In compenso aumenta lo spawn rate dei boost, ma non la quantità di punti che si ottengono prendendone uno.
Perdendo punti si ritorna ai livelli precedenti.

### Velocità dell'auto
Ad ogni tick l'auto si sposta di un'unità in avanti.
La velocità viene aumentata incrementando i ticks-per-second (TPS). 
Il delay iniziale tra due tick è 200ms (5 TPS).
Ad ogni livello questo delay viene decrementato di 10ms. Al livello 19 il gioco va a 100 TPS.
Dal livello 20 i TPS sono i massimi raggiungibili dal calcolatore che si utilizza per giocare (delay = 0ms).

### Ostacoli
Colpendo un ostacolo si subisce danno, ovvero si perdono punti.
Il danno iniziale di un ostacolo è pari a 20, ed aumenta di 20 ad ogni livello. Non c'è alcun limite superiore.
Ad ogni tick viene generato un ostacolo.

### Boost
Raccogliendo un boost si aumenta il proprio punteggio di 15 punti. Questo valore è costante.
Ad ogni tick c'è una probabilità che compaia un boost, e questa probabilità aumenta proseguendo nei livelli.
La probabilità non aumenta più dopo il livello 10.