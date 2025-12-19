#include <iostream>
#include <iomanip>
#include <cstdlib>

typedef int elementtypeq;

struct Node {
    elementtypeq val;
    Node* next;
};

typedef Node* elementq;

struct Queue {
    elementq front;
    elementq rear;
};

/* Inicijalizacija reda */
void InitQ(Queue& Q) {
    elementq p = new Node;
    p->next = nullptr;        // VAŽNO
    Q.front = Q.rear = p;
}

/* Provjera je li red prazan */
bool IsEmptyQ(Queue& Q) {
    return Q.front == Q.rear;
}

/* Dohvat prvog elementa */
elementtypeq FrontQ(Queue& Q) {
    if (IsEmptyQ(Q)) {
        std::cout << "Red je prazan" << std::endl;
        exit(EXIT_FAILURE);
    }
    return Q.front->next->val;
}

/* Ubacivanje u red */
void EnqueueQ(Queue& Q, elementtypeq x) {
    elementq p = new Node;
    p->val = x;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
}

/* Izbacivanje iz reda */
void DequeueQ(Queue& Q) {
    if (IsEmptyQ(Q)) {
        std::cout << "Red je prazan" << std::endl;
        exit(EXIT_FAILURE);
    }
    elementq p = Q.front;
    Q.front = Q.front->next;
    delete p;
}

/* Brisanje cijelog reda */
void DisposeQ(Queue& Q) {
    while (Q.front != nullptr) {
        elementq p = Q.front;
        Q.front = Q.front->next;
        delete p;
    }
    Q.rear = nullptr;
}

int main() {
    Queue Q;
    InitQ(Q);
    
    int n;
    std::cin >> n;          // broj procesa
    
    int trajanje;
    std::cin >> trajanje;   // duljina obrade jednog procesa
    
    int dolazak = 0;        // apsolutno vrijeme dolaska
    double suma_cekanja = 0;
    int trenutno_vrijeme = 0;
    
    // prvi proces: dolazak u 0 sekundi
    EnqueueQ(Q, 0);
    
    // ostali procesi: učitavamo razliku u odnosu na prethodni dolazak
    for (int i = 1; i < n; ++i) {
        int razlika;
        std::cin >> razlika;
        dolazak += razlika;
        
        EnqueueQ(Q, dolazak);
    }
    
    // obrada procesa u FCFS redoslijedu
    while (!IsEmptyQ(Q)) {
        int tren_dolazak = FrontQ(Q);
        DequeueQ(Q);
        
        int pocetak = (trenutno_vrijeme < tren_dolazak)
                        ? tren_dolazak
                        : trenutno_vrijeme;
        
        int cekanje = pocetak - tren_dolazak;
        
        std::cout << tren_dolazak << " "
                  << pocetak << " "
                  << cekanje << std::endl;
        
        suma_cekanja += cekanje;
        trenutno_vrijeme = pocetak + trajanje;
    }
    
    std::cout << std::fixed << std::setprecision(1)
              << suma_cekanja / n << std::endl;
    
    DisposeQ(Q);
    return 0;
}
