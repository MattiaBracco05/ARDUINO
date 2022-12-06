int luminosità = 0;
int incremento = 5;

void setup ()
{
pinMode (9, OUTPUT);
}
void loop()
{
analogWrite (9, luminosità); // invia alla porta 9 una tensione pari a (5/255)
luminosità = luminosità + incremento;
if (luminoità == 0 || luminosità == 255) // il simbolo || e’ un operatore booleano che
// rappresenta la “or” mentre == e’ il simbolo convenzionalmente utilizzato per verificare la
// condizione di uguaglianza. Non viene utilizzato il normale simbolo = poiche’ il programma lo
// interpreterebbe come l’assegnazione di un valore es. luminosità = 0 verrebbe interpretato
// come “assegna 0 alla variabile luminosità”
 {
 incremento = incremento *-1; // se la luminosità ha raggiunto gli estremi ( 0 oppure 255)
 // cambia segno all'incremento (lo si moltiplica per -1 e quindi se
 // era 5 lo fa diventare -5 e viceversa)
 }
delay (50); //attende 50 millisecondi prima di ricominciare il ciclo
}
