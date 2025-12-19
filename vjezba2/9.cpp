#include "redpolje.h"

void sortiranje(queue<int>& red,queue<int>& red2, int k, int i){
    while(!red.IsEmpty()){
        int elem = red.Front();
        red.Dequeue();
        if(elem%k == i){
            red2.Enqueue(elem);
        }else{
            red.Enqueue(elem);
        }
    }
    sortiranje(red, red2, k, i++);
}


int main(){
    queue<int> red;
    queue<int> red2;
    int n; std::cin >> n;
    srand(time(0));
    for(int i=0; i<n; i++){
        red.Enqueue(rand()%10 +1);
    }
    int k; std::cin >> k;
    sortiranje(red,red2,k,0);

   



}