//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
#define PROJETOAEROPORTO_GROUNDTRANSPORTATION_H

#include <string>

using namespace std;


class groundTransportation {

private:
    string type;
    unsigned int distance;
    //Schedule schedule; Class schedule should be implemented?

public:
    groundTransportation();
    groundTransportation(string type, unsigned int distance);
    void setType(string type);
    void setDistance(unsigned int distance);
    string getType();
    unsigned int getDistance();



};


#endif //PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
