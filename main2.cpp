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
    std::cout << "nullptr\n";
}

//this doesn't work
void addReadingBroken(Node* head, int value){
    Node* node = new Node;
    node->value = value;
    node->next = head;
    head = node; //changes only this function's copy of head

}

//this works
Node* addReading(Node* head, int value){
    Node* node = new Node;
    node->value = value;
    node->next = head;
    return node;        // the new node is the new head
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


    Node* node = new Node; //cheapest place to add a node is the front (no need to move anything)
    node->value = 7;
    node->next = head; //new node points at the old first node
    head = node; //head points at the new node

    //The caller then stores the result in its own head pointer:
    Node* head2 = nullptr;
    head2 = addReading(head2, 2);
    head2 = addReading(head2, 9);
    head2 = addReading(head2, 5);
    printReadings(head2);
    std::cout<< '\n';

    if(!(head2 == nullptr)){
        Node* removed = new Node; 
        removed = head2;          //remember first node
        head2 = head2->next;      //head moves to the second node
        delete removed;           //release the old first node
        removed = nullptr;

    }
    printReadings(head2);

    delete first;
    delete second;
    delete third;
    delete node;

    return 0;
}