#include <iostream>
#include <cstdlib>

#ifndef MAXSE
#define MAXSE 1000
#endif

#ifndef Comp
#define Comp(a,b) ((a) < (b) ? -1 : ((a) == (b) ? 0 : 1))
#endif

template<typename T>
class set {
private:
    T el[MAXSE];
    int NoEl;

public:
    set() : NoEl(0) {}

    bool isEmpty() const {
        return NoEl == 0;
    }

    int size() const {
        return NoEl;
    }

private:
    int BinSearch(T x) const {
        // Sigurno za prazan skup
        int i = 0, j = NoEl - 1;

        while (i <= j) {
            int k = i + (j - i) / 2;
            int c = Comp(el[k], x);

            if (c == 0) return k;
            if (c < 0)  i = k + 1;
            else        j = k - 1;
        }
        return -1;
    }

public:
    bool isElement(T x) const {
        return BinSearch(x) != -1;
    }

    void Insert(T x) {
        if (NoEl == MAXSE) {
            std::cout << "Skup je prepunjen" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        if (BinSearch(x) != -1) {
            return; // već postoji, ništa ne radi
        }

        // umetanje u sortirani niz: pomakni veće udesno
        int i = NoEl - 1;
        while (i >= 0 && Comp(el[i], x) == 1) {
            el[i + 1] = el[i];
            --i;
        }
        el[i + 1] = x;
        ++NoEl;
    }

    void Delete(T x) {
        int i = BinSearch(x);
        if (i >= 0) {
            for (int j = i + 1; j < NoEl; ++j) {
                el[j - 1] = el[j];
            }
            --NoEl;
        }
    }

    T GetElementFromIndex(int i) const {
        if (i < 0 || i >= NoEl) {
            std::cout << "Neispravan indeks" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        return el[i];
    }

    // Presjek skupova: vraća novi skup
    static set<T> Intersect(const set& a, const set& b) {
        set<T> presjekSet;

        for (int i = 0; i < a.NoEl; ++i) {
            T elem = a.el[i];              // brže od GetElementFromIndex
            if (b.isElement(elem)) {
                presjekSet.Insert(elem);
            }
        }
        return presjekSet;
    }

    void Print() const {
    if (NoEl == 0) {
        std::cout << "Skup je prazan" << std::endl;
        return;
    }

    std::cout << "{ ";
    for (int i = 0; i < NoEl; ++i) {
        std::cout << el[i];
        if (i < NoEl - 1)
            std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

};
