#include <iostream>
#include "btreepoknovi.h" // Koristimo implementaciju binarnog stabla pomocu pokazivaca

using namespace std;

// Funkcija za umetanje elementa u stablo tako da se postuje BST svojstvo
// Koristimo samo ATP operacije: Root, LeftChild, RightChild, Label, CreateRoot, CreateLeftChild, CreateRightChild
void UmetniUBST(btree<int>& stablo, int x) {
    // Ako je stablo prazno, kreiraj korijen
    if (stablo.IsEmpty()) {
        stablo.CreateRoot(x);
        return;
    }

    // Inace trazi mjesto za umetanje
    btree<int>::node trenutni = stablo.Root();
    bool ubacen = false;

    while (!ubacen) {
        if (x < stablo.Label(trenutni)) {
            // Idi lijevo
            if (stablo.LeftChild(trenutni) == stablo.lambda) {
                // Ako nema lijevog djeteta, kreiraj ga
                stablo.CreateLeftChild(trenutni, x);
                ubacen = true;
            } else {
                // Ako ima, nastavi pretragu lijevo
                trenutni = stablo.LeftChild(trenutni);
            }
        } else {
            // Idi desno (x >= label)
            if (stablo.RightChild(trenutni) == stablo.lambda) {
                // Ako nema desnog djeteta, kreiraj ga
                stablo.CreateRightChild(trenutni, x);
                ubacen = true;
            } else {
                // Ako ima, nastavi pretragu desno
                trenutni = stablo.RightChild(trenutni);
            }
        }
    }
}

// InOrder obilazak (Lijevo - Korijen - Desno) koji vraca sortirane elemente u polje
void InOrderToField(btree<int>& stablo, btree<int>::node n, int a[], int& index) {
    if (n == stablo.lambda) return;

    // 1. Obidi lijevo podstablo
    if (stablo.LeftChild(n) != stablo.lambda) {
        InOrderToField(stablo, stablo.LeftChild(n), a, index);
    }

    // 2. Obradi trenutni cvor (zapisi u polje)
    a[index++] = stablo.Label(n);

    // 3. Obidi desno podstablo
    if (stablo.RightChild(n) != stablo.lambda) {
        InOrderToField(stablo, stablo.RightChild(n), a, index);
    }
}

// Glavna funkcija za sortiranje
void BSTSort(int a[], int n) {
    btree<int> stablo;

    // 1. Ubaci sve elemente iz polja u BST
    for (int i = 0; i < n; i++) {
        UmetniUBST(stablo, a[i]);
    }

    // 2. Vrati elemente iz stabla u polje (InOrder obilaskom)
    int index = 0;
    InOrderToField(stablo, stablo.Root(), a, index);
    
    // Stablo ce se automatski obrisati kad izade iz scope-a (destruktor)
}

int main() {
    int n;
    cout << "Unesite broj elemenata: ";
    cin >> n;

    int* a = new int[n];
    cout << "Unesite " << n << " elemenata: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sortiranje
    BSTSort(a, n);

    cout << "Sortirano polje: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}

/*
 * ANALIZA SLOZENOSTI:
 * 
 * 1. Umetanje (Insert):
 *    - Umetanje jednog elementa u BST traje O(h), gdje je h visina stabla.
 *    - Za n elemenata:
 *      - Najbolji slucaj (balansirano stablo): h = log n -> Ukupno O(n log n)
 *      - Najgori slucaj (stablo degenerira u listu, npr. sortirani ulaz): h = n -> Ukupno O(n^2)
 * 
 * 2. Obilazak (InOrder):
 *    - Posjecujemo svaki cvor tocno jednom.
 *    - Slozenost: O(n)
 * 
 * UKUPNA SLOZENOST:
 * - O(n^2) u najgorem slucaju (worst-case)
 * - O(n log n) u prosjecnom/najboljem slucaju
 */
