#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;  // Initialize data
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;  // Corrected initialization
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void display() {  // Function to display the list (for debugging)
        Node* temp = head;
        while (temp!=NULL) {
            cout << temp->data <<" <=> ";
            temp = temp->next;
        }
        cout << "NULL\n"<<endl;
    }
    void push_back(int val){
         Node*newNode = new Node(val);
         if(head == NULL){
            head = tail = NULL;
         }
         else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
         }
    }
    void pop_front(){
        if(head == NULL){
            cout<<"list is empty"<<endl;
        }
        Node*temp = head;
        head = head->next;
        if(head!=NULL){
            head->next =NULL;
        }
        temp->next = NULL;
        delete temp;
    }
    void pop_back()  {
        Node*temp = tail;
        tail = tail->prev;

        if(tail!=NULL){
            tail->next = NULL ;

        }
        temp->prev = NULL;
        delete temp;

    }
        
};

int main() {
    DoublyList D;
    D.push_front(3);
    D.push_front(4);
    D.push_back(2);
    D.push_back(1);
    D.display();
    D.pop_front();


    D.display();
    D.pop_back();
    D.pop_back();
    D.display();
    D.pop_front();
    return 0;
}
