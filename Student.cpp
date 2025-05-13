#include <iostream>
#include "Student.h"
#include "Status.h"

Student::Student(const char* givenName, const char* familyName, const Date& dateOfBirth, int StudentId, const std::vector<std::pair<Subjects, std::vector<int>>>& Grades, Status StatusValue)
: Person(givenName, familyName, dateOfBirth) {
    studentId = StudentId;
    grades = Grades;
    status = StatusValue;
}

Student::Student(const char* GivenName, const char* FamilyName, Date& DateOfBirth, int StudentId)
: Person(givenName, familyName, dateOfBirth), studentId(studentId), grades(), status(Status::ENROLLED) {}

Student::Student(const char* GivenName, const char * FamilyName, int StudentID) {
    givenName = new char[strlen(GivenName) + 1];
    strcpy(givenName, GivenName);
    familyName = new char[strlen(FamilyName) + 1];
    strcpy(familyName, FamilyName);
    studentId = StudentID;
}

Student::Student(const Student& other)
    : Person(other), studentId(other.studentId), grades(other.grades), status(other.status) {}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Person::operator=(other);
        studentId = other.studentId;
        grades = other.grades;
        status = other.status;
    }
    return *this;
}

// Student::~Student()
// {
//     if(givenName != nullptr)
//         delete[] givenName;
//     if(familyName != nullptr)
//         delete[] familyName;
//     studentId = 0;
//     grades.clear();
//     //status = 0;
//     //dateOfBirth = new (0, 0, 0);
// }

const char *Student::getFamilyName() const
{
    return familyName;
}

const char *Student::getGivenName() const
{
    return givenName;
}

const Status &Student::getStatus() const
{
    return status;
}

const int Student::getStudentId() const {
    return studentId;
}

const std::string Student::enumToString(Subjects subject) const {
    switch (subject) {
        case Subjects::Math:
            return "Math";
        case Subjects::ComputerScience:
            return "ComputerScience";
        case Subjects::English:
            return "English";
        case Subjects::Physics:
            return "Physics";
        case Subjects::History:
            return "History";
    }
}

double Student::averageGrade(const Subjects subject) const {
    double sum = 0, average;
    for (const auto& entry : grades) {
        if(entry.first == subject) {
            const std::vector<int>& numbers = entry.second;
            for(int number : numbers) {
                sum += number;
            }
            average = sum / grades.size();
            break;
        }
        //std::accumulate(grades)
    }
    return average;
}

double Student::averageOfAverages() const {
    double sum = 0, average;
    for (const auto& entry : grades) {
        sum += averageGrade(entry.first);
    }
    return sum / grades.size();
}

int Student::callAgeMethod() const {
    return date.getAge(dateOfBirth);
}


void Student::addGrade(int grade, const Subjects subject)
{
    //if(grade)
    for (auto& entry : grades) {
        if (entry.first == subject) {
            entry.second.push_back(grade);
        }
    }
    std::cout << "Added grade: " << grade << " at " << enumToString(subject) << " to " << familyName << " " << givenName << std::endl;
}

void Student::modifyGrade(int index, int newGrade, Subjects subject)
{
    for (auto& entry : grades) {
        if (entry.first == subject) {
            int oldGrade = entry.second[index];
            entry.second[index] = newGrade;
            std::cout << "Grade " << oldGrade << " modified with the grade " << newGrade << " at " << enumToString(subject) << std::endl;
        }
    }
}

void Student::removeGrade(int index, Subjects subject)
{
    for (auto& entry : grades) {
        if (entry.first == subject) {
            int oldGrade = entry.second[index];
            entry.second.erase(entry.second.begin() + index);
            std::cout << "Removed grade: " << oldGrade << " at " << enumToString(subject) << std::endl;
        }
    }
}

