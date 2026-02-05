#include <cstring>
#include "opcenito.h"

class trie {
private:
struct nodetype {
       char letter;
       bool terminal;
}; 

tree<nodetype> T;

public:

typedef tree<nodetype>::node node;

tree<nodetype>::node lambda;


trie () {
	 lambda = T.lambda;
	 nodetype n = {' ',false};
	 T.CreateRoot(n);
}

bool IsEmpty() {
	 return T.FirstChild(T.Root()) == T.lambda;
}

bool IsElement(char s[]) {
	 tree<nodetype>::node n = T.Root();
	 for (int i =0; i < strlen(s); i++) {
	 	 tree<nodetype>::node n1 = T.FirstChild(n);
	 	 while (n1 != T.lambda && T.Label(n1).letter != s[i]) 
	 	       n1 = T.NextSibling(n1);
	     if (n1 == T.lambda)
	        return false;
	     else 
	         if (i == strlen(s)-1)
	            return T.Label(n1).terminal;
	         else
	             n = n1;
	 }
}

void Insert(char s[]) {
	 tree<nodetype>::node n = T.Root();
	 for (int i = 0; i < strlen(s); i++) {
	 	 tree<nodetype>::node n1 = T.FirstChild(n);
	 	 while (n1 != T.lambda && T.Label(n1).letter != s[i])
	 	       n1 = T.NextSibling(n1);
	 	 if (n1 == T.lambda) {
	 	    nodetype p;
	 	    p.letter = s[i];
	 	    p.terminal = false;
	 	    T.CreateChild(n,p);
	 	    n1 = T.FirstChild(n);
	 	    while (T.Label(n1).letter != s[i])
	 	          n1 = T.NextSibling(n1);
		 }	 		     
	 	 n = n1;
	 }
	 nodetype p = T.Label(n);
	 p.terminal = true;
	 T.ChangeLabel(n,p);
}

void Delete(char s[]) {
	 tree<nodetype>::node n = T.Root();
	 for (int i = 0; i < strlen(s); i++) {
	 	 tree<nodetype>::node n1 = T.FirstChild(n);
	 	 while (n1 != T.lambda && T.Label(n1).letter != s[i]) 
	 	       n1 = T.NextSibling(n1);
	 	 if (n1 == T.lambda)
	 	    return;
	 	 n = n1;
	 }
	 nodetype p = T.Label(n);
	 p.terminal = false;
	 T.ChangeLabel(n,p);
	 while (T.FirstChild(n) == T.lambda && !T.Label(n).terminal && n != T.Root()) {
	 	   tree<nodetype>::node n1 = T.Parent(n);
	 	   T.Delete(n);
	 	   n = n1;
	 }
}

};

