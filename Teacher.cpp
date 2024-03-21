#include "Teacher.h"
#include"Course.h"
#include"Student.h"
class Course;

Teacher::Teacher(const std::string& teacherID, const std::string& name, const std::string& email)
    : teacherID(teacherID), name(name), email(email) {}

// Other member functions...

void Teacher::assignCourse(Course* course) {
    coursesTaught.push_back(course);
}

void Teacher::removeCourse(Course* course) {
    for (auto it = coursesTaught.begin(); it != coursesTaught.end(); ++it) {
        if (*it == course) {
            coursesTaught.erase(it);
            return;
        }
    }
}

void Teacher::viewCourses() const
{
    cout << "Courses taught by " << name << ":" << endl;
    for (auto course : coursesTaught) {
        cout << course->getCourseName() << endl;

    }
}
string Teacher::getName() const {
    return name;
}
string Teacher::getEmail() const {

    return email;
}

string Teacher::getID() const {

    return teacherID;
}