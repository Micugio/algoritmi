# Programmazione 1

## 💻 Compilatore & Terminale

I comandi seguenti vanno eseguiti all'interno della cartella in cui si trova il file.

```bash
# Compilazione di un singolo file
g++ <nomefile.cc>

# Compilazione di file multipli (assegnando il nome 'main' al file principale)
g++ <main.cc>

# Esecuzione dell'ultimo file compilato
./a.out

# Mostra i file e le cartelle nel percorso corrente
ls

# Entra nella cartella specificata
cd <nomepercorso>

# Naviga direttamente alla cartella degli esempi di Programmazione 1 su WSL (Windows 11)
cd /mnt/c/esempiP1
```

---
## 👀 Scorciatoie da tastiera per Visual Studio Code
* `CTRL + SHIFT + V` = attiva modalità visualizzazione file MarkDown.
* `CTRL + F` = cerca parole nel file attuale.

---

## 🐙 Git

```bash
# Clona una repository remota sulla macchina locale
git clone <link>

# Aggiunge tutte le modifiche effettuate nell'area di staging
git add .

# Salva le modifiche nel database del repository locale
git commit -m "<messaggio>"

# Invia i commit del repository locale al server remoto (GitHub)
git push

# Scarica e unisce le modifiche da GitHub al repository locale
git pull
```

---

## 🛠️ Valgrind

### Installazione
```bash
sudo apt update
sudo apt upgrade
sudo apt install valgrind

# Verifica l'avvenuta installazione
valgrind --version
```

### Compilazione ed Esecuzione
```bash
# Compila abilitando i simboli di debug (-g)
g++ -g nomefile.cc

# Esegue il programma sotto il controllo di Valgrind per scovare memory leak
valgrind ./a.out
```

---

## 🔤 Sequenze di Escape

