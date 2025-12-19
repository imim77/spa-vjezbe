#include <iostream>
#include <cstdlib>


#define MAXS 1000

template<typename T>
class Stack{
private:
    T el[MAXS];
    int top;
public:
    Stack(){
        top = MAXS-1;
    }

    bool isEmpty(){
        return top == MAXS-1;
    }

    T Top(){
        if(top == MAXS-1){
            std::cout << "Stog je prazan";
            exit(EXIT_FAILURE);
        }else{
            return el[top+1];
        }
    }

    void Push(T x){
        if(top == -1){
            std::cout << "Stog je prepunjen";
            exit(EXIT_FAILURE);
        }else{
            el[top--] = x;
        }
    }

    void Pop(){
        if(top == MAXS-1){
            std::cout << "Stog je prazan";
            exit(EXIT_FAILURE);
        }else{
            top++;
            
        }
    }
};