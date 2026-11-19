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

int counter = 0;

void visita(vector<nodo>& grafo, int value){
    if (!grafo[value].visited) {
        grafo[value].visited = true;
        counter++;
        for(int i=0; i<grafo[value].vic.size(); i++){
            visita(grafo, grafo[value].vic[i]);
        }
    }
}

int main() {
    int N, M, s;

    in >> N >> M >> s;

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

    visita(grafo, s);
    out << counter << endl;

    return 0;
}
