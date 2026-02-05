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
        
        // Read children into stack first, then add in reverse (so FirstChild = leftmost)
        Stack<int> djeca;
        for(int i = 0; i < brDjece && upisano + i < n; i++){
            std::cin >> vr;
            djeca.Push(vr);
        }
        // Add children in reverse order so leftmost becomes FirstChild
        int added = 0;
        while(!djeca.isEmpty() && upisano < n){
            stablo.CreateChild(elem, djeca.Top());
            djeca.Pop();
            upisano++;
            added++;
        }
        
        // Enqueue children (now in left-to-right order via FirstChild/NextSibling)
        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            red.Enqueue(dijete);
            dijete = stablo.NextSibling(dijete);
        }
    }
}


void ispisStabla(tree<int>& stablo, tree<int>::node n, int level){
    if(n == stablo.lambda) return;
    
    // Print indentation (tabs for current level)
    for(int i = 0; i < level; i++){
        std::cout << "\t";
    }
    
    // Print this node and follow FirstChild path on same line
    tree<int>::node current = n;
    while(current != stablo.lambda){
        std::cout << stablo.Label(current);
        if(stablo.FirstChild(current) != stablo.lambda){
            std::cout << "\t";
        }
        current = stablo.FirstChild(current);
    }
    std::cout << std::endl;
    
    // Process siblings of nodes along the FirstChild path
    current = n;
    int depth = level;
    while(current != stablo.lambda){
        tree<int>::node child = stablo.FirstChild(current);
        if(child != stablo.lambda){
            // Process siblings of the first child (next brothers)
            tree<int>::node sibling = stablo.NextSibling(child);
            while(sibling != stablo.lambda){
                ispisStabla(stablo, sibling, depth + 1);
                sibling = stablo.NextSibling(sibling);
            }
        }
        current = stablo.FirstChild(current);
        depth++;
    }
}


int main(){
    int n; std::cin >> n;
    tree<int> stablo;
    popuniStablo(stablo, n);
    ispisStabla(stablo, stablo.Root(), 0);
}

// cd /Users/mislavvusic/Desktop/strukturemat/vjezba4 && g++ -o 7 7.cpp && echo "11 4 3 7 6 8 2 2 8 0 1 5 1 3 1 1 2 9 2" | ./7