#include "opcenito.h"
#include "../vjezba2/redpolje.h"
#include "../vjezba2/stogpolje.h"


// Option 1: Input with children count
// Format: n root [numChildren child1 child2 ...] for each node in BFS
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

// Option 2: Input with sentinel (-1 marks end of children)
// Format: root [child1 child2 ... -1] for each node in BFS
void popuniStabloSentinel(tree<int>& stablo){
    int vr; std::cin >> vr;
    stablo.CreateRoot(vr);
    queue<tree<int>::node> red;
    red.Enqueue(stablo.Root());
    
    while(!red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        
        std::cin >> vr;
        while(vr != -1){
            stablo.CreateChild(elem, vr);
            std::cin >> vr;
        }
        
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


// Calculate height of tree
int visinaStabla(tree<int>& stablo, tree<int>::node n){
    if(n == stablo.lambda) return 0;
    int maxVisina = 0;
    tree<int>::node dijete = stablo.FirstChild(n);
    while(dijete != stablo.lambda){
        int v = visinaStabla(stablo, dijete);
        if(v > maxVisina) maxVisina = v;
        dijete = stablo.NextSibling(dijete);
    }
    return maxVisina + 1;
}


// Print tree level by level with parent centered above children
void ispisStabla(tree<int>& stablo){
    int visina = visinaStabla(stablo, stablo.Root());
    
    queue<tree<int>::node> trenutnaRazina;
    queue<tree<int>::node> sljedecaRazina;
    
    trenutnaRazina.Enqueue(stablo.Root());
    int razina = 0;
    
    while(!trenutnaRazina.IsEmpty()){
        // Print leading spaces (more for higher levels)
        for(int i = 0; i < (visina - razina - 1) * 2; i++){
            std::cout << " ";
        }
        
        // Process current level
        while(!trenutnaRazina.IsEmpty()){
            auto elem = trenutnaRazina.Front();
            trenutnaRazina.Dequeue();
            
            std::cout << stablo.Label(elem);
            
            // Add spacing between nodes on same level
            for(int i = 0; i < (visina - razina) * 2; i++){
                std::cout << " ";
            }
            
            // Enqueue children for next level (left to right)
            Stack<tree<int>::node> pomocni;
            tree<int>::node dijete = stablo.FirstChild(elem);
            while(dijete != stablo.lambda){
                pomocni.Push(dijete);
                dijete = stablo.NextSibling(dijete);
            }
            while(!pomocni.isEmpty()){
                sljedecaRazina.Enqueue(pomocni.Top());
                pomocni.Pop();
            }
        }
        
        std::cout << std::endl;
        razina++;
        
        // Move to next level
        while(!sljedecaRazina.IsEmpty()){
            trenutnaRazina.Enqueue(sljedecaRazina.Front());
            sljedecaRazina.Dequeue();
        }
    }
}


int main(){
    int n; std::cin >> n;
    tree<int> stablo;
    popuniStablo(stablo, n);
    ispisStabla(stablo);
}


// cd /Users/mislavvusic/Desktop/strukturemat/vjezba4 && g++ -o 4 4.cpp && echo "11 4 3 7 6 8 2 2 8 0 1 5 1 3 1 1 2 9 2" | ./4