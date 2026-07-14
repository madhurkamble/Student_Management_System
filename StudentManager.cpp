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

int StudentManager::findStudentIndex(int rollNo)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getRollNo() == rollNo)
        {
            return i;
        }
    }

    return -1;
}


void StudentManager::searchStudent()
{
    int rollNo;

    cout << "\nEnter Roll Number : ";
    cin >> rollNo;

    int index = findStudentIndex(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found.\n";
    }
    else
    {
        cout << "\nStudent Found:\n";
        students[index].display();
    }
}

void StudentManager::updateStudent()
{
    int rollNo;

    cout << "\nEnter Roll Number to Update: ";
    cin >> rollNo;

    int index = findStudentIndex(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found.\n";
        return;
    }

    cin.ignore();

    string name;
    int age;
    string branch;
    float cgpa;

    cout << "\nEnter New Name : ";
    getline(cin, name);

    cout << "Enter New Age : ";
    cin >> age;

    cin.ignore();

    cout << "Enter New Branch : ";
    getline(cin, branch);

    cout << "Enter New CGPA : ";
    cin >> cgpa;

    students[index].setName(name);
    students[index].setAge(age);
    students[index].setBranch(branch);
    students[index].setCGPA(cgpa);

    cout << "\nStudent updated successfully!\n";
}

void StudentManager::deleteStudent()
{
    int rollNo;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> rollNo;

    int index = findStudentIndex(rollNo);

    if (index == -1)
    {
        cout << "\nStudent not found.\n";
        return;
    }

    char choice;

    while (true)
    {
        cout << "\nAre you sure you want to delete this student? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            students.erase(students.begin() + index);
            cout << "\nStudent deleted successfully!\n";
            break;
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "\nDeletion cancelled.\n";
            break;
        }
        else
        {
            cout << "\nInvalid choice! Please enter Y or N.\n";
        }
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
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
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
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank you!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);
}