#include <iostream>

/*Linked List: a sequence stored as separately allocated pieces each holding one value
and the address of the next piece, called a Node and reach its members through a pointer with the
arrow operator*/

struct Node {
    int value;
    Node* next;
};



int main(){
    Node* third = new Node;
    third -> value = 2;
    third -> next = nullptr; //nothing comes after this node

    Node* second = new Node;
    second -> value = 9;
    second -> next = third;

    Node* first = new Node;
    first -> value = 3;
    first -> next = second;

    Node* head = first;

    std::cout << head ->value << '\n';
    std::cout << head->next->value << '\n';
    std::cout << head->next->next->value << '\n';

    delete first;
    delete second;
    delete third;

    return 0;
}