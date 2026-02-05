#include <iostream>
#include <cstring>
#include "../vjezba2/stogpolje.h"
//#include "btreepoknovi.h"   // Pointer-based implementation
#include "bbbkursori.h"       // Cursor/array-based implementation
using namespace std;

// Funkcija za provjeru da li je karakter operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Funkcija za određivanje prioriteta operatora
int priority(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Funkcija za pretvorbu infix u postfix
void infixToPostfix(char infix[], char postfix[]) {
    Stack<char> S;
    int j = 0; // indeks za postfix niz
    int len = strlen(infix);
    
    for (int i = 0; i < len; i++) {
        char c = infix[i];
        
        // Preskačemo razmake
        if (c == ' ')
            continue;
        
        // Ako je operand (broj ili varijabla), dodaj u postfix
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[j++] = c;
        }
        // Ako je otvorena zagrada, stavi na stog
        else if (c == '(') {
            S.Push(c);
        }
        // Ako je zatvorena zagrada
        else if (c == ')') {
            // Skidaj sa stoga dok ne nađeš otvorenu zagradu
            while (!S.isEmpty() && S.Top() != '(') {
                postfix[j++] = S.Top();
                S.Pop();
            }
            if (!S.isEmpty() && S.Top() == '(') {
                S.Pop(); // Ukloni otvorenu zagradu
            }
        }
        // Ako je operator
        else if (isOperator(c)) {
            // Skidaj operatore sa većim ili jednakim prioritetom
            while (!S.isEmpty() && priority(S.Top()) >= priority(c)) {
                postfix[j++] = S.Top();
                S.Pop();
            }
            S.Push(c);
        }
    }
    
    // Skini sve preostale operatore sa stoga
    while (!S.isEmpty()) {
        postfix[j++] = S.Top();
        S.Pop();
    }
    
    postfix[j] = '\0'; // Terminiraj string
}

// Pomoćna funkcija za izgradnju podstabla iz postfix izraza
// pos je trenutna pozicija u postfix nizu (čitamo s desna na lijevo)
void buildSubtree(btree<char>& tree, typename btree<char>::node parent, bool isLeft, char postfix[], int& pos) {
    if (pos < 0) return;
    
    char c = postfix[pos--];
    
    if (isLeft) {
        tree.CreateLeftChild(parent, c);
        typename btree<char>::node current = tree.LeftChild(parent);
        if (isOperator(c)) {
            // Desno dijete prvo, pa lijevo (obrnuti redoslijed jer čitamo postfix s desna)
            buildSubtree(tree, current, false, postfix, pos);
            buildSubtree(tree, current, true, postfix, pos);
        }
    } else {
        tree.CreateRightChild(parent, c);
        typename btree<char>::node current = tree.RightChild(parent);
        if (isOperator(c)) {
            buildSubtree(tree, current, false, postfix, pos);
            buildSubtree(tree, current, true, postfix, pos);
        }
    }
}

// Funkcija za izgradnju stabla izraza iz postfix notacije
void buildExpressionTree(btree<char>& tree, char postfix[]) {
    int len = strlen(postfix);
    if (len == 0) return;
    
    int pos = len - 1;
    char c = postfix[pos--];
    
    // Kreiraj korijen s zadnjim znakom (mora biti operator ili jedini operand)
    tree.CreateRoot(c);
    
    if (isOperator(c)) {
        // Izgradi desno podstablo prvo, pa lijevo (obrnuto od postfix čitanja)
        buildSubtree(tree, tree.Root(), false, postfix, pos);
        buildSubtree(tree, tree.Root(), true, postfix, pos);
    }
}

// Inorder obilazak stabla (ispisuje infix izraz sa zagradama)
void inorderPrint(btree<char>& tree, typename btree<char>::node n) {
    if (n == tree.lambda) return;
    
    char c = tree.Label(n);
    bool hasChildren = (tree.LeftChild(n) != tree.lambda || tree.RightChild(n) != tree.lambda);
    
    if (hasChildren) cout << "(";
    
    inorderPrint(tree, tree.LeftChild(n));
    cout << c;
    inorderPrint(tree, tree.RightChild(n));
    
    if (hasChildren) cout << ")";
}

// Postorder obilazak stabla (ispisuje postfix izraz)
void postorderPrint(btree<char>& tree, typename btree<char>::node n) {
    if (n == tree.lambda) return;
    
    postorderPrint(tree, tree.LeftChild(n));
    postorderPrint(tree, tree.RightChild(n));
    cout << tree.Label(n);
}

// Preorder obilazak stabla (ispisuje prefix izraz)
void preorderPrint(btree<char>& tree, typename btree<char>::node n) {
    if (n == tree.lambda) return;
    
    cout << tree.Label(n);
    preorderPrint(tree, tree.LeftChild(n));
    preorderPrint(tree, tree.RightChild(n));
}

int main() {
    char infix[100];
    char postfix[100];
    
    cout << "Unesite infix izraz: ";
    cin.getline(infix, 100);
    
    cout << "Infix izraz:   " << infix << endl;
    
    // Pretvorba u postfix
    infixToPostfix(infix, postfix);
    cout << "Postfix izraz: " << postfix << endl;
    
    // Izgradnja stabla izraza iz postfix notacije
    btree<char> expressionTree;
    buildExpressionTree(expressionTree, postfix);
    
    // Ispis stabla u različitim oblicima
    cout << "\n--- Ispis iz stabla izraza ---" << endl;
    
    cout << "Postorder (postfix): ";
    postorderPrint(expressionTree, expressionTree.Root());
    cout << endl;
    
    cout << "Preorder (prefix):   ";
    preorderPrint(expressionTree, expressionTree.Root());
    cout << endl;
    
    cout << "Inorder (infix):     ";
    inorderPrint(expressionTree, expressionTree.Root());
    cout << endl;
    
    return 0;
}
