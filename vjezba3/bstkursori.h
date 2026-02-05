#include <iostream>
#include <cstdlib>

#ifndef MAXB
#define MAXB 1000
#endif

#ifndef Comp
#define Comp(a,b) (a<b ? -1 : (a==b ? 0 : 1))
#endif

template <typename nodetype>
class BST {
private:
    struct btr {
        nodetype label;
        int parent, left, right;
    };
    
    btr el[MAXB];
    int empty;  // glava liste praznih elemenata
    int root;   // korijen stabla (-1 ako je prazno)
    
public:
    typedef int node;
    const node lambda = -1;
    
    // Konstruktor - inicijalizira prazno stablo
    BST() {
        // Povezujemo sve elemente u listu praznih
        for (int i = 0; i < MAXB - 1; i++)
            el[i].parent = i + 1;
        el[MAXB - 1].parent = lambda;
        empty = 0;
        root = lambda;
    }
    
    // Provjerava je li stablo prazno - O(1)
    bool IsEmpty() {
        return root == lambda;
    }
    
    // Provjerava postoji li cvor s oznakom x - O(n)
    bool IsNode(nodetype x) {
        int p = root;
        while (p != lambda && Comp(el[p].label, x) != 0) {
            if (Comp(el[p].label, x) == -1)
                p = el[p].right;
            else
                p = el[p].left;
        }
        return (p != lambda);
    }
    
    // Vraca oznaku cvora
    nodetype Label(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        return el[n].label;
    }
    
    // Vraca korijen stabla
    node Root() {
        return root;
    }
    
    // Vraca roditelja cvora
    node Parent(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        return el[n].parent;
    }
    
    // Vraca lijevo dijete
    node LeftChild(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        return el[n].left;
    }
    
    // Vraca desno dijete
    node RightChild(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        return el[n].right;
    }
    
    // Vraca minimalni element - O(n)
    nodetype Min() {
        if (root == lambda) {
            std::cout << "Stablo je prazno" << std::endl;
            exit(EXIT_FAILURE);
        }
        int p = root;
        while (el[p].left != lambda)
            p = el[p].left;
        return el[p].label;
    }
    
    // Vraca maksimalni element - O(n)
    nodetype Max() {
        if (root == lambda) {
            std::cout << "Stablo je prazno" << std::endl;
            exit(EXIT_FAILURE);
        }
        int p = root;
        while (el[p].right != lambda)
            p = el[p].right;
        return el[p].label;
    }
    
    // Umetanje elementa - O(n)
    void Insert(nodetype x) {
        if (empty == lambda) {
            std::cout << "Polje je popunjeno" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        // Ako je stablo prazno, stvaramo korijen
        if (root == lambda) {
            int novi = empty;
            empty = el[empty].parent;  // pomicemo glavu liste praznih
            
            el[novi].label = x;
            el[novi].left = el[novi].right = el[novi].parent = lambda;
            root = novi;
        }
        else {
            int p = root;
            bool next = true;
            
            // Trazimo mjesto za umetanje
            do {
                if (Comp(el[p].label, x) == 1 && el[p].left != lambda)
                    p = el[p].left;
                else if (Comp(el[p].label, x) == -1 && el[p].right != lambda)
                    p = el[p].right;
                else
                    next = false;
            } while (next);
            
            // Umetanje ako element ne postoji
            if (Comp(el[p].label, x) != 0) {
                int novi = empty;
                empty = el[empty].parent;
                
                el[novi].label = x;
                el[novi].left = el[novi].right = lambda;
                el[novi].parent = p;
                
                if (Comp(el[p].label, x) == -1)
                    el[p].right = novi;
                else
                    el[p].left = novi;
            }
        }
    }
    
    // Brisanje elementa - O(n)
    void Delete(nodetype x) {
        int n = root;
        
        // Trazimo cvor za brisanje
        while (n != lambda && Comp(el[n].label, x) != 0) {
            if (Comp(el[n].label, x) == 1)
                n = el[n].left;
            else
                n = el[n].right;
        }
        
        if (n != lambda) {
            int p;
            
            // Slucaj 1: cvor ima oba djeteta
            if (el[n].left != lambda && el[n].right != lambda) {
                // Trazimo inorder nasljednika (najmanji u desnom podstablu)
                p = el[n].right;
                while (el[p].left != lambda)
                    p = el[p].left;
                el[n].label = el[p].label;
                n = p;  // sada brisemo nasljednika umjesto originalnog cvora
            }
            
            // Slucaj 2: cvor ima najvise jedno dijete
            if (el[n].left != lambda)
                p = el[n].left;
            else
                p = el[n].right;
            
            // Povezujemo dijete s roditeljem
            if (p != lambda)
                el[p].parent = el[n].parent;
            
            if (el[n].parent != lambda) {
                if (el[el[n].parent].left == n)
                    el[el[n].parent].left = p;
                else
                    el[el[n].parent].right = p;
            }
            else {
                // Brisemo korijen
                root = p;
            }
            
            // Vracamo obrisani cvor u listu praznih
            el[n].parent = empty;
            empty = n;
        }
    }
    
private:
    // Pomocna funkcija za inorder obilazak
    void InOrder(int n, nodetype a[], int &i) {
        if (n == lambda) return;
        
        if (el[n].left != lambda)
            InOrder(el[n].left, a, i);
        a[i++] = el[n].label;
        if (el[n].right != lambda)
            InOrder(el[n].right, a, i);
    }
    
    // Pomocna funkcija za rekurzivno brisanje podstabla
    void Del(int n) {
        if (n == lambda) return;
        
        if (el[n].left != lambda)
            Del(el[n].left);
        if (el[n].right != lambda)
            Del(el[n].right);
        
        // Vracamo cvor u listu praznih
        el[n].parent = empty;
        empty = n;
    }
    
public:
    // Inorder ispis (sortirano)
    void InorderPrint() {
        InorderPrintRec(root);
    }
    
private:
    void InorderPrintRec(int n) {
        if (n == lambda) return;
        InorderPrintRec(el[n].left);
        std::cout << el[n].label << " ";
        InorderPrintRec(el[n].right);
    }
    
public:
    // Sortiranje polja pomocu BST-a
    int Sort(nodetype a[], int n) {
        // Cistimo stablo
        if (root != lambda)
            Del(root);
        root = lambda;
        
        // Resetiramo listu praznih
        for (int i = 0; i < MAXB - 1; i++)
            el[i].parent = i + 1;
        el[MAXB - 1].parent = lambda;
        empty = 0;
        
        // Umetamo sve elemente
        for (int j = 0; j < n; j++)
            Insert(a[j]);
        
        // Inorder obilazak daje sortirani niz
        int i = 0;
        InOrder(root, a, i);
        return i;
    }
    
    // Destruktor
    ~BST() {
        if (root != lambda)
            Del(root);
    }
};

