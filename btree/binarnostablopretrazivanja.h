#include <iostream>
#include <cstdlib>


#ifndef Comp
#define Comp(a,b) (a<b ? -1 : (a==b ? 0 : 1))
#endif


template<typename T>
class BST{
private:
   struct btr{
      T label;
      btr* left, *right, *parent;
   };
   btr* B;
public:
   BST(){
      B = nullptr;
   }

   bool isEmpty(){
      return B == nullptr;
   };

   bool isNode(T x){
      btr* p = B;
      while(p != NULL && Comp(p->label, x) != 0){
         if(Comp(p->label, x) == -1){
            p = p->right;
         }else{
            p = p->left;
         }
      }
      return (p != NULL);
   }

   T Min(){
      if(B == NULL){
         std::cout << "Stablo je prazno" << std::endl;
         exit(EXIT_FAILURE);
      }else{
         btr* p = B;
         while(p->left != NULL){
            p = p->left;
         }
         return p->label;
      }
   }


   T Max(){
      if(B == NULL){
         std::cout << "Stablo je prazno" << std::endl;
         exit(EXIT_FAILURE);
      }else{
         btr* p = B;
         while(p->right != NULL){
            p = p->right;
         }
         return p->label;
      }
   }

   void Insert(T x){
      if(B == NULL){
         B = new btr;
         B->label = x;
         B->left = NULL;
         B->right = NULL;
         B->parent = NULL;
      }else{
         btr* p = B;
         bool next = true;
         do{
            if(Comp(p->label, x) == 1 && p->left != NULL){
               p = p->left;
            }else{
               if(Comp(p->label, x) == -1 && p->right != NULL){
                  p = p->right;
               }else{
                  next = false;
               }
            }
         }while(next);
         if(Comp(p->label, x) != 0){
               btr* n = new btr;
               n->label = x;
               n->left = n->right = NULL;
               n->parent = p;
               if(Comp(p->label, x) == -1){
                  p->right = n;
               }else{
                  p->left = n;
               }
         }
      }
   }


void Delete(T x) {
    btr *n = B, *p;

    while (n != NULL && Comp((*n).label, x) != 0) {
        if (Comp((*n).label, x) == 1) {
            n = (*n).left;
        } else {
            n = (*n).right;
        }
    }

    if (n != NULL) {
        if ((*n).left != NULL && (*n).right != NULL) {
            p = (*n).right;
            while ((*p).left != NULL) {
                p = (*p).left;
            }
            (*n).label = (*p).label;
            n = p;
        }

        if ((*n).left != NULL) {
            p = (*n).left;
        } else {
            p = (*n).right;
        }

        if (p != NULL) {
            (*p).parent = (*n).parent;
        }

        if ((*n).parent != NULL) {
            if ((*(*n).parent).left == n) {
                (*(*n).parent).left = p;
            } else {
                (*(*n).parent).right = p;
            }
        } else {
            B = p;
            if (p != NULL) {
                (*p).parent = NULL;
            }
        }

        delete n;
    }
}
private:
void Del(btr* n){
   if(n->left != NULL){
      Del(n->left);
   }
   if(n->right != NULL){
      Del(n->right);
   }
   delete n;
}
public:


//void InOrder(btr* n, T a[], int &i){
      //if(n->left != NULL){
         //InOrder(n->left, a, i);
      //}
      //a[i++] = n->label;
      //if(n->right != NULL){
         //InOrder(n->right,a,i);
      //}
//}


//int Sort(T a[], int n){
   //if(B != NULL){
      //Del(B);
   //}
   //B = NULL;
   //int i = 0;
   //for(int j = 0; j<n; j++){
      //Insert(a[j]);
   //}
   //InOrder(B, a, i);
   //return i;
//}




void InOrderNeparni(btr* n, T a[], int &i){
   if(n == NULL) return;  // BITNO: provjera za NULL
   InOrderNeparni(n->left, a, i);
   if(n->label%2 == 1){
      a[i++] = n->label;
   }
   InOrderNeparni(n->right, a, i);
}

void ReverseOrderParni(btr* n, T a[], int &i){ 
   if(n == NULL) return;  // BITNO: provjera za NULL
   ReverseOrderParni(n->right, a, i);
   if(n->label%2 == 0){
      a[i++] = n->label;
   }
   ReverseOrderParni(n->left, a, i);
}



int poljeParniNeparni(T a[]){
   int i = 0;
   InOrderNeparni(B, a, i);
   ReverseOrderParni(B,a,i);
   return i;

}


~BST(){
   if(B != NULL){
      Del(B);
   }
}

};






