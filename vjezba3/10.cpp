#include "bbbpokazivaci.h"
#include "../vjezba2/redpolje.h"

void popuniStablo(btree<char>& stablo, int n){
    char vrijednost; std::cin >> vrijednost; 
    stablo.CreateRoot(vrijednost);
    if(n == 1) return;

    queue<btree<char>::node> red;
    red.Enqueue(stablo.Root());
    int br = 1;
    while(br < n && !red.IsEmpty()){
        btree<char>::node elem = red.Front();
        red.Dequeue();

        if(br < n){
            std::cin >> vrijednost;
            stablo.CreateLeftChild(elem,vrijednost);
            red.Enqueue(stablo.LeftChild(elem));
            br++;
        }
        if(br < n){
            std::cin >> vrijednost;
            stablo.CreateRightChild(elem, vrijednost);
            red.Enqueue(stablo.RightChild(elem));
            br++;
        }
    } 
}

// Rekurzivna funkcija koja izračunava visinu podstabla i provjerava balansiranost
// Vraća visinu podstabla, a balansiranost provjerava kroz referencu
int izracunajVisinuIBalansiranost(btree<char>& stablo, btree<char>::node n, bool& balansirano) {
    if (n == stablo.lambda) {
        return -1; // visina praznog podstabla je -1
    }
    
    // Rekurzivno izračunaj visinu lijevog podstabla
    int visinaLijevo = izracunajVisinuIBalansiranost(stablo, stablo.LeftChild(n), balansirano);
    if (!balansirano) {
        return -1; // ako već nije balansirano, prekini
    }
    
    // Rekurzivno izračunaj visinu desnog podstabla
    int visinaDesno = izracunajVisinuIBalansiranost(stablo, stablo.RightChild(n), balansirano);
    if (!balansirano) {
        return -1; // ako već nije balansirano, prekini
    }
    
    // Provjeri balansiranost trenutnog čvora
    int razlika = (visinaLijevo > visinaDesno) ? (visinaLijevo - visinaDesno) : (visinaDesno - visinaLijevo);
    if (razlika > 1) {
        balansirano = false;
        return -1;
    }
    
    // Vrati visinu trenutnog podstabla (max visina djece + 1)
    return (visinaLijevo > visinaDesno ? visinaLijevo : visinaDesno) + 1;
}

// Glavna funkcija za provjeru balansiranosti stabla
bool jeBalansirano(btree<char>& stablo) {
    if (stablo.IsEmpty()) {
        return true;
    }
    
    bool balansirano = true;
    izracunajVisinuIBalansiranost(stablo, stablo.Root(), balansirano);
    return balansirano;
}

int main(){
    int n; 
    std::cin >> n;
    btree<char> stablo;
    popuniStablo(stablo, n);
    
    if (jeBalansirano(stablo)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    
    return 0;
}