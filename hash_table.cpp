
#include <iostream>
#include <string.h>
using namespace std;
struct node {
    int value;
    node* next;
} *Hashtable[10];
class hashing {
public:
    hashing() {
        for (int i = 0; i < 10; i++) {
            Hashtable[i] = NULL;
        }
    }
    int Hashfunction(int value) {
        return (value % 10);
    }
    node* create_node(int x) {
        node* temp = new node;
        temp->next = NULL;
        temp->value = x;
        return temp;
    }
    void display() {
        for (int i = 0; i < 10; i++) {
            node* temp = Hashtable[i];
            cout << "a[" << i << "]";
            while (temp != NULL) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    int search(int value) {
        bool flag = false;
        int hash_val = Hashfunction(value);
        node* entry = Hashtable[hash_val];
        while (entry != NULL) {
        	cout << "\nElement found at:";
            if (entry->value == value) {
                cout << hash_val << ":" << entry->value << endl;
                flag = true;
            }
            entry = entry->next;
        }
        if (!flag) {
            return -1;
        }
        return hash_val;
    }
    void delete_element(int value) {
        int hash_val = Hashfunction(value);
        node* entry = Hashtable[hash_val];
        node* prev = NULL;
        if (entry == NULL) {
            cout << "Elements is not present!!" << endl;
            return;
        }
        while (entry != NULL && entry->value != value) {
            prev = entry;
            entry = entry->next;
        }
        if (entry == NULL) {
            cout << "Element not found." << endl;
            return;
        }
        if (prev == NULL) {
            Hashtable[hash_val] = entry->next;
        } else {
            prev->next = entry->next;
        }
        delete entry;
        cout << "Element " << value << " deleted successfully." << endl;
    }
    void insertelement(int value) {
        int hash_val = Hashfunction(value);
        node* temp = new node;
        node* head = create_node(value);
        temp = Hashtable[hash_val];
        if (temp == NULL) {
            Hashtable[hash_val] = head;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = head;
        }
    }
};
int main() {
    int ch;
    int data, search, del;
    int flag = 0;
    hashing h;
    char ans = 'y';
    char a;
    int n;
    do {
        cout << "------TELEPHONE--------" << endl;
        cout << "1.INSERT" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.SEARCH" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.EXIT" << endl;
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter phone no to be inserted:"<<endl;
                cout<<"how many  number do you want to store:";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                	cin >> data;
                	h.insertelement(data);
				}
                break;
            case 2:h.display();
                break;
            case 3: cout << "Enter the no to be searched:";
                cin >> search;
                if (h.search(search) == -1) {
                    cout << "Element is not present!" << endl;
                    continue;
                }
                break;
            case 4: cout << "Enter the phone number to be deleted:";
                cin >> del;
                h.delete_element(del);
                break;
            case 5: cout << "Do you want to exit:";
                cin >> a;
                if (a == 'y') {
                    flag = 1;
                }
                break;
            default:cout << "Invalid choice. Please try again." << endl;
        }
    } while (!flag);
    return 0;
}
