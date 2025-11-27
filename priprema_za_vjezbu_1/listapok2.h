#include <iostream>
#include <cstdlib>

template <typename elementtype>
class list {
private:
struct lst {
       elementtype val;
       lst *next, *prev;
};

public:
typedef lst *element;

private:
element L;

public:
inline static const element lambda=NULL;

list() {
       L = new lst;
       (*L).next = (*L).prev = L;
}

bool IsEmpty() {
     return (*L).next == L;
}

elementtype Retrieve(element e) {
            if (e == lambda || (*e).next == L)  {
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
        else
            if ((*e).next == L)
               return lambda;
            else 
                return (*e).next;
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
            else
                return (*e).prev;
}

element First() {
        return L;
}

element End() {
        return (*L). prev;
}

void Insert(element e, elementtype x) {
	 if (e == lambda) {
   	    std::cout << "Nepostojeci element"
	 	          << std::endl;
	    exit(EXIT_FAILURE);
     }
	 else {
          element p = new lst;
          (*p).val = x;
          (*p).next = (*e).next;
          (*p).prev = e;
          (*(*p).next).prev = p;
          (*e).next = p;
	 }
}

void Delete(element e) {
     if (e == lambda || (*e).next == L) {
        std::cout << "Nepostojeci element" 
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          element p = (*e).next;
          (*(*p).next).prev = e;
          (*e).next = (*(*e).next).next;
          delete p;
     }
}

void ChangeValue(element e, elementtype x) {
     if (e == lambda || (*e).next == L) {
        std::cout << "Nepostojeci element"
                  << std::endl;
        exit(EXIT_FAILURE);
	 }
     else 
         (*(*e).next).val = x;
}

~list() {
        element p,k=(*L).prev;
        while (L != k) {
              p = L;
              L = (*L).next;
              delete p;
        }
        delete L;
}
};

