//
// Created by Tiago Branquinho on 04/12/2021.
//

#ifndef PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
#define PROJETOAEROPORTO_GROUNDTRANSPORTATION_H

#include <string>


class groundTransportation {

private:
    std::string type;
    unsigned int distance;
    //Schedule schedule; Class schedule should be implemented?

public:
    groundTransportation();
    groundTransportation(std::string type, unsigned int distance);
    void setType(std::string type);
    void setDistance(unsigned int distance);
    std::string getType();
    unsigned int getDistance();



};


#endif //PROJETOAEROPORTO_GROUNDTRANSPORTATION_H
