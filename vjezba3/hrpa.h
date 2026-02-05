#include <iostream>
#include <cstdlib>

#ifndef Comp
#define Comp(a,b) (a<b ? -1 : (a==b ? 0 : 1))
#endif

#ifndef MAXH
#define MAXH 1000
#endif

template <typename nodetype>
class heap {
private:
nodetype el[MAXH+1];
int NoEl;

public:
heap() {
    NoEl = 0;
}

bool IsEmpty() {
	 return NoEl == 0; 
}

nodetype RootLabel() {
         if (NoEl == 0) {
            std::cout << "Hrpa je prazna"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else 
             return el[1];
}

void Insert(nodetype x) {
     if (NoEl == MAXH) {
        std::cout << "Hrpa je popunjena"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else { 
          el[++NoEl] = x;
          int n = NoEl;
          while (n>1 && Comp(el[n], el[n/2]) == -1) {
                nodetype p = el[n/2];
                el[n/2] = el[n];
                el[n] = p;
                n /= 2;
          }
     }
}

void DeleteRoot() {
     if (NoEl == 0) {
        std::cout << "Hrpa je prazna"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else { 
          int n =1;
          el[1] = el[NoEl--];
          int k;
          bool next;
          do {
             if (2*n+1 <= NoEl && 
                 Comp(el[2*n+1],el[2*n]) == -1)
                k = 2*n+1;
             else
                k = 2*n;
             if (k <= NoEl && 
                 Comp(el[k], el[n]) == -1) {
                nodetype p = el[n];
                el[n] = el[k];
                el[k] = p;
                next = true;
                n = k;
             }  
             else
                 next = false;
         } while (next);
     }
}
};

