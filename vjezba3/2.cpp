#include "bbbpokazivaci.h"
#include "../vjezba2/redpolje.h"


void PopuniStablo(btree<int>& stablo, int n) {
    if (n <= 0) return;
    
    int vrijednost;
    std::cin >> vrijednost;
    stablo.CreateRoot(vrijednost);
    
    if (n == 1) return;
    
    
    queue<btree<int>::node> red;
    red.Enqueue(stablo.Root());
    
    int ucitano = 1; // već smo učitani korijen
    
    while (ucitano < n && !red.IsEmpty()) {
        btree<int>::node trenutni = red.Front();
        red.Dequeue();
        
        // Učitaj lijevo dijete
        if (ucitano < n) {
            std::cin >> vrijednost;
            stablo.CreateLeftChild(trenutni, vrijednost);
            red.Enqueue(stablo.LeftChild(trenutni));
            ucitano++;
        }
        
        // Učitaj desno dijete
        if (ucitano < n) {
            std::cin >> vrijednost;
            stablo.CreateRightChild(trenutni, vrijednost);
            red.Enqueue(stablo.RightChild(trenutni));
            ucitano++;
        }
    }
}

// BFS level-order ophodnja pomoću reda
void LevelOrder(btree<int>& stablo) {
    if (stablo.IsEmpty()) {
        return;
    }
    
    queue<btree<int>::node> red;
    red.Enqueue(stablo.Root());
    
    bool prvi = true;
    
    while (!red.IsEmpty()) {
        btree<int>::node trenutni = red.Front();
        red.Dequeue();
        
        // Ispiši oznaku čvora
        if (prvi) {
            std::cout << stablo.Label(trenutni);
            prvi = false;
        } else {
            std::cout << " " << stablo.Label(trenutni);
        }
        
        // Dodaj lijevo dijete u red ako postoji
        btree<int>::node lijevo = stablo.LeftChild(trenutni);
        if (lijevo != stablo.lambda) {
            red.Enqueue(lijevo);
        }
        
        // Dodaj desno dijete u red ako postoji
        btree<int>::node desno = stablo.RightChild(trenutni);
        if (desno != stablo.lambda) {
            red.Enqueue(desno);
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    
    btree<int> stablo;
    PopuniStablo(stablo, n);
    
    LevelOrder(stablo);
    
    return 0;
}

