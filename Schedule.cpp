//
// Created by alexandre on 05/12/21.
//

#include "Schedule.h"

#include <iostream>

using namespace std;

Schedule::Schedule(const string& hm) {
    setTime(hm);
}

void Schedule::displayTime() {
    cout << getTime();
}

void Schedule::setTime(const std::string& hm) {
    strptime(hm.c_str(), "%R", &tm);
    time = mktime(&tm);
}

string Schedule::getTime() {
    stringstream ss;
    ss << put_time(&tm, "%R");
    return ss.str();
}

int Schedule::getHour() const {
    return tm.tm_hour;
}

int Schedule::getMin() const {
    return tm.tm_min;
}

bool Schedule::operator<(const Schedule &s) const {
    return this->time < s.time;
}