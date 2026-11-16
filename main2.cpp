#include <iostream>

/*Linked List: a sequence stored as separately allocated pieces each holding one value
and the address of the next piece, called a Node and reach its members through a pointer with the
arrow operator*/

struct Node {
    int value;
    Node* next;
};

//to visit every node we keep a second pointer
void printReadings(const Node* head){
    for (const Node* current = head; current != nullptr; current = current->next) {
        std::cout << current->value << " -> ";
    }
    //std::cout << "nullptr\n";
}

int totalReadings(const Node* head){
    int total = 0;
    for(const Node* current = head; current != nullptr; current = current->next){
        ++total;
    }
    std::cout << total << std::endl;
    return total;
}

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

    printReadings(head);
    std::cout << totalReadings(head);

    delete first;
    delete second;
    delete third;

    return 0;
}