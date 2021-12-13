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
    char c; int h, m;
    stringstream input(hm);
    input >> h >> c >> m;
    if (h < 0 || h > 24 || m < 0 || m > 59 || c != ':')
        throw InvalidScheduleException();
    tm.tm_hour = h;
    tm.tm_min  = m;
    }

string Schedule::getTime() const{
    char timeStr[MAXSIZE];
    strftime (timeStr,MAXSIZE,"%H:%M",&tm);
    return timeStr;
}

int Schedule::getHour() const {
    return tm.tm_hour;
}

int Schedule::getMin() const {
    return tm.tm_min;
}

bool Schedule::operator<(const Schedule &s) const {
    return getTime() < s.getTime();
}
