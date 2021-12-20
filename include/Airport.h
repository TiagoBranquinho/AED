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
    /**
     * Class constructor that sets the name and city attributes
     * @param name airport name string
     * @param city airport city location string
     */
    Airport(std::string name, std::string city);
    unsigned int getId() const;
    std::string getName() const;
    std::string getCity() const;
    /**
     * Adds the ground transportation argument to the locals argument
     * @param groundTransportation ground transportation object passed by reference
     */
    void addGroundTransportation(const GroundTransportation &groundTransportation);
    /**
     * Gets the bst in order iterator in locals attribute
     * @return locals bst in order iterator
     */
    BSTItrIn<GroundTransportation> localsItrIn();
    /**
     * Gets the bst begin iterator in locals attribute
     * @return locals bst begin iterator
     */
    iteratorBST<GroundTransportation> localsBeginItr();
    /**
     * Gets the bst end iterator in locals attribute
     * @return locals bst end iterator
     */
    iteratorBST<GroundTransportation> localsEndItr();
    TransportationLocals &getLocals();
    /**
     * Operator to print the airport object in the correct format
     * @param os stream where the airport will be printed
     * @param aiport airport object passed by reference
     * @return ostream with the airport printed
     */
    friend std::ostream& operator<<(std::ostream& os, const Airport &aiport);
};


#endif //PROJETOAEROPORTO_AIRPORT_H