| Sequenza | Significato | Effetto |
| :---: | :--- | :--- |
| `\b` | Backspace | Cancella un carattere a sinistra |
| `\n` | Newline | Va a capo |
| `\t` | Tab | Inserisce una tabulazione (spazio grande) |
| `\\` | Backslash | Stampa il carattere `\` |
| `\'` | Apostrofo | Stampa il carattere `'` |
| `\"` | Virgolette | Stampa il carattere `"` |

---

## 🔄 Valori Booleani

*   **NOT (`!`)**: Restituisce il valore opposto (si usa con una sola variabile).
*   **AND (`&&`)**: Restituisce `true` solo se entrambi i valori sono `true`.
*   **OR (`||`)**: Restituisce `true` se almeno uno dei valori è `true`.
*   **XOR**: Restituisce `true` solo se i valori sono diversi tra loro (`true` e `false`).

> **Rappresentazione numerica:**
> *   `true` = `1`
> *   `false` = `0`

---

## 🔠 Maiuscole e Minuscole

*Assumendo che il valore delle Maiuscole preceda le minuscole nella tavola ASCII e che il carattere in input sia una lettera:*

*   **Maiuscole**: valore numerico minore di `91` (fino a 'Z')
*   **Minuscole**: valore numerico maggiore di `91` (da 'a' in poi)

---

## 📦 Variabili

*   Se inizializzi una variabile **fuori dal `main`** (variabile globale) senza assegnarle un valore, assume automaticamente il valore `= 0`.
*   Se inizializzi una variabile **dentro il `main`** senza assegnarle un valore, assume un valore indeterminato (spazzatura in memoria).
*   👉 **QUINDI**: Assegna sempre un valore di partenza a ogni variabile quando la inizializzi.
*   ⚠️ **IN GENERALE**: Cerca di **NON** usare variabili globali. Se proprio necessarie, devono essere costanti e scritte con nomi in MAIUSCOLO (es: `const int Y;`).

---

## 🔀 Espressione Condizionale (Operatore Ternario)

Sintassi: `condizione ? valore_se_vero : valore_se_falso`

### Esempio Semplice
```cpp
// Equivalente compatto di un blocco if-else di assegnazione
i == 5 ? n = 1 : n = 0;
```
*Equivale a:*
```cpp
if (i == 5) {
    n = 1;
} else {
    n = 0;
}
```

### Esempio Complesso
```cpp
// Utilizzo diretto nel ritorno di una funzione
return found ? location - 1 : -1;
```
*Equivale a:*
```cpp
if (found) {
    return location - 1; // Restituisce questo se 'found' è vero
} else {
    return -1;           // Restituisce questo se 'found' è falso
}
```

---

## 🔢 Ordine degli Operatori (Precedenza dal più alto al più basso)

1.  **Operatori unari e di precedenza massima**: `::`, `()`, `++` (prefisso), `sizeof`, `*` (indiretto), `&` (indirizzo), `~`, `!`
2.  **Moltiplicativi**: `*` (moltiplicazione), `/` (divisione), `%` (modulo)
3.  **Additivi**: `+` (addizione), `-` (sottrazione)
4.  **Shifts bit a bit**: `<<`, `>>`
5.  **Relazionali**: `<`, `<=`, `>`, `>=`
6.  **Di uguaglianza**: `==`, `!=`
7.  **AND bit a bit**: `&`
8.  **OR esclusivo bit a bit (XOR)**: `^`
9.  **OR bit a bit**: `|`
10. **AND logico**: `&&`
11. **OR logico**: `||`
12. **Espressione condizionale**: `?:`
13. **Assegnazione**: `=`, `+=`, `-=`, `*=`, ecc.

---

## 📚 Librerie Utili

### `<iomanip>`
*   `setw(n)`: Stampa $n$ spazi di formattazione.
*   `numero << setprecision(n)`: Stampa $n$ cifre significative del numero (senza approssimazione).
*   `numero << fixed << setprecision(n)`: Stampa esattamente $n$ cifre decimali dopo la virgola (con approssimazione).

### `<cctype>`
*   `isalnum(c)`: Controlla se il carattere `c` è alfanumerico. Ritorna `1` (True) o `0` (False).
*   `toupper(c)`: Converte `c` da minuscolo a MAIUSCOLO (*Nota: funziona solo se `c` è minuscolo*).

### `<cstdlib>`
*   `srand(time(NULL));`: Da inserire all'inizializzazione per generare il seed dei numeri casuali.   
    **->NOTA:** per usare `time(NULL)` devi includere la libreria **`<ctime>`**
*   `rand()`: Genera un numero casuale.
*   `atoi(argv[1])`: Converte una stringa (C-string) in un valore di tipo `int`.
*   `atof(argv[2])`: Converte una stringa (C-string) in un valore di tipo `double`.

### `<cstring>`
*   `strlen(s)`: Restituisce la lunghezza della stringa `s` (escludendo il carattere terminatore `\0`).
*   `strchr(s, c)`: Restituisce un puntatore alla prima occorrenza del carattere `c` nella stringa `s`, oppure `NULL` se `c` non è presente.
*   `strrchr(s, c)`: Restituisce un puntatore all'ultima occorrenza del carattere `c` nella stringa `s`, oppure `NULL` se `c` non è presente.
*   `strstr(s, t)`: Restituisce un puntatore alla prima occorrenza della sottostringa `t` nella stringa `s`, oppure `NULL` se `t` non è presente.
*   `strcpy(s, t)`: Copia e sovrascrive la stringa `t` dentro la stringa `s`, restituendo `s`.
*   `strncpy(s, t, n)`: Copia `n` caratteri della stringa `t` dentro la stringa `s` e restituisce `s`. Se non è presente `\0` nei primi `n` caratteri, la stringa `s` non sarà ben formata.
*   `strcat(s, t)`: Concatena in coda la stringa `t` alla stringa `s`, restituendo `s`.
*   `strncat(s, t, n)`: Concatena `n` caratteri della stringa `t` in coda alla stringa `s` e restituisce `s`. Viene sempre aggiunto il carattere terminatore `\0`.
*   `strcmp(s, t)`: Confronta le due stringhe e restituisce un valore negativo, nullo (`0`) o positivo se `s` è alfabeticamente minore, uguale o maggiore di `t`.

---

## 📍 Tutti i Casi di Utilizzo dei Puntatori

| Cosa voglio fare | Sintassi | Perché |
| :--- | :---: | :--- |
| **Puntare a una variabile normale** | `int* p = &x` | `x` non è un indirizzo, serve l'operatore di indirizzo `&` |
| **Puntare a un puntatore** | `int* p = &p` | Serve l'indirizzo di memoria del puntatore stesso |
| **Copiare un indirizzo già esistente** | `(int* p = &x) -> int* q = p` | `p` contiene già un indirizzo al suo interno, non serve `&` |

---

## ⚖️ Quando Usare un Riferimento o un Puntatore

| Caso d'uso | Usa riferimento | Usa puntatore |
| :--- | :---: | :---: |
| Modificare una variabile passata a una funzione | ✔️ | ✔️ |
| Evitare la gestione di valori nulli | ✔️ | ❌ |
| Dover poter cambiare dinamicamente ciò a cui "punta" | ❌ | ✔️ |
| Allocazione dinamica della memoria | ❌ | ✔️ |
| Strutture dati dinamiche (es. liste concatenate, alberi) | ❌ | ✔️ |

---

## 🔍 Focus: Puntatori (`*pd`)
> **RICORDA**: Un puntatore memorizza come valore l'**indirizzo di memoria** della variabile a cui punta.

1.  **Inizializzazione**: `int *pd = &x` *(Nota: Inizializza sempre un puntatore dicendogli subito a cosa puntare).*
2.  Si tratta di una nuova variabile con un proprio spazio fisico in memoria.
3.  **Puntatore all'indirizzo**: Assume come valore l'indirizzo di un'altra variabile. Usando l'operatore di dereferenziazione `*pd` si ottiene direttamente il valore contenuto in quell'indirizzo.
4.  L'indirizzo contenuto nel puntatore può essere modificato nel corso del programma per puntare a variabili diverse.
5.  **Esempio**: `*pd = 5` modifica il valore della variabile puntata da `pd` impostandolo a `5`.

### Altre tipologie di puntatori:
1.  Puntatori a `void` (generici)
2.  Puntatori a costante
3.  Costanti puntatori
4.  Costanti puntatore a costante
5.  Puntatori a puntatori (doppio puntatore)

---

## 🔗 Focus: Riferimenti (`&`)

1.  **Inizializzazione**: `int &y = x`
2.  Funziona come un **Alias (sinonimo)** della variabile originale, **NON** è una copia.
3.  Non possiede uno spazio di memoria dedicato autonomo.
4.  Una volta inizializzato ed associato a una variabile, il legame dura per **tutta la vita del riferimento** e non può essere modificato per riferirsi a un'altra variabile.

---

## ❓ Significato degli Operatori `&` e `*`

*   `&x` $\rightarrow$ Ottengo l'**indirizzo** di memoria della variabile `x`.
*   `*pd` $\rightarrow$ Ottengo il **valore** memorizzato all'indirizzo a cui punta `pd`.
*   *Se scrivessi solo* `pd` $\rightarrow$ Otterrei l'**indirizzo** contenuto nel puntatore `pd`.

---

## 🛠️ Funzioni o Procedure

*   Funzione che restituisce un tipo (`int`, `double`, etc.) = **FUNZIONE**
*   Funzione che restituisce `void` = **PROCEDURA**

1.  **Parametri formali**: Le variabili definite nella firma della funzione.
2.  **Parametri attuali**: I valori o le variabili passate concretamente al momento della chiamata.

---

## 🔄 Funzioni Ricorsive

```text
Funzioni Ricorsive
├── VOID (produce effetti)
│     │
│     ├── Tail recursive (la chiamata ricorsiva è l'ultima istruzione)
│     │
│     └── NON tail recursive (c'è altro codice da eseguire dopo la chiamata ricorsiva)
│
└── RETURN (produce un valore)
      │
      ├── Calcolo al RITORNO
      │                 │
      │                 └── NON tail recursive (c'è altro codice dopo la chiamata ricorsiva)
      │
      └── Calcolo all’ANDATA (con accumulatore)
                        │
                        └── Tail recursive (la chiamata ricorsiva è l'ultima istruzione)
```

---

## 📊 Array e Funzioni

*   Gli array vengono passati alle funzioni **sempre per riferimento** (sotto forma di puntatore). Per proteggere i dati da modifiche accidentali, si consiglia di usare la keyword `const`:
    ```cpp
    int funzione (const int myArray[dim]); // 'dim' deve essere una costante
    ```
*   Quando passi un array a una funzione, esso decade a puntatore e **la sua dimensione si perde**.
*   **Array 1D**: Il compilatore non ha bisogno di conoscere la dimensione nella firma della funzione; si occupa semplicemente di scorrerlo per il numero di volte indicato da una variabile di supporto (es. `dim`).
*   **Array 2D**: Il compilatore **DEVE** necessariamente conoscere la dimensione della seconda coordinata (`DIM2`), ovvero il numero di colonne. Questo serve a calcolare correttamente l'offset di memoria per passare alla riga successiva.

---

## 🔤 Stringhe

*   `cin.getline(s, n)` $\rightarrow$ Legge da `cin` una riga in `s` fino a capo linea, per un massimo di `n-1` caratteri (il carattere `\n` non viene letto, cioè si ferma); restituisce `0` se incontra la fine del file (`eof`).
*   `cin.get(c)` $\rightarrow$ Legge da `cin` e salva in `c` un singolo carattere (spaziature comprese), restituendo `c` (oppure `\0` se `c` è `eof`).
*   `cout.put(c)` $\rightarrow$ Scrive sullo stream `cout` il singolo carattere `c`.
*   `cin.eof()` $\rightarrow$ Ritorna un valore diverso da `0` se lo stream `cin` ha raggiunto la sua fine (End Of File). Va usato sempre dopo almeno un'operazione di lettura e richiede un separatore dopo l'ultimo elemento letto.
*   `cin.fail()` $\rightarrow$ Ritorna un valore diverso da `0` se lo stream `cin` ha rilevato uno stato di errore (es. una stringa fornita per un `int`) o un end-of-file. Va usato dopo almeno un'operazione di lettura e non richiede un separatore dopo l'ultimo elemento letto.
*   `cin.clear()` $\rightarrow$ Ripristina lo stato normale dello stream `cin` dallo stato di errore.

---

## Funzioni che restiuiscono array (statici o dinamici)
### Restituire array statici
Una funzione può restituire un array **statico** se **allocato** staticamente al suo **esterno** (array globale o passato come parametro alla funzione):
```cpp
// Array globale
int a[dim] = {1,2,3,4,5,6,7,8,9,dim};

int *times(int k) {
  for (int i=0; i<dim; i++)
    a[i]=a[i]*k;
  return a; 
}
```   
**OPPURE:**
```cpp
// Array passato come parametro alla funzione
int *times(int a[], int k) {
  for (int i=0; i<dim; i++)
    a[i]=a[i]*k;
  return a; 
}
```   

### Restituire array dinamici
Una funzione può restituire un array **dinamico** se **allocato** dinamicamente al suo **interno**:
```cpp
int *times(int a[10], int k) {
  int * b = new int[10];
  for (int i=0; i<10; i++)
    b[i]=a[i]*k;
  return b;
}
```   

---

## 💡 NOTE IMPORTANTI

> In C++, quando usi un numero intero (`int`) all'interno di un'operazione logica o lo assegni a una variabile booleana, il compilatore effettua una **conversione implicita automatica** (coercizione).
> 
> La regola in C++ per questa conversione è:
> *   `0` (zero) equivale a `false`.
> *   **Qualsiasi valore diverso da zero** (sia positivo che negativo, ad esempio `-2`) equivale a `true`.
> 
> Di conseguenza, una variabile `c` che vale `-2` viene interpretata a tutti gli effetti come `true`.

