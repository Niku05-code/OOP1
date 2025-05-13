#include "Teacher.h"

Teacher::Teacher(const char* GivenName, const char* FamilyName, const Date& DateOfBirth, Subjects Subject, Date DateOfHiring, std::vector<Student> Students)
    : Person(GivenName, FamilyName, DateOfBirth) {
    subject = Subject;
    dateOfHiring = DateOfHiring;
    students = Students;
}

void Teacher::assignStudent(const Student &student) {
    students.push_back(student);
}

void Teacher::deassignStudent(const Student &student) {
    for (auto i = students.begin(); i != students.end(); ++i) {
        if (student.getStudentId() == i -> getStudentId()) {
            students.erase(i);
            return;
        }
    }
}

int Teacher::callAgeMethod() const {
    return dateOfHiring.getAge(dateOfHiring);
}


int Teacher::getNumbersOfStudents() const{
    return students.size();
}


void Teacher::display() const {
    Person::display();
    std::cout << "Subject: ";
    switch (subject) {
        case Subjects::Math: {
            std::cout << "Math";
            break;
        }
        case Subjects::ComputerScience: {
            std::cout << "Computer Science";
            break;
        }
        case Subjects::English: {
            std::cout << "English";
            break;
        }
        case Subjects::Physics: {
            std::cout << "Physics";
            break;
        }
        case Subjects::History: {
            std::cout << "History";
            break;
        }
    }
    std::cout << "\nDate of Hiring: " << dateOfHiring<< "\n";

    std::cout << "Students Assigned: ";
    if (students.empty()) {
        std::cout << "None";
    } else {
        for (const auto& student : students) {
            std::cout << student.getStudentId() << " ";
        }
    }
    std::cout << "\n";

    if(callAgeMethod() < 6)
        std::cout << "Experience: Novice";
    else if(callAgeMethod() < 16)
        std::cout << "Experience: Experienced";
    else
        std::cout << "Experience: Veteran";

}


