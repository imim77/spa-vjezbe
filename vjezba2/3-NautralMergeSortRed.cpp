#include <iostream>
#include "vjezba2/redpolje.h"

void NaturalMergeSort(int n, int A[]){
    int* B = new int[n];

    bool sorted = false;
    while(!sorted){
        sorted = true;
        int i = 0;      // indeks u ulaznom polju A
        int out = 0;    // indeks za upis u pomoćno polje B

        while(i < n){
            queue<int> red;   // red za prvu rastuću sekvencu

            // 1) Učitaj prvu rastuću sekvencu u red
            red.Enqueue(A[i]);
            i++;
            while(i < n && A[i] >= A[i-1]){
                red.Enqueue(A[i]);
                i++;
            }

            // 2) Ako smo na kraju polja, nema druge sekvence za spajanje
            if(i >= n){
                // samo prepiši sadržaj reda u B
                while(!red.IsEmpty()){
                    B[out++] = red.Front();
                    red.Dequeue();
                }
                // jedna sekvenca u ovom prolazu → ako se to dogodi za cijelo polje, polje je sortirano
                break;
            }

            // 3) Inače, pročitaj sljedeću rastuću sekvencu iz A kao drugu sekvencu
            int start2 = i;
            while(i < n && (i == start2 || A[i] >= A[i-1])){
                i++;
            }
            int end2 = i; // druga sekvenca je A[start2 .. end2-1]

            sorted = false; // imamo barem dvije sekvence, polje još nije potpuno sortirano

            // 4) Spoji sekvencu u redu (1. sekvenca) i A[start2..end2-1] (2. sekvenca) u B
            int k = start2;
            while(!red.IsEmpty() && k < end2){
                if(red.Front() <= A[k]){
                    B[out++] = red.Front();
                    red.Dequeue();
                }else{
                    B[out++] = A[k++];
                }
            }

            // dokrajči ostatke
            while(!red.IsEmpty()){
                B[out++] = red.Front();
                red.Dequeue();
            }
            while(k < end2){
                B[out++] = A[k++];
            }
        }

        // 5) Prebaci sadržaj iz pomoćnog niza natrag u ulazni
        for(int t = 0; t < n; ++t){
            A[t] = B[t];
        }
    }

    delete [] B;
}




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