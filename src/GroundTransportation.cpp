//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/GroundTransportation.h"

using namespace std;

unsigned GroundTransportation::ID = 0;

GroundTransportation::GroundTransportation(string type, unsigned int distance) {
    this->type = type;
    this->distance = distance;
    id = ID++;
}

void GroundTransportation::setType(string type) {
    this->type = type;
}

void GroundTransportation::setDistance(unsigned int distance) {
    this->distance = distance;
}

string GroundTransportation::getType() const {
    return type;
}

unsigned int GroundTransportation::getDistance() {
    return distance;
}

void GroundTransportation::setSchedules(vector<Schedule> &schedules) {
    this->schedules = schedules;
    sortSchedules();
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
    os << local.getType() << endl;
    return os;
}



