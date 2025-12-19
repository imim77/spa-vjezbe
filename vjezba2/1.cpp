#include <iostream>
#include <cstdlib>


template<typename T>
class DoubleQueue{
private:
    struct que{
        T val;
        que* next;
    };

    que* front;
    que* rear;
public:
    DoubleQueue(){
        que* p = new que;
        p->next = nullptr;
        front = rear = p;
    }

    bool isEmpty(){
        return front == rear;
    }

    T Front(){
        if(front == rear){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return front->next->val;
        }
    }

    T Top(){
        if(front == rear){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return front->next->val;
        }
    }

    void Push(T x){
        que* novi = new que;
        novi->val = x;
        novi->next = front->next;
        front->next = novi;
        if(rear == front){
            rear = novi;
        }
        
    }

    void Enqueue(T x){
        que* novi = new que;
        novi->val = x;
        novi->next = nullptr;
        rear->next = novi;
        rear = novi;
    }

    void Dequeue(){
        if(front == rear){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            que* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void Pop(){
        if(front == rear){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            que* temp = front;
            front = front->next;
            delete temp;
        }
    }

    ~DoubleQueue(){
        while(front != NULL){
            que* p = front;
            front = front->next;
            delete p;
        }
    }
};



int main(){
    DoubleQueue<int> red;
        DoubleQueue<int> red2;
        int n; std::cin >> n;
    for(int i=0; i<n; i++){
        int elem; std::cin >> elem;
        red.Enqueue(elem);
    }
    for(int i=0; i<n; i++){
        int elem = red.Front();
        std::cout << "Element: " << elem;
        red.Dequeue();
        std::cout << "Mičem Element: " << elem;
        red2.Push(elem);    
    }

    for(int i=0; i<n; i++){
        std::cout << "Brišem element: " << red2.Front();
        red2.Dequeue();
    }

    
}