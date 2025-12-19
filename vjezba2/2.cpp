#include <iostream>
#include <cstdlib>
#define MAXQ 1000

template<typename T>
class DobleQueuePolje{
private:
    T el[MAXQ];
    int front,rear;
    bool empty;

    int AddOne(int a){
        return a == MAXQ-1 ? 0 : a+1;
    }

    int SubOne(int a){
        return a == 0 ? MAXQ-1 : a-1;
    }

public:
    DobleQueuePolje(){
        front = 0;
        rear = MAXQ-1;
        empty = true;
    }

    bool isEmpty(){
        return (AddOne(rear) == front && empty);
    }

    T Front(){
        if(AddOne(rear) == front && empty){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return el[front];
        }
    }

    T Top(){
        if(AddOne(rear) == front && empty){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return el[front];
        }
    }



    void Push(T x){
        if(AddOne(rear) == front && !empty){
            std::cout << "Red je prepunjen";
            exit(EXIT_FAILURE);
        }else{
            front = SubOne(front);
            el[front] = x;
            empty = false;
        }
    }

    void Enqueue(T x){
        if(AddOne(rear) == front && !empty){
            std::cout << "Red je prepunjen";
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

    void Pop(){
        if(AddOne(rear) == front && empty){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            front = AddOne(front);
            empty = true;
        }
    }


};


int main(){
    DobleQueuePolje<int> red;
    DobleQueuePolje<int> red2;
    int n; std::cin >> n;
    for(int i=0; i<n; i++){
        int elem; std::cin >> elem;
        red.Enqueue(elem);
    }
    for(int i=0; i<n; i++){
        int elem = red.Front();
        red.Dequeue();
        
        red2.Push(elem);
    }
    for(int i=0; i<n; i++){
        std::cout <<  red2.Front() << " ";
        red2.Dequeue();
    }

};