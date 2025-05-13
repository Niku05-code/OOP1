#include <iostream>
#include "Date.h"

Date::Date(std::string Day, std::string Month, int Year)
{
    day = Day;
    month = Month;
    year = Year;
}

Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }
    return *this;
}

const std::string &Date::getDay() const
{
    return day;
}
const std::string &Date::getMonth() const
{
    return month;
}
const int &Date::getYear() const
{
    return year;
}

const int Date::getAge(Date data) const {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    int age = now->tm_year + 1900 - data.getYear();
    int month = std::stoi(data.getMonth());
    int day = std::stoi(data.getDay());
    if (now->tm_mon + 1 < month || (now->tm_mon + 1 == month && now->tm_mday < day))
        age--;
    return age;
}


std::ostream& operator<<(std::ostream& out, const Date& date)
{
    out << date.getDay();
    out << "/" << date.getMonth() << "/" << date.getYear();
    return out;
}



