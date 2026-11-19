#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


struct nodo{
    vector<int> vic;      // Nodi vicino al nodo attuale
    bool visited = false;
};

vector<nodo> grafo;


ifstream in("input.txt");
ofstream out("output.txt");

/*
vector<nodo> trasposto (vector<nodo> & grafo) {
}
*/


int cicloRec(vector<int> & dt, vector<int> & ft, int & time, int value) {
    
    dt[value] = time;
    time++;
    grafo[value].visited = true;

    for(int i=0; i<grafo[value].vic.size(); i++){
        if(dt[grafo[value].vic[i]] == -1) { // CASO RIC
            return cicloRec(dt, ft, time, grafo[value].vic[i]);
        }
        else { // CASO BASE
            if( (ft[grafo[value].vic[i]] == -1) && (dt[value] > dt[grafo[value].vic[i]]) ) {
                return time - dt[grafo[value].vic[i]];  // SBAGLIATO fare time meno finish
            }
        }
    }
    time++;
    ft[value] = time;
    return -1;
    
}

int ciclo(int N) {
    vector<int> dt (N, -1);
    vector<int> ft (N, -1);
    int time = 0;
    for(int i=0; i<N; i++){
        if(grafo[i].visited == false) {
            int n = cicloRec(dt, ft, time, i);
            if(n != -1) {
                return n;
            }
        }
    }
    
    return -1; // n = -1 in questo caso
}


int main() {
    int N, M;

    in >> N >> M;

    grafo.resize(N);

    for(int i=0; i<M; i++) {
        int from, to;
        in >> from >> to;
        grafo[from].vic.push_back(to);
    }


    for(int i=0; i<N; i++){
        cout << "Nodo " << i << " ha " << grafo[i].vic.size() << " vicini \n";

        for(int j=0; j<grafo[i].vic.size(); j++) {
            cout << "  " << grafo[i].vic[j] << "\n";
        }
    }

    out << ciclo(N) << endl;

    return 0;
}
