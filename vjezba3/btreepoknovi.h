#include <iostream>
#include <cstdlib>

template <typename nodetype>
class btree {
private:
struct btr {
       nodetype label;
       btr *parent,*left,*right;
};

btr *B;

public:
typedef btr *node;
const node lambda = NULL;

btree(nodetype x) {
     B = new btr;
     (*B).parent = (*B).left = (*B).right = NULL;
     (*B).label = x;
}

btree() {
     B = NULL;
}

bool IsEmpty() {
     return B == NULL;
}

nodetype Label(node n) {
         if (n == lambda) {
            std::cout << "Nepostojeci cvor"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else
             return (*n).label;
}

node Root() {
     return B;
}


node Parent(node n) {
    if (n == lambda) {
       std::cout << "Nepostojeci cvor"
                 << std::endl;
       exit(EXIT_FAILURE);
    }
    else
        return (*n).parent;
}

node LeftChild(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         return (*n).left;
}

node RightChild(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         return (*n).right;         
}

void ChangeLabel(node n, nodetype x) {
	 if (n == lambda) {
	 	std::cout << "Nepostojeci cvor"
	 	          << std::endl;
	    exit(EXIT_FAILURE);
	 }
	 else
	     (*n).label = x;
}

void CreateRoot(nodetype x) {
	 if (B != NULL) {
	 	std::cout << "Stablo nije prazno"
	 	          << std::endl;
	    exit(EXIT_FAILURE);
	 }
	 else {
	 	  B = new btr;
	 	  (*B).left = (*B).right = (*B).parent = NULL;
	 	  (*B).label = x;
	 }
}

void CreateLeftChild(node n, nodetype x) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         if ((*n).left != NULL) {
            std::cout << "Cvor vec ima "
                      << "lijevo dijete"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else {
             node p = new btr;
             (*p).label = x;
             (*p).left = (*p).right = NULL;
             (*p).parent = n;
             (*n).left = p;
         }
}

void CreateRightChild(node n, nodetype x) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         if ((*n).right != NULL) {
            std::cout << "Cvor vec ima "
                      << "desno dijete"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else {
             node p = new btr;
             (*p).label = x;
             (*p).left = (*p).right = NULL;
             (*p).parent = n;
             (*n).right = p;
         }
}

private:
void Del(node n) {
     if ((*n).left != NULL)
        Del((*n).left);
     if ((*n).right != NULL)
        Del((*n).right); 
     delete n;
}

public:
void Delete(node n) {
     if (n == lambda) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         if ((*n).parent != NULL) {
            if ((*(*n).parent).left == n)
               (*(*n).parent).left = NULL;
            else 
                (*(*n).parent).right = NULL;
            Del(n);
		 }
		 else {
		 	  Del(n);
		 	  B = NULL;
	}
}

~btree() {
	  if (B != lambda)
	     Del(B);
}
};
//     if ((*n).parent != NULL)
//        if ((*(*n).parent).left == n)
//           (*(*n).parent).left = NULL;
//        else 
//            (*(*n).parent).right = NULL;


