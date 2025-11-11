#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"

class Instructor : public Person {
private:
    string department;
    int experienceYears;

public:
    Instructor();
    Instructor(string name, int id, string dept, int exp);
    void display();
};

#endif
