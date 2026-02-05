#include <iostream>
#include <cstdlib>

#ifndef MAXB
#define MAXB 1000
#endif

#ifndef Comp
#define Comp(a,b) (a < b ? -1 : (a == b ? 0 : 1))
#endif


template<typename T>
class BST{
private:
    struct btr{
        T label;
        int left,right,parent;
    };
    btr el[MAXB];
    int empty;
public:
    typedef int node;
    static node lambda = -1;

    BST(){
        for(int i = 0; i<MAXB-1; i++){
            el[i].parent = i+1;
        }
        el[MAXB-1].parent = lambda;
        empty = 0;
    }
    BST(T x){
        el[0].label = x;
        el[0].parent = el[0].left = el[0].right = lambda;
        for(int i = 1; i<MAXB-1; i++){
            el[i].parent = i+1;
        }
        el[MAXB-1].parent = lambda;
        empty = 0;
    }

    bool isEmpty(){
        return empty == 0;
    }

    T Root(){
        return empty == 0 ? lambda : 0;
    }

    T Label(node n){
        if(n == lambda){
            std::cout << "Nepostojeci";
        }else{
            return el[n].label;
        }
    }

    bool isNode(T x){
        node p = 0;
        while(p != lambda && Comp(el[p], x)){
            if(Comp(el[p], x) == 1){
                p = el[p].left;
            }else{
                p = el[p].right;
            }
        }
        return p != lambda;
    }

    T Min(){
        if(empty == 0){
            std::cout << "stablo je prazno";
        }
        node p = 0;
        while(el[p].left != lambda){
            p = el[p].left;
        }
        return el[p].label;
    }
    T Max(){
        if(empty == 0){
            std::cout << "stablo je prazno";
        }
        node p = 0;
        while(el[p].right != lambda){
            p = el[p].right;
        }
        return el[p].label;
    }

    void Insert(T x){
        if(empty == 0){
            el[0].label = x;
            el[0].parent = el[0].left = el[0].right = lambda;
            return;
        }
        node p = 0;
        bool next = true;
        do{
           if (Comp(el[p].label, x) == 1) {  // label > x -> lijevo
                if (el[p].left != lambda)
                    p = el[p].left;
                else
                    next = false;
            } else if (Comp(el[p].label, x) == -1) {  // label < x -> desno
                if (el[p].right != lambda)
                    p = el[p].right;
                else
                    next = false;
            } else {
                // x vec postoji, ne ubacuj duplikat
                return;
            }
        }while(next);

        int n = empty;
        empty = el[empty].parent;
        el[n].label = x;
        el[n].left = el[n].right = lambda;
        el[n].parent = p;

        if(Comp(el[p].label, x) == -1){
            el[p].right = n;
        }else{
            el[p].left = n;
        }
    }
};