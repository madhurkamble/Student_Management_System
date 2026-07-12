#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int age;
    string branch;
    float cgpa;

public:
    Student();

    // Input & Display
    void input();
    void display() const;

    // Getters
    int getRollNo() const;
    string getName() const;
    int getAge() const;
    string getBranch() const;
    float getCGPA() const;

    // Setters
    void setName(const string &name);
    void setAge(int age);
    void setBranch(const string &branch);
    void setCGPA(float cgpa);
};

#endif