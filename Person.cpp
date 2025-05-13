#include "Person.h"

Person::Person(const char* GivenName, const char* FamilyName, const Date& DateOfBirth)
{
    givenName = new char[strlen(GivenName) + 1];
    strcpy(givenName, GivenName);
    familyName = new char[strlen(FamilyName) + 1];
    strcpy(familyName, FamilyName);
    dateOfBirth = DateOfBirth;
}

Person::Person(const Person& other)
{
    givenName = new char[strlen(other.givenName) + 1];
    strcpy(givenName, other.givenName);

    familyName = new char[strlen(other.familyName) + 1];
    strcpy(familyName, other.familyName);

    dateOfBirth = other.dateOfBirth;
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        givenName = new char[strlen(other.givenName) + 1];
        strcpy(givenName, other.givenName);

        familyName = new char[strlen(other.familyName) + 1];
        strcpy(familyName, other.familyName);

        dateOfBirth = other.dateOfBirth;
    }
    return *this;
}

const char* Person::getGivenName() const {
    return givenName;
}

const char* Person::getFamilyName() const {
    return familyName;
}

const Date& Person::getDateOfBirth() const {
    return dateOfBirth;
}

void Person::setGivenName(const char* name) {
    givenName = new char[strlen(name) + 1];
    strcpy(givenName, name);
}

void Person::setFamilyName(const char* name) {
    familyName = new char[strlen(name) + 1];
    strcpy(familyName, name);
}

void Person::setDateOfBirth(const Date& dob) {
    dateOfBirth = dob;
}

void Person::display() const {
    std::cout << "Name: " << (givenName ? givenName : "Unknown") << " " << (familyName ? familyName : "Unknown") << std::endl;
    std::cout << "Date of Birth: " << dateOfBirth << std::endl;
}

std::istream& operator>>(std::istream& in, Person& person) {
    char givenName[100];
    char familyName[100];
    std::string day, month;
    int year;

    in >> givenName >> familyName;

    person.givenName = new char[strlen(givenName) + 1];
    strcpy(person.givenName, givenName);

    person.familyName = new char[strlen(familyName) + 1];
    strcpy(person.familyName, familyName);
    in >> day >> month >> year;
    person.dateOfBirth = Date(day, month, year);

    return in;
}


