//
// Created by Tiago Branquinho on 12/12/2021.
//

#include "../include/TransportCart.h"

using namespace std;

unsigned int TransportCart::ID = 0;

TransportCart::TransportCart() = default;

TransportCart::TransportCart(unsigned int c, unsigned int n, unsigned int m): C_MAX(c), N_MAX(n), M_MAX(m) {
    id = ID++;
    buildCartCarriages();
}

unsigned int TransportCart::getC() const{
    return C_MAX;
}

unsigned int TransportCart::getN() const{
    return N_MAX;
}

unsigned int TransportCart::getM() const{
    return M_MAX;
}

std::list<std::list<std::stack<Baggage>>> TransportCart::getSlots() {
    return slots;
}

void TransportCart::addCarriage() {
    slots.emplace_back();
}

void TransportCart::addStack() {
    slots.back().push_back(stack<Baggage>());
}

bool TransportCart::addBaggage(const Baggage &baggage) {
    if (cartFull) return false;
    bool done = false;
    auto carriage = slots.begin();
    advance(carriage, numBaggages / (N_MAX * M_MAX));

    for (auto& stack : *carriage){
        if (stack.size() < M_MAX){
            stack.push(baggage);
            numBaggages++;
            done = true;
            break;
        }
    }
    checkCartFull();
    if (done) return done;
    else return false;
}

void TransportCart::buildCartCarriages() {
    slots.clear();
    for (unsigned int i = 0; i < C_MAX; i++) {
        addCarriage();
        for (unsigned int j = 0; j < N_MAX; j++)
            addStack();
    }
    cartFull = false;
    numBaggages = 0;
}

void TransportCart::checkCartFull() {
    if (numBaggages == C_MAX*N_MAX*M_MAX)
        cartFull = true;
}

bool TransportCart::operator==(const TransportCart &cart) const{
    return this->getId() == cart.getId();
}

unsigned int TransportCart::getId() const {
    return id;
}

unsigned int TransportCart::getNumBaggs() const{
    return numBaggages;
}

unsigned int TransportCart::getSize() const{
    return C_MAX*N_MAX*M_MAX;
}

bool TransportCart::empty() const {
    return numBaggages;
}

void TransportCart::reset() {
    buildCartCarriages();
}
