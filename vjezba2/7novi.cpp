#include <iostream>
#include <cstdlib>
#include "stogpolje.h"

template<typename T>
class Queue2Reda{
private:
    Stack<T> stog1;
    Stack<T> stog2;
    int NoEl;
public:
    Queue2Reda(){
        NoEl = 0;
    }

    bool isEmpty(){
        return NoEl == 0;
    }

    void Enqueue(T x){
        while(!stog1.isEmpty()){
            stog2.Push(stog1.Top());
            stog1.Pop();
        }
        
        stog1.Push(x);
        while(!stog2.isEmpty()){
            stog1.Push(stog2.Top());
            stog2.Pop();
        }
        NoEl++;
    }

    void Dequeue(){
        if(stog1.isEmpty()){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            stog1.Pop();
        }
    }


    T Front(){
        if(NoEl == 0){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return stog1.Top();
        }
    }


};


void RedNesto(Queue2Reda<int>& red){
    if(red.isEmpty()) return;
    auto front = red.Front();
    red.Dequeue();
    RedNesto(red);
    if(front%2 != 1){
        red.Enqueue(front);
    }
}



int main(){
    Queue2Reda<int> red;
    int n; std::cin >> n;
    for(int i = 0; i < n; i++){
        int m; std::cin >> m;
        red.Enqueue(m);
    }
    do{
         std::cout << red.Front();
        red.Dequeue();
    }while(!red.isEmpty());
   

    /*while(!red.isEmpty()){
        auto front = red.Front();
        red.Dequeue();
        if(front%2 != 0){
            red.Enqueue(front);
        }
    }
    */
}
