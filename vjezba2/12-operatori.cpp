#include <iostream>
#include "stogpolje.h" 

int main() {
    Stack<int> stog;
    int trenutniRezultat;

    // 1. Učitaj početni broj
    if (!(std::cin >> trenutniRezultat)) {
        return 0;
    }

    // Stavi početni broj na stog
    stog.Push(trenutniRezultat);

    char op;
    // Petlja čita znak po znak. Ako učita operator, nastavlja. 
    // Ako učita znamenku (početak undo broja), prekida.
    while (std::cin >> op) {
        
        // Provjera je li učitani znak operator
        if (op == '+' || op == '-' || op == '*' || op == '/') {
            int operand;
            // Ako je operator, mora slijediti broj
            std::cin >> operand;

            // Dohvati trenutno stanje s vrha (ne radimo Pop jer čuvamo povijest!)
            int prethodni = stog.Top();
            stog.Push(op == '+' ? prethodni+operand : op == '-' ?  prethodni - operand : op == '*' ?  prethodni * operand : prethodni / operand);
        } else {
            // Ako znak NIJE operator, znači da smo naletjeli na broj za 'undo' (npr. '4')
            // Vraćamo taj znak natrag u ulazni tok da ga možemo učitati kao int
            std::cin.putback(op);
            break; 
        }
    }

    // Učitaj broj koraka za poništavanje
    int undoN = 0;
    if (std::cin >> undoN) {
        // Poništi zadnjih undoN operacija
        for (int i = 0; i < undoN; ++i) {
            // Pazimo da ne ispraznimo stog potpuno ako se traži previše undo koraka
            // Iako bi po logici zadatka uvijek trebao ostati barem jedan rezultat ako je unos ispravan
            if (!stog.isEmpty()) {
                stog.Pop();
            }
        }
    }

    // Ispis rezultata (vrh stoga)
    if (!stog.isEmpty()) {
        std::cout << stog.Top() << std::endl;
    }

    return 0;
}