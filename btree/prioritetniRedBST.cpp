#include "binarnostablopretrazivanja.h"


template<typename T>
class priorityQueue{
private:
    BST<T> S;
public:
    void InitPQ(){
        S = BST<T>();
    };

    bool isEmptyPQ(){
        return S.isEmpty();
    }

    T MaxPQ(){
        if(S.isEmpty()){
            std::cout << "Red je prazan" << std::endl;
            exit(EXIT_FAILURE);
        }
        return S.Max();
    }

    void InsertPQ(T x){
        S.Insert(x);
    }

    void DeleteMax(){
        if(S.isEmpty()){
            std::cout << "Red je prazan" << std::endl;
            exit(EXIT_FAILURE); 
        }else{
            S.Delete(S.Max())
        } 
    }

    void DisposePQ(){
        delete S;
        S = NULL;
    }


};