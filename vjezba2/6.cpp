
#include <iostream>
#include <cstdlib>

#define MAXS 1000

template<typename elementtype>
class Stack {
private:
    elementtype el[MAXS];
    int top1;  // Vrh prvog stoga (raste prema dolje)
    int top2;  // Vrh drugog stoga (raste prema gore)

public:
    Stack() {
        top1 = -1;        // Stog 1 počinje s lijeve strane
        top2 = MAXS;      // Stog 2 počinje s desne strane
    }

    // Provjerava je li stog d prazan
    bool IsEmpty(int d) {
        switch(d) {
            case 1:
                return (top1 == -1);
            case 2:
                return (top2 == MAXS);
            default:
                std::cout << "Neispravan broj stoga!" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    // Vraća element s vrha stoga d
    elementtype Front(int d) {
        switch(d) {
            case 1:
                if(top1 == -1) {
                    std::cout << "Greska: Stog 1 je prazan!" << std::endl;
                    exit(EXIT_FAILURE);
                }
                return el[top1];
                
            case 2:
                if(top2 == MAXS) {
                    std::cout << "Greska: Stog 2 je prazan!" << std::endl;
                    exit(EXIT_FAILURE);
                }
                return el[top2];
                
            default:
                std::cout << "Neispravan broj stoga!" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    // Dodaje element x u stog d
    void Push(int d, elementtype x) {
        // Provjera je li nema više mjesta (stogovi su se susreli)
        if(top1 + 1 == top2) {
            std::cout << "Greska: Stogovi su puni!" << std::endl;
            exit(EXIT_FAILURE);
        }

        switch(d) {
            case 1:
                el[++top1] = x;
                break;
                
            case 2:
                el[--top2] = x;
                break;
                
            default:
                std::cout << "Neispravan broj stoga!" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    // Briše element s vrha stoga d
    void Pop(int d) {
        switch(d) {
            case 1:
                if(top1 == -1) {
                    std::cout << "Greska: Stog 1 je prazan!" << std::endl;
                    exit(EXIT_FAILURE);
                }
                top1--;
                break;
                
            case 2:
                if(top2 == MAXS) {
                    std::cout << "Greska: Stog 2 je prazan!" << std::endl;
                    exit(EXIT_FAILURE);
                }
                top2++;
                break;
                
            default:
                std::cout << "Neispravan broj stoga!" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

  
};

int main(){
    
}

