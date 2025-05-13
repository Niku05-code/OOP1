#pragma once
#include <iostream>
#include "Date.h"
#include "Date.h"

class Person {
protected:
    char* givenName;
    char* familyName;
    Date dateOfBirth;

public:
    Person() = default;
    Person(const char* givenName, const char* familyName, const Date& dateOfBirth);

    Person(const Person& other);

    Person& operator=(const Person& other);

    //virtual ~Person() = default;

    const char* getGivenName() const;
    const char* getFamilyName() const;
    const Date& getDateOfBirth() const;

    void setGivenName(const char* name);
    void setFamilyName(const char* name);
    void setDateOfBirth(const Date& dob);

    friend std::istream& operator>>(std::istream& in, Person& person);

    virtual void display() const;
};
