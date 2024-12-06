#include <iostream>

// Definizione della classe Lista come template
template <typename T>
class ListaPuntatori {
  private:
    // Definizione della struttura del nodo
    struct Nodo {
        T valore;      // Valore del nodo
        Nodo* next;    // Puntatore al nodo successivo
    };

    Nodo* head;       // Puntatore alla testa della lista
    Nodo* coda;       // Puntatore alla coda della lista
    int lung;         // Lunghezza effettiva della lista

  public:
    // Costruttore
    ListaPuntatori() {
        head = nullptr;
        coda = nullptr;
        lung = 0;
    }

    // Distruttore per liberare la memoria
    ~ListaPuntatori() {
        while (head != nullptr) {
            Nodo* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Inserisce un elemento alla fine della lista
    void inslista(T elem) {
        Nodo* nuovo = new Nodo{elem, nullptr};
        if (lung == 0) {
            head = coda = nuovo;
        } else {
            coda->next = nuovo;
            coda = nuovo;
        }
        lung++;
    }

    // Cancella l'elemento dalla testa della lista
    void canclista() {
        if (lung == 0) {
            std::cout << "Errore: lista vuota." << std::endl;
            return;
        }
        Nodo* toDelete = head;
        head = head->next;
        delete toDelete;
        lung--;
        if (lung == 0) {
            coda = nullptr;
        }
    }

    // Restituisce l'elemento in testa alla lista
    T leggilista() {
        if (lung == 0) {
            std::cout << "Errore: lista vuota." << std::endl;
            return T(); // Restituisce un valore di default
        }
        return head->valore;
    }

    // Restituisce la lunghezza della lista
    int lunghezza() const {
        return lung;
    }
};

// Definizione della classe Coda
template <typename T>
class Coda {
private:
    ListaPuntatori<T> lista;

public:
    // Costruttore
    Coda() {}

    // Aggiunge un elemento alla fine della coda
    void enqueue(T elem) {
        lista.inslista(elem);
    }

    // Rimuove l'elemento in testa alla coda e lo restituisce
    T dequeue() {
        if (lista.lunghezza() == 0) {
            // Gestione di una coda vuota
            std::cout << "Errore: la coda Ã¨ vuota." << std::endl;
            return T(); // Restituisce un valore di default
        }
        T frontElem = lista.leggilista();
        lista.canclista();
        return frontElem;
    }

    // Restituisce l'elemento in testa alla coda senza rimuoverlo
    T front() {
        if (lista.lunghezza() == 0) {
            // Gestione di una coda vuota
            std::cout << "Errore: la coda Ã¨ vuota." << std::endl;
            return T(); // Restituisce un valore di default
        }
        return lista.leggilista();
    }

    // Verifica se la coda Ã¨ vuota
    bool isEmpty() const {
        return lista.lunghezza() == 0;
    }

    // Restituisce il numero di elementi nella coda
    int size() const {
        return lista.lunghezza();
    }
};

