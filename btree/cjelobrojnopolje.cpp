#include <iostream>
#include <cstdlib>
#include <ctime>

// Pomocna funkcija za sortiranje dijela polja uzlazno (bubble sort)
void sortUzlazno(int a[], int pocetak, int kraj){
    for(int i = pocetak; i < kraj; i++){
        for(int j = pocetak; j < kraj - (i - pocetak); j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Pomocna funkcija za sortiranje dijela polja silazno (bubble sort)
void sortSilazno(int a[], int pocetak, int kraj){
    for(int i = pocetak; i < kraj; i++){
        for(int j = pocetak; j < kraj - (i - pocetak); j++){
            if(a[j] < a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Funkcija koja poreduje n elemenata polja tako da:
// - na pocetku budu neparni brojevi sortirani SILAZNO
// - na kraju budu parni brojevi sortirani UZLAZNO
void poredajNeparneIParne(int a[], int n){
    // Korak 1: Razdvoji neparne i parne - neparni na pocetak, parni na kraj
    int i = 0, j = n - 1;
    
    while(i < j){
        // Pronadi parni s lijeve strane
        while(i < j && a[i] % 2 != 0){
            i++;
        }
        // Pronadi neparni s desne strane
        while(i < j && a[j] % 2 == 0){
            j--;
        }
        // Zamijeni ih
        if(i < j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    
    // Pronadi granicu izmedu neparnih i parnih
    int granica = 0;
    while(granica < n && a[granica] % 2 != 0){
        granica++;
    }
    
    // Korak 2: Sortiraj neparne SILAZNO (od 0 do granica-1)
    if(granica > 0){
        sortSilazno(a, 0, granica - 1);
    }
    
    // Korak 3: Sortiraj parne UZLAZNO (od granica do n-1)
    if(granica < n){
        sortUzlazno(a, granica, n - 1);
    }
}

int main(){
    int n;
    std::cout << "Unesite broj elemenata n: ";
    std::cin >> n;
    
    // Alociraj polje
    int* a = new int[n];
    
    // Inicijaliziraj generator slucajnih brojeva
    srand(time(NULL));
    
    // Ispuni polje slucajnim vrijednostima od -1000 do 1000
    std::cout << "Generirano polje: ";
    for(int i = 0; i < n; i++){
        a[i] = rand() % 2001 - 1000;  // raspon [-1000, 1000]
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    // Pozovi funkciju za poredak
    poredajNeparneIParne(a, n);
    
    // Ispisi rezultat
    std::cout << "Poredano polje (neparni silazno | parni uzlazno): ";
    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    // Oslobodi memoriju
    delete[] a;
    
    return 0;
}
