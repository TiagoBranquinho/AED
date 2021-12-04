//
// Created by Tiago Branquinho on 25/11/2021.
//

#include "Date.h"

using namespace std;


Date::Date() = default;

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    if (!isValid(day, month))
        throw InvalidDateException(day, month);
}

void Date::setDay(unsigned int day) {
    this->day = day;
    if (!isValid(day, month))
        throw InvalidDateException(day, month);
}

void Date::setMonth(unsigned int month) {
    this->month = month;
    if (!isValid(day, month))
        throw InvalidDateException(day, month);
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

unsigned int Date::getDay() {
    return day;
}

unsigned int Date::getMonth() {
    return month;
}

unsigned int Date::getYear() {
    return year;
}

bool Date::isValid(unsigned int day, unsigned int month) {
    unsigned int maxDays = 30;
    if(month > 12)
        return false;
    else if(month == 2){
        maxDays = 28;
    }
    else if(month < 8) {
        if(month % 2 != 0){
            maxDays = 31;
        }
    }
    else if(month % 2 == 0)
        maxDays = 31;
    if(day > maxDays)
        return false;
    return true;
}

bool Date::operator<(Date &d) const {
    if(this->year == d.getYear()){
        if(this->month == d.getMonth()){
            return this->day < d.getDay();
        }
        else
            return this->month < d.getMonth();
    }
    else
        return this->year < d.getYear();
}

