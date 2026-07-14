#pragma once

#include <vector>
#include "Student.h"

class StudentManager
{
private:
    std::vector<Student> students;
    int findStudentIndex(int rollNo);
    
public:
    void addStudent();
    void displayStudents();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    void showMenu();
};