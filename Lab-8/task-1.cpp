// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>

using namespace std;

// ---------- DEFINE STRUCTURE ----------
struct Student{
    string name;
    string email;
    int id;
    double gpa;

    Student(){
        name = "unknown";
        email = "unknwon@example.com";
        id = -1;
        gpa = 0.0;
    }

    Student(string name, string email, int id, double gpa){
        this->name = name;
        this->email = email;
        this->id = id;
        this->gpa = gpa;
    }

    void print(){
        cout << "Student ID: " << id << endl;
        cout << "Student name: " << name << endl;
        cout << "Student email: " << email << endl;
        cout << "Student GPA: " << gpa << endl;
        cout << endl << endl;
    }
};

// ---------- DEFINE NODE CLASS ----------
class Node {
public:
    Student* data;
    Node* next;

    Node(Student* student) {
        data = student;
        next = nullptr;
    }

    ~Node() {
        delete data;
    }
};

// ---------- DEFINE LINKED LIST CLASS ----------
class LinkedList {
    private:
        Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(Student* student) {
        Node* newNode = new Node(student);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void prepend(Student* student) {
        Node* newNode = new Node(student);
        newNode->next = head;
        head = newNode;
    }

    void remove(int studentId) {
        if (head == nullptr) return;

        if (head->data->id == studentId) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data->id != studentId) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student z ID " << studentId << " nie istnieje w liœcie.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->data->print();
            temp = temp->next;
        }
    }
};

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    Student *student1 = new Student();
    student1->print();
    Student *student2 = new Student("Peter", "peter@p.lodz.pl", 124, 4.0);
    student2->print();

    Student *student3 = student2; // pointer copy
    student3->print();
    student3->id = -1;
    student3->print();
    student2->print();

    student1->name = "Matty";
    student1->email = "matty@p.lodz.pl";
    student1->id = 123;
    student1->gpa = 4.75;

    student1->print();

    cout << "------------- Lista -------------" << endl;

    LinkedList myList;
    myList.append(student1);
    myList.append(student2);

    myList.display();

    return 0;
}
