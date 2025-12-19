#include <iostream>
#include <cstdlib>


template<typename elementtype>
class Queue{
private:
    struct que{
        elementtype val;
        que* next;
    };

    que* rear, *front;

public:
    Queue(){
        que* p = new que;
        p->next = NULL;
        front = rear = p;
    }

    bool isEmpty(){
        return front == rear;
    }

    elementtype Front(){
        if(front == rear){
            std::cout << "Red je prazan";
            exit(EXIT_FAILURE);
        }else{
            return front->next->val;
        }
    }


    void Enqueue(elementtype x){
        que* n = new que;
        n->val = x;
        n->next = NULL;
        rear->next = n;
        rear = n;
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

    ~Queue(){
        while(front != NULL){
            que* p = front;
            front = front->next;
            delete p;
        }
    }

};

// Sortiranje reda korištenjem samo javnih metoda Queue (insertion sort u pomoćni red)
template<typename T>
void SortQueue(Queue<T>& q, bool ascending = true){
    if(q.isEmpty()) return;

    // izračunaj veličinu reda kroz privremeni red
    Queue<T> tmp;
    int n = 0;
    while(!q.isEmpty()){
        T v = q.Front();
        q.Dequeue();
        tmp.Enqueue(v);
        n++;
    }
    while(!tmp.isEmpty()){ // vrati elemente natrag u izvorni red
        q.Enqueue(tmp.Front());
        tmp.Dequeue();
    }

    Queue<T> aux;
    int auxSize = 0;

    for(int processed = 0; processed < n; ++processed){
        T x = q.Front();
        q.Dequeue();

        if(auxSize == 0){
            aux.Enqueue(x);
            auxSize = 1;
            continue;
        }

        bool inserted = false;
        int currentSize = auxSize;
        for(int i = 0; i < currentSize; ++i){
            T v = aux.Front();
            aux.Dequeue();
            if(!inserted && (ascending ? (x < v) : (x > v))){
                aux.Enqueue(x);
                inserted = true;
            }
            aux.Enqueue(v);
        }
        if(!inserted){
            aux.Enqueue(x);
        }
        auxSize++;
    }

    // vrati sortirane elemente u originalni red
    while(!aux.isEmpty()){
        q.Enqueue(aux.Front());
        aux.Dequeue();
    }
}

int main(){
    Queue<int> red;
    red.Enqueue(3);
    red.Enqueue(1);
    red.Enqueue(4);
    red.Enqueue(2);

    SortQueue(red, true); // uzlazno sortiranje

    while(!red.isEmpty()){
        std::cout << red.Front() << " ";
        red.Dequeue();
    }
}