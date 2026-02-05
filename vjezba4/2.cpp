#include "opcenito.h"
#include "../vjezba2/redpolje.h"



void popuniStablo(tree<int>& stablo, int n){
    int vr; std::cin >> vr;
    stablo.CreateRoot(vr);
    queue<tree<int>::node> red;
    red.Enqueue(stablo.Root());
    int upisano = 0;
    while(upisano < n && !red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        std::cin >> vr;
        stablo.CreateChild(elem, vr);
        red.Enqueue(stablo.FirstChild(elem));
        upisano++;
    }
    
}


void obradiStablo(tree<int>& stablo){
    queue<tree<int>::node> red;
    red.Enqueue(stablo.Root());

    while(!red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        std::cout << stablo.Label(elem) << " ";

        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            red.Enqueue(dijete);
            dijete = stablo.NextSibling(dijete);
        }
    }
}



int main(){
    int n; std::cin >> n;
    tree<int> stablo;
    popuniStablo(stablo,n);
    obradiStablo(stablo);

}