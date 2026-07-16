#pragma once

#include <vector>
#include "Student.h"
#include <fstream>

class StudentManager
{
private:
    std::vector<Student> students;
    int findStudentIndex(int rollNo);
    void saveToFile();
    void loadFromFile();
public:
    StudentManager();
    void addStudent();
    void displayStudents();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    void totalStudents();
    void sortStudents();
    void showMenu();
};