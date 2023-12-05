#pragma once
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
    PatientQueue();
    void input();
    void addPatient(string name, int age, string gender, string disease);
    void deletePatient();
    void displayPatient();
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
    DoctorList();
    void dinput();
    void insertDoctor(string name, string specialization);
    void deleteDoctor(string name);
    void displayDoctor();
};
void user();



    



