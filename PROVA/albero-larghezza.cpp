#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Tree {
    char  _value;
    Tree* _parent;
    Tree* _leftmostChild;
    Tree* _rightSibling;

    // Costruisce un nuovo nodo contenente v, senza figli o genitori
    Tree(char v)
        : _value(v), _parent(nullptr),
          _leftmostChild(nullptr), _rightSibling(nullptr) {}

    // Distruggere un nodo distrugge tutti i suoi discendenti
    // (ma NON i suoi fratelli)
    ~Tree() {
        while (_leftmostChild != nullptr) {
            deleteChild();
        }
    }

    // Vietiamo la copia: due nodi non possono condividere gli stessi figli
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

    // Legge il valore memorizzato nel nodo
    char read() const { return _value; }

    // Modifica il valore memorizzato nel nodo
    void write(char v) { _value = v; }

    // Restituisce il padre, oppure nullptr se questo nodo e' radice
    Tree* parent() const { return _parent; }

    // Restituisce il primo figlio, oppure nullptr se questo nodo e' una foglia
    Tree* leftmostChild() const { return _leftmostChild; }

    // Restituisce il prossimo fratello, oppure nullptr se assente
    Tree* rightSibling() const { return _rightSibling; }

    // Inserisce il sottoalbero t come primo figlio di questo nodo
    void insertChild(Tree* t) {
        t->_parent = this;
        t->_rightSibling = _leftmostChild;   // il vecchio primo figlio scala di una posizione
        _leftmostChild = t;
    }

    // Inserisce il sottoalbero t come prossimo fratello di questo nodo
    void insertSibling(Tree* t) {
        t->_parent = _parent;                // stesso padre
        t->_rightSibling = _rightSibling;    // il vecchio fratello scala di una posizione
        _rightSibling = t;
    }

    // Distrugge l'albero radicato nel primo figlio
    void deleteChild() {
        if (_leftmostChild == nullptr) return;
        Tree* c = _leftmostChild;
        _leftmostChild = c->_rightSibling;   // il secondo figlio diventa il primo
        c->_rightSibling = nullptr;          // isolo c dai suoi fratelli
        delete c;                            // il distruttore elimina c e i suoi discendenti
    }

    // Distrugge l'albero radicato nel prossimo fratello
    void deleteSibling() {
        if (_rightSibling == nullptr) return;
        Tree* s = _rightSibling;
        _rightSibling = s->_rightSibling;    // il fratello dopo s prende il suo posto
        s->_rightSibling = nullptr;
        delete s;
    }
};

// ---------- Funzioni di supporto (fuori dalla specifica) ----------

// Aggiunge un figlio come ULTIMO figlio di 'padre' e lo restituisce.
Tree* aggiungiFiglio(Tree* padre, char v) {
    Tree* nuovo = new Tree(v);
    if (padre->leftmostChild() == nullptr) {
        padre->insertChild(nuovo);
    } else {
        Tree* u = padre->leftmostChild();
        while (u->rightSibling() != nullptr) {
            u = u->rightSibling();
        }
        u->insertSibling(nuovo);
    }
    return nuovo;
}

// Stampa indentata: un livello = 4 spazi
void stampa(Tree* t, int livello = 0) {
    if (t == nullptr) return;
    cout << string(livello * 4, ' ') << t->read() << endl;
    for (Tree* u = t->leftmostChild(); u != nullptr; u = u->rightSibling()) {
        stampa(u, livello + 1);
    }
}

// ---------- Breadth-First Search (come nella slide) ----------

void bfs(Tree* t) {
    if (t == nullptr) return;

    queue<Tree*> Q;
    Q.push(t);                                   // Q.enqueue(t)

    while (!Q.empty()) {                         // while not Q.isEmpty()
        Tree* u = Q.front();                     // Tree u = Q.dequeue()
        Q.pop();                                 //   (in C++ sono due operazioni)

        cout << u->read() << " ";                // print u

        u = u->leftmostChild();                  // u = u.leftmostChild()
        while (u != nullptr) {                   // while u != nil
            Q.push(u);                           //   Q.enqueue(u)
            u = u->rightSibling();               //   u = u.rightSibling()
        }
    }
}

// ---------- main ----------

int main() {
    //         A
    //        / \
    //       B   E
    //      / \ / \
    //     C  D F  G
    Tree* A = new Tree('A');
    Tree* B = aggiungiFiglio(A, 'B');
    Tree* E = aggiungiFiglio(A, 'E');
    Tree* C = aggiungiFiglio(B, 'C');
    Tree* D = aggiungiFiglio(B, 'D');
    aggiungiFiglio(E, 'F');
    aggiungiFiglio(E, 'G');

    cout << "Struttura dell'albero:" << endl;
    stampa(A);

    cout << "\nBFS: ";
    bfs(A);
    cout << endl;

    cout << "\nPadre di C: " << C->parent()->read() << endl;
    cout << "Padre della radice: "
         << (A->parent() == nullptr ? "nil" : "?") << endl;

    cout << "D contiene: " << D->read() << endl;
    D->write('Z');
    cout << "D dopo write('Z'): " << D->read() << endl;

    A->insertChild(new Tree('N'));
    cout << "\nDopo A->insertChild(N), BFS: ";
    bfs(A);
    cout << endl;

    A->deleteChild();
    cout << "Dopo A->deleteChild(),   BFS: ";
    bfs(A);
    cout << endl;

    B->deleteSibling();
    cout << "Dopo B->deleteSibling(), BFS: ";
    bfs(A);
    cout << endl;

    delete A;
    return 0;
}