#ifndef PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H
#define PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H

#include "bst.h"
#include "GroundTransportation.h"

class TransportationLocals {
private:
    BST<GroundTransportation> locals;
    unsigned int sz = 0;
public:
    TransportationLocals(): locals(GroundTransportation("", 0)){};
    void print();
    unsigned int size();
    void addGroundTransportation(const GroundTransportation &groundTransportation);
    void removeGroundTransportation(const GroundTransportation &groundTransportation);
    vector<GroundTransportation> asVector();
    BSTItrIn<GroundTransportation> itrInOrder();
    iteratorBST<GroundTransportation> beginItr();
    iteratorBST<GroundTransportation> endItr();
};


#endif //PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H
