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
        // Enqueue children in left-to-right order
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


bool imaJednoDijete(tree<int>& stablo, tree<int>::node n){
    tree<int>::node dijete = stablo.FirstChild(n);
    // Has exactly one child if: FirstChild exists AND it has no siblings
    return dijete != stablo.lambda && stablo.NextSibling(dijete) == stablo.lambda;
}


void ispisCvoroviJednoDijetePreorder(tree<int>& stablo){
    Stack<tree<int>::node> stog;
    stog.Push(stablo.Root());
    
    while(!stog.isEmpty()){
        auto elem = stog.Top();
        stog.Pop();
        
        // Check if node has exactly one child
        if(imaJednoDijete(stablo, elem)){
            std::cout << stablo.Label(elem) << " ";
        }
        
        // Push children directly (rightmost first due to CreateChild, so leftmost ends on top)
        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            stog.Push(dijete);
            dijete = stablo.NextSibling(dijete);
        }
    }
}


void ispisCvoroviJednoDijeteLevelorder(tree<int>& stablo){
    queue<tree<int>::node> red;
    red.Enqueue(stablo.Root());
    
    while(!red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        
        // Check if node has exactly one child
        if(imaJednoDijete(stablo, elem)){
            std::cout << stablo.Label(elem) << " ";
        }
        
        // Enqueue children in left-to-right order (reverse because CreateChild stores right-to-left)
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




int main(){
    int n; std::cin >> n;
    tree<int> stablo;
    popuniStablo(stablo, n);
    //ispisCvoroviJednoDijetePreorder(stablo);
    ispisCvoroviJednoDijeteLevelorder(stablo);
}