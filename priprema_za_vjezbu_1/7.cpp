//#include "listapok.h"
//#include "listapolje.h"
// 7 ZADATAK!
int h(int x){
    return x%11;
}


template<typename T>
class hashTablica{
public:
    list<int> pretinci[11];

    void Insert(T x){
        if(isElement(x)){
            std::cout << "element već postoji u tablici"; 
        }
        int indeks = h(x);
        pretinci[indeks].Insert(pretinci[indeks].First(), x);
    }


    void Delete(T x){
        int indeks = h(x);
        auto it = pretinci[indeks].First();
        while(it != pretinci[indeks].End()){
            if(x == pretinci[indeks].Retrieve(it)){
                pretinci[indeks].Delete(it);
                std::cout << "obrisan element";
            }
        }
    }



    bool isElement(T x){
        int indeks = h(x);
        auto p = pretinci[indeks].First();
        while(p != pretinci[indeks].End()){
            if(x == pretinci[indeks].Retrieve(p)){
                return true;
            }
            p = pretinci[indeks].Next(p);
        }
        return false;
    }

    void PrintAll(){
        for(int i=0; i<11; i++){
            std::cout << "Pretinac: [" << i << "]: ";
            auto p = pretinci[i].First();
            while(p != pretinci[i].End()){
                std::cout << pretinci[i].Retrieve(p) << " ";
                p = pretinci[i].Next(p);
            }
            std::cout << std::endl;
        }
    }
};


int main(){
    hashTablica<int> ha;
    int n; std::cin >> n;
    srand(time(0));
    for(int i=0; i<n; i++){
        ha.Insert(rand()%100+1);
    }
    ha.PrintAll();
    int x;
    while(true){
        std::cout << "unesite broj za provjeru/brisanje (0 za kraj)";
        std::cin >> x;
        if (x == 0) break;

        if(ha.isElement(x)){
            std::cout << "Element " << x << " pronaden u tablici -> Brisem ga." << std::endl;
            ha.Delete(x);
        }else{
            std::cout << "Element " << x << " NIJE pronaden u tablici." << std::endl;
            ha.PrintAll();
        }
    }

    return 0;
}