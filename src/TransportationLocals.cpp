#include "../include/TransportationLocals.h"

void TransportationLocals::addGroundTransportation(const GroundTransportation &groundTransportation) {
    locals.insert(groundTransportation);
}

void TransportationLocals::printLocals() {
    locals.printTree();
}

BSTItrIn<GroundTransportation> TransportationLocals::localsItrIn() {
    return BSTItrIn<GroundTransportation>(locals);
}
