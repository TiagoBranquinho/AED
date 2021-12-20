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
    GroundTransportation();
    GroundTransportation(std::string type, unsigned int distance);
    void setType(std::string type);
    unsigned int getId() const;
    std::string getType() const;
    unsigned int getDistance() const;
    std::vector<Schedule> getSchedules();
    void addSchedule(const Schedule &schedule);
    void removeSchedule(const Schedule &schedule);
    void sortSchedules();
    void printSchedules();
    bool operator<(const GroundTransportation &local) const;
    friend std::ostream &operator<<(std::ostream &os, GroundTransportation &local);
};


#endif //PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
