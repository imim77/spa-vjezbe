#include <iostream>
#include <cstdlib>
#define MAXQ 1000

template<typename elementtype>
class Queue{
private:
    elementtype el[MAXQ];
    int front,rear;
    bool empty;

    int AddOne(elementtype a){
        return a == MAXQ-1 ? 0 : a+1;
    }

    int SubOne(elementtype a){
        return a == 0 ? MAXQ-1 : a-1;
    }


public:
    Queue(){
        front = 0;
        rear = MAXQ-1;
        empty = true;
    };

    bool isEmpty(){
        return (AddOne(rear) == front && empty);
    }

    elementtype Front(){
        if(AddOne(rear) == front && empty){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return el[front];
        }
    }

    void Enqueue(elementtype x){
        if(AddOne(rear) == front && !empty){
            std::cout << "Red je prepunjen";
        }
        rear = AddOne(rear);
        el[rear] = x;
        empty = false;
    }

    void Dequeue(){
        if(AddOne(rear) == front && empty){
            std::cout << "Red je prazan";
        }
        front = AddOne(front);
        empty = true;
        
    }

    void Push(elementtype x){
        if(AddOne(rear) == front && !empty){
            std::cout << "Red je prepunjen";
        }
        
        front = SubOne(front);
        el[front] = x;
        empty = false;
    }
};

int main(){
    Queue<int> red;
    red.Enqueue(7);
    red.Push(12);
    auto a = red.Front();
    std::cout << a;
}