#include "listapok.h"
// 13 zadatak
list<double> mnozenjePolinom(list<double>& lista1, list<double>& lista2){
    list<double> rezLista;
    
    // Calculate sizes of both lists
    int size1 = 0;
    for(auto it = lista1.First(); it != lista1.End(); it = lista1.Next(it)){
        size1++;
    }
    
    int size2 = 0;
    for(auto it = lista2.First(); it != lista2.End(); it = lista2.Next(it)){
        size2++;
    }
    
    // Result polynomial has degree (size1-1) + (size2-1) = size1+size2-2
    // So it has size1+size2-1 coefficients
    int resultSize = size1 + size2 - 1;
    
    // Initialize result list with zeros
    for(int k = 0; k < resultSize; k++){
        rezLista.Insert(rezLista.End(), 0.0);
    }
    
    // Multiply polynomials: for each coefficient position k in result,
    // sum all products a_i * b_j where i + j = k
    int i = 0;
    for(auto it1 = lista1.First(); it1 != lista1.End(); it1 = lista1.Next(it1)){
        double coef1 = lista1.Retrieve(it1);
        int j = 0;
        for(auto it2 = lista2.First(); it2 != lista2.End(); it2 = lista2.Next(it2)){
            double coef2 = lista2.Retrieve(it2);
            int k = i + j;
            
            // Get current value at position k
            auto pos = rezLista.First();
            for(int idx = 0; idx < k; idx++){
                pos = rezLista.Next(pos);
            }
            double current = rezLista.Retrieve(pos);
            
            // Update value at position k
            rezLista.ChangeValue(pos, current + coef1 * coef2);
            
            j++;
        }
        i++;
    }
    
    return rezLista;
}


int main(){
    list<double> lista1;
    list<double> lista2;
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i <= n; i++){
        double koef;
        std::cin >> koef;
        lista1.Insert(lista1.End(), koef);
    }

    int m;
    std::cin >> m;

    for(int j = 0; j <= m; j++){
        double koef;
        std::cin >> koef;
        lista2.Insert(lista2.End(), koef);
    }

    auto rezi = mnozenjePolinom(lista1, lista2);
    
    for(auto it = rezi.First(); it != rezi.End(); it = rezi.Next(it)){
        std::cout << rezi.Retrieve(it) << " ";
    }
    std::cout << std::endl;
}