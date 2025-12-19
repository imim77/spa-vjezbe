#include <iostream>
#include "stogpolje.h"

int main(){
    Stack<int> st;

    // prvi broj u izrazu
    int current;
    if (!(std::cin >> current)) {
        return 0;
    }
    st.Push(current);

    // čitanje operatora i brojeva dok ne naiđemo na undo broj
    while (true) {
        char op;
        if (!(std::cin >> op)) {
            // nema više ništa – nema ni undo broja
            break;
        }
        std::cin >> op;
        int x; std::cin >> x;

        switch (op) {
            case '+': current = current + x; break;
            case '-': current = current - x; break;
            case '*': current = current * x; break;
            case '/': current = current / x; break; // cjelobrojno dijeljenje
        }

        st.Push(current);
    }

    // sada čitamo broj za undo
    int undoN = 0;
    if (!(std::cin >> undoN)) {
        undoN = 0;
    }

    // poništi zadnjih undoN operacija
    for (int i = 0; i < undoN; ++i) {
        if (!st.isEmpty()) {
            st.Pop();
        }
    }

    // rezultat je stanje na vrhu stoga
    int result = st.Top();
    std::cout << result << std::endl;

    return 0;
}