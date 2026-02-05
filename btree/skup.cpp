#include "binarnostablopretrazivanja.h"





template<typename T>
class set{ 
private:
    BST<T>* S;
public:
    // InitS(S) - Operacija inicijalizira prazni skup
    void InitS(){
        S = new BST<T>();
    }

    // IsEmptyS(S) - Operacija vraca true ako je skup S prazan, a inace vraca false
    bool IsEmptyS(){
        return S->isEmpty();
    }

    // IsElementS(S,x) - Operacija vraca true ako je x element skupa S, a false ako nije
    bool IsElementS(T x){
        return S->isNode(x);
    }

    // InsertS(S,x) - Operacija dodaje vrijednost x u skup S. Ako x vec postoji u skupu S, onda ne radi nista
    void InsertS(T x){
        S->Insert(x);
    }

    // DeleteS(S,x) - Operacija brise vrijednost x iz skupa S. Ako vrijednost x ne postoji u skupu S onda ne radi nista
    void DeleteS(T x){
        S->Delete(x);
    }

    // DisposeS(S) - Operacija oslobada memorijski prostor koji je zauzimao skup S
    void DisposeS(){
        delete S;
        S = nullptr;
    }
};


int main(){
    set<int> S;
    
    S.InitS();
    
    S.InsertS(5);
    S.InsertS(3);
    S.InsertS(7);
    S.InsertS(5);  // vec postoji, ne radi nista
    
    std::cout << "IsEmptyS: " << (S.IsEmptyS() ? "true" : "false") << std::endl;
    std::cout << "IsElementS(5): " << (S.IsElementS(5) ? "true" : "false") << std::endl;
    std::cout << "IsElementS(10): " << (S.IsElementS(10) ? "true" : "false") << std::endl;
    
    S.DeleteS(5);
    std::cout << "Nakon DeleteS(5), IsElementS(5): " << (S.IsElementS(5) ? "true" : "false") << std::endl;
    
    S.DisposeS();
    
    return 0;
}
