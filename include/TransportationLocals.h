#ifndef PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H
#define PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H

#include "bst.h"
#include "GroundTransportation.h"

class TransportationLocals {
private:
    BST<GroundTransportation> locals;
public:
    TransportationLocals(): locals(GroundTransportation("", 0)){};
    void addGroundTransportation(const GroundTransportation &groundTransportation);
    void printLocals();
    BSTItrIn<GroundTransportation> localsItrIn();

};


#endif //PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H
