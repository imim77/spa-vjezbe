#include "bbbpokazivaci.h"
#include "../vjezba2/redpolje.h"

void PopuniStablo(btree<int>& stablo, int n){
    int x; std:: cin >> x;
    stablo.CreateRoot(x);

    if(n == 1) return;

    queue<btree<int>::node> red; 
    red.Enqueue(stablo.Root());
    int upisano = 1;
    while(upisano < n && !red.IsEmpty()){
        btree<int>::node trenutni = red.Front();
        red.Dequeue();
        if(upisano < n){
            std::cin >> x;
            stablo.CreateLeftChild(trenutni, x);
            red.Enqueue(stablo.LeftChild(trenutni));
            upisano++;
        }
        if(upisano < n) {
            std::cin >> x;
            stablo.CreateRightChild(trenutni, x);
            red.Enqueue(stablo.RightChild(trenutni));
            upisano++;
        }
    }
}

// Forward deklaracija
bool dfs(btree<int>& stablo, btree<int>::node left, btree<int>::node right);

bool jejeSimetricno(btree<int>& stablo, btree<int>::node n){
    return dfs(stablo, stablo.LeftChild(n), stablo.RightChild(n));
}

bool dfs(btree<int>& stablo, btree<int>::node left, btree<int>::node right){
    // Oba su prazna - simetrično
    if(left == stablo.lambda && right == stablo.lambda){
        return true;
    }
    // Jedan je prazan, drugi nije - nije simetrično
    if(left == stablo.lambda || right == stablo.lambda){
        return false;
    }
    // Provjeri su li oznake jednake i rekurzivno provjeri djecu
    // Za simetričnost: lijevo dijete lijevog čvora mora biti jednako desnom djetetu desnog čvora
    // i desno dijete lijevog čvora mora biti jednako lijevom djetetu desnog čvora
    return (stablo.Label(left) == stablo.Label(right) && 
            dfs(stablo, stablo.LeftChild(left), stablo.RightChild(right)) && 
            dfs(stablo, stablo.RightChild(left), stablo.LeftChild(right)));
}



int main(){
    int n; std::cin >> n;
    btree<int> stablo;
    PopuniStablo(stablo, n);
    bool rez = jejeSimetricno(stablo, stablo.Root());
    std::cout << rez;
    
}