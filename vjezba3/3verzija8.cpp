#include <iostream>
#include <cstring>
#include "../vjezba2/stogpolje.h"
#include "btreepoknovi.h"

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

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

void infixToPostfix(char infix[], char postfix[]) {
    Stack<char> S;
    int j = 0;
    int len = strlen(infix);
    
    for (int i = 0; i < len; i++) {
        char c = infix[i];
        
        if (c == ' ')
            continue;
        
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            S.Push(c);
        }
        else if (c == ')') {
            while (!S.isEmpty() && S.Top() != '(') {
                postfix[j++] = S.Top();
                S.Pop();
            }
            if (!S.isEmpty() && S.Top() == '(') {
                S.Pop();
            }
        }
        else if (isOperator(c)) {
            while (!S.isEmpty() && priority(S.Top()) >= priority(c)) {
                postfix[j++] = S.Top();
                S.Pop();
            }
            S.Push(c);
        }
    }
    
    while (!S.isEmpty()) {
        postfix[j++] = S.Top();
        S.Pop();
    }
    
    postfix[j] = '\0';
}

void buildSubtree(btree<char>& tree, btree<char>::node parent, bool isLeft, char postfix[], int& pos) {
    if (pos < 0) return;
    
    char c = postfix[pos--];
    
    if (isLeft) {
        tree.CreateLeftChild(parent, c);
        btree<char>::node current = tree.LeftChild(parent);
        if (isOperator(c)) {
            buildSubtree(tree, current, false, postfix, pos);
            buildSubtree(tree, current, true, postfix, pos);
        }
    } else {
        tree.CreateRightChild(parent, c);
        btree<char>::node current = tree.RightChild(parent);
        if (isOperator(c)) {
            buildSubtree(tree, current, false, postfix, pos);
            buildSubtree(tree, current, true, postfix, pos);
        }
    }
}

void buildExpressionTree(btree<char>& tree, char postfix[]) {
    int len = strlen(postfix);
    if (len == 0) return;
    
    int pos = len - 1;
    char c = postfix[pos--];
    
    tree.CreateRoot(c);
    
    if (isOperator(c)) {
        buildSubtree(tree, tree.Root(), false, postfix, pos);
        buildSubtree(tree, tree.Root(), true, postfix, pos);
    }
}



void postorderPrint(btree<char>& tree, btree<char>::node n) {
    if (n == tree.lambda) return;
    
    postorderPrint(tree, tree.LeftChild(n));
    postorderPrint(tree, tree.RightChild(n));
    cout << tree.Label(n);
}



int main() {
    char infix[] = "(3*x+1)*(4+x)-(2*x+3)";
    char postfix[100];
    
    cout << "Infix izraz:   " << infix << endl;
    
    infixToPostfix(infix, postfix);
    cout << "Postfix izraz: " << postfix << endl;
    
    btree<char> expressionTree;
    buildExpressionTree(expressionTree, postfix);
    
    
    cout << "Postorder (postfix): ";
    postorderPrint(expressionTree, expressionTree.Root());
    cout << endl;
    
   
    
    return 0;
}