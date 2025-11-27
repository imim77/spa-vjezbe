#include <iostream>
#include <cstdlib>


struct Node{
    int val;
    Node* next;
};



int Size(Node* list){
    int counter = 0;
    while(list != nullptr){
        counter++;
        list = list->next;
    }
    return counter;
}


Node* selectPivot(Node *list){
    int n = Size(list);
    int k = rand()%n;

    Node *pivot = list;
    for(int i=0; i<k; i++){
        pivot = pivot->next;
    }
    return pivot;
}


Node* quickSort(Node* list){
    if(list == nullptr || list->next == nullptr){
        return list;
    }

    Node* manje = nullptr, *vece = nullptr;
    Node* temp = nullptr, *next = nullptr;

    Node* pivot = selectPivot(list);

    while(list != nullptr){
        next = list->next;
        if(list->val != pivot->val){
            list->next = temp;
            temp = list;
        }
        list = next;
    }

    while(temp != nullptr){
        next = temp->next;
        if(temp->val < pivot->val){
            temp->next = manje;
            manje = temp;
        }else{
            temp->next = vece;
            vece = temp;
        }
        temp = next;
    }

    manje = quickSort(manje);
    vece = quickSort(vece);

    pivot->next = vece;

    if(manje == nullptr){
        return pivot;
    }

    Node *kraj = manje;
    while(kraj->next != nullptr){
        kraj = kraj->next;
    }
    kraj->next = pivot;
    return manje;

}


void Dodaj(Node*& head, int val){
    Node* node = new Node{val, head};
    head = node;
};

void Print(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        std::cout << curr->val << " ";
        curr = curr->next;
    }
};


int main(){
    int n; std::cin >> n;
    Node* list = nullptr;
    for(int i=0; i<n; i++){
        int x; std::cin >> x;
        Dodaj(list, x);
    }
    Print(list);
    list = quickSort(list);
    std::cout << std::endl;
    Print(list);
}