//#include "listapok.h"
    #include "listakursori.h"
//#include "listapok2.h"
//#include "listapolje.h"



int main(){
    list<int> lista;
    std::cout << "stupanj polinoma: ";
    int n; std::cin >> n;

    for(int i=n; i>=0; i--){
        std::cout << "za stupanj" << i << "koeficijent: ";
        int koef; std::cin >> koef;
        lista.Insert(lista.End(), koef);

    }

    std::cout << "x: "; int x; std::cin >> x;

    int suma= lista.Retrieve(lista.First());
    int counter = 0;

    
    for(auto iter = lista.Next(lista.First()); iter != lista.End(); iter = lista.Next(iter)){
        suma = suma * x + lista.Retrieve(iter);
        counter++;
    }

    std::cout << suma << std::endl;
    std::cout << counter << std::endl;





}