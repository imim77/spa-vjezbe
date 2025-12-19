#include "redpolje.h"





int main(){
    queue<int> red;
    int n;
    std::cin >> n;

    // Učitavanje elemenata u red
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        red.Enqueue(a);
    }

    // Selekcijsko sortiranje koristeći samo operacije nad redom
    // Nakon svake iteracije i, i najmanjih elemenata nalazi se na kraju reda.
    for(int i = 0; i < n; i++){
        int minVal = INT_MAX;

        // 1) Pronađi minimum među prvih (n - i) elemenata, ali zadrži poredak u redu
        for(int j = 0; j < n; j++){
            int x = red.Front();
            red.Dequeue();

            if(j < n - i && x < minVal){
                minVal = x;
            }

            red.Enqueue(x);
        }

        // 2) Ukloni prvu pojavu minimuma iz prvih (n - i) elemenata
        bool removed = false;
        for(int j = 0; j < n; j++){
            int x = red.Front();
            red.Dequeue();

            if(j < n - i && !removed && x == minVal){
                removed = true;        // preskoči ovu (prvu) pojavu minimuma
                continue;
            }

            red.Enqueue(x);
        }

        // 3) Dodaj pronađeni minimum na kraj reda
        red.Enqueue(minVal);
    }
    while(!red.IsEmpty()){
        std::cout << red.Front() << " ";
        red.Dequeue();
    }
    std::cout << std::endl;
    return 0;

}