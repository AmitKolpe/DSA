#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {  
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {  
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0) {  
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) { 
            if(temp==NULL){
             cout<<"invalid postion"<<endl;
                return;
            }
              
            
            temp = temp->next;
        }

        if (temp == nullptr) {  
            cout << "Position out of range" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        
        if (newNode->next == nullptr) {  
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {  
            tail = NULL;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {  
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List ll;  
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.display(); 
    ll.insert(40,3);
    ll.display();
    ll.pop_front();
    ll.display();
    ll.pop_back();
    ll.display();
    ll.insert(50,5);
    return 0;
}
