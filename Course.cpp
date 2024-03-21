#include "Course.h"
#include "Teacher.h"
#include "Student.h"

Course::Course(const string& code, const string& name, Teacher* teacher, size_t capacity) :
    courseCode(code), courseName(name), teacher(teacher), maxCapacity(capacity) {}

bool Course::enrollStudent(Student* student) {
    if (studentsEnrolled.size() < maxCapacity) {
        studentsEnrolled.push_back(student);
        return true;
    }
    return false;
}

void Course::viewStudents() const {
    cout << "Students enrolled in " << courseName << ":" << endl;
    for (auto student : studentsEnrolled) {
        cout << student->getName() << endl;
    }
}

size_t Course::getEnrolledStudentCount() const {
    return studentsEnrolled.size();
}

size_t Course::getMaxCapacity() const {
    return maxCapacity;
}
string Course::getCourseCode() const {
    return courseCode;
}

Course::Course(const std::string& code, const std::string& name, int capacity)
    : courseCode(code), courseName(name), maxCapacity(capacity) {
    // Constructor implementation...
}
