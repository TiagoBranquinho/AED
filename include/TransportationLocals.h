#ifndef PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H
#define PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H

#include "bst.h"
#include "GroundTransportation.h"

class TransportationLocals {
private:
    BST<GroundTransportation> locals;
    unsigned int sz = 0;
public:
    /**
     * Class constructor with the not found node for the locals bst
     */
    TransportationLocals(): locals(GroundTransportation("", 0)){};
    /**
     * Prints all the ground transportations in the locals bst
     */
    void print();
    unsigned int size()const;
    /**
     * Adds a ground transportation to the locals bst
     * @param groundTransportation ground transportation object passed by reference
     */
    void addGroundTransportation(const GroundTransportation &groundTransportation);
    /**
     * Removes a ground transportation from locals bst
     * @param groundTransportation ground transportation object passed by reference
     */
    void removeGroundTransportation(const GroundTransportation &groundTransportation);
    /**
     * Gets a vector of all the ground transportation nodes of the locals bst
     * @return vector of nodes of the locals bst
     */
    vector<GroundTransportation> asVector();
    BSTItrIn<GroundTransportation> itrInOrder();
    iteratorBST<GroundTransportation> beginItr();
    iteratorBST<GroundTransportation> endItr();
};


#endif //PROJETOAEROPORTO_TRANSPORTATIONLOCALS_H
