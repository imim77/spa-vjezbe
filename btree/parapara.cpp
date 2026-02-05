#include "binarnostablopretrazivanja.h"



// O(n^2)
void BSTSort(int n, int a[]){
    BST<int> B;
    for(int i = 0; i<n; i++){
        B.Insert(a[i]);
    }
    int i = 0;
    while(!B.isEmpty()){
        int minimalni = B.Min();
        B.Delete(minimalni);
        a[i++] = minimalni;
    }
}
// O(n)






int main(){
    int b[20];
    BST<int> B;
    B.Insert(10);
    B.Insert(7);
    B.Insert(12);
    B.Insert(6);
    B.Insert(9);
    B.Insert(3);
    B.Insert(15);
    B.Insert(2);
    B.Insert(8);
    
    int count = B.poljeParniNeparni(b);
    
    std::cout << "Neparni (uzlazno) + Parni (silazno): ";
    for(int i = 0; i < count; i++){
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
}