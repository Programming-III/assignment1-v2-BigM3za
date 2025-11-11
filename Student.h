#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int yearLevel;
    string major;

public:
    Student();
    Student(string name, int id, int yearLevel, string major);
    void display();
};

#endif
