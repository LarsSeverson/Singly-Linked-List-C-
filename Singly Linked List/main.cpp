/*
    Singly Linked List
    ~~~~~~~~~~~~~~~~~~~~~~~~
    * This is the implementation of a Singly Linked List
    * A linked list contains a Node which hold a value of whatever type and also holds a pointer to the next Node
    * This is a linear data structure and it is useful for when you're dealing with a problem that has a dynamic size
    * In a linked list you can push or pop values from either side of the list. However it is important to note the time complexity difference between popping/pushing from the front and pushing/popping from the back(O(n))
    
 */

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL){
    }
};

class SinglyLinkedList{
private:
    Node* head;
public:
    SinglyLinkedList() : head(NULL){
        cout << "Constructing\n";
        // Set head of list to NULL
    }
    ~SinglyLinkedList(){
        cout << "Deconstructing\n";
        Node* current = head;
        while(current != NULL){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    
    void push_front(int val){ // O(1)
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void push_back(int val){ // O(n)
        Node* newNode = new Node(val);
        Node* current = head;
        if (head == NULL){
            head = newNode;
            return;
        }
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    
    void display(){
        Node* current = head;
        
        while(current != NULL){
            cout << current->data;
            if (current->next != NULL){
                cout << ", ";
            }
            current = current->next;
        }
        cout << endl;
    }
    
    void reverse(){
        Node* current = head;
        Node* prev = NULL;
        Node* n;
        while(current != NULL){
            n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        head = prev;
    }
    
    void deleteNth(int n){
        Node* current = head;
        if (n == 1){
            head = head->next;
            delete current;
            return;
        }
        for(int i = 1; i < n - 1; i++){
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    
    void deleteVal(int val){
        Node* current = head;
        Node* prev = head;
        if (head->data == val){
            head = head->next;
            delete current;
            return;
        }
        while(current->data != val){
            prev = current;
            current = current->next;
        }
        Node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }
};

int main(){
    SinglyLinkedList TheList;
    
    TheList.push_back(4);
    TheList.push_front(6);
    TheList.push_back(5);
    TheList.display();
    
    TheList.push_back(8);
    TheList.push_back(9);
    TheList.display();
    
    TheList.reverse();
    TheList.display();
    
    TheList.deleteNth(1);
    TheList.display();
    
    TheList.deleteVal(8);
    TheList.display();
    TheList.deleteVal(4);
    TheList.display();
    TheList.deleteNth(2);
    TheList.display();
    return 0;
}
