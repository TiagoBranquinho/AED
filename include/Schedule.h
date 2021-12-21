#ifndef PROJETOAEROPORTO_SCHEDULE_H
#define PROJETOAEROPORTO_SCHEDULE_H

#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <exception>

class Schedule {
private:
    struct std::tm time{0};

public:
    /**
     * Default class constructor
     */
    Schedule();
    /**
     * Class constructor with the time string
     * @param hm time string in HH:MM format
     */
    Schedule(const std::string& hm);
    void setTime(const std::string& hm);
    /**
     * Sets the time with separated number of hours and minutes
     * @param hour hours integer number
     * @param min minutes integer number
     */
    void setTime(unsigned int hour, unsigned int min);
    /**
     * Gets the time string
     * @return time string in HH:MM format
     */
    std::string getTime() const;
    void setHour(unsigned int hour);
    int getHour() const;
    int getMin() const;
    /**
     * Checks if the time represented in the arguments is valid
     * @param hour hour integer number
     * @param min minutes integer number
     * @return true if the time is valid or false otherwise
     */
    bool invalidSchedule(unsigned int hour, unsigned int min);
    /**
     * Checks if the time is lower than another time
     * @param s schedule object passed by reference
     * @return true if this object time is lower than the schedule argument time or false otherwise
     */
    bool operator<(const Schedule &s) const;
    /**
     * Operator to print the schedule object in the correct format
     * @param os stream where the schedule will be printed
     * @param schedule schedule object passed by reference
     * @return ostream with the schedule printed
     */
    friend std::ostream &operator<<(std::ostream &os, Schedule &schedule);
    /**
     * Calculates the difference between two schedule's times
     * @param sch schedule object passed by reference
     * @return a new schedule object that represents that difference
     */
    Schedule diffTime(const Schedule& sch);
    /**
     * Adds a schedule time to another schedule object
     * @param sch schedule object passed by reference
     * @return a new schedule object with the result time
     */
    Schedule addTime(const Schedule& sch) const;
private:
    /**
     * Converts the time of hours and minutes to only minutes
     * @return integer number of minutes
     */
    int convertToMin() const;
    /**
     * Converts a number of minutes to a schedule object
     * @param min integer number of minutes
     * @return a new schedule object with the resultant time
     */
    static Schedule convertToSchedule(int min);
};

class InvalidScheduleException : public std::exception {
    const char * what () const noexcept override {
        return "Invalid schedule format!";
    }
};

#endif //PROJETOAEROPORTO_SCHEDULE_H
