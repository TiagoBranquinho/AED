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
    /**
     * Default class contructor
     */
    GroundTransportation();
    /**
     * Class constructor with ground transportation type and distance
     * @param type type string
     * @param distance distance integer
     */
    GroundTransportation(std::string type, unsigned int distance);
    void setType(std::string type);
    unsigned int getId() const;
    std::string getType() const;
    unsigned int getDistance() const;
    /**
     * Gets a copy of the schedules vector of the ground transportation
     * @return copy of the schedules vector
     */
    std::vector<Schedule> getSchedules();
    void addSchedule(const Schedule &schedule);
    void removeSchedule(const Schedule &schedule);
    void sortSchedules();
    void printSchedules();
    /**
     * Checks what ground transportation has the smaller distance
     * @param local ground transportation object passed by reference
     * @return true if this ground transportation has smaller distance or false otherwise
     */
    bool operator<(const GroundTransportation &local) const;
    /**
     * Operator to print the ground transportation object in the correct format
     * @param os stream where the ground transportation will be printed
     * @param local ground transportation object passed by reference
     * @return ostream with the ground transportation printed
     */
    friend std::ostream &operator<<(std::ostream &os, GroundTransportation &local);
};


#endif //PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
