#include <iostream>
#include "pila.cpp"
#include "coda.cpp"


int main() {
    
    // Test della classe Pila
    std::cout << "Test della classe Pila:\n";
    Pila<int> pila;
    
    std::cout << "Push: 10\n";
    pila.push(10);
    std::cout << "Push: 20\n";
    pila.push(20);
    std::cout << "Push: 30\n";
    pila.push(30);

    std::cout << "Elemento in cima alla pila: " << pila.top() << "\n"; // Output: 30
    std::cout << "Dimensione della pila: " << pila.size() << "\n"; // Output: 3

    std::cout << "Pop: " << pila.pop() << "\n"; // Output: 30
    std::cout << "Dimensione della pila dopo il pop: " << pila.size() << "\n"; // Output: 2

    std::cout << "La pila è vuota? " << (pila.size() == 0 ? "Sì" : "No") << "\n"; // Output: No

    // Test della classe Coda
    std::cout << "\nTest della classe Coda:\n";
    Coda<int> coda;

    std::cout << "Enqueue: 10\n";
    coda.enqueue(10);
    std::cout << "Enqueue: 20\n";
    coda.enqueue(20);
    std::cout << "Enqueue: 30\n";
    coda.enqueue(30);

    std::cout << "Elemento in testa alla coda: " << coda.front() << "\n"; // Output: 10
    std::cout << "Dimensione della coda: " << coda.size() << "\n"; // Output: 3

    std::cout << "Dequeue: " << coda.dequeue() << "\n"; // Output: 10
    std::cout << "Dimensione della coda dopo il dequeue: " << coda.size() << "\n"; // Output: 2

    std::cout << "La coda e' vuota? " << (coda.size() == 0 ? "Sì" : "No") << "\n"; // Output: No

    return 0;
};
