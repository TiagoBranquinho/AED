//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "../include/groundTransportation.h"

using namespace std;


groundTransportation::groundTransportation() = default;

groundTransportation::groundTransportation(string type, unsigned int distance) {
    this->type = type;
    this->distance = distance;

}

void groundTransportation::setType(string type) {
    this->type = type;
}

void groundTransportation::setDistance(unsigned int distance) {
    this->distance = distance;
}

string groundTransportation::getType() {
    return type;
}

unsigned int groundTransportation::getDistance() {
    return distance;
}

void groundTransportation::setSchedules(vector<Schedule> &schedules) {
    this->schedules = schedules;
    sortSchedules();
}

std::vector<Schedule> groundTransportation::getSchedules() {
    return schedules;
}

void groundTransportation::addSchedule(const Schedule &schedule) {
    schedules.push_back(schedule);
    sortSchedules();
}

void groundTransportation::removeSchedule(const Schedule &schedule) {
    for(vector<Schedule>::iterator it = schedules.begin(); it != schedules.end(); it++){
        if((*it).getTime() == schedule.getTime()) {
            schedules.erase(it);
            break;
        }
    }
}

bool CompareSchedule(Schedule schedule1, Schedule schedule2){
    return schedule1 < schedule2;
}

void groundTransportation::sortSchedules() {
    sort(schedules.begin(), schedules.end(), CompareSchedule);
}



