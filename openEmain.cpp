#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<map>
#include<string>
#include<sstream>
#include"Teacher.h"
#include"Course.h"
#include"Student.h"
using namespace std;
void static displayMainMenu() // Function to display menu
{
    cout << "---------------------------------------" << endl;
    cout << "1. Enroll in a Course" << endl;
    cout << "2. View Enrolled Courses" << endl;
    cout << "3. Exit" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter your choice: ";
}
void static enrollCourse(Student& student, vector<Course>& courses)   // Function to enroll in a course
{
    cout << "Available Courses:" << endl;
    int i = 1;
    for (const auto& course : courses) {
        cout << i++ << ". " << course.getCourseName() << " (Teacher: " << course.getTeacher()->getName() << ", Capacity: " << course.getMaxCapacity() << ")" << endl;
    }
    cout << "Enter the course number to enroll (0 to cancel): ";
    int choice;
    cin >> choice;
    if (choice > 0 && choice <= courses.size()) {
        Course& selectedCourse = courses[static_cast<std::vector<Course, std::allocator<Course>>::size_type>(choice) - 1];
        if (selectedCourse.enrollStudent(&student)) {
            cout << "Successfully enrolled in " << selectedCourse.getCourseName() << endl;
        }
        else {
            cout << "Sorry, the course is full. Enrollment failed." << endl;
        }
    }
    else {
        cout << "Invalid choice. Enrollment canceled." << endl;
    }
}


void static viewCourses(const Student& student) //Function to display enrolled courses
{

    ifstream file("courses.txt"); // Assuming the file name is "courses.txt"
    if (!file.is_open()) {
        cerr << "Failed to open the file.\n";
    }
    string course;
    while (getline(file, course)) {
        cout << course << endl;
    }

    file.close();
}
void static viewEnrolled()
{
    ifstream file("Enrolled.txt"); // Assuming the file name is "courses.txt"
    if (!file.is_open()) {
        cerr << "Failed to open the file.\n";
    }
    string course;
    while (getline(file, course)) {
        cout << course << endl;
    }

    file.close();

}
int main() {
    // Create students
    vector<Student> students;
    Student student1("111", "tayyaba", "tayyaba@gmail.com");
    Student student2("222", "Samreen", "samreen@gmail.com");
    // Create teachers
    vector<Teacher>teachers;
    Teacher teacher1("T1", "maam joddat", "joddat@gmail.com");
    Teacher teacher2("T2", "sir waleed", "waleed@gmail.com");
    Teacher teacher3("T3", "sir tamim", "tamim@gmail.com");
    // Create courses
    vector<Course> courses;
    courses.push_back(Course("ES", "Environmental sciences", &teacher1, 3));
    courses.push_back(Course("oop", "object oriented programming ", &teacher2, 2));
    courses.push_back(Course("cf", "computer fundamentals", &teacher3, 2));
    string name, email;
    cout << " Bahria University Management System " << endl;
    cout << "----------------------------------------";
    cout << "\nEnter your detail for admission: " << endl;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Offered cousres: ";
    viewCourses(student1);
    // Main loop
    while (true) {
        displayMainMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            enrollCourse(student1, courses);
            break;
        case 2:
            viewEnrolled();
            break;
        case 3:
            cout << "Exiting University Management System. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }


    return 0;
}