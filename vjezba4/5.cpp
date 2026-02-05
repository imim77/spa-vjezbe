#include "opcenito.h"
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
        // Enqueue children left-to-right
        Stack<tree<int>::node> pomocni;
        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            pomocni.Push(dijete);
            dijete = stablo.NextSibling(dijete);
        }
        while(!pomocni.isEmpty()){
            red.Enqueue(pomocni.Top());
            pomocni.Pop();
        }
    }
}

void DFS(tree<int>& stablo){
    Stack<tree<int>::node> stog;
    Stack<tree<int>::node> rezultat;
    stog.Push(stablo.Root());
    while(!stog.isEmpty()){
        auto elem = stog.Top();
        stog.Pop();
        rezultat.Push(elem);
        
        // Push children in left-to-right order (reverse because FirstChild returns rightmost)
        Stack<tree<int>::node> pomocni;
        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            pomocni.Push(dijete);
            dijete = stablo.NextSibling(dijete);
        }
        while(!pomocni.isEmpty()){
            stog.Push(pomocni.Top());
            pomocni.Pop();
        }
    }
    while(!rezultat.isEmpty()){
        std::cout << stablo.Label(rezultat.Top()) << " ";
        rezultat.Pop();
    }
}


int main(){
    int n; std::cin >> n;
    tree<int> stablo;
    popuniStablo(stablo, n);
    DFS(stablo);
}