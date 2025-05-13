#pragma once
#include "Date.h"
#include "Person.h"
#include "Status.h"
#include "Subjects.h"

class Student : public Person
{
private:
    int studentId;
    std::vector<std::pair<Subjects, std::vector<int>>> grades;
    Status status;
    Date date;

public:
    Student() = default;

    Student(const char* givenName, const char* familyName, const Date& dateOfBirth, int StudentId, const std::vector<std::pair<Subjects, std::vector<int>>>& Grades, Status StatusValue);

    Student(const char* GivenName, const char* FamilyName, Date& DateOfBirth, int StudentId);

    Student(const char* GivenName, const char * FamilyName, int StudentID);

    Student& operator=(const Student& other);

    Student(const Student& other);

    //~Student();

    const char* getGivenName() const;
    const char* getFamilyName() const;
    const Status& getStatus() const;
    const int getStudentId() const;

    const std::string enumToString(Subjects subject) const;

    double averageGrade(const Subjects subject) const;
    double averageOfAverages() const;
    int callAgeMethod() const;

    void addGrade(int grade, const Subjects subject);
    void modifyGrade(int index, int newGrade, Subjects subject);
    void removeGrade(int index, Subjects subject);

    void display();

    friend std::istream& operator>>(std::istream& in, Student& student);
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

void studentStatus(std::vector<Student>& students, Status status);
void sortStudents(std::vector<Student>& students);