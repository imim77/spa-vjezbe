#include <iostream>
#include <cstdlib>

#ifndef MAXB
#define MAXB 1000
#endif

#ifndef Comp
#define Comp(a,b) (a < b ? -1 : (a == b ? 0 : 1))
#endif

template <typename nodetype>
class BST {
private:
    struct btr {
        nodetype label;
        int parent, left, right;
    };

    btr el[MAXB];
    int empty;

public:
    typedef int node;
    const node lambda = -1;

    // Konstruktor - prazno stablo
    BST() {
        for (int i = 0; i < MAXB - 1; i++)
            el[i].parent = i + 1;
        el[MAXB - 1].parent = lambda;
        empty = 0;
    }

    // Konstruktor s korijenom
    BST(nodetype x) {
        el[0].label = x;
        el[0].parent = el[0].left = el[0].right = lambda;
        for (int i = 1; i < MAXB - 1; i++)
            el[i].parent = i + 1;
        el[MAXB - 1].parent = lambda;
        empty = 1;
    }

    bool isEmpty() {
        return empty == 0;
    }

    node Root() {
        return empty == 0 ? lambda : 0;
    }

    nodetype Label(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        return el[n].label;
    }

    // Provjera postoji li element x u stablu
    bool isNode(nodetype x) {
        node p = Root();
        while (p != lambda && Comp(el[p].label, x) != 0) {
            if (Comp(el[p].label, x) == -1)  // label < x -> idi desno
                p = el[p].right;
            else
                p = el[p].left;
        }
        return p != lambda;
    }

    // Vrati minimum
    nodetype Min() {
        if (Root() == lambda) {
            std::cout << "Stablo je prazno" << std::endl;
            exit(EXIT_FAILURE);
        }
        node p = Root();
        while (el[p].left != lambda)
            p = el[p].left;
        return el[p].label;
    }

    // Vrati maksimum
    nodetype Max() {
        if (Root() == lambda) {
            std::cout << "Stablo je prazno" << std::endl;
            exit(EXIT_FAILURE);
        }
        node p = Root();
        while (el[p].right != lambda)
            p = el[p].right;
        return el[p].label;
    }

    // Umetanje elementa
    void Insert(nodetype x) {
        if (empty == lambda) {
            std::cout << "Polje je popunjeno" << std::endl;
            exit(EXIT_FAILURE);
        }
        // Ako je stablo prazno, kreiraj korijen na poziciji 0
        // (empty == 0 znaci prazno stablo, pa korijen ide na indeks 0)
        if (empty == 0) {
            empty = el[0].parent;  // Pomakni empty na sljedeci slobodni
            el[0].label = x;
            el[0].left = el[0].right = el[0].parent = lambda;
            return;
        }

        // Inace trazi mjesto za umetanje
        node p = 0;
        bool next = true;
        do {
            if (Comp(el[p].label, x) == 1) {  // label > x -> lijevo
                if (el[p].left != lambda)
                    p = el[p].left;
                else
                    next = false;
            } else if (Comp(el[p].label, x) == -1) {  // label < x -> desno
                if (el[p].right != lambda)
                    p = el[p].right;
                else
                    next = false;
            } else {
                // x vec postoji, ne ubacuj duplikat
                return;
            }
        } while (next);

     
        int n = empty;
        empty = el[empty].parent;
        el[n].label = x;
        el[n].left = el[n].right = lambda;
        el[n].parent = p;

        if (Comp(el[p].label, x) == -1)
            el[p].right = n;
        else
            el[p].left = n;
    }

    // Brisanje elementa po vrijednosti
    void Delete(nodetype x) {
        node n = 0;

        // Pronadi cvor s vrijednoscu x
        while (n != lambda && Comp(el[n].label, x) != 0) {
            if (Comp(el[n].label, x) == 1)  // label > x -> lijevo
                n = el[n].left;
            else
                n = el[n].right;
        }

        if (n != lambda) {
            node p;
            // Ako ima oba djeteta, zamijeni sa sljedbenikom
            if (el[n].left != lambda && el[n].right != lambda) {
                p = el[n].right;
                while (el[p].left != lambda)
                    p = el[p].left;
                el[n].label = el[p].label;
                n = p;  // Sada brisemo p
            }

            // Sada n ima najvise jedno dijete
            if (el[n].left != lambda)
                p = el[n].left;
            else
                p = el[n].right;

            // Povezi roditelja od n s djetetom p
            if (p != lambda)
                el[p].parent = el[n].parent;

            if (el[n].parent != lambda) {
                if (el[el[n].parent].left == n)
                    el[el[n].parent].left = p;
                else
                    el[el[n].parent].right = p;
            } else {
                // n je korijen, p postaje novi korijen
                // Ako p != lambda, moramo ga prebaciti na poziciju 0
                if (p != lambda && p != 0) {
                    // Kopiraj p na poziciju 0
                    el[0] = el[p];
                    // Azuriraj djecu da pokazuju na novog roditelja (0)
                    if (el[0].left != lambda)
                        el[el[0].left].parent = 0;
                    if (el[0].right != lambda)
                        el[el[0].right].parent = 0;
                    // Oslobodi staru poziciju p
                    el[p].parent = empty;
                    empty = p;
                    // n vec treba biti osloboden
                    if (n != p) {
                        el[n].parent = empty;
                        empty = n;
                    }
                    return;
                } else if (p == lambda) {
                    // Stablo postaje prazno - vrati cvor u free listu
                    el[n].parent = empty;
                    empty = n;
                    return;
                }
            }

            // Oslobodi cvor n
            el[n].parent = empty;
            empty = n;
        }
    }

private:
    void Del(node n) {
        if (el[n].left != lambda)
            Del(el[n].left);
        if (el[n].right != lambda)
            Del(el[n].right);
        el[n].parent = empty;
        empty = n;
    }

public:
    // Destruktor - oslobodi sve cvorove
    ~BST() {
        if (Root() != lambda)
            Del(Root());
    }
};
