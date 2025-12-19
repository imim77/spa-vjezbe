#ifndef MAXQ
#define MAXQ 1000
#endif

#include <iostream>
#include <cstdlib>

template <typename elementtype>
class queue {
private:
elementtype el[MAXQ];
int front, rear;
bool empty;

int AddOne (int a) {
	return a == MAXQ - 1 ? 0: a+1;
}

public:
queue() {
     front = 0;
     rear = MAXQ-1;
     empty = true;
}

bool IsEmpty() {
     return (AddOne(rear) == front && empty);
}

elementtype Front() {
            if (AddOne(rear) == front && 
                 empty) {
               std::cout << "Red je "
                         << "prazan "  
                         << std::endl;
               exit(EXIT_FAILURE); 
            }
            else
                return el[front];
}

void Enqueue(elementtype x) {
     if (AddOne(rear) == front && !empty) {
        std::cout << "Red je prepunjen"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          rear = AddOne(rear);
          el[rear] = x;
          empty = false;
     }
}

void Dequeue() {
     if (AddOne(rear) == front && empty) {
        std::cout << "red je prazan" 
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          front = AddOne(front);
          empty = true;
	 }
}
};

