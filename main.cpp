#include <cstring?
#include <iostream>
#include "Node.h"

using namespace std;

//Prototypes for fututre functions
void addStudent(node*& head);
void printStudents(node* head);
void deleteStudent(node*& head, int studentID);
double calculateAverageGPA(node* head);
void deleteList(node*& head);

int main() {
    node* head = nullptr;
    char choice;

    while (true) {
        cout << "Enter choice (A for ADD, P for PRINT, D for DELETE, V for AVERAGE, Q for QUIT): ";
        cin >> choice;

        if (choice == 'A') {
            addStudent(head);
        } else if (choice == 'P') {
            printStudents(head);
        } else if (choice == 'D') {
            int studentID;
            cout << "Enter student ID to delete: ";
            cin >> studentID;
            deleteStudent(head, studentID);
        } else if (choice == 'V') {
            cout << "Average GPA: " << calculateAverageGPA(head) << endl;
        } else if (choice == 'Q') {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
//ADD function
void addStudent(node*& head) {

}
//PRINT function
void printStudents(node* head) {

}
//DELETE function
void deleteStudent(node*& head, int studentID) {

}
//AverageGPA function
double calculateAverageGPA(node* head) {

}





