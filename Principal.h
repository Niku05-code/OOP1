#pragma once
#include "Person.h"
#include "Student.h"
#include "Date.h"
#include "Teacher.h"

class Principal : public Person {
private:
    //static std::unique_ptr<Principal> instance;
    std::vector<Teacher> teachers;
    std::vector<Student> students;

public:

    Principal() = default;

    Principal(const char* GivenName, const char* FamilyName, const Date& DateOfBirth, std::vector<Teacher> Teachers, std::vector<Student> Students);

    void addTeacher(const Teacher& Teacher);
    void addStudent(const Student& Student);

    //static Principal& getInstance();

    void displaySchoolOverview() const;
    void displayNumberOfStudents() const;
};