#include "stogpolje.h"

struct FrameIter {
    int i;
    int n;
    int k;
    long long rez;
};

long long binomniStog_ON(int n, int k) {
    if (k > n - k) k = n - k;   // simetričnost

    Stack<FrameIter> stog;
    stog.Push({0, n, k, 1});    // start: i=0, rez=1

    long long lastResult = 0;

    while (!stog.isEmpty()) {
        FrameIter f = stog.Top();
        stog.Pop();

        if (f.i == f.k) {       // gotovi smo
            lastResult = f.rez;
            continue;
        }

        // jedan korak petlje: rez *= (n-i); rez /= (i+1);
        f.rez *= (f.n - f.i);
        f.rez /= (f.i + 1);
        f.i++;

        stog.Push(f);           // vratimo natrag ažurirani frame
    }

    return lastResult;
}


int main(){
    int n,k;
    std::cin >> n;
    std::cin >> k;
    int rez = binomniStog_ON(n,k);
    std::cout << rez;
    /*if(k > n){
        std::cout << "Pogreška k ne smije biti veći od n";
        exit(EXIT_FAILURE);
    }
    */


}