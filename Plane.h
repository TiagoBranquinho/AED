#ifndef PROJETOAEROPORTO_PLANE_H
#define PROJETOAEROPORTO_PLANE_H

#include <string>
#include <list>
#include <queue>

#include "Flight.h"
#include "Service.h"

using namespace std;

class Plane {

private:
    string plate;
    unsigned int capacity;
    list<Flight> flightPlan;
    queue<Service> servicesTODO;
    queue<Service> servicesDONE;

public:
    Plane(string plate, unsigned int capacity);
    string getPlate();
    unsigned int getCapacity();
    void setPlate(string plate);
    void setCapacity(unsigned int capacity);

};

#endif //PROJETOAEROPORTO_PLANE_H