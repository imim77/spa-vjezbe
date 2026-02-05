#include "opcenitostablo.h"
#include "../vjezba2/redpolje.h"

void levelOrder(tree<int>& stablo){
    queue<tree<int>::node> red;
    red.Enqueue(stablo.Root());
    
    while(!red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        
        // Ispisi trenutni cvor
        std::cout << stablo.Label(elem) << " ";
        
        // Dodaj SVU djecu trenutnog cvora u red
        // (prolazimo kroz FirstChild pa sve NextSiblinge)
        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            red.Enqueue(dijete);
            dijete = stablo.NextSibling(dijete);
        }
    }
}



int main(){
    tree<int> opcstablo;
    
    // Korijen
    opcstablo.CreateRoot(4);
    
    // Djeca korijena (dodaju se kao first child, pa idu obrnutim redoslijedom)
    // Zelimo: 3, 1, 7 (s lijeva na desno)
    opcstablo.CreateChild(opcstablo.Root(), 7);   // trece dijete
    opcstablo.CreateChild(opcstablo.Root(), 1);   // drugo dijete
    opcstablo.CreateChild(opcstablo.Root(), 3);   // prvo dijete
    
    // Dohvati prvo dijete korijena (3)
    tree<int>::node cvor3 = opcstablo.FirstChild(opcstablo.Root());
    // Dijete cvora 3 je 1
    opcstablo.CreateChild(cvor3, 1);
    
    // Dohvati cvor 1 (dijete od 3)
    tree<int>::node cvor1_pod3 = opcstablo.FirstChild(cvor3);
    // Djeca cvora 1: 2, 5 (s lijeva na desno)
    opcstablo.CreateChild(cvor1_pod3, 5);
    opcstablo.CreateChild(cvor1_pod3, 2);
    
    // Dohvati cvor 7 (trece dijete korijena)
    tree<int>::node cvor1_dijeteKorijena = opcstablo.NextSibling(cvor3);  // ovo je 1 (dijete korijena)
    tree<int>::node cvor7 = opcstablo.NextSibling(cvor1_dijeteKorijena);  // ovo je 7
    
    // Djeca cvora 7: 5, 8 (s lijeva na desno)
    opcstablo.CreateChild(cvor7, 8);
    opcstablo.CreateChild(cvor7, 5);
    
    // Dohvati cvor 8 (dijete od 7)
    tree<int>::node cvor5_pod7 = opcstablo.FirstChild(cvor7);  // prvo dijete je 5
    tree<int>::node cvor8 = opcstablo.NextSibling(cvor5_pod7); // sljedeci sibling je 8
    
    // Dijete cvora 8 je 9
    opcstablo.CreateChild(cvor8, 9);
    
    /*
     * Struktura stabla:
     *              4
     *          /   |   \
     *         3    1    7
     *         |        / \
     *         1       5   8
     *        / \          |
     *       2   5         9
     */
    
    std::cout << "Level-order obilazak: ";
    levelOrder(opcstablo);
    std::cout << std::endl;
    
    return 0;
}