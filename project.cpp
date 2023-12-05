#include <iostream>
#include <cctype>
#include <string>
#include "project.h"
using namespace std;

PatientQueue::PatientQueue()
{
	front = NULL;
	rear = NULL;
}

void PatientQueue:: input()
{
    int vote = 1;
    string name, disease,gender;
    int age;

 while (vote == 1)
 {
    cout << "Enter the patient name: ";
    cin >> name;
    cout << "Enter the patient age: ";
    cin >> age;

    string genderInput;
    cout << "Enter patient gender (1-male, 2-female, 3-other): ";
    cin >> genderInput;
    bool validInput = true;
    for (char ch : genderInput)
        {
            if (!isdigit(ch))
            {
                validInput = false;
                break;
            }
        }

        if (validInput)
        {
            int gender1 = stoi(genderInput);
            if (gender1 == 1)
                gender = "male";

            else if (gender1 == 2)
                gender = "female";

            else if (gender1 == 3)
                gender = "other";

            else
                cout << "Invalid gender input. Please choose 1, 2, or 3." << endl;
        }

        else
        {
            cout << "Please enter a numeric value for gender." << endl;
        }

        cout << "enter patient disease\n";
        cin >> disease;
        addPatient(name,age,gender,disease);
        cout << "do you want to enter any other patient informations\n 1-yes\n 2-no\n";
        cin >> vote;
        while (vote != 1 && vote != 2)
        {
            cout << "do you want to enter any other patient informations\n 1-yes\n 2-no\n";
            cin >> vote;
        }
    }
}

void PatientQueue::addPatient(string name,int age,string gender,string disease)
{
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

void PatientQueue::deletePatient()
{
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
}

void PatientQueue::displayPatient()
{
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

DoctorList::DoctorList()
{
    head = NULL;
}

void DoctorList::dinput()
{
    string name, specialization;
    int vote = 1;
    while (vote ==1)
    {
        cout << "enter the doctor name\n";
        cin >> name;
        cout << "enter the doctor specialization\n";
        cin >> specialization;
        insertDoctor(name, specialization);
        cout << "do you want to add any other doctors informations\n 1-yes\n 2-no\n";
        cin >> vote;
        while (vote != 1 && vote != 2)
        {
            cout << "do you want to add any other doctors informations\n 1-yes\n 2-no\n";
            cin >> vote;

        }
    }
    
   

}

void DoctorList::insertDoctor(string name, string specialization)
{
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

void DoctorList::deleteDoctor(string name) {
    doctorNode* curr = head;
    doctorNode* temp = nullptr; // Initialize temp

    if (curr == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    while (curr != nullptr) {
        if (curr->name == name) {
            if (curr == head) {
                head = curr->next;
            }
            else if (curr->next == nullptr) {
                curr->prev->next = nullptr; // Update prev pointer of new tail
            }
            else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            temp = curr; // Set temp before deletion
            curr = curr->next; // Move curr to the next node
            delete temp; // Delete the node
            return;
        }
        curr = curr->next;
    }
    cout << "Doctor not found\n" << endl;
}

void DoctorList::displayDoctor()
{
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

void user()
{
    string user = "patients";
    string options = "nothing";
    string options2 = "nothing";
    string dname,state;
    int user1,options1,state1,options3;
    cout << "choose the type of informations u need to insert\n 1-patients\n 2-doctors\n";
    cin >> user1;
    if (user1 == 1)
        user = "patients";
    else if (user1 == 2)
        user = "doctors";
    else
    {
        cout << "please choose between the available options\n 1-patients\n 2-doctors\n";
        cin >> user1;
    }

    PatientQueue q;
    DoctorList d;

    while (true)
    {
        if (user1 == 1)
        {
            
            q.input();
            do
            {
                cout << "choose one of the following options\n 1-display\n 2-delete\n 3-nothing\n";
                cin >> options1;
        
                if (options1 == 1)
                {
                    
                    q.displayPatient();
                }
                else if (options1 ==2)
                {
                
                    q.deletePatient();
                }
                else if (options1 ==3)
                    options = "nothing";
                else
                {
                    cout <<"error\n";
                   
                    
                }
               
            }
            
                
       

            while (options1 != 3);
            cout << "do u want to exit\n 1-yes\n 2-no)\n";
            cin >> state1;
            if (state1 == 2)
            {
                
                cout << "choose the type of informations u need to insert\n 1-patients\n 2-doctors\n";
                cin >> user1;
            }
            else if (state1==1)
            {
            
                break;
            }
            else
            {
                cout << "please choose between the available options\n 1-patients\n 2-doctors\n";
                cin >> user1;

            }
                

            
        }

        else if(user1==2)
        {
            
            d.dinput();
            do
            {
                cout << "please choose from the available options\n 1-display\n 2-delete\n 3-nothing\n";
                cin >> options3;
                if (options3 == 1)
                {
                    d.displayDoctor();
                }
                else if (options3 == 2)
                {
                    cout << "enter the doctors name you want to delete\n";
                    cin >> dname;
                    d.deleteDoctor(dname);
                }
                else if (options3 == 3)
            
                    continue;
                else
                {
                    cout <<"error\n";
                

                }
            } while (options3 != 3);
              cout << "do u want to exit\n 1-yes\n 2-no\n";
              cin >> state1;
              if (state1 ==2)
              {
                  cout << "please choose between the available options\n 1-patients\n 2-doctors\n";
                  cin >> user1;

                  continue;
              }
              else if(state1==1)
              {
                  break;
              }
              else
              {
                  cout << "please choose between the available options\n 1-yes\n 2-no\n";
                  cin >> state1;
              }

           
                 
        }
    }
}
