#include <iostream>
#include <string>
using namespace std;

// Node structure for patients
struct patientNode {
    string name;
    int age;
    string gender;
    string disease;
    patientNode* next;
};

// Queue class for patients
class PatientQueue {
    private:
        patientNode* front;
        patientNode* rear;
    public:
        PatientQueue() {
            front = NULL;
            rear = NULL;
        }
        void addPatient(string name, int age, string gender, string disease) {
            patientNode* temp = new patientNode;
            temp->name = name;
            temp->age = age;
            temp->gender = gender;
            temp->disease = disease;
            temp->next = NULL;
            if (front == NULL && rear == NULL) {
                front = rear = temp;
                return;
            }
            rear->next = temp;
            rear = temp;
        }
        void deletePatient() {
            if (front == NULL) {
                cout << "Queue is empty" << endl;
                return;
            }
            if (front == rear) {
                front = rear = NULL;
            } else {
                front = front->next;
            }
        }
        void displayPatient() {
            if (front == NULL) {
                cout << "Queue is empty" << endl;
                return;
            }
            patientNode* temp = front;
            while (temp != NULL) {
                cout << "Name: " << temp->name << endl;
                cout << "Age: " << temp->age << endl;
                cout << "Gender: " << temp->gender << endl;
                cout << "Disease: " << temp->disease << endl;
                temp = temp->next;
            }
        }
};

// Node structure for doctors
struct doctorNode {
    string name;
    string specialization;
    doctorNode* prev;
    doctorNode* next;
};

// Doubly Linked List class for doctors
class DoctorList {
    private:
        doctorNode* head;
    public:
        DoctorList() {
            head = NULL;
        }
        void insertDoctor(string name, string specialization) {
            doctorNode* temp = new doctorNode;
            temp->name = name;
            temp->specialization = specialization;
            temp->prev = NULL;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
                return;
            }
            doctorNode* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = temp;
            temp->prev = curr;
        }
        void deleteDoctor(string name) {
            doctorNode* curr = head;
            while (curr != NULL) {
                if (curr->name == name) {
                    if (curr == head) {
                        head = curr->next;
                        curr->next->prev = NULL;
                    } else if (curr->next == NULL) {
                        curr->prev->next = NULL;
                    } else {
                        curr->prev->next = curr->next;
                        curr->next->prev = curr->prev;
                    }
                    delete curr;
                    return;
                }
                curr = curr->next;
            }
            cout << "Doctor not found" << endl;
        }
        void displayDoctor() {
            if (head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            doctorNode* curr = head;
            while (curr != NULL) {
                cout << "Name: " << curr->name << endl;
                cout << "Specialization: " << curr->specialization << endl;
                curr = curr->next;
            }
        }
};

void Psystem()
{
	string Pname;
    string Pgender;
    string Pfever;
    int Page;

    cout << "Enter patient's information" << endl;
    cout << "Enter Patient's name" << endl;
    cin >> Pname;
    cout << "Enter Patient's age" << endl;
    cin >> Page;
    cout << "Enter Patient's Gender (Male / Female / Other)" << endl;
    cin >> Pgender;
    cout << "Enter Patient's medical Condition:" << endl;
    cin >> Pfever;
    PatientQueue pq;
    pq.addPatient(Pname, Page, Pgender, Pfever);
    pq.addPatient(Pname, Page, Pgender, Pfever);
    pq.addPatient(Pname, Page, Pgender, Pfever);
    pq.displayPatient();
    pq.deletePatient();
    pq.displayPatient();

}
