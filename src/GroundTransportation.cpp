//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/GroundTransportation.h"
#include <iostream>

using namespace std;

unsigned GroundTransportation::ID = 0;

GroundTransportation::GroundTransportation() = default;

GroundTransportation::GroundTransportation(string type, unsigned int distance) {
    this->type = type;
    this->distance = distance;
    id = ID++;
}

void GroundTransportation::setType(string type) {
    this->type = type;
}

unsigned int GroundTransportation::getId() const{
    return id;
}

string GroundTransportation::getType() const {
    return type;
}

unsigned int GroundTransportation::getDistance() const{
    return distance;
}

std::vector<Schedule> GroundTransportation::getSchedules() {
    return schedules;
}

void GroundTransportation::addSchedule(const Schedule &schedule) {
    schedules.push_back(schedule);
    sortSchedules();
}

void GroundTransportation::removeSchedule(const Schedule &schedule) {
    for(auto it = schedules.begin(); it != schedules.end(); it++){
        if((*it).getTime() == schedule.getTime()) {
            schedules.erase(it);
            break;
        }
    }
}

void GroundTransportation::sortSchedules() {
    sort(schedules.begin(), schedules.end());
}

bool GroundTransportation::operator<(const GroundTransportation &local) const {
    return distance < local.distance;
}

ostream &operator<<(ostream &os, GroundTransportation &local) {
    os << local.getId() << setw(3) << "-" << setw(10) <<  local.getType() << setw(7) << "-" << setw(10) << local.getDistance() << endl;
    return os;
}

void GroundTransportation::printSchedules() {
    for (auto sch : schedules){
        cout << sch.getTime() << endl;
    }
}



