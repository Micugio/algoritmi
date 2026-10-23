#include <fstream>
using namespace std;

int N;
//Array dichiarato con la dimensione massima
int arr[1000000];

int main() {
    ifstream in ("input.txt");

    in >> N;
    for(int i=0;i<N;i++) {
        in >> arr[i];
    }
    
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

    ofstream out("output.txt");

    out<<mx<<endl;
    return 0;
}