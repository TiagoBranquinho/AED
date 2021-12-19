#include "../include/TransportationLocals.h"

void TransportationLocals::print() {
    locals.printTree();
}

void TransportationLocals::addGroundTransportation(const GroundTransportation &groundTransportation) {
    locals.insert(groundTransportation);
    sz++;
}

void TransportationLocals::removeGroundTransportation(const GroundTransportation &groundTransportation) {
    locals.remove(groundTransportation);
    sz--;
}

vector<GroundTransportation> TransportationLocals::asVector() {
    vector<GroundTransportation> v;
    iteratorBST<GroundTransportation> it = locals.begin();
    while (it != locals.end()){
        v.push_back(*it);
        it++;
    }
    return v;
}

BSTItrIn<GroundTransportation> TransportationLocals::itrInOrder() {
    return BSTItrIn<GroundTransportation>(locals);
}

iteratorBST<GroundTransportation> TransportationLocals::beginItr() {
    return locals.begin();
}

iteratorBST<GroundTransportation> TransportationLocals::endItr() {
    return locals.end();
}

unsigned int TransportationLocals::size() const{
    return sz;
}
