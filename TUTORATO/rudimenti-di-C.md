# Rudimenti di C++

## Hello world (stampa a video)

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Ciao mondo!";
    return 0;
}
```
Per stampare un messaggio a video si usa l'istruzione *cout*, `cout << "Messaggio";` oppure `cout << nomediunavariabile;`

**NB:** Tutto il codice va scritto dentro al main e prima del return (per ora, poi vedremo cosa può essere scritto fuori).

## Le variabili

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    double b = 3.5;
    float c = 7.2;
    char d = 'a';
    
    cout << a << " " << b << " " << c << " " << d;

    return 0;
}
```
Ci sono quattro tipi principali di variabili: int (numeri interi), double e float (numeri decimali), char (caratteri). I caratteri vengono sempre rappresentati tra apici, come nell'esempio: 'a'.

Per quanto riguarda la stampa a video, ricordo che (ad esempio) con `cout << a;` viene stampato il valore che ha la variabile a in questo punto preciso del programma.

## Input e output

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Inserire a: ";
    cin >> a;
    cout << "\nInserire b: ";
    cin >> b;
    
    return 0;
}
```
L'istruzione `cin >> a` legge il numero inserito da tastiera e lo salva nella variabile `a`.

## Operazioni con le variabili

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 3, b = 2;
    int somma = a+b;
    int differenza = a-b;
    int prodotto = a*b;
    int rapporto = a/b;
    int resto = a%b;

    cout << somma << " " << differenza << " " << prodotto << " " << rapporto << " " << resto;
    
    return 0;
}
```
**Esercizio**: scrivere un programma che, inseriti due numeri da tastiera, calcoli e stampi somma, differenza, prodotto, quoziente e resto della divisione del primo per il secondo. Potete calcolare anche la radice: basta aggiungere la libreria *math.h* o *cmath* (quindi all'inizio mettere `#include<math.h>` o `#include<cmath>`) e usare l'operazione `sqrt()`.

## Le istruzioni if e else

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 3, b = 2;
    if(a>b){
        cout << "a e' maggiore di b";
    }else{
        cout << "a e' minore (o uguale) di b";
    }
    
    return 0;
}
```
In generale l'istruzione if controlla la *condizione*, se è vera esegue le *istruzioni 1*, altrimenti esegue le *istruzioni 2*: 

```cpp
if(condizione){
    istruzioni1;
}else{
    istruzioni2;
}
```

**Esercizio**: scrivere un programma che, inserito un numero da tastiera, stampi se è pari o dispari.

## Lo switch
```cpp
switch(espressione intera) { 
case (valore costante 1): 
    istruzioni1;
    break; 
case (valore costante 2):
    istruzioni2;
    break;  
...
default:    // è opzionale 
    istruzioni default;
 } 
```
Lo switch si usa per eseguire istruzioni diverse a seconda del valore di una precisa espressione. Per lo stesso scopo potrebbero essere utilizzati svariati if con molte condizioni, ma in queste situazioni l'uso dello switch semplifica di molto il codice. Lo switch valuta il valore dell'espressione passata come parametro e se il valore corrisponde ad uno di quelli specificati nei *case* viene eseguito il blocco di istruzioni corrispondente. Se il blocco individuato termina con un'istruzione break allora il programma esce dallo switch, altrimenti, vengono eseguiti anche i blocchi successivi finchè non viene trovato un *break* o non si raggiunge l'ultimo blocco dello switch. Se nessun blocco corrisponde al parametro passsato allora viene eseguito il blocco default, se presente. 

**Esercizio (la calcolatrice)**: scrivere un programma che dati due interi A e B ed un'operazione (quindi un simbolo tra +, -, * ,/) stampi a video il risultato dell'operazione (A+B oppure A-B eccetera).

## Il ciclo while
```cpp
while(condizione) { 
    istruzioni;
} 
```
Il while serve per eseguire ripetutamente un insieme di istruzioni, finchè una certa condizione è vera. La condizione rappresenta un controllo booleano (vero/falso) che viene effettuato ad ogni iterazione (cioè ad ogni "giro", "ciclo"). All'inizio di ogni iterazione viene fatto un controllo: se la condizione è falsa il while termina, se è vera vengono eseguite le istruzioni e poi viene controllata nuovamente la condizione, e così via...

**Esempio:**

```cpp
#include<iostream>
using namespace std;

int main(){
	int a = 10;
	while(a>0){
		cout << " a = " << a << endl;
		a--;
	}
    
	return 0;
}

