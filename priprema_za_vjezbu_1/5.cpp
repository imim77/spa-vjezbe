//#include "listapok.h"
//#include "listapok2.h"
//#include "listakursori.h"
#include "listapolje.h"

int main(){
    list<int> lista;
    std::cout << "Unesi br: ";
    int n; std::cin >> n;
    auto e = lista.First();
    srand(time(0));
    for(int i=0; i<n; i++){
        lista.Insert(e, rand()%20+1);
    }
    
    for(list<int>::element i = lista.First(); i!=lista.End(); i= lista.Next(i)){
        std::cout << lista.Retrieve(i) << " ";
    };
    int p,k;
    std::cout << "unesti p: "; std::cin>>p;
    std::cout << "unesti k: "; std::cin>>k;
    
    for(int i=1; i<p; i++){
        e = lista.Next(e);
    }
    std::cout << "p: " << lista.Retrieve(e) << std::endl; 
    list<int>::element curr = e;
 
    while(true){
        for (int j = 0; j < k; j++) {
            if (curr == lista.End() || lista.Next(curr) == list<int>::lambda) {
                break;
            }
            curr = lista.Next(curr);
        }
    
        if (lista.Next(curr) == list<int>::lambda) {
            break;;   
        }
    
        std::cout << lista.Retrieve(curr) << std::endl;
    }
    
    


}