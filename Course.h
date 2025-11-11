#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include "Instructor.h"

class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
    Instructor* instructor;

public:
    Course();
    Course(string code, string name, int max);
    ~Course();
    void setInstructor(Instructor* inst);
    void addStudent(const Student& s);
    void displayCourseInfo();
};

#endif
