#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct nodo{
  vector<int> vic;
  bool visited = false;
};

vector<nodo> grafo;

int main(){
  ifstream in("input.txt");

  int N, M;

  in >> N >> M;

  grafo.resize(N);

  for(int i=0; i<M; i++){
    int from, to;
    in >> from >> to;
    grafo[from].vic.push_back(to);
  }

  for(int i=0; i<N; i++){
    cout << "Nodo " << i << " ha " << grafo[i].vic.size() << " vicini \n";
    for(int j=0; j<grafo[i].vic.size(); j++) {
      cout << "  " << grafo[i].vic[j] << "\n";
    }
      
    /* Sintassi c++11
    for(int v:grafo[i].vic)
    cout<<" "<<v<<"\n";
     */
  }

  return 0;
}
