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
        
        // Read children into stack, then add in reverse (leftmost becomes FirstChild)
        Stack<int> djeca;
        for(int i = 0; i < brDjece && upisano + i < n; i++){
            std::cin >> vr;
            djeca.Push(vr);
        }
        while(!djeca.isEmpty() && upisano < n){
            stablo.CreateChild(elem, djeca.Top());
            djeca.Pop();
            upisano++;
        }
        
        // Enqueue children left-to-right
        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            red.Enqueue(dijete);
            dijete = stablo.NextSibling(dijete);
        }
    }
}


// Bottom-up levelorder: last level first (left-to-right), then second-to-last, etc.
void bottomUpLevelorder(tree<int>& stablo){
    queue<tree<int>::node> red;
    Stack<tree<int>::node> stog;
    red.Enqueue(stablo.Root());

    while(!red.IsEmpty()){
        auto elem = red.Front();
        red.Dequeue();
        stog.Push(elem);
        
        // Enqueue children right-to-left (so when reversed, it's left-to-right)
        // Since CreateChild prepends, FirstChild is leftmost, so we need to reverse
        Stack<tree<int>::node> pomocni;
        tree<int>::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            pomocni.Push(dijete);
            dijete = stablo.NextSibling(dijete);
        }
        // Pop from pomocni to enqueue (reverses to right-to-left)
        while(!pomocni.isEmpty()){
            red.Enqueue(pomocni.Top());
            pomocni.Pop();
        }
    }
    
    // Pop from stack: gives bottom-up, left-to-right within levels
    while(!stog.isEmpty()){
        auto elem = stog.Top();
        std::cout << stablo.Label(elem) << " ";
        stog.Pop();
    }
}


int main(){
    int n; std::cin >> n;
    tree<int> stablo;
    popuniStablo(stablo, n);
    bottomUpLevelorder(stablo);
}

// cd /Users/mislavvusic/Desktop/strukturemat/vjezba4 && g++ -o 8 8.cpp && echo "11 4 3 7 6 8 2 2 8 0 1 5 1 3 1 1 2 9 2" | ./8