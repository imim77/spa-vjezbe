//#include "btreepolje.h"
#include "bbbpokazivaci.h"
#include <queue>

//void popuniBinarnoStablo(int n){
    //btree<int> binaryTree; 
    //for(int i=1; i<=n; i++){
        //if(i == 1){
            //binaryTree.CreateRoot(i);
            //binaryTree.CreateLeftChild(binaryTree.Root(),2*i);
            //binaryTree.CreateRightChild(binaryTree.Root(), 2*i+1);
            //continue;
        //}else{
            //std::cout << "Za mene(i): " << i << "parent mi je: " << binaryTree.Parent(i) << std::endl;
            //binaryTree.CreateLeftChild(binaryTree.Parent(i), 2*i);
            //binaryTree.CreateRightChild(binaryTree.Parent(i), 2*i+1);
        //}
    //}
    
//}





// Create a complete binary tree with labels 1..n (level-order, left-to-right)
void popuniStablo(btree<int>& stablo, int n);


void Process(btree<int>& stablo, btree<int>::node n){
    std::cout << stablo.Label(n) << " ";
}

void ophodnja(btree<int>& stablo, btree<int>::node n){ 
    Process(stablo, n);
    if(stablo.LeftChild(n) != stablo.lambda){
        ophodnja(stablo, stablo.LeftChild(n));
    } 
    if(stablo.RightChild(n) != stablo.lambda){
        ophodnja(stablo, stablo.RightChild(n));
    }
    
}

void Preorder(btree<int>& stablo){
    ophodnja(stablo, stablo.Root());
}


void popuniStablo(btree<int>& stablo, int n){
    if(n <= 0) return;
    stablo.CreateRoot(1);
    if(n == 1) return;

    std::queue<btree<int>::node> q;
    q.push(stablo.Root());
    int nextLabel = 2;

    while(nextLabel <= n){
        auto parent = q.front();

        if(stablo.LeftChild(parent) == stablo.lambda){
            stablo.CreateLeftChild(parent, 2*nextLabel);
            q.push(stablo.LeftChild(parent));
            ++nextLabel;
            if(nextLabel > n) break;
        }

        if(stablo.RightChild(parent) == stablo.lambda){
            stablo.CreateRightChild(parent, 2*nextLabel+1);
            q.push(stablo.RightChild(parent));
            ++nextLabel;
            if(nextLabel > n) break;
        }

        q.pop();
    }
}



int main(){
    int n; std::cout << "n: "; std::cin >> n;    
    btree<int> stablo; 
    popuniStablo(stablo, n);
    Preorder(stablo);
    
    //popuniBinarnoStablo(n);
    //PrO(B,B.Root());
}