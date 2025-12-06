#include <iostream>
#include <cstdlib>
#define MAXS 1000


template<typename elementtype>
class Stack{
private:
    elementtype el[MAXS];
    int top;
public:
    Stack(){
        top = MAXS-1;
    }
    
    bool isEmpty(){
        return top == MAXS-1;
    }

    elementtype Top(){
        if(top == MAXS-1){
            std::cout << "Stog je prazan";
            exit(EXIT_FAILURE);
        }else{
            return el[top+1];
        }
    }

    void Push(elementtype x){
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

bool DobroUparene(const char* izraz){
    Stack<char> stog;
    int velicina = strlen(izraz);
    for(int i=0; i<velicina; i++){
        std::cout << "Char: " << izraz[i] << std::endl;
        switch(izraz[i]){
            case '(':
                stog.Push(izraz[i]);
                break;
            case ')':
                if(stog.isEmpty()){
                    return false;
                };
                stog.Pop();
        }
    }
    return stog.isEmpty();
}


int main(){
    char izraz1[] = "(())";
    if(DobroUparene(izraz1)){
        std::cout << "Zagrade su dobro uparene\n";
    }else{
        std::cout << "Zagrade nisu dobro uparene\n";
    }
}