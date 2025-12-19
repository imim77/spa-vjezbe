#include <iostream>
#include <cstdlib>

void Merge(int i, int k, int j, int A[], int B[]){
    int I = i; int K = k+1; int J = i;
    while(I <= K && K <= j){
        if(A[I] <= A[K]){
            B[J++] = A[I++];
        }else{
            B[J++] = A[K++];
        }
    }
    if(K > J){
        while(I <= k){
            B[J++] = A[I++];
        }
    }else{
        while(K <= j){
            B[j++] = A[K++];
        }
    }
    for(int m=i; m <= j; m++){
        A[m] = B[m];
    }
}



void RMSort(int i,int j, int A[], int B[]){
    if(j-i > 0){
        int k = (i+j)/2;
        RMSort(i,k,A,B);
        RMSort(k+1,j,A,B);
        Merge(i,k,j,A,B);
        
    }
}


void MergeSort(int n, int A[]){
    int* B = new int [n];
    RMSort(0,n-1,A,B);
    delete []B;
}


int main(){
   
}