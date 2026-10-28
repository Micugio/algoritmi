#include <iostream>
#include <fstream>
using namespace std;

int R, C;
int mat[2000][2000];  //Matrice dichiarata con la dimensione massima

int main() {
    ifstream in ("input.txt");
    ofstream out("output.txt");

    in >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            in >> mat[i][j];
        }
    }

    //STAMPA MATRICE
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            for(int i=0; i<R; i++) {
                for(int j=i; j<C; j++) {
                    //calcola somma della sottosequenza
                    int tot = 0;
                    for(int k=i; k<=j; k++) {
                        tot += arr[k];
                    }
                    mx = max(mx,tot);
                    }
    }
        }
    }

    /*
    //soluzione parziale
    int mx = 0;

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

    out << mx << endl;

    */

    return 0;
}