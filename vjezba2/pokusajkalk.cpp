#include "stogpolje.h"

int main(){
    Stack<int> stog;
    
    // Učitaj početni broj
    int rez;
    if (!(std::cin >> rez)) {
        return 0;
    }
    stog.Push(rez);
    
    // Računaj izraz korak po korak (bez prioriteta operacija)
    // Čitaj dok ima operatora i brojeva
    char op;
    while (std::cin >> op) {
        // Provjeri je li ovo operator
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            // Nije operator, vrati se nazad i pročitaj kao broj za undo
            std::cin.putback(op);
            break;
        }
        
        int x;
        if (!(std::cin >> x)) {
            break;
        }
        
        // Uzmi zadnji rezultat sa stoga
        int trenutniRezultat = stog.Top();
        
        // Primijeni operaciju
        int noviRezultat;
        switch(op) {
            case '+':
                noviRezultat = trenutniRezultat + x;
                break;
            case '-':
                noviRezultat = trenutniRezultat - x;
                break;
            case '*':
                noviRezultat = trenutniRezultat * x;
                break;
            case '/':
                noviRezultat = trenutniRezultat / x;
                break;
            default:
                continue; // preskoči nepoznati operator
        }
        
        // Spremi novi rezultat na stog (čuvamo sve međurezultate za undo)
        stog.Push(noviRezultat);
    }
    
    // Učitaj broj operacija za undo
    int undoN = 0;
    if (std::cin >> undoN) {
        // Poništi zadnjih undoN operacija (skini zadnjih undoN elemenata sa stoga)
        for (int i = 0; i < undoN && !stog.isEmpty(); ++i) {
            stog.Pop();
        }
    }
    
    // Ispiši rezultat (zadnji element na stogu)
    if (!stog.isEmpty()) {
        std::cout << stog.Top() << std::endl;
    }
    
    return 0;
}
