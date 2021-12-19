//
// Created by Tiago Branquinho on 25/11/2021.
//

#ifndef PROJETOAEROPORTO_DATE_H
#define PROJETOAEROPORTO_DATE_H

#include <string>

class Date {
private:
    unsigned int day,month,year;
    std::string date;
public:
    Date();
    Date(std::string date);
    Date(unsigned int day, unsigned int month, unsigned int year);
    void setDate(std::string date);
    void setDate(unsigned int day, unsigned int month, unsigned int year);
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    std::string getDate() const;
    bool validDate(unsigned int day, unsigned int month, unsigned int year);
    bool validDate(std::string date);
    bool operator<(const Date &d) const;
    bool leapYear(unsigned int year);
};

class InvalidDateException: public std::exception{
private:
    unsigned int day,month,year;
public:
    InvalidDateException(unsigned int day,unsigned int month, unsigned int year):day(day),month(month),year(year){};
    const char * what () const noexcept override {
        return "Invalid date format!";
    }
};
#endif //PROJETOAEROPORTO_DATE_H
