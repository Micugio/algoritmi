#include <iostream>
#include <fstream>
#include <vector>
#include <queue> 
using namespace std;

struct nodo{
    vector<int> vic;      // Nodi vicino al nodo attuale
    bool visited = false;
};

vector<nodo> grafo;

queue<int> q;

int N, M;

ifstream in("input.txt");
ofstream out("output.txt");

void distance(vector<nodo>& grafo, int value){
    q.push(value);
    vector<int> distance(N);

    while (!q.empty) {
        nodo u = q.front();
        q.pop();
        for(int i=0; i<grafo[value].vic.size(); i++){
            if (distance[grafo[value].vic[i]]) {
                //
            }
        }
    }

    if (!grafo[value].visited) {
        grafo[value].visited = true;
        counter++;
        for(int i=0; i<grafo[value].vic.size(); i++){
            visita(grafo, grafo[value].vic[i]);
        }
    }
}

void diametro(vector<nodo>& grafo, int value){
    if (!grafo[value].visited) {
        grafo[value].visited = true;
        counter++;
        for(int i=0; i<grafo[value].vic.size(); i++){
            visita(grafo, grafo[value].vic[i]);
        }
    }
}

int main(){
    in >> N >> M;

    grafo.resize(N);

    for(int i=0; i<N-1; i++) {
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


    //visita(grafo, s);
    out << endl;

    return 0;
}
