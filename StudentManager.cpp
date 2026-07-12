#include "StudentManager.h"
#include <iostream>

using namespace std;

void StudentManager::addStudent()
{
    Student student;

    cout << "\n===== Add Student =====\n";

    student.input();

    students.push_back(student);

    cout << "\nStudent added successfully!\n";
}

void StudentManager::displayStudents()
{
    if (students.empty())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n===== Student Records =====\n";

    for (const Student &student : students)
    {
        student.display();
    }
}

void StudentManager::showMenu()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "     STUDENT MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            cout << "\nThank you!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);
}