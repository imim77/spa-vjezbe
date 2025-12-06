#include <iostream>
#include <cstdlib>
#define MAXQ 1000

template<typename elmenttype>
class Queue{
private:
    elmenttype el[MAXQ];
    int front,rear;
    bool empty;

    int AddOne(int a){
        return a == MAXQ-1 ? 0 : a+1;
    }


public:
    Queue(){
        front = 0;
        rear = MAXQ-1;
        empty = true;
    }

    bool isEmpty(){
        return (AddOne(rear)==front && empty);
    }

    elmenttype Front(){
        if(AddOne(rear) == front && empty){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return el[front];
        }
    }

    void Enqueue(elmenttype x){
        if(AddOne(rear) == front && !empty){
            std::cout << "Red je popunjen";
            exit(EXIT_FAILURE);
        }else{
            rear = AddOne(rear);
            el[rear] = x;
            empty = false;
        }
    }

    void Dequeue(){
        if(AddOne(rear) == front && empty){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            front = AddOne(front);
            empty = true;
        }
    }
};



void IzokreniRed(Queue<int>& red){
    if(red.isEmpty()){
        return;
    }

    int x = red.Front();
    red.Dequeue();

    IzokreniRed(red);

    red.Enqueue(x);
}


void IspisReda(Queue<int> Tempred){
    while(!Tempred.isEmpty()){
        std::cout << Tempred.Front() << " ";
        Tempred.Dequeue();  
    }
    std::cout << std::endl;
}



int main(){
    Queue<int> red;
    red.Enqueue(10); // 10,6,11,5
    red.Enqueue(6);
    red.Enqueue(11);
    red.Enqueue(5);
    std::cout << red.Front();


    std::cout << "Prije izokretanja: ";
    IspisReda(red); 

    IzokreniRed(red);

    std::cout << "Nakon izokretanja: ";
    IspisReda(red);

    
};
