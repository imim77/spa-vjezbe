#include "stogpolje.h"



int main(){
    Stack<int> stog;
    Stack<int> stog2;
    int n; std::cin >> n;
    for(int i=0; i<n; i++){
        int elem; std::cin >> elem;
        stog.Push(elem);
    }

    for(int i=0; i<n; i++){
        int el = stog.Top();
        stog.Pop();
        stog2.Push(el);
    }
    for(int i=0; i<n; i++){
        int elem = stog2.Top();
        stog2.Pop();
        stog.Push(elem);
        std::cout << stog.Top() << " ";
    }

    
}

