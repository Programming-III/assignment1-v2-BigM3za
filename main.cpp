#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"

using namespace std;

Person::Person() {
    this->name = "";
    this->id = 0;
}

Person::Person(string name, int id) {
    this->name = name;
    this->id = id;
}

string Person::getName() {
    return name;
}

int Person::getID() {
    return id;
}

void Person::display() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}

Student::Student() : Person() {
    this->yearLevel = 0;
    this->major = " ";
}

Student::Student(string name, int id, int yearLevel, string major) : Person(name, id) {
    this->yearLevel = yearLevel;
    this->major = major;
}

void Student::display() {
    cout << "Name: " << getName() << endl;
    cout << "Year: " << yearLevel << endl;
    cout << "Major: " << major << endl;
}

Instructor::Instructor() : Person() {
    this->department = " ";
    this->experienceYears = 0;
}

Instructor::Instructor(string name, int id, string dept, int exp) : Person(name, id) {
    this->department = dept;
    this->experienceYears = exp;
}

void Instructor::display() {
    cout << "Name: " << getName() << endl;
    cout << "Department: " << department << endl;
    cout << "Experience: " << experienceYears << " years" << endl;
}

Course::Course() {
    this->courseCode = " ";
    this->courseName = " ";
    this->maxStudents = 0;
    this->currentStudents = 0;
    this->students = NULL;
    this->instructor = NULL;
}

Course::Course(string code, string name, int max) {
    this->courseCode = code;
    this->courseName = name;
    this->maxStudents = max;
    this->currentStudents = 0;
    this->students = new Student[max];
    this->instructor = NULL;
}

Course::~Course() {
    delete[] students;
}

void Course::setInstructor(Instructor* inst) {
    this->instructor = inst;
}

void Course::addStudent(const Student& s) {
    if (currentStudents < maxStudents) {
        students[currentStudents] = s;
        currentStudents++;
    }
}

void Course::displayCourseInfo() {
    cout << "Course: " << courseCode << " - " << courseName << endl;
    cout << "Max Students: " << maxStudents << endl;

    cout << "Currently Enrolled: ";
    for (int i = 0; i < currentStudents; i++) {
        cout << students[i].getName() << " (ID: " << students[i].getID() << ")";
        if (i < currentStudents - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Instructor Info:" << endl;
    if (instructor != NULL) {
        instructor->display();
    }

    cout << "Student info:" << endl;
    for (int i = 0; i < currentStudents; i++) {
        students[i].display();
        if (i < currentStudents - 1) {
            cout << endl;
        }
    }
}

int main() {
    Student s1("Omar Nabil", 2202, 2, "Informatics");
    Instructor i1("Dr. Lina Khaled", 1101, "Computer Science", 5);

    Course c1("CS101", "Introduction to Programming", 3);

    c1.setInstructor(&i1);
    c1.addStudent(s1);

    c1.displayCourseInfo();

    return 0;
}
