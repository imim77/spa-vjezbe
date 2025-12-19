#include "stogpolje.h"


/*int sastogom(int n, int k){
    Stack<int> stog;
    while(!stog.isEmpty()){
        if(k == 0 || n == k){
            return 1;
        }

    }
}
*/

struct Frame{
    int n;
    int k;
    int stage;   // 0 = tek ušli, 1 = lijevo dijete gotovo, čeka desno, 2 = kombiniranje
    int value;   // rezultat lijevog djeteta
};

int binomniStog(int n, int k){
   Stack<Frame> stog;
   stog.Push({n, k, 0, 0});

   int lastResult = 0;  // rezultat zadnjeg dovršenog \"rekurzivnog\" poziva

   while(!stog.isEmpty()){
        Frame f = stog.Top();
        stog.Pop();

        // Baza rekurzije: C(n,0) = C(n,n) = 1
        if(f.k == 0 || f.n == f.k){
            lastResult = 1;
            continue;
        }

        if(f.stage == 0){
            // tek ušli u C(n,k): prvo računamo lijevo dijete C(n-1,k-1)
            f.stage = 1;
            stog.Push(f);                         // vratit ćemo se na ovaj frame nakon lijevog djeteta
            stog.Push({f.n - 1, f.k - 1, 0, 0});  // lijevo dijete
            continue;
        }

        if(f.stage == 1){
            // upravo smo završili lijevo dijete; njegov rezultat je u lastResult
            f.value = lastResult;                 // spremi C(n-1,k-1)
            f.stage = 2;
            stog.Push(f);                         // vratimo se nakon desnog djeteta
            stog.Push({f.n - 1, f.k, 0, 0});      // desno dijete C(n-1,k)
            continue;
        }

        // stage == 2: završili smo desno dijete; lastResult = C(n-1,k)
        // a f.value = C(n-1,k-1); sada kombiniramo
        lastResult = f.value + lastResult;        // C(n,k)
   }

   return lastResult;
}


int binomniBezStoga(int n, int k){
    long int rez = 1;
    if(k > n-k){
        k = n-k;
    }
    for(int i=0; i<k; ++i){
        rez *= (n-i);
        rez /= (i+1);
    }
    return rez;
}

int binomni(int n, int k){
    if(k == 0 || n == k){
        return 1;
    }
    return binomni(n-1, k-1) + binomni(n-1, k);
}


int main(){
    int n,k;
    std::cin >> n;
    std::cin >> k;
    //int rez = binomni(n,k);q
    //int rez = binomniStog(n,k);
    int rez = binomniBezStoga(n,k);
    std::cout << rez;
    /*if(k > n){
        std::cout << "Pogreška k ne smije biti veći od n";
        exit(EXIT_FAILURE);
    }
    */


}