#include <iostream>
#include <queue> //per utilizzare le code
using namespace std;

struct tree {
    int value = 0;
    tree * left = nullptr;
    tree * right = nullptr;
};


tree * new_nodo(int value, tree * left = nullptr, tree * right = nullptr) {  // crea un nuovo nodo
    tree * n = new tree;
    n->value = value;
    n->left = left;
    n->right = right;
    return n;
}

void distruggi(tree * t) {  // libera la memoria (post-order)
    if (t == nullptr) return;
    distruggi(t->left);
    distruggi(t->right);
    delete t;
}

void bfs(tree * t) {
    queue<int> q;
    q.push(t->value);
    while (!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();
        t = t->left;
        while (t)
    }
}


int main() {
    tree * albero =
        new_nodo(0,
            new_nodo(1,
                new_nodo(2,
                    new_nodo(3)),
                new_nodo(1)),
            new_nodo(5,
                nullptr,
                new_nodo(2)));

    /*

    Livello 0:          0
                       / \
    Livello 1:        1   5
                     / \   \
    Livello 2:      2   1   2
                   /
    Livello 3:    3

    */
    cout << "Visita per livello albero (stampa i valori): " << endl;
    bfs(albero);

    /*
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
    */
    
    return 0;
}
