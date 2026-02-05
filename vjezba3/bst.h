
#include <iostream>
#include <cstdlib>

#ifndef Comp
#define Comp(a,b) (a<b ? -1 : (a==b ? 0 : 1))
#endif

template <typename nodetype>
class BST {
private:
struct btr {
       nodetype label;
       btr *parent,*left,*right;
};

btr *B;

public: 
BST() {
	  B = NULL;
}

bool IsEmpty() {
	 return B == NULL;
}

bool IsNode(nodetype x) {
	 btr *p = B;
     while (p != NULL && Comp((*p).label,x) != 0)
           if (Comp((*p).label, x) == -1)
              p = (*p).right;
           else
               p = (*p).left;
     return (p != NULL);
}

nodetype Min() {
         if (B == NULL) {
            std::cout << "Stablo je prazno"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else {
              btr *p = B;
              while ((*p).left != NULL) 
                    p = (*p).left;
              return (*p).label;
            }
}

nodetype Max() {
         if (B == NULL) {
            std::cout << "Stablo je prazno"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else {
              btr *p = B;
              while ((*p).right != NULL) 
                    p = (*p).right;
              return (*p).label;
         }
}

void Insert(nodetype x) {
     if (B == NULL){
        B = new btr;
        (*B).label = x;
        (*B).left = (*B).right 
                  = (*B).parent = NULL; 
     }
     else {
          btr *p = B;
          bool next = true;
          do {
          	 if (Comp((*p).label, x)  == 1 && (*p).left != NULL)
          	    p = (*p).left;
          	 else
          	     if (Comp((*p).label, x)  == -1 && (*p).right != NULL)
          	        p = (*p).right;
          	     else
          	         next = false;
		  } while (next);          
          if (Comp((*p).label, x) != 0) {
             btr *n = new btr;
             (*n).left = (*n).right = NULL;
             (*n).parent = p;
             (*n).label = x;
             if (Comp((*p).label, x) == -1)
               (*p).right = n;
             else 
                 (*p).left = n;
		  }
     }
}

void Delete(nodetype x) {
     btr *n = B, *p;
     while (n != NULL && Comp((*n).label, x) != 0)
           if (Comp((*n).label, x) == 1)
              n = (*n).left;
           else
               n = (*n).right;
     if (n != NULL) {
        if ((*n).left != NULL && (*n).right != NULL) {
           p = (*n).right;
           while ((*p).left != NULL)
                 p = (*p).left;
           (*n).label = (*p).label;
           n = p;
		}   
        if ((*n).left != NULL) 
           p = (*n).left;
		else 
		    p = (*n).right;
		if (p != NULL)
		   (*p).parent = (*n).parent;
		if ((*n).parent != NULL) {
           if ((*(*n).parent).left == n)
              (*(*n).parent).left = p;
           else 
               (*(*n).parent).right = p;
		}
		else {
			 B = p;
			 if (p != NULL)
   			    (*p).parent = NULL;
		}
        delete n;    	    	
	 }
}

private: 
void Del(btr *n) {
	    if ((*n).left != NULL)
	       Del((*n).left);
	    if ((*n).right != NULL)
	       Del((*n).right);
	    delete n;
}

public:
~BST () {
	if (B != NULL)
  	   Del(B);
}

private:
void InOrder(btr *n, nodetype a[], int &i) {
	 if ((*n).left != NULL)
	    InOrder((*n).left, a, i);
	 a[i++] = (*n).label;
	 if ((*n).right != NULL)
	    InOrder((*n).right,a,i);   
}

public:
int Sort(nodetype a[],int n) {
	if (B != NULL)
	   Del(B);
	B = NULL;
    int i=0;
    for (int i=0;i<n;i++)
        Insert(a[i]);
    InOrder(B,a,i);
    return i;
}
};


/*void InBST(bst &B, nodebst p){
	 if ((*p).left != NULL)
	    InBST(B,(*p).left);
	 std::cout << (*p).label << " ";
	 if ((*p).right != NULL)
	    InBST(B,(*p).right);
}

void InorderBST(bst &B) {
	 nodebst p = B;
	 InBST(B,p);
}*/

