#include "opcenitobtree.h"
#include "../vjezba2/redpolje.h"
#include "../vjezba2/stogpolje.h"

void popuniStablo(tree<int>& stablo, int n){
    int vr; std::cin >> vr;
    stablo.CreateRoot(vr);
    queue<tree<int>::node> red;
    red.Enqueue(stablo.Root());
    int upisano = 1;
    while(upisano < n && !red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        int brDjece; std::cin >> brDjece;
        for(int i = 0; i < brDjece && upisano < n; i++){
            std::cin >> vr;
            stablo.CreateChild(elem, vr);
            upisano++;
        }
        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            red.Enqueue(dijete);
            dijete = stablo.NextSibling(dijete);
        }
    }
}

void preorderPrint(tree<int>& stablo, tree<int>::node n) {
    if (n == stablo.lambda) return;
    std::cout << stablo.Label(n) << " ";
    tree<int>::node dijete = stablo.FirstChild(n);
    while(dijete != stablo.lambda) {
        preorderPrint(stablo, dijete);
        dijete = stablo.NextSibling(dijete);
    }
}

int main() {
    int n; std::cin >> n;
    tree<int> stablo;
    popuniStablo(stablo, n);
    std::cout << "Full tree: ";
    preorderPrint(stablo, stablo.Root());
    std::cout << std::endl;
}
