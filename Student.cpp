#include "Student.h"

Student::Student()
{
    rollNo = 0;
    age = 0;
    cgpa = 0.0f;
}

void Student::input()
{
    cout << "\nEnter Roll Number : ";
    cin >> rollNo;

    cin.ignore();

    cout << "Enter Name : ";
    getline(cin, name);

    cout << "Enter Age : ";
    cin >> age;

    cin.ignore();

    cout << "Enter Branch : ";
    getline(cin, branch);

    cout << "Enter CGPA : ";
    cin >> cgpa;
}

void Student::display() const
{
    cout << "\n-----------------------------\n";
    cout << "Roll Number : " << rollNo << endl;
    cout << "Name        : " << name << endl;
    cout << "Age         : " << age << endl;
    cout << "Branch      : " << branch << endl;
    cout << "CGPA        : " << cgpa << endl;
}

int Student::getRollNo() const
{
    return rollNo;
}

string Student::getName() const
{
    return name;
}

int Student::getAge() const
{
    return age;
}

string Student::getBranch() const
{
    return branch;
}

float Student::getCGPA() const
{
    return cgpa;
}

void Student::setName(const string &n)
{
    name = n;
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setBranch(const string &b)
{
    branch = b;
}

void Student::setCGPA(float c)
{
    cgpa = c;
}