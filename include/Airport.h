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
    unsigned int id;
    std::string name;
    std::string city;
    TransportationLocals locals;
    static unsigned int ID;

public:
    Airport(std::string name, std::string city);
    unsigned int getId() const;
    std::string getName() const;
    std::string getCity() const;
    void setName(std::string name);
    void setCity(std::string city);
    void addGroundTransportation(const GroundTransportation &groundTransportation);
    void printLocals();
    BSTItrIn<GroundTransportation> localsItrIn();
    iteratorBST<GroundTransportation> localsBeginItr();
    iteratorBST<GroundTransportation> localsEndItr();
    TransportationLocals &getLocals();
    friend std::ostream& operator<<(std::ostream& os, const Airport &aiport);
};


#endif //PROJETOAEROPORTO_AIRPORT_H
