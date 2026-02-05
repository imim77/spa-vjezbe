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


bool isLeaf(tree<int>& stablo, tree<int>::node n) {
    return stablo.FirstChild(n) == stablo.lambda;
}


// Collect all original leaves into an array
void collectOriginalLeaves(tree<int>& stablo, tree<int>::node n, 
                           tree<int>::node leaves[], int& count) {
    if (n == stablo.lambda) return;
    
    if (isLeaf(stablo, n)) {
        leaves[count++] = n;
    }
    
    tree<int>::node dijete = stablo.FirstChild(n);
    while(dijete != stablo.lambda) {
        collectOriginalLeaves(stablo, dijete, leaves, count);
        dijete = stablo.NextSibling(dijete);
    }
}


// Check if node is in original leaves array
bool isOriginalLeaf(tree<int>::node n, tree<int>::node leaves[], int count) {
    for(int i = 0; i < count; i++) {
        if(leaves[i] == n) return true;
    }
    return false;
}


// Delete all original leaves (only those that can be safely deleted)
void deleteOriginalLeaves(tree<int>& stablo, tree<int>::node originalLeaves[], int leafCount) {
    bool deleted = true;
    while(deleted) {
        deleted = false;
        
        Stack<tree<int>::node> stog;
        stog.Push(stablo.Root());
        
        while(!stog.isEmpty()) {
            tree<int>::node curr = stog.Top();
            stog.Pop();
            
            // Check if deletable: is leaf, no next sibling, was original leaf, not root
            if(curr != stablo.Root() && 
               isLeaf(stablo, curr) && 
               stablo.NextSibling(curr) == stablo.lambda &&
               isOriginalLeaf(curr, originalLeaves, leafCount)) {
                stablo.Delete(curr);
                deleted = true;
                break;
            }
            
            tree<int>::node dijete = stablo.FirstChild(curr);
            while(dijete != stablo.lambda) {
                stog.Push(dijete);
                dijete = stablo.NextSibling(dijete);
            }
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
    
    // Collect original leaves
    tree<int>::node originalLeaves[1000];
    int leafCount = 0;
    collectOriginalLeaves(stablo, stablo.Root(), originalLeaves, leafCount);
    
    // Delete original leaves
    deleteOriginalLeaves(stablo, originalLeaves, leafCount);
    
    // Print preorder
    preorderPrint(stablo, stablo.Root());
}
