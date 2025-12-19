#include <iostream>
#include <cstdlib>
#define MAXQ 1000

template<typename T>
class QueueKursor{
private:
    struct que{
        T val;
        int next;
    };
    que el[MAXQ];
    int front,rear;
    bool empty;

    int addOne(int a){
        return a == MAXQ-1 ? 0 : a+1;
    }
public:
    QueueKursor(){
        front = 0;
        rear = MAXQ-1;
        empty = true;
        
    }

    bool isEmpty(){
        return(addOne(rear) == front && empty);
    }

    T Front(){
        if(addOne(rear) == front && empty){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return el[front].val;
        }
    }

    void Enqueue(T x){
        if(addOne(rear) == front && !empty){
            std::cout << "Red je prepunjen";
            exit(EXIT_FAILURE);
        }else{
            rear = addOne(rear);
            el[rear].val = x;
            el[rear].next = rear;
            empty = false;
        }
    }

    void Dequeue(){
        if(addOne(rear) == front && empty){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            front = addOne(front);
            empty = true;
        }
    }
};



int main(){
    QueueKursor<int> red;
    int n; std::cin >> n;
    for(int i=0; i<n; i++){
        int elem; std::cin >> elem;
        red.Enqueue(elem);
    }
    for(int i=0; i<n; i++){
        int elem = red.Front();
        red.Dequeue();
        if(elem%2 == 1){
            red.Enqueue(elem);
        }
    }
    do{
        std::cout << red.Front() << " ";
        red.Dequeue();
    }while(!red.isEmpty());
    
    
    
}