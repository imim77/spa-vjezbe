#include "btreepoknovi.h"
#include "../vjezba2/redpolje.h"


int zbroj = 0;

void ProcessNode(btree<int>& stablo, btree<int>::node n){
    zbroj += stablo.Label(n);
}


int zbrojsvihCvorovaStabla(btree<int>& stablo, btree<int>::node n){
        if(stablo.LeftChild(n) != stablo.lambda){
            zbrojsvihCvorovaStabla(stablo, stablo.LeftChild(n));
        }
        ProcessNode(stablo, n);
        if(stablo.RightChild(n) != stablo.lambda){
            zbrojsvihCvorovaStabla(stablo, stablo.RightChild(n));
        }
        return zbroj;
}

int zbrojUnutarnjihListvoa(btree<int>& stablo, btree<int>::node n){
    if(n == stablo.lambda) return 0;

    // If it's a leaf (no children), it's not an internal node
    if(stablo.LeftChild(n) == stablo.lambda && stablo.RightChild(n) == stablo.lambda){
        return 0;
    }
    
    // It's an internal node - add its label AND recurse to find more
    return stablo.Label(n) + 
           zbrojUnutarnjihListvoa(stablo, stablo.LeftChild(n)) + 
           zbrojUnutarnjihListvoa(stablo, stablo.RightChild(n));
}

int zbrojSvihListova(btree<int>& stablo, btree<int>::node n){
    if(n == stablo.lambda) return 0;

    if(stablo.LeftChild(n) == stablo.lambda && stablo.RightChild(n) == stablo.lambda){
        return n->label;
    }

    return zbrojSvihListova(stablo, stablo.LeftChild(n))+ 
    zbrojSvihListova(stablo,stablo.RightChild(n));
}


void popuniStablo(btree<int>& stablo, int n){
    if(n <= 0) return;
    int vr; std::cin >> vr;
    stablo.CreateRoot(vr);
    if(n == 1) return;
    queue<btree<int>::node> red;
    red.Enqueue(stablo.Root());

    int upisan = 1;
    while(upisan < n && !red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        if(upisan < n){
            std::cin >> vr;
            stablo.CreateLeftChild(elem, vr);
            red.Enqueue(stablo.LeftChild(elem));
            upisan++;
        }

        if(upisan < n){
            std::cin >> vr;
            stablo.CreateRightChild(elem, vr);
            red.Enqueue(stablo.RightChild(elem));
            upisan++;
        }
    }
}



int main(){
    int i; std::cin >> i;
    btree<int> stablo;
    popuniStablo(stablo,i);
    //int z = zbrojsvihCvorovaStabla(stablo, stablo.Root());
    int z = zbrojSvihListova(stablo, stablo.Root());
    int zz = zbrojUnutarnjihListvoa(stablo, stablo.Root());
    std::cout << "zbroj: " << z;
    std::cout << "zbroj unutranji: " << zz;
}