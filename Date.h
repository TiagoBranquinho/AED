//
// Created by Tiago Branquinho on 25/11/2021.
//

#ifndef PROJETOAEROPORTO_DATE_H
#define PROJETOAEROPORTO_DATE_H
#include <string>


class Date {
private:
    unsigned int day,month,year;
public:
    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);
    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);
    unsigned int getDay();
    unsigned int getMonth();
    unsigned int getYear();
    static bool isValid(unsigned int day, unsigned int month);
    bool operator<(Date &d) const;
};

class InvalidDateException {
private:
    unsigned int day,month;
public:
    InvalidDateException(unsigned int day,unsigned int month):day(day),month(month){};
    unsigned int getDay() {return day;};
    unsigned int getMonth() {return month;};

};
#endif //PROJETOAEROPORTO_DATE_H
