#include "listapok.h"

// 12 zadatak
struct elem{
    int val;
    unsigned int freq;
};

int main(){
    list<int> lista;
    list<elem> sazetaLista;
    int n;
    if(!(std::cin >> n)) return 0;

    srand(time(0));
    for(int i = 0; i < n; ++i){
        lista.Insert(lista.First(), rand() % 20 + 1);
    }

    for(auto it = lista.First(); it != lista.End(); it = lista.Next(it)){
        std::cout << lista.Retrieve(it) << " ";
    }
    std::cout << std::endl;

    for(auto iter = lista.First(); iter != lista.End(); iter = lista.Next(iter)){
        int vrijednost = lista.Retrieve(iter);
        bool pronaden = false;

        for(auto e = sazetaLista.First(); e != sazetaLista.End(); e = sazetaLista.Next(e)){
            elem trenutni = sazetaLista.Retrieve(e);
            if(trenutni.val == vrijednost){
                trenutni.freq++;
                sazetaLista.ChangeValue(e, trenutni);
                pronaden = true;
                break;
            }
        }

        if(!pronaden){
            elem novi;
            novi.val = vrijednost;
            novi.freq = 1;
            sazetaLista.Insert(sazetaLista.First(), novi);
        }
    }

    for (auto it = sazetaLista.First(); it != sazetaLista.End(); it = sazetaLista.Next(it)) {
        elem e = sazetaLista.Retrieve(it);
        std::cout << "(" << e.val << "," << e.freq << ") ";
    }
    std::cout << std::endl;

    return 0;
}