void Student::display() {
    std::cout << "Name: " << givenName << " " << familyName << std::endl;
    std::cout << "Id: " << studentId << std::endl;
    std::cout << "Grades: " << std::endl;
    for (auto& entry : grades) {
        std::cout << enumToString(entry.first) << " ";
        for (int i = 0; i < entry.second.size(); ++i) {
            std::cout << entry.second[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Average Grade: " << std::endl;
    for (auto& entry : grades) {
        std::cout << enumToString(entry.first) << " ";
        std::cout << averageGrade(entry.first) << " ";
        std::cout << std::endl;
    }

    std::cout << "Status: ";
    switch (status)
    {
        case Status::ENROLLED:
        {
            std::cout << "ENROLLED" << std::endl;
            break;
        }
        case Status::GRADUATED:
        {
            std::cout << "GRADUATED" << std::endl;
            break;
        }
        case Status::DROPPED_OUT:
        {
            std::cout << "DROPPED_OUT" << std::endl;
            break;
        }
    }
    if(dateOfBirth.getYear() != 0 && dateOfBirth.getDay() != "" && dateOfBirth.getMonth() != "" ) {
        std::cout << "Date of Birth: " << dateOfBirth << std::endl;
        std::cout << "Age: " << date.getAge(dateOfBirth) << std::endl;
    }
}

std::istream& operator>>(std::istream& in, Student& student)
{
    int subjectInt;
    int numGrades;
    int grade;
    int statusInt;
    Status studentStatus;

    in >> static_cast<Person&>(student);

    in >> student.studentId;

    student.grades.resize(5);
    for(int i = 0; i < 5; ++i) {
        in >> subjectInt;
        student.grades[i].first = static_cast<Subjects>(subjectInt);
        in >> numGrades;
        student.grades[i].second.resize(numGrades);
        for(int j = 0; j < numGrades; ++j) {
            // in >> grade;
            // student.grades[i].second.push_back(grade);
            in >> student.grades[i].second[j];
        }
    }

    in >> statusInt;
    student.status = static_cast<Status>(statusInt);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << "Name: " << student.givenName << " " << student.familyName << std::endl;
    out << "Id: " << student.studentId << std::endl;
    out << "Grades: " << std::endl;
    for (auto& entry : student.grades) {
        std::cout << student.enumToString(entry.first) << ": ";
        for (int i = 0; i < entry.second.size(); ++i) {
            std::cout << entry.second[i] << " ";
        }
        std::cout << std::endl;
    }
    out << "Average Grade: " << std::endl;
    for (auto& entry : student.grades) {
        std::cout << student.enumToString(entry.first) << ": ";
        std::cout << student.averageGrade(entry.first);
        std::cout << std::endl;
    }
    out << "Total: " << student.averageOfAverages() << std::endl;
    out << "Status: ";
    switch (student.status)
    {
        case Status::ENROLLED:
        {
            out << "ENROLLED" << std::endl;
            break;
        }
        case Status::GRADUATED:
        {
            out << "GRADUATED" << std::endl;
            break;
        }
        case Status::DROPPED_OUT:
        {
            out << "DROPPED_OUT" << std::endl;
            break;
        }
    }
    if(student.dateOfBirth.getYear() != 0 && student.dateOfBirth.getDay() != "" && student.dateOfBirth.getMonth() != "" ) {
        out << "Date of Birth: " << student.dateOfBirth << std::endl;
        out << "Age: " << student.callAgeMethod() << std::endl;
    }
    return out;
}

void studentStatus(std::vector<Student>& students, Status status)
{
    std::cout << "Students with status ";
    switch (status)
    {
        case Status::ENROLLED:
        {
            std::cout << "ENROLLED";
            break;
        }
        case Status::GRADUATED:
        {
            std::cout << "GRADUATED";
            break;
        }
        case Status::DROPPED_OUT:
        {
            std::cout << "DROPPED_OUT";
            break;
        }
    }
    std::cout << ":" << std::endl;

    for (auto student : students)
    {
        if (student.getStatus() == status)
            std::cout << student.getFamilyName() << " " << student.getGivenName()<< std::endl;
    }
}

void sortStudents(std::vector<Student>& students)
{
    auto comp = [] (Student& a, Student& b)
    {
        return a.averageOfAverages() > b.averageOfAverages();
    };
    std::sort(students.begin(), students.end(), comp);
}