```


**Esercizio**: scrivere un programma che faccia continuare ad inserire un numero da tastiera fino a che questo non è pari.

## Il ciclo for
```cpp
int i;
for(i = valore iniziale; condizione; incremento della variabile i) { 
  istruzioni; 
} 
```
I cicli for seguono un meccanismo simile al while, vengono solitamente usati quando si conosce il numero di iterazioni da fare (mentre il while solitamente quando questo numero non è conosciuto).

Il for fa uso di una variabile, in questo caso la variabile i, come contatore del numero di iterazioni. Come prima cosa, a questa variabile viene dato un valore iniziale. Finchè il valore di i rispetta la condizione, vengono eseguite le istruzioni contenute tra la parentesi graffe. Eseguito il blocco di istruzioni, la variabile i, viene incrementata secondo l'incremento e, se la condizione è soddisfatta, il ciclo viene ripetuto. 

**Esempio:**

```cpp
#include<iostream>
using namespace std;

int main(){
	int i;
	for(i = 0; i<10; i++){
		cout << " i = " << i << endl;
	}
    
	return 0;
}

```

<br>
<br>

# Struttura di un programma
Spesso è utile dividere il programma in più funzioni in modo da avere una serie di vantaggi, tra i quali la modularità del codice. Ora vedremo come dichiarare e chiamare una funzione.

## Firma
La firma di una funzione è costituita da vari elementi:
* Tipo di ritorno
* Nome della funzione
* Lista degli argomenti

![Funzione](https://i.postimg.cc/wM1yPWbw/Immagine.png)

## Funzioni in azione
La prima funzione che viene chiamata quando viene eseguito un programma è la funzione `main`. 
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> riempi_vettore(int dim){
    vector<int> v;
    for(int i = 0; i < dim; i++)
        v.push_back(i);

    return v;
}

void stampa_vettore(vector<int> &vect){
    for(int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
}

int main(){ 
    vector<int> v;
    v = riempi_vettore(5);
    stampa_vettore(v);
}
```

