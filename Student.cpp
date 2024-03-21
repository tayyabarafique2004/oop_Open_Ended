#include "Student.h"
#include "Course.h"

Student::Student(const string& studentID, const string& name, const string& email) : studentID(studentID), name(name), email(email) {}


void Student::enrollCourse(Course* course) {
    coursesEnrolled.push_back(course);
}

void Student::dropCourse(Course* course) {
    for (auto it = coursesEnrolled.begin(); it != coursesEnrolled.end(); ++it) {
        if (*it == course) {
            coursesEnrolled.erase(it);
            return;
        }
    }
}

void Student::viewCourses() const {
    cout << "Enrolled Courses:" << endl;
    for (const auto& coursePtr : coursesEnrolled) {
        const Course& course = *coursePtr; // Dereference the pointer to get the Course object
        cout << "Course Code: " << course.getCourseCode() << endl;
        cout << "Course Name: " << course.getCourseName() << endl;

        cout << "-------------------" << endl;
    }
}


string Student::getName() const {
    return name;
}
string Student::getID() const {
    return studentID;
} // Getter for student ID

string Student::getEmail() const {
    return email;
}