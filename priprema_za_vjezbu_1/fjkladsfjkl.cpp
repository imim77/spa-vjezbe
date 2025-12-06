#include <iostream>
#include <cstdlib>


template<typename elementtype>
class Stack{
private:
    struct stk{
        elementtype val;
        stk* next;
    };
public:
    stk* S;
    Stack(){
        S = new stk;
        S->next = NULL;
    };

    bool isEmpty(){
        return S->next == NULL;
    }

    elementtype Top(){
        if(S->next == nullptr){
            std::cout << "Stog je prazan";
            exit(EXIT_FAILURE);
        }
        return S->next->val;
    }

    void Push(elementtype x){
        stk* p = new stk;
        p->val = x;
        p->next = S->next;
        S->next = p;
    }

    void Pop(){
        if(S->next == nullptr)[
            std::cout << "Stog je prazan";
            exit(EXIT_FAILURE);
        ]else{
            stk* p = S;
            S = S->next;
            delete p;
        }
    }

    ~Stack(){
        while(S != nullptr){
            stk* temp = S;
            S = S->next;
            delete temp;
        }
    }
};

