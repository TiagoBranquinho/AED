//
// Created by Tiago Branquinho on 25/11/2021.
//

#include "../include/Date.h"
#include <sstream>
#include <iomanip>

using namespace std;

Date::Date() = default;

Date::Date(std::string date) {
    setDate(date);
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    setDate(day, month, year);
}

void Date::setDate(std::string date) {
    if (validDate(date)) {
        int y, m, d; char c;
        stringstream ss(date);
        ss >> y >> c >> m >> c >> d;
        setDate(d,m,y);
    }
    else throw InvalidDateException(day, month, year);
}

void Date::setDate(unsigned int day, unsigned int month, unsigned int year) {
    if (validDate(day, month, year)){
        stringstream ss;
        ss   << setfill ('0') << setw (4) << year  << "/"
             << setfill ('0') << setw (2) << month << "/"
             << setfill ('0') << setw (2) << day ;
        date = ss.str();
        this->day = day;
        this->month = month;
        this->year = year;
    }
    else throw InvalidDateException(day, month, year);
}

unsigned int Date::getDay() const{
    return day;
}

unsigned int Date::getMonth() const{
    return month;
}

unsigned int Date::getYear() const {
    return year;
}

std::string Date::getDate() const{
    return date;
}

bool Date::validDate(unsigned int day, unsigned int month, unsigned int year) {
    if (day == 0 || month == 0 || year == 0 || day > 31 || month > 12)
        return false;
    if (leapYear(year)){
        if (month == 2 && day > 29)
            return false;
        if ((month < 8 && month%2 == 0) || (month >= 8 && month%2 != 0))
            return day <= 30;
    }
    else{
        if (month == 2 && day > 28)
            return false;
        if ((month < 8 && month%2 == 0) || (month >= 8 && month%2 != 0))
            return day <= 30;
    }
    return true;
}

bool Date::validDate(string date) {
    int y, m, d; char c;
    stringstream ss(date);
    ss >> y >> c >> m >> c >> d;
    if (validDate(d,m,y) && c == '/')
        return true;
    return false;
}

bool Date::operator<(const Date &d) const {
    return getDate() < d.getDate();
}

bool Date::leapYear(unsigned int year) {
    if (year%4 == 0){
        if (year%100 == 0){
            if (year%400 == 0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

std::ostream &operator<<(ostream &os, const Date &date) {
    os << date.getDate();
    return os;
}

