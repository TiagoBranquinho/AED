//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
#define PROJETOAEROPORTO_GROUNDTRANSPORTATION_H

#include <string>
#include "Schedule.h"
#include <vector>
#include <algorithm>


class groundTransportation {

private:
    std::string type;
    unsigned int distance;
    std::vector<Schedule> schedules;
public:
    groundTransportation();
    groundTransportation(std::string type, unsigned int distance);
    void setType(std::string type);
    void setDistance(unsigned int distance);
    std::string getType();
    unsigned int getDistance();
    void setSchedules(std::vector<Schedule> &schedules);
    std::vector<Schedule> getSchedules();
    void addSchedule(const Schedule &schedule);
    void removeSchedule(const Schedule &schedule);
    void sortSchedules();
};

class ScheduleNotFoundException{
private:
    Schedule schedule;
public:
    ScheduleNotFoundException(Schedule schedule) : schedule(schedule) {};
    Schedule getSchedule(){return schedule;}
};


#endif //PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
