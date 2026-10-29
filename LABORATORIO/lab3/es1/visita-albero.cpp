#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct nodo{
  vector<int> vic;
  bool visited = false;
};

vector<nodo> grafo;

ifstream in("input.txt");
ofstream out("output.txt");

void preOrder(const vector<nodo>& grafo, const int value){

    out << value << " ";

    for(int i=0; i<grafo[value].vic.size(); i++){
        preOrder(grafo, grafo[value].vic[i]);
    }
}

void inOrder(const vector<nodo>& grafo, const int value){

    if(grafo[value].vic.empty()){
        out << value << " ";
        return;
    }

    // Stampa prima il primo figlio, poi la radice e poi i restanti figli
    inOrder(grafo, grafo[value].vic[0]);

    out << value << " ";

    for(int i=1; i<grafo[value].vic.size(); i++){
        inOrder(grafo, grafo[value].vic[i]);
    }
}


void postOrder(const vector<nodo>& grafo, const int value){
    for(int i=0; i<grafo[value].vic.size(); i++){
        postOrder(grafo, grafo[value].vic[i]);
    }

    out << value << " ";
}


int main(){
  int N, r;

  in >> N >> r;

  grafo.resize(N);

  for(int i=0; i<N-1; i++) {
    int from, to;
    in >> from >> to;
    grafo[from].vic.push_back(to);
  }

/*
  for(int i=0; i<N; i++){
    cout << "Nodo " << i << " ha " << grafo[i].vic.size() << " vicini \n";
    for(int j=0; j<grafo[i].vic.size(); j++) {
      cout << "  " << grafo[i].vic[j] << "\n";
    }
    */
      
    /* Sintassi c++11
    for(int v:grafo[i].vic)
    cout<<" "<<v<<"\n";

  }
*/

  preOrder(grafo, r);
  out << endl;

  inOrder(grafo, r);
  out << endl;

  postOrder(grafo, r);
  out << endl;

  return 0;
}
