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
    /**
     * Default class constructor
     */
    Date();
    /**
     * Class constructor with a date string
     * @param date string in YYYY/MM/DD format
     */
    Date(std::string date);
    /**
     * Class constructor with day, mont and year integer numbers
     * @param day day of the month
     * @param month month number
     * @param year year number
     */
    Date(unsigned int day, unsigned int month, unsigned int year);
    void setDate(std::string date);
    void setDate(unsigned int day, unsigned int month, unsigned int year);
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    std::string getDate() const;
    /**
     * Checks if a date with the given arguments is valid
     * @param day day of the month
     * @param month month number
     * @param year year number
     * @return true if the date if valid or false otherwise
     */
    bool validDate(unsigned int day, unsigned int month, unsigned int year);
    /**
     * Checks if a date with the given date string is valid
     * @param date string in YYYY/MM/DD format
     * @return true if the date if valid or false otherwise
     */
    bool validDate(std::string date);
    /**
     * Checks if a date is before another
     * @param d date object passed by reference
     * @return true if this date comes before d date or false otherwise
     */
    bool operator<(const Date &d) const;
    /**
     * Checks if a given year is a leap year
     * @param year year number
     * @return true if year argument is leap or false otherwise
     */
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
