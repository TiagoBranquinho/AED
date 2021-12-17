//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
#define PROJETOAEROPORTO_GROUNDTRANSPORTATION_H

#include <string>
#include "Schedule.h"
#include <vector>
#include <algorithm>


class GroundTransportation {

private:
    unsigned int id;
    std::string type;
    unsigned int distance;
    std::vector<Schedule> schedules;
    static unsigned int ID;

public:
    GroundTransportation(std::string type, unsigned int distance);
    void setType(std::string type);
    void setDistance(unsigned int distance);
    std::string getType() const;
    unsigned int getDistance() const;
    void setSchedules(std::vector<Schedule> &schedules);
    std::vector<Schedule> getSchedules();
    void addSchedule(const Schedule &schedule);
    void removeSchedule(const Schedule &schedule);
    void sortSchedules();
    bool operator<(const GroundTransportation &local) const;
    friend std::ostream &operator<<(std::ostream &os, GroundTransportation &local);
};

class ScheduleNotFoundException{
private:
    Schedule schedule;
public:
    ScheduleNotFoundException(Schedule schedule) : schedule(schedule) {};
    Schedule getSchedule(){return schedule;}
};


#endif //PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
