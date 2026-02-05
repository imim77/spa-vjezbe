#ifndef MAXT
#define MAXT 1000
#endif

#include <iostream>
#include <cstdlib>

template <typename nodetype>
class tree {
private:
struct trnd {
       nodetype label;
       int child,sibling,parent;
       bool used;
};

trnd el[MAXT];
int empty;

public:
typedef int node;
const int lambda = -1;

tree(nodetype x) {
	el[0].label = x;
	el[0].child = el[0].sibling = el[0].parent = lambda;
	for (int i =1; i < MAXT-1; i++)
	    el[i].sibling = i+1;
    el[MAXT-1].sibling = lambda;
    empty = 1;
}

tree() {
	for (int i =  0; i < MAXT-1; i++)
	    el[i].sibling = i+1;
    el[MAXT-1].sibling = lambda;
    empty = 0;
}

bool IsEmpty() {
	 return !empty;
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
	 if (empty)
        return 0;
     else
         return lambda;
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

node FirstChild(node n) {
	 if (n == lambda) {
	    std::cout << "Nepostojeci cvor" 
	              << std::endl;
	    exit(EXIT_FAILURE);
	 }
	 else
	     return el[n].child;
}

node NextSibling(node n) {
	 if (n == lambda) {
	 	std::cout << "Nepostojeci cvor" 
	              << std::endl;
	    exit(EXIT_FAILURE);
	 }
	 else
	     return el[n].sibling;
}

node ChangeLabel(node n, nodetype x) {
	 if (n == lambda) {
	    std::cout << "Nepostojeci cvor" 
	              << std::endl;
	    exit(EXIT_FAILURE);
	 }
	 else
	     el[n].label = x;
}

void CreateRoot(nodetype x) {
	 if (empty) {
	 	std::cout << "Stablo nije prazno"
	 	          << std::endl;
	    exit(EXIT_FAILURE);
	 }
	 else {
	 	  empty = el[0].sibling;
	 	  el[0].label = x;
	 	  el[0].parent = el[0].child = el[0].sibling = lambda;
	 }
}

void CreateChild(node n, nodetype x) {
	 if (n == lambda) {
	    std::cout << "Nepostojeci cvor" 
	              << std::endl;
	    exit(EXIT_FAILURE);
	 }
	 else {
	  	  if (empty == lambda) {
	  	   	 std::cout << "Stablo je popunjeno"
	  	   	           << std::endl;
	  	   	 exit(EXIT_FAILURE);
		  }
		  else {
		       int i = empty;
		   	    empty = el[empty].sibling;
		   	    el[i].label = x;
			    el[i].child = lambda;
			    el[i].parent = n;
			    el[i].sibling = el[n].child;
			    el[n].child = i;
		   }
	  }
}

private:
void Del(node n) {
	 if (el[n].sibling != lambda)
	    Del(el[n].sibling);
	 if (el[n].child != lambda)
	    Del(el[n].child);
	 el[n].used = empty;
	 empty = n;
}

public:
void Delete(node n) {
	 if (n == lambda) {
	 	std::cout << "Nepostojeci cvor"
		          << std::endl;
	    exit(EXIT_FAILURE); 
	 }
	 else {
	 	  if (el[n].child != lambda)
	 	     Del(el[n].child);
	 	  if (el[n].parent != lambda)
	 	    if (el[el[n].parent].child == n){
	 	        el[el[n].parent].child = el[n].sibling;
			}else{
	 	     	  int i = el[el[n].parent].child;
	 	     	  while (el[i].sibling != n)
	 	     	        i = el[i].sibling;
	 	     	  el[i].sibling = el[n].sibling;
			}
		  el[n].sibling = empty;
		  empty = n;
	 }
}

};

