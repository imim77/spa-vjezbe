#include <iostream>
#include <cstdlib>

void NaturalMergeSort(int n, int A[]){
    int* B = new int[n];
    int i,j,k, noseq;
    do{
        noseq = 0;
        i = 0;
        while(i<n){
            j = i;
            while(j< n && (j == i || A[j] >= A[j-1])){
                B[j] = A[j];
                j++;
            }
            if(j<n){
                int I = i;
                k = j;
                while(i<j && (k == j || A[k]>=A[k-1]) && k<n){
                    if(B[i] < A[k]){
                        A[I++] = B[i++];
                    }else{
                        A[I++] = A[k++];
                    }
                }
                if(i<j){
                    while(i<j){
                        A[I++] = B[i++];
                    }
                }else{
                    while(k == j || A[k] >= A[k-1]){
                        k++;
                    }
                    noseq++;
                }
                i = k;
            }else{
                noseq++;
                i=j;
            }
        }
    }while(noseq>1);
    delete []B;    
};




void printArray(const char* msg, int A[], int n){
    std::cout << msg;
    for(int i = 0; i < n; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    // TEST 1: već sortiran niz
    int A1[] ={2, 5, 7, 1, 3, 6, 4, 8};;
    int n1 = sizeof(A1) / sizeof(int);

    printArray("Test 1 - prije: ", A1, n1);
    NaturalMergeSort(n1, A1);
    printArray("Test 1 - poslije: ", A1, n1);
    std::cout << std::endl;

   
}