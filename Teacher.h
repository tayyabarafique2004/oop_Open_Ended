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
class Teacher
{
private:
    string teacherID;
    string name;
    string email;
    vector<Course*> coursesTaught;

public:
    Teacher(const std::string& teacherID, const std::string& name, const std::string& email);


    void assignCourse(Course* course);
    void removeCourse(Course* course);
    void viewCourses() const;
    string getName() const;
    string getEmail() const;
    string getID() const;
};