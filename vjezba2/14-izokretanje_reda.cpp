#include "redpolje.h"
#include "stogpolje.h"

/*void OkreniRedRekurzija(queue<int>& red, Stack<int>& stog){
    if(red.IsEmpty()) return;
    stog.Push(red.Front());
    red.Dequeue();
    OkreniRedRekurzija(red,stog);
    std::cout << stog.Top() << " ";
    stog.Pop();
}
*/


void OkreniRedRekurzija(queue<int>& red){
    if(red.IsEmpty()) return;
    auto front = red.Front();
    red.Dequeue();
    OkreniRedRekurzija(red);
    red.Enqueue(front);
}


void OkreniRedIterativno(queue<int>& red){
    Stack<int> stog;
    while(!red.IsEmpty()){
        stog.Push(red.Front());
        red.Dequeue();
    }
    
    while(!stog.isEmpty()){
        std::cout << stog.Top() << " ";
        stog.Pop();
    }
}



int main(){
    queue<int> red;
    Stack<int> stog;
    int n; std::cin >> n;
    for(int i = 0; i<n; i++){
        int elem; std::cin >> elem;
        red.Enqueue(elem);
    }
    //OkreniRedIterativno(red);
    OkreniRedRekurzija(red);
    while(!red.IsEmpty()){
        std::cout << red.Front() << " ";
        red.Dequeue();
    }
}