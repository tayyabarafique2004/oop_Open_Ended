#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<map>
#include<string>
#include"Teacher.h"
#include"Course.h"
#include"Student.h"

using namespace std;
class Teacher; // Forward declaration
class Student; // Forward declaration

class Course {
private:
    string courseCode;
    string courseName;
    Teacher* teacher;
    size_t maxCapacity;
    vector<Student*> studentsEnrolled;

public:
    Course(const string& code, const string& name, Teacher* teacher, size_t capacity);
    Course(const std::string& code, const std::string& name, int capacity);
    string getCourseName() const { return courseName; }
    Teacher* getTeacher() const { return teacher; }
    bool enrollStudent(Student* student);
    void viewStudents() const;
    size_t getEnrolledStudentCount() const;
    size_t getMaxCapacity() const;
    string getCourseCode() const;

};