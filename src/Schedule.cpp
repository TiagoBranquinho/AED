//
// Created by alexandre on 05/12/21.
//

#include "../include/Schedule.h"

#include <iostream>

using namespace std;

Schedule::Schedule() = default;

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
    if (invalidSchedule(h, m) || c != ':')
        throw InvalidScheduleException();
    time.tm_hour = h;
    time.tm_min  = m;
}

void Schedule::setTime(unsigned int h, unsigned int m) {
    const size_t MAXSIZE=6;
    char timeStr[MAXSIZE];
    tm tm{0}; tm.tm_hour = (int)h; tm.tm_min = (int)m;
    strftime (timeStr,MAXSIZE,"%H:%M",&tm);
    setTime(timeStr);
}

string Schedule::getTime() const{
    const size_t MAXSIZE=6;
    char timeStr[MAXSIZE];
    strftime (timeStr,MAXSIZE,"%H:%M",&time);
    return timeStr;
}

void Schedule::setHour(unsigned int hour) {
    setTime(hour, time.tm_min);
}

void Schedule::setMin(unsigned int min) {
    setTime(time.tm_hour, min);
}

int Schedule::getHour() const {
    return time.tm_hour;
}

int Schedule::getMin() const {
    return time.tm_min;
}

bool Schedule::invalidSchedule(unsigned int h, unsigned int m) {
    return h < 0 || h > 24 || m < 0 || m > 59;
}

bool Schedule::operator<(const Schedule &s) const {
    return getTime() < s.getTime();
}

Schedule Schedule::diffTime(const Schedule &sch) {
    int res;
    int min1 = this->convertToMin();
    int min2 = sch.convertToMin();
    if (min1 > min2) res = min1 - min2;
    else res = min2 - min1;
    return convertToSchedule(abs(res));
}

Schedule Schedule::addTime(const Schedule &sch) const {
    int res;
    int min1 = this->convertToMin();
    int min2 = sch.convertToMin();
    res = min1 + min2;
    return convertToSchedule(res % (24 * 60));
}

int Schedule::convertToMin() const{
    return getHour()*60 + getMin();
}

Schedule Schedule::convertToSchedule(int min) {
    Schedule res("00:00");
    int h, m;
    h = min/60;
    m = min - h*60;
    res.setTime(h, m);
    return res;
}

std::ostream &operator<<(ostream &os, Schedule &schedule) {
    os << schedule.getTime();
    return os;
}

