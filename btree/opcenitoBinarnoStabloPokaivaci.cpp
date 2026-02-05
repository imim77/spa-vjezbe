#include <iostream>
#include <cstdlib>


template<typename T>
class triePok{
private:
    struct btr{
        T label;
        btr* child, *sibling, *parent;
    };

    btr* B;
public:
    typedef btr* node;
    const node lambda = NULL;

    triePok(){
        B = NULL;
    }

    triePok(T x){
        B = new btr;
        B->label = x;
        B->child = B->sibling = B->parent = NULL; 
    }

    bool isEmpty(){
        return B == NULL;
    }


    T Label(node n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->label;
        }
    }

    node Root(){
        return B;
    }

    node Parent(node n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->parent;
        }
    }

    node FirstChild(node n){ 
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->child;
        }
    }

    node NextSibling(node n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n->sibling;
        }
    }

    void ChangeLebel(node n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            n->label = x;
        }
    }

    void CreateRoot(T x){
        if(B != NULL){
            std::cout << "Stablo već ima korijen" << std::endl;
            exit(EXIT_FAILURE);
        }else{
           B = new btr;
           B->label = x;
           B->child = B->sibling = B->parent = NULL;  
        }
    }

    
    void CreateChild(node n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            btr* novi = new btr; 
            novi->label = x;
            novi->parent = n;
            novi->child = lambda;
            novi->sibling = n->child;
            n->child = novi;
        }
    }
private:
    // Brise n i sve njegove potomke (siblinge i djecu rekurzivno)
    void Del(node n){
        if(n->sibling != lambda){
            Del(n->sibling);
        }
        if(n->child != lambda){
            Del(n->child);
        }
        delete n;
    }
    

public:
    void Delete(node n){
        if(n == lambda){
            std::cout << "Nepostojeci cvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        else {
            // Prvo obrisi svu djecu cvora n
            if(n->child != lambda){
                Del(n->child);
            }
            
            // Ako cvor ima roditelja, odspoji ga iz liste djece
            if(n->parent != lambda){
                // Ako je n prvo dijete roditelja
                if(n->parent->child == n){
                    n->parent->child = n->sibling;
                }
                else {
                    // Inace, pronadi prethodnog siblinga i preskoci n
                    node i = n->parent->child;
                    while(i->sibling != n){
                        i = i->sibling;
                    }
                    i->sibling = n->sibling;
                }
            }
            else {
                // n je korijen
                B = NULL;
            }
            
            delete n;
        }
    }

    void DisposeT(){
        if(B != NULL){
            Del(B);
            B = NULL;
        }
    }

    ~triePok(){
        if(B != lambda){
            Del(B);
        }
    }
};


int main(){
    triePok<int> T;
    T.CreateRoot(1);
    T.CreateChild(T.Root(), 2);
    T.CreateChild(T.Root(), 3);
    T.CreateChild(T.FirstChild(T.Root()), 4);
    
    std::cout << "Root: " << T.Label(T.Root()) << std::endl;
    std::cout << "First child: " << T.Label(T.FirstChild(T.Root())) << std::endl;
    
    // Brisanje prvog djeteta (3) - koje ima dijete 4
    T.Delete(T.FirstChild(T.Root()));
    
    std::cout << "Nakon brisanja, first child: " << T.Label(T.FirstChild(T.Root())) << std::endl;
    
    return 0;
}