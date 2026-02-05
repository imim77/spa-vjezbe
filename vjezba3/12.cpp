#include <iostream>

// Struktura za čuvanje elementa zajedno s informacijom o polju iz kojeg dolazi
struct Element {
    int vrijednost;
    int indeksPolja;  // indeks polja (0..k-1)
    int pozicija;     // pozicija u tom polju
};

// Definiraj Comp makro za Element strukturu (potreban za hrpu)
// Mora biti definiran prije uključivanja hrpa.h
#ifndef Comp
#define Comp(a,b) (a.vrijednost < b.vrijednost ? -1 : (a.vrijednost == b.vrijednost ? 0 : 1))
#endif

#include "hrpa.h"

// Spoji k sortiranih polja u jedno sortirano polje koristeći hrpu
void spojiPolja(int** polja, int* velicine, int k, int* rezultat) {
    heap<Element> hrpa;
    
    // Dodaj prvi element svakog polja u hrpu
    for(int i = 0; i < k; i++) {
        if(velicine[i] > 0) {
            Element elem;
            elem.vrijednost = polja[i][0];
            elem.indeksPolja = i;
            elem.pozicija = 0;
            hrpa.Insert(elem);
        }
    }
    
    int indeksRezultata = 0;
    
    // Dok hrpa nije prazna, uzmi najmanji element i dodaj ga u rezultat
    while(!hrpa.IsEmpty()) {
        Element minElem = hrpa.RootLabel();
        hrpa.DeleteRoot();
        
        // Dodaj element u rezultat
        rezultat[indeksRezultata++] = minElem.vrijednost;
        
        // Ako ima sljedeći element u tom polju, dodaj ga u hrpu
        if(minElem.pozicija + 1 < velicine[minElem.indeksPolja]) {
            Element sljedeci;
            sljedeci.vrijednost = polja[minElem.indeksPolja][minElem.pozicija + 1];
            sljedeci.indeksPolja = minElem.indeksPolja;
            sljedeci.pozicija = minElem.pozicija + 1;
            hrpa.Insert(sljedeci);
        }
    }
}

int main() {
    int k;
    std::cin >> k;
    
    int** polja = new int*[k];
    int* velicine = new int[k];
    int ukupnaVelicina = 0;
    
    // Učitaj polja
    for(int i = 0; i < k; i++) {
        int n;
        std::cin >> n;
        velicine[i] = n;
        ukupnaVelicina += n;
        
        polja[i] = new int[n];
        
        // Učitaj elemente i provjeri sortiranost
        for(int j = 0; j < n; j++) {
            std::cin >> polja[i][j];
        }
    }
    
    // Spoji polja koristeći hrpu
    int* rezultat = new int[ukupnaVelicina];
    spojiPolja(polja, velicine, k, rezultat);
    
    // Ispiši rezultat
    for(int i = 0; i < ukupnaVelicina; i++) {
        if(i > 0) std::cout << " ";
        std::cout << rezultat[i];
    }
    std::cout << std::endl;
    
    // Oslobodi memoriju
    for(int i = 0; i < k; i++) {
        delete[] polja[i];
    }
    delete[] polja;
    delete[] velicine;
    delete[] rezultat;
    
    return 0;
}
