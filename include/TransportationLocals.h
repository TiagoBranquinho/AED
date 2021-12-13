#ifndef PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H
#define PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H

#include "bst.h"
#include "GroundTransportation.h"

class TransportationLocals {
private:
    BST<GroundTransportation> locals;
public:
    TransportationLocals(): locals(GroundTransportation("", 0)){};
    void print();
    void addGroundTransportation(const GroundTransportation &groundTransportation);
    void removeGroundTransportation(const GroundTransportation &groundTransportation);
    vector<GroundTransportation> asVector();
    BSTItrIn<GroundTransportation> itrInOrder();
    iteratorBST<GroundTransportation> beginItr();
    iteratorBST<GroundTransportation> endItr();
};


#endif //PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H
