#include <iostream>
#include <string>  //libreria per funzione stampa_ruotato()
using namespace std;

/*
struct tree {
    int v = 0;
    tree * left;
    tree * right;
};
*/

struct tree {
    int v = 0;
    tree * left = nullptr;
    tree * right = nullptr;
};


int albero_livello(tree * t, int livello = 0) {
    if (t == nullptr) {
        return 0;
    }
    else {
        if (t->v == livello) {
            return 1 + albero_livello(t->left, livello+1) + albero_livello(t->right, livello+1);
        }
        else {
            return 0 + albero_livello(t->left, livello+1) + albero_livello(t->right, livello+1);
        }
    }
}

tree * new_nodo(int v, tree * left = nullptr, tree * right = nullptr) {  // crea un nuovo nodo
    tree * n = new tree;
    n->v = v;
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

void stampa_ruotato(tree * t, int livello = 0) {
    if (t == nullptr) return;

    stampa_ruotato(t->right, livello + 1);              // 1. prima il sottoalbero destro
    cout << string(livello * 4, ' ') << t->v << endl;   // 2. poi il nodo, indentato
    stampa_ruotato(t->left, livello + 1);               // 3. infine il sinistro
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

    //stampa_ruotato(albero);

    int totale = albero_livello(albero);

    cout << "Numero di nodi che hanno il proprio valore uguale al livello in cui si trovano sono: " << endl;
    cout << totale << endl;

    distruggi(albero);

    return 0;
}