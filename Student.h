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
class Course;
class Teacher;
class Student
{
private:
    string studentID;
    string name;
    string email;
    vector<Course*> coursesEnrolled;

public:
    Student(const string& studentID, const string& name, const string& email);

    void enrollCourse(Course* course);
    void dropCourse(Course* course);

    string getName() const;
    string getID()const;  // Getter for student ID
    string getEmail()const;
    void viewCourses()const;

};
