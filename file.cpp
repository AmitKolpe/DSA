#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

// Employee class Declaration
class Employee {
private:
    int code;
    char name[20];
    float salary;
public:
    void read();
    void display();
    int getEmpCode() { return code; }
    float getSalary() { return salary; }
    void updateSalary(float s) { salary = s; }
};

// Read employee record
void Employee::read() {
    cout << "Enter employee code: ";
    cin >> code;
    cout << "Enter name: ";
    cin.ignore(1);
    cin.getline(name, 20);
    cout << "Enter salary: ";
    cin >> salary;
}

// Display employee record
void Employee::display() {
    cout << code << " " << name << "\t" << salary << endl;
}

// Global declaration
fstream file;

// Will delete file when program is being executed
void deleteExistingFile() {
    remove("EMPLOYEE.DAT");
}

// Function to append record into file
void appendToFile() {
    Employee x;
    x.read();

    file.open("EMPLOYEE.DAT", ios::binary | ios::app);
    if (!file) {
        cout << "ERROR IN CREATING FILE\n";
        return;
    }

    file.write((char*)&x, sizeof(x));
    file.close();
    cout << "Record added successfully.\n";
}

void displayAll() {
    Employee x;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file) {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }

    while (file.read((char*)&x, sizeof(x))) {
        if (x.getSalary() >= 10000 && x.getSalary() <= 20000)
            x.display();
    }

    file.close();
}

void searchForRecord() {
    Employee x;
    int c;
    int isFound = 0;

    cout << "Enter employee code: ";
    cin >> c;

    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file) {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }

    while (file.read((char*)&x, sizeof(x))) {
        if (x.getEmpCode() == c) {
            cout << "RECORD FOUND\n";
            x.display();
            isFound = 1;
            break;
        }
    }

    if (!isFound)
        cout << "Record not found!!!\n";

    file.close();
}

void increaseSalary() {
    Employee x;
    int c;
    int isFound = 0;
    float sal;

    cout << "Enter employee code: ";
    cin >> c;

    fstream tempFile("TEMP.DAT", ios::binary | ios::out);
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);

    if (!file || !tempFile) {
        cout << "ERROR IN OPENING FILE\n";
        return;
    }

    while (file.read((char*)&x, sizeof(x))) {
        if (x.getEmpCode() == c) {
            cout << "Salary hike? ";
            cin >> sal;
            x.updateSalary(x.getSalary() + sal);
            isFound = 1;
        }
        tempFile.write((char*)&x, sizeof(x));
    }

    file.close();
    tempFile.close();

    remove("EMPLOYEE.DAT");
    rename("TEMP.DAT", "EMPLOYEE.DAT");

    if (isFound)
        cout << "Salary updated successfully.\n";
    else
        cout << "Record not found!!!\n";
}

void insertRecord() {
    Employee x;
    Employee newEmp;
    newEmp.read();

    fstream fin;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    fin.open("TEMP.DAT", ios::binary | ios::out);

    if (!file || !fin) {
        cout << "Error in opening file!!!\n";
        return;
    }

    bool inserted = false;
    while (file.read((char*)&x, sizeof(x))) {
        if (!inserted && x.getEmpCode() > newEmp.getEmpCode()) {
            fin.write((char*)&newEmp, sizeof(newEmp));
            inserted = true;
        }
        fin.write((char*)&x, sizeof(x));
    }

    if (!inserted)
        fin.write((char*)&newEmp, sizeof(newEmp));  // Add at the end

    file.close();
    fin.close();

    remove("EMPLOYEE.DAT");
    rename("TEMP.DAT", "EMPLOYEE.DAT");
    cout << "Record inserted successfully.\n";
}

int main() {
    deleteExistingFile();

    int n;
    do {
        cout << "\nENTER CHOICE\n";
        cout << "1. ADD AN EMPLOYEE\n";
        cout << "2. DISPLAY EMPLOYEES (Salary 10000 to 20000)\n";
        cout << "3. SEARCH EMPLOYEE BY CODE\n";
        cout << "4. INCREASE SALARY\n";
        cout << "5. INSERT RECORD IN ORDER\n";
        cout << "6. EXIT\n";
        cin >> n;

        switch (n) {
            case 1:
                appendToFile();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchForRecord();
                break;
            case 4:
                increaseSalary();
                break;
            case 5:
                insertRecord();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (n != 6);

    return 0;
}
