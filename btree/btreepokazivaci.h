#include <iostream>
#include <cstdlib>

template<typename T>
class btree {
private:
    struct btr{
        T label;
        btr *parent,*right,*left;          
    };

    btr* B;
public:

    const btr* lambda = NULL;

    btree(){
        B = lambda;
    }

    btree(T x){
        B = new btr;
        B->parent = NULL;
        B->left = NULL;
        B->right = NULL;
        B->label = x;
    }

    bool isEmpty(){
        return B == lambda;
    }

    T Label(btr* n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->label;
        }
    }

    btr* Root(){
        return B;
    }

    btr* Parent(btr* n){
        if (n == lambda){
            std::cout << "Neposotjeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->parent;
        }
    }

    btr* LeftChild(btr* n){
        if(n == lambda){
            std::cout << "Nepostojećo element" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->left;
        }
    }

    btr* RightChild(btr* n){
        if(n == lambda){
            std::cout << "Nepostojećo čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->right;
        }
    }

    void ChangeLabel(btr* n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći čvor";
            exit(EXIT_FAILURE);
        }else{
            n->label = x;
        }
    }

    void CreateRoot(T x){
        if(B != lambda){
            std::cout << "Binarno stablo nije prazno" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            B = new btr;
            B->label = x;
            B->right = NULL;
            B->left = NULL;
            B->parent = NULL;
        }
    }

    void CreateLeftChild(btr* n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            if(n->left != NULL){
                std::cout << "Čvor već ima lijevo dijete" << std::endl;
                exit(EXIT_FAILURE);
            }else{
                btr* p = new btr;
                n->left = p;
                p->label = x;
                p->parent = n;
                p->left = lambda;
                p->right = lambda;
            }
        }
    }

    void CreateRightChild(btr* n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći element" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            if(n->right != NULL){
                std::cout << "Čvor već ima desno dijete" << std::endl;
                exit(EXIT_FAILURE);
            }else{
                btr* p = new btr;
                n->right = p;
                p->label = x;
                p->left = lambda;
                p->right = lambda;
                p->parent = n;
            }
        }
    }

private:
    void Del(btr* n){
        if(n->left != NULL){
            Del(n->left);
        }
        if(n->right != NULL){
            Del(n->right);
        }
        delete n;
    }

public:
    void Delete(btr* n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            if(n->parent != NULL){
                if(n->parent->left == n){
                    n->parent->left = NULL;
                }else{
                    n->parent->right = NULL;
                }
                Del(n);
            }else{
                Del(n);
                B = NULL;
            }
        }
    }

    ~btree(){
        if(B != lambda){
            Del(B);
        }
    }

};