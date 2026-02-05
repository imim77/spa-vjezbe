#include "btreepoknovi.h"
#include "../vjezba2/redpolje.h"


// O(n) - svaki cvor se posjeti tocno jednom
void ispisi(btree<int>& stablo, btree<int>::node n, int level){
    if(n == stablo.lambda){
        return;
    }
    // 1. Lijevi potomci se ispisuju IZNAD cvora
    ispisi(stablo, stablo.LeftChild(n), level + 1);
    
    // 2. Ispred cvora ispisujemo tabulatore (onoliko kolika je razina)
    for(int i = 0; i < level; i++){
        std::cout << "\t";
    }
    std::cout << stablo.Label(n) << std::endl;
    
    // 3. Desni potomci se ispisuju ISPOD cvora
    ispisi(stablo, stablo.RightChild(n), level + 1);
}

void Process(btree<int>& stablo, btree<int>::node n){
    std::cout << stablo.Label(n) << " ";
}

void ophodnja(btree<int>& stablo, btree<int>::node n, int level){  
    if(stablo.LeftChild(n) != stablo.lambda){
        ophodnja(stablo, stablo.LeftChild(n), level+=1);
    } 
    Process(stablo, n);
    if(stablo.RightChild(n) != stablo.lambda){
        ophodnja(stablo, stablo.RightChild(n), level+=1);
    }
    
}

void Preorder(btree<int>& stablo){
    ophodnja(stablo, stablo.Root(), 0);
}

void popuniStabloV2(btree<int>& stablo, int n){
    if(n <= 0) return;

    int vr; std::cin >> vr;
    stablo.CreateRoot(vr);
    if(n == 1) return;
    queue<btree<int>::node> red;
    red.Enqueue(stablo.Root());
    int ucitano = 1;


    while(ucitano < n && !red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        if(ucitano < n){
            std::cin >> vr;
            stablo.CreateLeftChild(elem, vr);
            red.Enqueue(stablo.LeftChild(elem));
            ucitano++;
        }

        if(ucitano < n){
            std::cin >> vr;
            stablo.CreateRightChild(elem, vr);
            red.Enqueue(stablo.RightChild(elem));
            ucitano++;
        }

    }
}

int main(){
    int n; std::cin >> n;
    btree<int> stablo;
    popuniStabloV2(stablo, n);
    
    // Ispis stabla: lijevi iznad, desni ispod, tabulatori po razini
    ispisi(stablo, stablo.Root(), 0);
    
    return 0;
}