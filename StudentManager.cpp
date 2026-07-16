#include "StudentManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

void StudentManager::saveToFile()
{
    ofstream out("students.txt");

    if (!out)
    {
        cout << "\nError opening file for writing!\n";
        return;
    }

    out << students.size() << endl;

    for (const Student &student : students)
    {
        student.writeToFile(out);
    }

    out.close();
}

void StudentManager::loadFromFile()
{
    std::ifstream in("students.txt");

    if (!in)
    {
        return;
    }

    students.clear();

    int totalStudents = 0;

    if (!(in >> totalStudents))
    {
        std::cout << "Invalid or empty file.\n";
        return;
    }

    in.ignore();

    for (int i = 0; i < totalStudents; i++)
    {
        Student student;
        student.readFromFile(in);
        students.push_back(student);
    }
}

StudentManager::StudentManager()
{
    loadFromFile();
    std::cout << "Student Records Loaded Successfully!\n";
    std::cout << "Total Number of Students : " << students.size() << "\n";
}

void StudentManager::addStudent()
{
    Student student;
    int rollNo;

    cout << "\n===== Add Student =====\n";

    cout << "Enter Roll Number : ";
    cin >> rollNo;

    if (findStudentIndex(rollNo) != -1)
    {
        cout << "\nStudent with Roll Number "
             << rollNo
             << " already exists!\n";
        return;
    }

    student.setRollNo(rollNo);

    cin.ignore();

    student.input();

    students.push_back(student);

    saveToFile();

    cout << "\nStudent added successfully!\n";

    std::cout << "\nTotal Number of Students : " << students.size() << '\n';
}

void StudentManager::displayStudents()
{
    if (students.empty())
    {
        cout << "\nNo student records found.\n";
        return;
    }

    std::cout << "\n=========================================\n";
    std::cout << "          STUDENT RECORDS\n";
    std::cout << "=========================================\n";

    for (const Student &student : students)
    {
        student.display();
    }

    std::cout << "\nTotal Number of Students : " << students.size() << '\n';
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

    while (true)
    {
        cout << "Enter New Age : ";
        cin >> age;

        if (age >= 16 && age <= 35)
            break;

        cout << "Invalid age! Age must be between 16 and 35.\n";
    }

    cin.ignore();

    cout << "Enter New Branch : ";
    getline(cin, branch);

    while (true)
    {
        cout << "Enter New CGPA : ";
        cin >> cgpa;

        if (cgpa >= 0.0 && cgpa <= 10.0)
            break;

        cout << "Invalid CGPA! CGPA must be between 0.0 and 10.0\n";
    }

    students[index].setName(name);
    students[index].setAge(age);
    students[index].setBranch(branch);
    students[index].setCGPA(cgpa);
    saveToFile();

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
            saveToFile();
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

    std::cout << "\nTotal Number of Students : " << students.size() << '\n';
}

void StudentManager::totalStudents()
{
    std::cout << "\n=====================================\n";
    std::cout << "Total Number of Students : " << students.size() << '\n';
    std::cout << "=====================================\n";
}

void StudentManager::sortStudents()
{
    if (students.empty())
    {
        std::cout << "\nNo student records found.\n";
        return;
    }

    int choice;

    std::cout << "\n========== SORT STUDENTS ==========\n";
    std::cout << "1. Sort by Roll Number\n";
    std::cout << "2. Sort by Name\n";
    std::cout << "3. Sort by CGPA (Highest First)\n";
    std::cout << "Enter Choice: ";
    std::cin >> choice;

    Student temp;

    switch (choice)
    {
    case 1:

        // Sort by Roll Number (Ascending)
        for (int i = 0; i < students.size() - 1; i++)
        {
            for (int j = 0; j < students.size() - i - 1; j++)
            {
                if (students[j].getRollNo() > students[j + 1].getRollNo())
                {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        std::cout << "\nStudents sorted by Roll Number.\n";
        break;

    case 2:

        // Sort by Name (Ascending)
        for (int i = 0; i < students.size() - 1; i++)
        {
            for (int j = 0; j < students.size() - i - 1; j++)
            {
                if (students[j].getName() > students[j + 1].getName())
                {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        std::cout << "\nStudents sorted by Name.\n";
        break;

    case 3:

        // Sort by CGPA (Descending)
        for (int i = 0; i < students.size() - 1; i++)
        {
            for (int j = 0; j < students.size() - i - 1; j++)
            {
                if (students[j].getCGPA() < students[j + 1].getCGPA())
                {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        std::cout << "\nStudents sorted by CGPA.\n";
        break;

    default:
        std::cout << "\nInvalid Choice!\n";
        return;
    }

    saveToFile();
}

void StudentManager::showMenu()
{
    int choice;

    do
    {
        std::cout << "\n=========================================\n";
        std::cout << "       STUDENT MANAGEMENT SYSTEM\n";
        std::cout << "=========================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Total Students\n";
        cout << "7. Sort Students\n";
        cout << "8. Exit\n";
        cout<<"Enter Your Choice: ";
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
            totalStudents();
            break;

        case 7:
            sortStudents();
            break;

        case 8:
            std::cout << "\n=========================================\n";
            std::cout << " Thank You for Using Student Management System!\n";
            std::cout << "=========================================\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 8);
}