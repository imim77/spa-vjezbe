#include <iostream>
#include <cstdlib>
#include "../vjezba2/redpolje.h"
#include "../vjezba2/stogpolje.h"

template<typename T>
class triePok{
private:
    struct btr{
        T label;
        btr* child, *sibling, *parent;
    };

    btr* B;
public:
    typedef btr* node;
    const node lambda = NULL;

    triePok(){
        B = NULL;
    }

    triePok(T x){
        B = new btr;
        B->label = x;
        B->child = B->sibling = B->parent = NULL; 
    }

    bool isEmpty(){
        return B == NULL;
    }


    T Label(node n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->label;
        }
    }

    node Root(){
        return B;
    }

    node Parent(node n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->parent;
        }
    }

    node FirstChild(node n){ 
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->child;
        }
    }

    node NextSibling(node n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->sibling;
        }
    }

    void ChangeLebel(node n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            n->label = x;
        }
    }

    void CreateRoot(T x){
        if(B != NULL){
            std::cout << "Stablo već ima korijen" << std::endl;
            exit(EXIT_FAILURE);
        }else{
           B = new btr;
           B->label = x;
           B->child = B->sibling = B->parent = NULL;  
        }
    }

    
    void CreateChild(node n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            btr* novi = new btr; 
            novi->label = x;
            novi->parent = n;
            novi->child = lambda;
            novi->sibling = n->child;
            n->child = novi;
        }
    }
private:
    // Brise n i sve njegove potomke (siblinge i djecu rekurzivno)
    void Del(node n){
        if(n->sibling != lambda){
            Del(n->sibling);
        }
        if(n->child != lambda){
            Del(n->child);
        }
        delete n;
    }
    

public:
    // Delete - only works for leaves, error if node has children
    void Delete(node n){
        if(n == lambda){
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        // Check if leaf (no children)
        if(n->child != lambda){
            std::cout << "Cvor nije list" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        // Unlink from parent's children list
        if(n->parent != lambda){
            if(n->parent->child == n){
                // n is first child
                n->parent->child = n->sibling;
            }
            else {
                // Find previous sibling
                node prev = n->parent->child;
                while(prev->sibling != n){
                    prev = prev->sibling;
                }
                prev->sibling = n->sibling;
            }
        }
        else {
            // n is root
            B = NULL;
        }
        
        delete n;
    }

    void DisposeT(){
        if(B != NULL){
            Del(B);
            B = NULL;
        }
    }

    ~triePok(){
        if(B != lambda){
            Del(B);
        }
    }
};


typedef triePok<int> tree;


void popuniStablo(tree& stablo, int n){
    int vr; std::cin >> vr;
    stablo.CreateRoot(vr);
    queue<tree::node> red;
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
        tree::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda){
            red.Enqueue(dijete);
            dijete = stablo.NextSibling(dijete);
        }
    }
}


bool isLeaf(tree& stablo, tree::node n) {
    return stablo.FirstChild(n) == stablo.lambda;
}


// Collect all original leaves
void collectLeaves(tree& stablo, tree::node n, tree::node leaves[], int& count) {
    if (n == stablo.lambda) return;
    
    if (isLeaf(stablo, n)) {
        leaves[count++] = n;
    }
    
    tree::node dijete = stablo.FirstChild(n);
    while(dijete != stablo.lambda) {
        tree::node next = stablo.NextSibling(dijete);
        collectLeaves(stablo, dijete, leaves, count);
        dijete = next;
    }
}


// Check if node is in original leaves array
bool isOriginalLeaf(tree::node n, tree::node leaves[], int count) {
    for(int i = 0; i < count; i++) {
        if(leaves[i] == n) return true;
    }
    return false;
}


// Delete all original leaves
void deleteOriginalLeaves(tree& stablo, tree::node originalLeaves[], int leafCount) {
    for(int i = 0; i < leafCount; i++) {
        tree::node leaf = originalLeaves[i];
        // Check if still a leaf and exists
        if(leaf != stablo.lambda && isLeaf(stablo, leaf) && leaf != stablo.Root()) {
            stablo.Delete(leaf);
        }
    }
}


void preorderPrint(tree& stablo, tree::node n) {
    if (n == stablo.lambda) return;
    
    std::cout << stablo.Label(n) << " ";
    
    tree::node dijete = stablo.FirstChild(n);
    while(dijete != stablo.lambda) {
        preorderPrint(stablo, dijete);
        dijete = stablo.NextSibling(dijete);
    }
}


void levelorderPrint(tree& stablo) {
    queue<tree::node> red;
    red.Enqueue(stablo.Root());
    
    while(!red.IsEmpty()) {
        tree::node elem = red.Front();
        red.Dequeue();
        
        std::cout << stablo.Label(elem) << " ";
        
        tree::node dijete = stablo.FirstChild(elem);
        while(dijete != stablo.lambda) {
            red.Enqueue(dijete);
            dijete = stablo.NextSibling(dijete);
        }
    }
}


int main(){
    int n; std::cin >> n;
    tree stablo;
    popuniStablo(stablo, n);
    
    // Print level order (BFS)
    std::cout << "Levelorder: ";
    levelorderPrint(stablo);
    std::cout << std::endl;
    
    // Print preorder
    std::cout << "Preorder: ";
    preorderPrint(stablo, stablo.Root());
    std::cout << std::endl;
    
    return 0;
}