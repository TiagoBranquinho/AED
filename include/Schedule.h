#ifndef PROJETOAEROPORTO_SCHEDULE_H
#define PROJETOAEROPORTO_SCHEDULE_H

#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <exception>

//#if defined(_WIN32)
//    #define so() "win"
//#elif defined(unix) || defined(__unix__) || defined(__unix)
//    #define so() "unix"
//#endif

class Schedule {
private:
    size_t MAXSIZE=6;
    struct std::tm tm{0};

public:
    Schedule(const std::string& hm);
    void displayTime();
    void setTime(const std::string& hm); // string format HH:MM
    std::string getTime() const;
    int getHour() const;
    int getMin() const;
    bool operator<(const Schedule &s) const;
};

class InvalidScheduleException : public std::exception {
    const char * what () const noexcept override {
        return "Invalid schedule format!";
    }
};

#endif //PROJETOAEROPORTO_SCHEDULE_H
