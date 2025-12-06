#include <iostream>
#include <cstdlib>

//MJEHURIČASTO SORTIRANJE
void BubbleSort(int n, int A[]){
    int pom;
    bool ex = true;
    for(int i = n-1; i > 0 && ex; i--){
        ex = false;
        for(int j = 0; j<i; j++){
            if(A[j] > A[j+1]){
                pom = A[j];
                A[j] = A[j+1];
                A[j+1] = pom;
                ex = true;
            }
        }
    }
}

// SORTIRANJE ZAMJENOM
void ExchagneSort(int n, int A[]){
    int pom;
    for(int i=n-1; i> 0; i--){
        for(int j=0; j<i; j++){
            if(A[j] > A[i]){
                pom = A[j];
                A[j] = A[i];
                A[i] = pom;
            }
        }
    }
}

//SORTIRANJE IZBOROM
void SelectionSort(int n, int A[]){
    int pom, max;
    for(int i=n-1; i>0; i--){
        max = 0;
        for(int j=1; j<i; j++){
            if(A[j] > A[max]){
                max = j;
            }
        }
        if(max != i){
            pom = A[max];
            A[max] = A[i];
            A[i] = pom;
        }

        
    }
}

//SORTIRAJNE UMETANJEM

void InsertionSort(int n, int A[]){
    int pom, j;
    for(int i=1; i<n; i++){
        pom = A[i];
        j = i-1;
        while(j>= 0 && A[j] > pom){
            A[j+1] = A[j--];
        }
        A[j+1] = pom;
    }
}



int main(){
    int a[] = {5,23,12,59,7,5,77};
    int velicina = sizeof(a)/sizeof(int);
    BubbleSort(velicina,a);
    
}