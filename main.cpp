#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <vector>

// void studentTestFunc() {
//     Student student1("John", "Doe", 1);
//     student1.addGrade(85);
//     student1.addGrade(90);
//     student1.display();
//     Student student2 = student1;
//     student2.display();
//     student2.addGrade(95);
//     std::cout<<student1;
//     std::cout<<student2;
// }

int main()
{
    // std::vector<std::pair<Subjects, std::vector<int>>> grades = {
    //     {Subjects::Math, {85, 90, 92}},
    //     {Subjects::ComputerScience, {78, 80, 88}},
    //     {Subjects::English, {91, 85}},
    //     {Subjects::Physics, {88, 93}},
    //     {Subjects::History, {95, 100}}
    // };
    // Student student1("Andrei", "Palaghia", Date("15", "3", 1980), 10, grades, Status::ENROLLED);
    //
    // std::cout << student1 << std::endl;

    // Student student1("John", "Doe", 1);
    // Student student2("Johnny", "Domer", 4);
    // std::vector<Student> students = {student1, student2};
    // Teacher teacher("Alice", "Johnson", Date("15", "3", 1980), Subjects::Math, {"01", "09", 2020}, students);
    // teacher.display();
    //
    // studentTestFunc();
    //
    std::ifstream fin("student.txt");
    std::vector<Student> students;
    if (!fin) {
        std::cerr << "Eroare la deschiderea fisierului!" << std::endl;
        return 1;
    }
    Student student1;
    while (fin >> student1)
    {
        students.push_back(student1);
    }
    fin.close();
    for(auto student : students) {
        std::cout << student;
        std::cout << std::endl;
    }
    //
    // studentStatus(students, Status::ENROLLED);
    // std::cout << std::endl;
    //
    // // student1 = students[0];
    // // student1.addGrade(5, student1);
    // // student1.modifyGrade(1, 3);
    // // student1.removeGrade(0);
    // // std::cout << std::endl;
    // // students[0] = student1;
    //
    // //std::cout << students[0] << std::endl;
    //
    // sortStudents(students);
    // for(auto student : students) {
    //     std::cout << student;
    //     std::cout << std::endl;
    // }

    return 0;
}