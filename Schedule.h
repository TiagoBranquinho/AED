#ifndef PROJETOAEROPORTO_SCHEDULE_H
#define PROJETOAEROPORTO_SCHEDULE_H

#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>

class Schedule {
private:
    std::time_t time;
    struct std::tm tm{0};

public:
    Schedule(const std::string& hm);
    void displayTime();
    void setTime(const std::string& hm); // string format HH:MM
    std::string getTime();
    int getHour() const;
    int getMin() const;
    bool operator<(const Schedule &s) const;
};


#endif //PROJETOAEROPORTO_SCHEDULE_H
