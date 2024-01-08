#include <cstring>
#include <iostream>
#include "Node.h"
#include <iomanip>
#include "Student.h"

// https://www.geeksforgeeks.org/iomanip-setprecision-function-in-c-with-examples/
// Used to learn how to set amount of decimals in a float.

using namespace std;

// Prototypes for future functions
void addStudent(node*& head, node* current, node* pre, node* newNode);
void printStudents(node* head);
void deleteStudent(node*& head, node* prev, int studentID);
double averageGPA(node* head);

int main() {
  node* head = nullptr;
  char choice;

  while (true) {
   cout << "Enter choice (A for ADD, P for PRINT, D for DELETE, V for AVERAGE, Q for QUIT): ";
   cin >> choice;
   if (choice == 'A') {
     int studentIDValue;
     cout << "Enter student ID: ";
     cin >> studentIDValue;
     char firstName[80];
     char lastName[80];
     double GPA;
     cout << "Enter first name: ";
     cin >> firstName;
     cout << "Enter last name: ";
     cin >> lastName;
     cout << "Enter GPA: ";
     cin >> GPA;
     cin.ignore(80, '\n');
     student* newStudent = new student(firstName, lastName, studentIDValue, GPA);
     node* newNode = new node(newStudent);
     addStudent(head, head, head, newNode);
   }else if (choice == 'P') {
     printStudents(head);
   } else if (choice == 'D') {
     int studentID;
     cout << "Enter student ID to delete: ";
     cin >> studentID;
     deleteStudent(head, nullptr, studentID);
   } else if (choice == 'V') {
     cout << "Average GPA: " << averageGPA(head) << endl;
   } else if (choice == 'Q') {
     break;
   } else {
     cout << "Invalid choice. Try again." << endl;
   }
  }
 return 0;
}

// ADD function
void addStudent(node*& head, node* current, node* pre, node* newNode) {
  if(head == nullptr) {
    newNode->setNext(head);
    head = newNode;
  }  
  else if(head->getStudent()->getStudentID() > newNode->getStudent()->getStudentID()) {
    newNode->setNext(head);
    head = newNode;
  }
  else if(head->getStudent()->getStudentID() < newNode->getStudent()->getStudentID()) {
    newNode->setNext(head);
    head = newNode;
  }
  else if(newNode->getStudent()->getStudentID() < current->getStudent()->getStudentID()) {
    newNode->setNext(head);
    head = newNode;
  }
  else {
    node* next = head->getNext();
    addStudent(head, current->getNext(), current, newNode);
  }
}

// PRINT function
void printStudents(node* head) {
  if (head == nullptr) {
    return;
  }

  cout << head->getStudent()->getFirstName() << " " << head->getStudent()->getLastName() << ", " << head->getStudent()->getStudentID() << ", " << fixed << setprecision(2) << head->getStudent()->getGPA() << endl;

  printStudents(head->getNext());
}

// DELETE function
void deleteStudent(node*& head, node* prev, int studentID) {
  if (head == nullptr) {
    cout << "Student not found." << endl;
    return;
  }

  if (head->getStudent()->getStudentID() == studentID) {
    node* temp = head;
    head = head->getNext();
    if(prev != nullptr) {
      prev->setNext(head);
    }
    delete temp;
    cout << "Student with ID " << studentID << " deleted." << endl;
    return;
  } 
  node* nextNode = head->getNext();
  deleteStudent(nextNode, head, studentID);
}


// AverageGPA function
double averageGPA(node* head) {
  if (head == nullptr) {
    cout << "No students in the list." << endl;
    return 0.0;
  }
  
  double totalGPA = 0.0;
  int count = 0;

  while (head != nullptr) {
    totalGPA += head->getStudent()->getGPA();
    count++;
    head = head->getNext();
  }

  if (count == 0) {
    cout << "No students in the list." << endl;
    return 0.0;
  }
    
  return totalGPA / count;
}









