#include <iostream>
#include "bstkursori.h"

using namespace std;

int main() {
    BST<int> stablo;
    int n;
    
    cout << "Unesite broj cvorova: ";
    cin >> n;
    
    cout << "Unesite " << n << " vrijednosti: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stablo.Insert(x);
    }
    
    cout << "Sortirano: ";
    stablo.InorderPrint();
    cout << endl;
    
    return 0;
}
