#ifndef MAXL
#define MAXL 1000
#endif

#include <iostream>
#include <cstdlib>

template <typename elementtype>
class list {
public:
inline static const int lambda = -1;

typedef int element;

private:
elementtype el[MAXL];
int NoEl;


public:
list() {
    NoEl = 0;
}

bool IsEmpty() {
     return NoEl == 0;
}

elementtype Retrieve(element e) {
             if (e == NoEl || e == lambda) {
                 std::cout << "Nepostojeci element" 
                           << std::endl;
                 exit(EXIT_FAILURE); 
             }
             else
                 return el[e];
}

element Next (element e) {
         if (e == lambda) {
            std::cout << "Nepostojeci element" 
                      << std::endl;
            exit(EXIT_FAILURE); 
         }
         else
             if (e < NoEl)
                return e+1;
             else
			     return lambda;
}

element Previous(element e) {
         if (e == lambda) {
            std::cout << "Nepostojeci element" 
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else
             return e-1;
}

element First() {
         return 0;
}

element End() {
         return NoEl;
}

void Insert(element e,elementtype x) {
     if (NoEl == MAXL) {
        std::cout << "Lista je prepunjena" 
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
     	  if (e == lambda) {
     	     std::cout << "Nepostojeci element" 
			           << std::endl;
		     exit(EXIT_FAILURE);	 
		  }
		  else {
               for (int i = NoEl - 1; i >= e; i--) 
                   el[i+1] = el[i];
               NoEl++;
               el[e] = x;
		  }
     }
}

void Delete(element e) {
     if (e == NoEl || e == lambda) {
        std::cout << "Nepostojeci element" 
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
         for (int i = e+1; i < NoEl; i++)
             el[i-1] = el[i];
         NoEl--;
     }
}

void ChangeValue(element e, elementtype x) {
     if (e == NoEl || e == lambda) {
        std::cout << "Nepostojeci element"
                  << std::endl;
        exit(EXIT_FAILURE);
	 }
     else 
         el[e] = x;
}

};

