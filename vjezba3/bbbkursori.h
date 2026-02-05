#include <iostream>
#include <cstdlib>
#ifndef MAXB
#define MAXB 1000
#endif

template <typename nodetype>
class btree {
private:
struct btr {
       nodetype label;
       int parent,left,right;
};

btr el[MAXB];
int empty;

public:
typedef int node;
const node lambda = -1;

btree(nodetype x) {
     el[0].label = x;
     el[0].parent = el[0].left = el[0].right = lambda;
     for (int i = 1; i < MAXB-1; i++)
         el[i].parent = i+1;
     el[MAXB-1].parent = lambda;
     empty = 1; 
}

btree() {
     for (int i = 0; i < MAXB-1; i++)
         el[i].parent = i+1;
     el[MAXB-1].parent = lambda;
     empty = 0;
}

bool IsEmpty() {
     return empty == 0;
}

nodetype Label(node n) {
         if (n == lambda) {
            std::cout << "Nepostojeci cvor"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else
             return el[n].label;
}

node Root() {
     return empty == 0 ? lambda : 0; 
}


node Parent(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         return el[n].parent;
}

node LeftChild(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         return el[n].left;
}

node RightChild(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         return el[n].right;         
}

void ChangeLabel(node n, nodetype x) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         el[n].label = x;
}

void CreateRoot(nodetype x) {
     if (empty != 0) {
        std::cout << "Stablo nije prazno"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          empty = el[0].parent;
          el[0].left = el[0].right = el[0].parent = lambda;
          el[0].label = x;
     }
}

void CreateLeftChild(node n, nodetype x) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         if (el[n].left != lambda) {
            std::cout << "Cvor vec ima "
                      << "lijevo dijete"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else {
              if (empty == lambda) {
                 std::cout << "Polje je popunjeno"
                           << std::endl;
                 exit(EXIT_FAILURE); 
              }
              int p = empty;
              empty = el[empty].parent;
              el[p].label = x;
              el[p].left = el[p].right = lambda;
              el[p].parent = n;
              el[n].left = p;
         }
}

void CreateRightChild(node n, nodetype x) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         if (el[n].right != lambda) {
            std::cout << "Cvor vec ima "
                      << "lijevo dijete"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else {
              if (empty == lambda) {
                 std::cout << "Polje je popunjeno"
                           << std::endl;
                 exit(EXIT_FAILURE); 
              }
              int p = empty;
              empty = el[empty].parent;
              el[p].label = x;
              el[p].left = el[p].right = lambda;
              el[p].parent = n;
              el[n].right = p;
         }
}

private:
void Del(node n) {
     if (el[n].left != lambda)
        Del(el[n].left);
     if (el[n].right != lambda)
        Del(el[n].right); 
     el[n].parent = empty;
     empty = n;
}

public:
void Delete(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         if (el[n].parent != lambda)
            if (el[el[n].parent].left == n)
               el[el[n].parent].left = lambda;
            else 
                el[el[n].parent].right = lambda;
        Del(n);
}
};



