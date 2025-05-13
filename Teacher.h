#pragma once
#include "Person.h"
#include "Student.h"
#include "Subjects.h"
#include "Date.h"
#include "Experiences.h"

class Teacher : public Person {
private:
    Subjects subject;
    Date dateOfHiring;
    std::vector<Student> students;

public:
    Teacher() = default;

    Teacher(const char* GivenName, const char* FamilyName, const Date& DateOfBirth, Subjects Subject, Date DateOfHiring, std::vector<Student> Students);

    void assignStudent(const Student& student);
    void deassignStudent(const Student& student);

    int callAgeMethod() const;

    int getNumbersOfStudents() const;

    void display() const override;

};
