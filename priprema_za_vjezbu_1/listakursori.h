#ifndef MAXL
#define MAXL 1000
#endif

#include <iostream>
#include <cstdlib>

template <typename elementtype>
class list {
private:
struct lst {
       elementtype val;
       int next, prev;
};

lst el[MAXL];
int empty;

public:
typedef int element;
inline static const int lambda=-1;

list () {
     el[0].next = el[0].prev = 0;
     for (int i = 1; i < MAXL-1; i++)
         el[i].next = i+1;
     el[MAXL-1].next = lambda;
     empty = 1;
}

bool IsEmpty() {
     return el[0].next == 0;
}

elementtype Retrieve(element e) {
            if (e == lambda || el[e].next == 0)  {
               std::cout << "Nepostojeci element" 
                         << std::endl;
               exit(EXIT_FAILURE);
            }
            else 
                return el[el[e].next].val;
}

element Next(element e) {
        if (e == lambda) {
           std::cout << "Nepostojeci element"
                     << std::endl;
           exit(EXIT_FAILURE);
        }
        else
            if (el[e].next == 0)
               return lambda;
            else
                return el[e].next;
}

element Previous(element e) {
        if (e == lambda) {
           std::cout << "Nepostojeci element"
                     << std::endl;
           exit(EXIT_FAILURE);
        }
        else
            if (e == 0)
               return lambda;
            else
                return el[e].prev;
}

element First() {
        return 0;
}

element End() {
        return el[0].prev;
}

void Insert (element e, elementtype x) {
     if (e == lambda) {
        std::cout << "Nepostojeci element"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          if (empty == lambda) {
             std::cout << "Lista je popunjena"
                       << std::endl;
             exit(EXIT_FAILURE);
         }
         int p = el[empty].next;
         el[empty].val = x;
         el[empty].next = el[e].next;
         el[empty].prev = e;
         el[el[e].next].prev = empty;
         el[e].next = empty;
         empty = p; 
     }
}

void Delete(element e) {
     if (e == lambda || el[e].next == 0) {
        std::cout << "Nepostojeci element" 
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          int p = el[e].next;
          el[el[el[e].next].next].prev = e;
          el[e].next = el[el[e].next].next;
          el[p].next = empty;
          empty = p;
     }
}

void ChangeValue(element e, elementtype x) {
     if (e == lambda || el[e].next == 0) {
        std::cout << "Nepostojeci element"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         el[el[e].next].val = x;
}
};

