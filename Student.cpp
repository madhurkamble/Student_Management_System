#include "Student.h"

Student::Student()
{
    rollNo = 0;
    age = 0;
    cgpa = 0.0f;
}

void Student::input()
{
    std::cout << "Enter Name : ";
    std::getline(std::cin, name);

    while (true)
    {
        std::cout << "Enter Age : ";
        std::cin >> age;

        if (age >= 16 && age <= 35)
            break;

        std::cout << "Invalid age! Age must be between 16 and 35.\n";
    }

    std::cin.ignore();

    std::cout << "Enter Branch : ";
    std::getline(std::cin, branch);

    while (true)
    {
        std::cout << "Enter CGPA : ";
        std::cin >> cgpa;

        if (cgpa >= 0.0 && cgpa <= 10.0)
            break;

        std::cout << "Invalid CGPA! CGPA must be between 0.0 and 10.0\n";
    }
}

void Student::writeToFile(std::ofstream &out) const
{
    out << rollNo << endl;
    out << name << endl;
    out << age << endl;
    out << branch << endl;
    out << cgpa << endl;
}

void Student::readFromFile(std::ifstream &in)
{
    in >> rollNo;
    in.ignore();

    getline(in, name);

    in >> age;
    in.ignore();

    getline(in, branch);

    in >> cgpa;
    in.ignore();
}

void Student::display() const
{
    std::cout << "\n=========================================\n";
    std::cout << "          STUDENT RECORDS\n";
    std::cout << "=========================================\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Roll Number : " << rollNo << '\n';
    std::cout << "Name        : " << name << '\n';
    std::cout << "Age         : " << age << '\n';
    std::cout << "Branch      : " << branch << '\n';
    std::cout << "CGPA        : " << cgpa << '\n';
    std::cout << "----------------------------------------\n";
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

void Student::setRollNo(int rollNo)
{
    this->rollNo = rollNo;
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