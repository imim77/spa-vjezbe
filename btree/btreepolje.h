#include <iostream>
#include <cstdlib>


#ifndef MAXB
#define MAXB 1000
#endif


template<typename T>
class btree{
private:
    struct elem{
        bool used;
        T label;
    };

    elem B[MAXB+1];
public:
    inline static const int lambda = 0;

    btree(){
        for(int i = 1; i <= MAXB; i++){
            B[i].used = false;
        }
    }

    btree(T x){
        B[1].label = x;
        B[1].used = true;
        for(int i = 2; i<=MAXB; i++){
            B[i].used = false;
        }
    }

    bool isEmpty(){
        return !B[1].used ;
    }


    T Label(int n){
        if(n == lambda){
            std::cout << "Neposotjeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }
        return B[n].label;
    }

    int Root(){
        return B[1].used ? 1 : lambda;
    }

    int Parent(int n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            return n/2;
        }
        
    }

    int LefChild(int n){
        if(n == lambda){
            std::cout << "Nepostojeći čvore" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            if(2*n <= MAXB && B[2*n].used){
                return 2*n;
            }else{
                return lambda;
            }
        }
    }

    int RightChild(int n){
        if(n == lambda){
            std::cout << "Nepostojeći čvor";
            exit(EXIT_FAILURE);
        }else{
            if(2*n+1 <= MAXB && B[2*n+1].used){
                return 2*n+1;
            }else{
                return lambda;
            }
        }
    }

    void ChangeLabel(int n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći čvor";
            exit(EXIT_FAILURE);
        }else{
            B[n].label = x;
        }
    }

    void CreateRoot(T x){
        if(B[1].used){
            std::cout << "Stablo nije prazno" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            B[1].used = true;
            B[1].label = x;
        }
    }

    void CreateLeftChild(int n, T x){
        if(n == lambda){
            std::cout << "Neposotjeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            if(2*n > MAXB ){
                std::cout << "Čvor je izvan dosega" << std::endl;
                exit(EXIT_FAILURE);
            }else if(B[2*n].used){
                std::cout << "Čvor vec imal lijevo dijete" << std::endl;
                exit(EXIT_FAILURE);
            }else{
                B[2*n].used = true;
                B[2*n].label = x;

            }
            
        }
    }


    void CreateRightChild (int n, T x){
        if(n == lambda){
            std::cout << "Nepostojeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            if(2*n+1 > MAXB){
                std::cout << "Čvor je izvan dosega" << std::endl;
                exit(EXIT_FAILURE);
            }else if(B[2*n+1].used){
                std::cout << "Čvor već ima desno dijete" << std::endl;
                exit(EXIT_FAILURE);
            }else{
                B[2*n+1].used = true;
                B[2*n+1].label = x;
            }
        }
    }

private:
    void Del(int n){
        if(2*n <= MAXB && B[2*n].used){
            Del(2*n);
        }
        if(2*n+1 <= MAXB && B[2*n+1].used){
            Del(2*n+1);
        }
        B[n].used = false;
    }

public:
    void Delete(int n){
        if(n == lambda){
            std::cout << "Neposotjeći čvor" << std::endl;
            exit(EXIT_FAILURE);
        }else{
            Del(n);
        }
    }

};