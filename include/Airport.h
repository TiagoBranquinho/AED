//
// Created by Tiago Branquinho on 05/12/2021.
//

#ifndef PROJETOAEROPORTO_AIRPORT_H
#define PROJETOAEROPORTO_AIRPORT_H

#include <string>
#include <vector>
#include "bst.h"
#include "TransportationLocals.h"

class Airport {
private:
    std::string name;
    std::string city;
    TransportationLocals locals;

public:
    Airport(std::string name, std::string city);
    std::string getName();
    std::string getCity() const;
    void setName(std::string name);
    void setCity(std::string city);
    void addGroundTransportation(const GroundTransportation &groundTransportation);
    void printLocals();
    BSTItrIn<GroundTransportation> localsItrIn();
    iteratorBST<GroundTransportation> localsBeginItr();
    iteratorBST<GroundTransportation> localsEndItr();
    TransportationLocals &getLocals();

};


#endif //PROJETOAEROPORTO_AIRPORT_H
