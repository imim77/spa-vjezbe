#include "listapok.h"


void ExchangeSort(list<int>& lista){
    for(auto e = lista.End(); e != lista.First(); e = lista.Previous(e)){
        for(auto j = lista.First(); j != e; j = lista.Next(j)){
            auto next_j = lista.Next(j);
            if(next_j != lista.End() && lista.Retrieve(j) > lista.Retrieve(next_j)){
                auto pom = lista.Retrieve(j);
                lista.ChangeValue(j, lista.Retrieve(next_j));
                lista.ChangeValue(next_j, pom);
            }
        }
    }
}

void BubbleSort(list<int>& lista){
    bool ex = true;
    for(auto e = lista.End(); e != lista.First() && ex; e = lista.Previous(e)){
        ex = false;
        for(auto j = lista.First(); j != e; j = lista.Next(j)){
            auto next_j = lista.Next(j);
            if(next_j != lista.End() && lista.Retrieve(j) > lista.Retrieve(next_j)){
                auto pom = lista.Retrieve(j);
                lista.ChangeValue(j, lista.Retrieve(next_j));
                lista.ChangeValue(next_j, pom);
                ex = true;
            }
        }
    }
}


int main(){
    list<int> lista;
    srand(time(0));
    for (int i=0; i<5; i++){
        lista.Insert(lista.End(),rand()%10+1);
    }

    std::cout << "Prije sortiranja\n";

    for(auto it=lista.First(); it != lista.End(); it = lista.Next(it)){
        std::cout << lista.Retrieve(it) << " ";
    }
    //ExchangeSort(lista);
    BubbleSort(lista);

    std::cout << "Poslije sortiranja: \n";


    for(auto it=lista.First(); it != lista.End(); it = lista.Next(it)){
        std::cout << lista.Retrieve(it) << " ";
    }
}