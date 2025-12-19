#include <iostream>
#include <cstdlib>
#include "stogpolje.h"
/*void printRange(const char* msg, int A[], int i, int j){
    std::cout << msg << " [";
    for(int k = i; k <= j; k++){
        std::cout << A[k];
        if(k < j) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
*/

struct Frame{
    int i,j,k;
    int state;
};


void Merge(int i,int k, int j, int A[], int B[]){
    int I = i; int K = k+1; int J=i;
    while(I <= k && K<=j){
        if(A[I] <= A[K]){
            B[J++] = A[I++];
        }else{
            B[J++] = A[K++];
        }
    }

    if(K > j){
        while(I <= k){
            B[J++] = A[I++];
        }
    }else{
        while(K <= j){
            B[J++] = A[K++];
        }
    }

    for(int m=i; m<=j; m++){
        A[m] = B[m];
    }

    //printRange(" Rezultat", A,i,j);
}




void RMSort(int i, int j, int A[], int B[]){
    Stack<Frame> stog;
    stog.Push({i,j,0,0});
    while(!stog.isEmpty()){
        Frame f = stog.Top();  // kopija, ne referenca
        stog.Pop();              // ukloni stari element
        
        if(f.i >= f.j){
            continue;            // segment veličine 1 ili manje je već sortiran
        }
        
        if(f.state == 0){
            f.k = (f.j+f.i)/2;
            f.state = 1;
            stog.Push(f);        // vrati ažurirani frame na stog
            stog.Push({f.i,f.k,0,0});  // lijevo dijete
        }else if(f.state == 1){
            f.state = 2;
            stog.Push(f);        // vrati ažurirani frame na stog
            stog.Push({f.k+1,f.j, 0,0});  // desno dijete
        }else{
            Merge(f.i,f.k,f.j,A,B);
            // frame je obrađen, ne vraćamo ga na stog
        }

    }
}


void MergeSort(int n, int A[]){
    int* B = new int [n];
    RMSort(0,n-1,A,B);
    delete []B;
    
}


int main(){
    int A[] = {7, 3, 5, 2, 6, 1, 4};
    int n = sizeof(A) / sizeof(int);

    std::cout << "POCETNI NIZ: ";
    for(int i = 0; i < n; i++){
        std::cout << A[i] << " ";
    }
    std::cout << "\n\n";

    MergeSort(n, A);

    std::cout << "\nKONACNI NIZ: ";
    for(int i = 0; i < n; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}