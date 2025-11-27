#include <cstdlib>
#include <iostream>


template <typename elementtype>
class list {

private:
struct rec {
       elementtype val;
       rec *next;
};


public:
typedef rec *element;

private:
element L;

public:
inline static const element lambda=NULL;

list() {
    L = new rec;
    (*L).next = NULL;
}

bool IsEmpty() {
     return (*L).next == NULL;
}

elementtype Retrieve(element e) {
            if (e == lambda || (*e).next ==  lambda) {
               std::cout << "Nepostojeci element" 
                         << std::endl;
               exit(EXIT_FAILURE);                 
            }
            else 
                return (*(*e).next).val;
}

element Next(element e) {
        if (e == lambda) {
           std::cout << "Nepostojeci element" 
                     << std::endl;
           exit(EXIT_FAILURE);
        }
        else return (*e).next;
}

element Previous(element e) {
        if (e == lambda) {
        std::cout << "Nepostojeci element" 
                      << std::endl;
             exit(EXIT_FAILURE);
         }
         else 
              if (e == L)
                 return lambda;
              else {
                   element p = L;
                   while ((*p).next != e) 
                         p = (*p).next;
                   return p;
             }
}

element First() {
        return L;
}

element End() {
        element p = L;
        while ((*p).next != lambda)
              p = (*p).next;
        return p;
}

void Insert(element e, elementtype x) {
     if (e == lambda) {
         std::cout << "Nepostojeci element"
                   << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
           element p = new rec;
          (*p).val = x;
          (*p).next = (*e).next;
          (*e).next = p;
     }
}

void Delete(element e) {
    if (e == lambda || (*e).next == lambda) {
       std::cout << "Nepostojeci element" 
                 << std::endl;
       exit(EXIT_FAILURE);
    }
    else {
         element p = (*e).next;
         (*e).next = (*(*e).next).next;
         delete p;
    }
}

void ChangeValue(element e, elementtype x) {
     if (e == lambda || (*e).next == lambda) {
         std::cout << "Nepostojeci element" 
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         (*(*e).next).val = x;
}

void Print(){
   while(L != NULL && L->next != NULL){
      L = L->next;
      std::cout << L->val << " ";
   }
}

~list() { 
        while (L != NULL) {
              element p = L;
               L = (*L).next;
               delete p;
        }
}
};

