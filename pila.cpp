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
    int lung;         // Lunghezza effettiva della lista

  public:
    // Costruttore
    ListaPuntatori() {
        head = nullptr;
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

    // Inserisce un elemento nella lista
    void inslista(T elem, int p) {
        Nodo* nuovo = new Nodo{elem, nullptr};
        if (p == 1) {
            nuovo->next = head;
            head = nuovo;
        } else {
            Nodo* corrente = head;
            for (int i = 1; i < p - 1; i++) {
                corrente = corrente->next;
            }
            nuovo->next = corrente->next;
            corrente->next = nuovo;
        }
        lung++;
    }

    // Cancella un elemento dalla lista
    void canclista(int p) {
        if (p == 1) {
            Nodo* toDelete = head;
            head = head->next;
            delete toDelete;
        } else {
            Nodo* corrente = head;
            for (int i = 1; i < p - 1; i++) {
                corrente = corrente->next;
            }
            Nodo* toDelete = corrente->next;
            corrente->next = toDelete->next;
            delete toDelete;
        }
        lung--;
    }

    // Restituisce un elemento dalla lista
    T leggilista(int p) {
        Nodo* corrente = head;
        for (int i = 1; i < p; i++) {
            corrente = corrente->next;
        }
        return corrente->valore;
    }

    // Restituisce la lunghezza

// Definizione della classe Pila
template <typename T>
class Pila {
private:
    ListaPuntatori<T> lista;
    int count; // Per tenere traccia del numero di elementi nella pila

public:
    // Costruttore
    Pila() : count(0) {}

    // Aggiunge un elemento alla pila
    void push(T elem) {
        lista.inslista(elem, 1); // Inserisce l'elemento all'inizio della lista
        count++;
    }

    // Rimuove l'elemento in cima alla pila e lo restituisce
    T pop() {
        if (count == 0) {
            // Gestione di una pila vuota
            std::cout << "Errore: la pila Ã¨ vuota." << std::endl;
            return T(); // Restituisce un valore di default
        }
        T topElem = lista.leggilista(1);
        lista.canclista(1);
        count--;
        return topElem;
    }

    // Restituisce l'elemento in cima alla pila senza rimuoverlo
    T top() {
        if (count == 0) {
            // Gestione di una pila vuota
            std::cout << "Errore: la pila Ã¨ vuota." << std::endl;
            return T(); // Restituisce un valore di default
        }
        return lista.leggilista(1);
    }

    // Restituisce il numero di elementi nella pila
    int size() const {
        return count;
    }
};




