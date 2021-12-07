//
// Created by Tiago Branquinho on 04/12/2021.
//

#include "groundTransportation.h"

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

bool CompareSchedule(Schedule schedule1, Schedule schedule2){
    return schedule1 < schedule2;
}

void groundTransportation::sortSchedules() {
    sort(schedules.begin(), schedules.end(), CompareSchedule);
}



