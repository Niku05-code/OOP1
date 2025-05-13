#include "Principal.h"

Principal::Principal(const char *GivenName, const char *FamilyName, const Date &DateOfBirth, std::vector<Teacher> Teachers, std::vector<Student> Students)
    : Person(GivenName, FamilyName, DateOfBirth){
    teachers = Teachers;
    students = Students;
}
// Principal &Principal::getInstance() {
//     if (!instance) {
//         instance = std::unique_ptr<Principal>(new Principal());
//     }
//     return *instance;
// }


void Principal::addTeacher(const Teacher &Teacher) {
    teachers.push_back(Teacher);
}
void Principal::addStudent(const Student& Student) {
    students.push_back(Student);
}
void Principal::displaySchoolOverview() const {
    std::cout << std::endl << "School Overview:" << std::endl;
    std::cout << "Number of Teachers:" << teachers.size() << std::endl;
    std::cout << "Number of Students:" << students.size() << std::endl;
}
void Principal::displayNumberOfStudents() const {
    for(auto &teacher : teachers) {
        std::cout << teacher.getFamilyName() << " " << teacher.getGivenName() << ": " << teacher.getNumbersOfStudents() << std::endl;
    }
}




