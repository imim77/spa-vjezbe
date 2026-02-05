#include <iostream>
#include <cstdlib>

#ifndef MAXPQ
#define MAXPQ 1000
#endif

#ifndef Comp
#define Comp(a, b) (a < b ? -1 : (a == b ? 0 : 1))
#endif


template<typename T>
class pqueue{
private:
    T el[MAXPQ];
    int NoEL;

public:
    // InitPQ(PQ) - Operacija inicijalizira prazni prioritetni red
    // Složenost: O(1)
    void InitPQ(){
        NoEL = 0;
    }

    // IsEmptyPQ(PQ) - Operacija vraća true ako je prioritetni red PQ prazan, a inače vraća false
    // Složenost: O(1)
    bool IsEmptyPQ(){
        return NoEL == 0;
    }

    // MaxPQ(PQ) - Operacija vraća maksimalnu vrijednost zapisanu u prioritetni red PQ
    // Ako je prioritetni red PQ prazan, vraća poruku pogreške
    // Složenost: O(1) - maksimum je uvijek na kraju sortiranog polja
    T MaxPQ(){
        if(NoEL == 0){
            std::cout << "Prioritetni red je prazan" << std::endl;
            exit(EXIT_FAILURE);
        }
        return el[NoEL - 1];
    }

    // InsertPQ(PQ,x) - Operacija dodaje vrijednost x u prioritetni red PQ
    // Složenost: O(n) - u najgorem slučaju pomičemo sve elemente
    // Amortizirana složenost: O(n)
    void InsertPQ(T x){
        if(NoEL == MAXPQ){
            std::cout << "Prioritetni red je prepunjen" << std::endl;
            exit(EXIT_FAILURE);
        }
        // Umetanje na ispravno mjesto (sortirano polje uzlazno)
        int i = NoEL - 1;
        while(i >= 0 && Comp(el[i], x) == 1){  // el[i] > x
            el[i + 1] = el[i];
            i--;
        }
        el[i + 1] = x;
        NoEL++;
    }

    // DeleteMaxPQ(PQ) - Operacija briše maksimalnu vrijednost iz prioritetnog reda PQ
    // Ako je prioritetni red PQ prazan, vraća poruku pogreške
    // Složenost: O(1) - samo smanjimo brojač jer je max na kraju
    void DeleteMaxPQ(){
        if(NoEL == 0){
            std::cout << "Prioritetni red je prazan" << std::endl;
            exit(EXIT_FAILURE);
        }
        NoEL--;
    }

    // DisposePQ(PQ) - Operacija oslobađa memorijski prostor koji je zauzimao prioritetni red PQ
    // Složenost: O(1)
    void DisposePQ(){
        NoEL = 0;
        // Polje je statički alocirano, nema potrebe za dealokacijom
    }
};

/*
 * SLOŽENOST OPERACIJA:
 * 
 * InitPQ(PQ)      - O(1)
 * IsEmptyPQ(PQ)   - O(1)
 * MaxPQ(PQ)       - O(1)
 * InsertPQ(PQ,x)  - O(n) najgori slučaj, O(n) amortizirana
 * DeleteMaxPQ(PQ) - O(1)
 * DisposePQ(PQ)   - O(1)
 * 
 * AMORTIZIRANA SLOŽENOST STRUKTURE:
 * - Implementacija koristi sortirano polje
 * - Insert je O(n) jer moramo pronaći mjesto i pomaknuti elemente
 * - DeleteMax i Max su O(1) jer je maksimum uvijek na kraju
 * - Za n operacija Insert + DeleteMax, ukupna složenost je O(n²)
 * - Amortizirana složenost po operaciji: O(n)
 */


int main(){
    pqueue<int> PQ;
    
    PQ.InitPQ();
    
    std::cout << "IsEmptyPQ: " << (PQ.IsEmptyPQ() ? "true" : "false") << std::endl;
    
    PQ.InsertPQ(5);
    PQ.InsertPQ(10);
    PQ.InsertPQ(3);
    PQ.InsertPQ(7);
    
    std::cout << "IsEmptyPQ: " << (PQ.IsEmptyPQ() ? "true" : "false") << std::endl;
    std::cout << "MaxPQ: " << PQ.MaxPQ() << std::endl;
    
    PQ.DeleteMaxPQ();
    std::cout << "Nakon DeleteMaxPQ, MaxPQ: " << PQ.MaxPQ() << std::endl;
    
    PQ.DeleteMaxPQ();
    std::cout << "Nakon DeleteMaxPQ, MaxPQ: " << PQ.MaxPQ() << std::endl;
    
    PQ.DisposePQ();
    std::cout << "Nakon DisposePQ, IsEmptyPQ: " << (PQ.IsEmptyPQ() ? "true" : "false") << std::endl;
    
    return 0;
}
