#include "stogpolje.h"


bool isValid(const char* izraz){
    Stack<char> stog;

    for(int i=0; i<strlen(izraz); i++){
        if(izraz[i] == '('){
            stog.Push(')');
        }else if(izraz[i] == '['){
            stog.Push(']');
        }else if(izraz[i] == '{'){
            stog.Push('}');
        }else if(izraz[i] == ')' || izraz[i] == '}' || izraz[i] == ']'){
            if(stog.isEmpty() || stog.Top() != izraz[i]){
                return false;
            }
            stog.Pop();
        }
    }
    return stog.isEmpty();
}


int main(){
    const char* izraz;
    const char* izraz2;
    izraz = "3*(x-1)/[7+x*(3*y-2)]+4*(1/x)";
    izraz2 = "3+{x-[2*[x-3]+2*(3*x-2])+4}-{2+[3+x*(4-y)]}";
    std::cout << isValid(izraz);
    std::cout << std::endl;
    std::cout << isValid(izraz2);
    

}