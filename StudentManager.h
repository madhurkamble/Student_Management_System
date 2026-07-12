#pragma once

#include <vector>
#include "Student.h"

class StudentManager
{
private:
    std::vector<Student> students;

public:
    void addStudent();
    void displayStudents();
    void showMenu();
};