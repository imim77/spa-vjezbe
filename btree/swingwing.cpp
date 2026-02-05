#include "btreepoknovi.h"
#include "../vjezba2/redpolje.h"




void popuniStablo(btree<int>& stablo, btree<int>::node n, int &i){
        if(i <= 0) return;

        if(i > 0 && stablo.LeftChild(n) == stablo.lambda){
            int vr; std::cin >> vr;
            stablo.CreateLeftChild(n,vr);
            i--;
            
        }
        popuniStablo(stablo, stablo.LeftChild(n), i);

        if(i > 0 && stablo.RightChild(n) == stablo.lambda){
            int vr; std::cin >> vr;
            stablo.CreateRightChild(n,vr);
            i--; 
        }
        popuniStablo(stablo, stablo.RightChild(n), i);
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

void ProcessNode(btree<int>& stablo, btree<int>::node n){
    std::cout << stablo.Label(n) << " ";
}


void Inorder(btree<int>& stablo, btree<int>::node n){
        if(stablo.LeftChild(n) != stablo.lambda){
            Inorder(stablo, stablo.LeftChild(n));
        }

        ProcessNode(stablo, n);

        if(stablo.RightChild(n) != stablo.lambda){
            Inorder(stablo, stablo.RightChild(n));
        }
}


btree<int>::node najmanjiZajednicki(btree<int>& stablo,btree<int>::node root,  btree<int>::node p, btree<int>::node q){
    if(root == stablo.lambda || root == p || root == q){
        return root;
    }
    btree<int>::node left = najmanjiZajednicki(stablo, stablo.LeftChild(root), p, q);
    btree<int>::node right = najmanjiZajednicki(stablo, stablo.RightChild(root), p, q);
    if(left != stablo.lambda && right != stablo.lambda){
        return root;
    }
    return (left != stablo.lambda) ? left : right;
}

// --- Pomoćna: nađi node po vrijednosti (prva po BFS-u) ---
btree<int>::node findByValue(btree<int>& stablo, int value){
    if(stablo.Root() == stablo.lambda) return stablo.lambda;

    queue<btree<int>::node> q;
    q.Enqueue(stablo.Root());

    while(!q.IsEmpty()){
        auto n = q.Front(); q.Dequeue();

        if(stablo.Label(n) == value) return n;

        if(stablo.LeftChild(n) != stablo.lambda)  q.Enqueue(stablo.LeftChild(n));
        if(stablo.RightChild(n) != stablo.lambda) q.Enqueue(stablo.RightChild(n));
    }
    return stablo.lambda;
}




int main(){
    int i; std::cin >> i;
    btree<int> stablo;
    popuniStabloV2(stablo, i);
    Inorder(stablo, stablo.Root());
    
    int vp, vq;
    std::cin >> vp >> vq;

    auto p = findByValue(stablo, vp);
    auto q = findByValue(stablo, vq);

    if(p == stablo.lambda || q == stablo.lambda){
        std::cout << "Ne postoji jedan od trazenih cvorova.\n";
        return 0;
    }

    auto lca = najmanjiZajednicki(stablo, stablo.Root(), p, q);
    if(lca == stablo.lambda){
        std::cout << "LCA nije pronaden.\n";
    } else {
        std::cout << "LCA: " << stablo.Label(lca) << "\n";
    }
}