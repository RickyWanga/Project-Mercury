# Titolo/Nome del progetto da definire

## Valutazione Progetto
Il gioco è parte integrante dello scritto ed è obbligatorio;
C'è un cap massimo di 8 punti e lo scritto è da 24, quindi si può anche tranquillamente arrivare alla lode;
In base alla qualità della mansione svolta da ciascuno potremo ricevere valutazioni individuali differenti, quindi un codice coeso, intuitivo e ben indentato farà la differenza;
Abbiamo UNA sola consegna, se non prendiamo almeno 2 punti dovremo consegnare un nuovo progetto.

## Indicazioni di Consegna
Il progetto è da consegnare due giorni prima dell'orale (da chiedere se si può consegnare anche prima);
Dobbiamo essere tutti presenti allo stesso orale;
Insieme ai vari file e ReadMe, dobbiamo anche consegnare una relazione di 3/4 pagine, dove vengono spiegate le scelte che facciamo e in generale il percorso progettuale del nostro gioco;
Le mail a cui consegnare sono giuseppe.lisanti@unibo.it e adele.veschetti2@unibo.it.

## Specifiche di Gioco
Il progetto consiste nell'implementare un gioco di corse automobilistiche, dove, chiaramente, si comanda un'auto;
Ci sono più livelli e il metodo di avanzamento è basato sul punteggio, più alto il livello, maggiore sarà la difficoltà, ma non ci sono traguardi, l'unico stop è il game over che si verifica se si perdono tutti i punti;
I punti sono cumulativi tra i vari livelli e se si scende sotto la soglia del livello attuale si torna al precedente;
Durante il gioco si potranno incontrare vari ostacoli e potenziamenti (a nostra discrezione) e anche altre auto, ostacoli ad esempio buche, chiodi o la collisione con gli estremi della mappa faranno perdere punti, mentre potenziamenti come token o gas 
faranno guadagnare punti.

## Specifiche di Codice
La mappa viene generata un livello alla volta dinamicamente (?) e deve essere implementata con caratteri ASCII, lo stesso vale per i vari 'elementi' (auto, ostacoli...);
È vietato usare librerie grafiche;
È obbligatorio usare le classi, per ogni classe va creato un file .hpp che la definisce e un file .cpp che ne implementa il comportamento.
