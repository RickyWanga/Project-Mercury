
# Documentazione Project-Mercury

## Table of contents
1. [ Main.cpp ](#main)  
2. [ Partita.cpp ](#partita)

<a name="main"></a>
## Main.cpp
Il main.cpp ha il compito di fare il setup delle impostazioni del terminale, come la dimensione e la  rimozione del cursore lampeggiante. Inoltre visualizza su schermo la schermata iniziale, per poi avviare la partita creandone un'istanza della classe e usando il metodo Partita::start(), a cui viene passato il controllo.

<a name="partita"></a>
## Partita.cpp
Partita.cpp è la classe che si occupa della gestione dei diversi componenti di gioco e la loro interazione. Contiene anche le informazioni relative al punteggio e al livello.

La classe contiene le seguenti funzioni pubbliche:

 - **Partita(int l, int h)**: è il costruttore; prende in input la lunghezza e l'altezza del campo. Si occupa di inizializzare le variabili e istanziare la classe Auto e le due Queue.
 - **start()**: contiene un ciclo while il quale richiama il metodo per la lettura degli input, per la stampa, per la gestione del punteggio, per la gestione degli ostacoli e dei boost. Il ciclo termina quando il punteggio diventa negativo.

Gli attributi privati sono:

 - **int length**: lunghezza del campo.
 - **int height**: altezza del campo.
 - **int punti**: punteggio attuale della partita.
 - int maxPunti: punteggio massimo raggiunto nella partita.
 - **int x, y**: coordinate dell'auto; la y è fissa in quanto l'auto viene posizionata in fondo al campo di gioco, mentre la x viene modificata in relazione agli input dell'utente.
 - **int input**: l'input dell'utente.
 - **Auto a**: istanza dell'auto.
 - **Queue obsQueue**: la coda che contiene gli ostacoli.
 - **Queue boostQueue**: la coda che contiene i boost.
 - **uint64_t t**: il tempo in millisecondi (since epoch, Jan 1 1970).
 - **uint64_t delay**: il delay tra due tick di gioco.
 - **int livello**: livello attuale.
 - **int danno**: il danno degli ostacoli calcolato in base al livello, verrà passato alla classe Hittable per la creazione di un ostacolo.

Le funzioni private sono:

 - **void bordo()**: stampa il bordo del campo.
 - **void stampaInfo()**: stampa le informazioni di gioco. Le informazioni sono: il numero di ostacoli presenti sul campo, il numero di boost presenti sul campo, se è avvenuta una collisione, il punteggio attuale, il livello attuale, il danno che provocano gli ostacoli, il delay tra due tick di gioco e il punteggio massimo raggiunto.
 - **int getRandomX()**: ritorna una coordinata x random, serve per lo spawn di ostacoli e boost.
 - **int getRandomSpawn()**: calcola la probabilità con cui un boost verrà spawnato.
 - **void queueManager()**: gestisce la creazione degli ostacoli e dei boost, la loro aggiunta in coda, il loro spostamento nel campo, il loro despawn e il check delle collisioni con l'auto.
 - **void stampa()**: stampa gli ostacoli e i boost sul campo richiamando i metodi di Queue.
 - **void processInput(int c)**: modifica la coordinata x dell'auto in base all'input c dell'utente.
 - uint64_t time(): ritorna il time_since_epoch in ms.
 - **void levelsManager()**: aggiorna il livello in base al punteggio e il delay e il danno in base al livello.
 - **void checkBound()**: controlla se l'auto colpisce il bordo modificando il punteggio di conseguenza.
 - **void end()**: mostra la schermata finale di gioco con il punteggio massimo raggiunto.

## Auto.cpp
Rappresenta il veicolo ed è sottoclasse di Entity. 

Le funzioni pubbliche sono:

 - **Auto()**: costruttore di default.
 - **Auto(int x, int y)**: costruttore che prende in input la posizione dell'auto nel campo.
 - **void processInput(int c, int length)**: prende in ingresso l'input da tastiera c e la lunghezza del campo e modifica la coordinata x dell'auto di conseguenza.
 
 Non contiene funzioni o attributi privati.

## Entity.cpp
È la classe padre di Auto e di Hittable. Si occupa della gestione della posizione degli elementi su schermo, della loro visualizzazione grafica e della stampa.

Gli attributi e le funzioni protected sono:

 - struct Pos: definizione della struttura che contiene le coordinate x e y.
 - Pos pos:le coordinate attuali dell'Entity.
 - Pos buffer:le coordinate dell'Entity precedenti a quella attuale. 
 - int color: il valore del colore di stampa del carattere.
 - char c: il carattere di stampa che rappresenta l'Entity.
 - void setChar(char _c): imposta il carattere di stampa c.
 - void setColor(int _color): imposta il colore di stampa del carattere.

Le funzioni pubbliche sono: 

 - Entity(): costruttore di default.
 - Entity(int x, int y, char _c, int _color): costruttore a cui vengono passate le coordinate x e y, il carattere di stampa e il colore del carattere.
 - Entity(int x): costruttore a cui viene passato solamente la coordinata x. Viene utilizzato dalla classe Hittable.
 - 

 
