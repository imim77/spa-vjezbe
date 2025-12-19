#include <iostream>
#include <iomanip>
#include "redpolje.h"

struct Proces {
    int dolazak;   // vrijeme dolaska u red
};

int main() {
    int n;
    std::cin >> n;          // broj procesa

    int trajanje;
    std::cin >> trajanje;   // duljina obrade jednog procesa

    queue<Proces> red;

    int dolazak = 0;        // apsolutno vrijeme dolaska
    double suma_cekanja = 0;
    int trenutno_vrijeme = 0;

    // prvi proces: dolazak u 0 sekundi
    Proces p;
    p.dolazak = 0;
    red.Enqueue(p);

    // ostali procesi: učitavamo razliku u odnosu na prethodni dolazak
    for (int i = 1; i < n; ++i) {
        int razlika;
        std::cin >> razlika;
        dolazak += razlika;

        Proces novi;
        novi.dolazak = dolazak;
        red.Enqueue(novi);
    }

    // obrada procesa u FCFS redoslijedu
    while (!red.IsEmpty()) {
        Proces tren = red.Front();
        red.Dequeue();

        int pocetak = (trenutno_vrijeme < tren.dolazak)
                        ? tren.dolazak
                        : trenutno_vrijeme;

        int cekanje = pocetak - tren.dolazak;

        std::cout << tren.dolazak << " "
                  << pocetak << " "
                  << cekanje << std::endl;

        suma_cekanja += cekanje;
        trenutno_vrijeme = pocetak + trajanje;
    }

    std::cout << std::fixed << std::setprecision(1)
              << suma_cekanja / n << std::endl;

    return 0;
}
