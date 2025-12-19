#include "redpolje.h"


int main(){
    queue<int> red;
    int br_procesa; std::cin >> br_procesa;
    int duljina_trajanja; std::cin >> duljina_trajanja;
    int n; std::cin >> n;
    int dolazak = 0;
    int pocetak_obrade = 0;
    int cekanje = 0;
    for(int i = 1; i< br_procesa-1; i++){
        int m; std::cin >> m;
        red.Enqueue(m);
    }
    std::cout << dolazak << " " << cekanje << " " << pocetak_obrade << std::endl;
    int proslifront = 0;
    float ukupnocekanje = 0.0f;
    while(!red.IsEmpty()){
        auto front = red.Front();
        proslifront += front; 
        cekanje += duljina_trajanja;
        std::cout << proslifront << " " << cekanje << " " << cekanje-proslifront << std::endl; 
        red.Dequeue();
        ukupnocekanje += cekanje-proslifront;
    }
    std::cout << "Prosjecno cekanje: " << ukupnocekanje/float(br_procesa-1);


}
