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
    Schedule();
    Schedule(const std::string& hm);
    void setTime(const std::string& hm); // string format HH:MM
    void setTime(unsigned int hour, unsigned int min);
    std::string getTime() const;
    void setHour(unsigned int hour);
    int getHour() const;
    int getMin() const;
    bool invalidSchedule(unsigned int hour, unsigned int min);
    bool operator<(const Schedule &s) const;
    friend std::ostream &operator<<(std::ostream &os, Schedule &schedule);
    Schedule diffTime(const Schedule& sch);
    Schedule addTime(const Schedule& sch) const;
private:
    int convertToMin() const;
    static Schedule convertToSchedule(int min);
};

class InvalidScheduleException : public std::exception {
    const char * what () const noexcept override {
        return "Invalid schedule format!";
    }
};

#endif //PROJETOAEROPORTO_SCHEDULE_H
