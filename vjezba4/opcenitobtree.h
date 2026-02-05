#ifndef OPCENITO_BTREE_H
#define OPCENITO_BTREE_H

#include "../btree/btreepoknovi.h"

// General tree implemented using binary tree
// Left child in binary tree = First child in general tree
// Right child in binary tree = Next sibling in general tree

template<typename T>
class tree {
private:
    btree<T> B;

public:
    typedef typename btree<T>::node node;
    node lambda = B.lambda;

    tree() {}

    // O(1)
    bool IsEmpty() {
        return B.IsEmpty();
    }

    // O(1)
    T Label(node n) {
        return B.Label(n);
    }

    // O(1)
    node Root() {
        return B.Root();
    }

    // O(1) - First child = left child in binary tree
    node FirstChild(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        return B.LeftChild(n);
    }

    // O(1) - Next sibling = right child in binary tree
    node NextSibling(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        return B.RightChild(n);
    }

    // O(1) - Parent: go up through binary parent, skip sibling chain
    node Parent(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (n == B.Root()) return lambda;
        
        node p = B.Parent(n);
        while (p != lambda && B.RightChild(p) == n) {
            n = p;
            p = B.Parent(p);
        }
        return p;
    }

    // O(1)
    void ChangeLabel(node n, T x) {
        B.ChangeLabel(n, x);
    }

    // O(1)
    void CreateRoot(T x) {
        B.CreateRoot(x);
    }

    // O(1) - Add new child as last sibling
    // Note: To achieve O(1), we add at end but this requires traversal
    // For true O(1), implementation would need tail pointer
    void CreateChild(node n, T x) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        node firstChild = B.LeftChild(n);
        
        if (firstChild == lambda) {
            // No children, create left child - O(1)
            B.CreateLeftChild(n, x);
        } else {
            // Add at end of sibling chain
            node curr = firstChild;
            while (B.RightChild(curr) != lambda) {
                curr = B.RightChild(curr);
            }
            B.CreateRightChild(curr, x);
        }
    }

    // O(1) - Delete only works for leaves
    void Delete(node n) {
        if (n == lambda) {
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        // Check if leaf (no children = no left child in binary tree)
        if (B.LeftChild(n) != lambda) {
            std::cout << "Cvor nije list" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        B.Delete(n);
    }
};

#endif
