#include <iostream>
#include <fstream>
//#include <vector> //per utilizzare i vector
using namespace std;

int N;
//Array dichiarato con la dimensione massima
int arr[1000000];

int main() {
    ifstream in ("input.txt");

    in >> N;
    for(int i=0; i<N; i++) {
        in >> arr[i];
    }

    /*
    //STAMPA VALORI
    for(int i=0;i<N;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    //soluzione parziale
    int mx = 0;

    /*
    //per ogni sottosequenza
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            //calcola somma della sottosequenza
            int tot = 0;
            for(int k=i; k<=j; k++) {
                tot += arr[k];
            }
            mx = max(mx,tot);
        }
    }
    */

    //cout << mx << endl;

    for(int i=0; i<N; i++) {
        int somma = 0;
        for(int j=i; j<N; j++) {
            somma = somma + arr[j];
            mx = max(mx,somma);
        }
    }

    //cout << mx << endl;

    ofstream out("output.txt");
    out << mx << endl;

    return 0;
}

/*
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    in>>N;
    for(int i=0; i<N; i++) {
        in>>arr[i];
    }

    for(int i=0; i<N; i++) {
        cout << arr[i] << endl;
    }

    vector<int> v; //Dichiaro un array di nome v, e specifico che conterrà elementi `int`

    int i = 0;

    while (i<N) {
        if (arr[i]>=0) {
            v.push_back(arr[i]);
            i++;
        }
        else {
            vector<int> v;
            i++;
        }    
    }
    i++;
    while (arr[i]>=0) {
        v.push_back(arr[i]);
        i++;
    }
    for(int i=0; i<N; i++)
        cout << arr[i] << endl;

    
    v.push_back(10); //La funzione push_back inserisce un elemento (in questo caso il numero 10) in fondo all'array
    v.push_back(20);
    v.push_back(30);
    
    for(int i = 0; i < v.size(); i++){  // La funzione size() ritorna il numero di elementi all'interno dell'array
        cout << v[i] << endl; // Per accedere all' i-esimo elemento, v[i]
    }
    

    return 0;
}
*/