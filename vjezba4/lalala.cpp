#include "setpolje.h"


int main(){
    set<int> setara;
    set<int> setara2;

    for(int d = 10; d < 23; d++){
        setara.Insert(d);
    }
    setara.Print();

    for(int j = 10; j<13; j++){
        setara2.Insert(j);
    }
    setara2.Print();

    auto presjek = setara.Intersect(setara, setara2);
    presjek.Print();


}