## Passaggio dei parametri per valore
Quando un parametro viene passato per valore (o copia) a una funzione, viene creata una copia di quell'oggetto che verrà utilizzata all'interno della funzione senza influenzare l'oggetto originale.
```cpp
#include <iostream>
using namespace std;

void passaggio_per_valore(int x){
    x = 2;
    cout << "All'interno della funzione x vale: " << x << endl;
}

int main() { 
    int val = 10;
    passaggio_per_valore(val);
    cout << "Dopo la chiamata, non è cambiato il valore originale di val: " << val << endl;
}
```
![Valore](https://i.postimg.cc/qqmRk2Wz/Immagine-2020-10-15-171109.png)

Tuttavia, questo significa che se viene passata una struttura dati molto grande, verrà copiata per intero: spesso non è una buona idea passare per valore un vettore di milioni di elementi.

## Passaggio dei parametri per riferimento
Quando un parametro viene passato per riferimento a una funzione, viene semplicemente passato un puntatore alla struttura dati. Qualsiasi cambiamento all'oggetto all'interno della funzione chiamata, si rifletterà nell'oggetto originale. 
Per indicare a una funzione che si vuole passare un parametro per riferimento, occorre mettere un `&` prima del nome del parametro.

```cpp
#include <iostream>
using namespace std;

void passaggio_per_valore(int &x){
    x = 2;
    cout << "All'interno della funzione x vale: " << x << endl;
}

int main() { 
    int val = 10;
    passaggio_per_valore(val);
    cout << "Dopo la chiamata, è cambiato il valore originale di val: " << val << endl;
}
```
![Riferimento](https://i.postimg.cc/dVNx8Dcr/Immagine-2020-10-15-171728.png)

<br>
<br>

# Input e output su file
Se il nostro programma, invece che leggere da tastiera e stampare a video, dovesse scrivere e leggere da file (solitamente file di estensione .txt), deve usare nuovi oggetti al posto di *cin* e *cout*. Ci serve la libreria *fstream*, che contiene tutto il necessario per lavorare con oggetti di tipo *filestream*. Useremo *ifstream* per leggere dati da file e *ofstream* per scrivere. 

Prima di tutto dobbiamo creare un file di input (ad esempio "input.txt") nella stessa cartella in cui è salvato il programma. In questo file scriviamo i dati da leggere. 

Ora nel nostro programma possiamo aprire il file da cui leggere e il file su cui scrivere (se non esiste viene creato automaticamente).
Con il comando `ifstream in ("input.txt");` andiamo ad aprire "input.txt", da cui possiamo leggere con il comando *in* (che funziona allo stesso modo del *cin*). Con `ofstream out ("output.txt");` viene creato o aperto (se già esistente) un file "output.txt" su cui possiamo scrivere con il comando *out* (analogo al *cout*).

```cpp
#include<fstream>
using namespace std;

int main(){
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int a;
	in >> a; //inserisco quello che leggo nella variabile a

	out << "Ciao! La variabile a vale " << a;
	
	in.close();
	out.close();
    
	return 0;
}

```

<br>
<br>

# Libreria standard C++
Nella libreria standard del C++ ci sono molte strutture dati già implementate, noi andremo a vedere le più utilizzate.

## Vector
La struttura dati `vector` implementa i vettori dinamici.
```cpp

#include <iostream>
#include <vector> //per utilizzare i vector
using namespace std;

int main() 
{ 
    vector<int> v; //Dichiaro un array di nome v, e specifico che conterrà elementi `int`
    
    v.push_back(10); //La funzione push_back inserisce un elemento (in questo caso il numero 10) in fondo all'array
    v.push_back(20);
    v.push_back(30);
    
    for(int i = 0; i < v.size(); i++){  // La funzione size() ritorna il numero di elementi all'interno dell'array
        cout << v[i] << endl; // Per accedere all' i-esimo elemento, v[i]
    }
    
}
```
![Vector](https://i.postimg.cc/3xH1X7zn/Immagine-2020-10-15-153955.png)

## Matrici
Ovviamente possiamo anche non limitarci agli array di interi, ad esempio potremmo pensare ad avere delle matrici dinamiche.

```cpp

#include <iostream>
#include <vector>
using namespace std;

int main() 
{ 
    vector<vector<int>> matrix; // Inizializzo una matrice di interi
    
    for(int i = 0; i < 5; i++){
        vector<int> tmp(5); // Voglio riempire le righe con dei vettori di 5 elementi
        for(int j = 0; j < 5; j++){
          tmp[j] = i+j; 
        }
        matrix.push_back(tmp);
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){ //questo ciclo stampa tutta la riga i-esima
            cout << matrix[i][j] << " ";
        }
        cout << endl; //manda a capo dopo aver stampato la riga
    }
    
}
```
![Matrix](https://i.postimg.cc/6qJ2k6rP/Immagine-2020-10-15-154115.png)

## Stack
Un'altra struttura dati molto utilizzata è lo stack.
```cpp
#include <iostream>
#include <stack> //per utilizzare gli stack
using namespace std;

int main() 
{ 
    stack<int> s;
    s.push(5); //La funzione push() inserisce un elemento in cima allo stack
    s.push(6); 
    s.push(7); 
    
    cout << "Lo stack ha dimensione " << s.size() << endl;

    while(!s.empty()){ //La funzione empty() restituisce true se lo stack è vuoto, false altrimenti
        cout << "L'elemento in cima allo stack è: " << s.top() << endl; 
        s.pop(); // La funzione pop() rimuove l'elemento in cima allo stack
        cout << "Lo stack ora ha dimensione " << s.size() << endl;
    }
}
```
![Stack](https://i.postimg.cc/bJKNZ6dS/stack.png)

## Queue
L'utilizzo delle code (queue) è molto simile a quello degli stack, con la differenza dell'ordine di estrazione degli elementi.
```cpp
#include <iostream>
#include <queue> //per utilizzare le code
using namespace std;

int main() 
{ 
    queue<int> q;
    q.push(5); //La funzione push() inserisce un elemento in fondo alla coda
    q.push(6); 
    q.push(7); 
    
    cout << "La coda ha dimensione " << q.size() << endl;
    
    while(!q.empty()){ //La funzione empty() restituisce true se la coda è vuota, false altrimenti
        cout << "L'elemento in cima alla coda è: " << q.front() << endl; 
        q.pop();
        cout << "La coda ora ha dimensione " << q.size() << endl;
    }
}
```
![Queue](https://i.postimg.cc/NfvjYPWW/queue.png)

## Funzioni utili della Standard Library

[sort](https://en.cppreference.com/w/cpp/algorithm/sort) : ordina il vettore dato in input

[reverse](https://en.cppreference.com/w/cpp/algorithm/reverse) : inverte l'ordine degli elementi

[min_element](https://en.cppreference.com/w/cpp/algorithm/min_element) : restituisce l'elemento minimo 

[max_element](https://en.cppreference.com/w/cpp/algorithm/max_element) : restituisce l'elemento massimo

[binary_search](https://en.cppreference.com/w/cpp/algorithm/binary_search) : cerca un valore in tempo O(log(n))

[copy](https://en.cppreference.com/w/cpp/algorithm/copy) : crea una copia di un oggetto
