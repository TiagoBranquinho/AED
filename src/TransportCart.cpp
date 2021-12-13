//
// Created by Tiago Branquinho on 12/12/2021.
//

#include "../include/TransportCart.h"

TransportCart::TransportCart() = default;

TransportCart::TransportCart(unsigned int c, unsigned int n, unsigned int m) {
    this->c = c;
    this->n = n;
    this->m = m;
    for (unsigned int i = 0; i < n; i++)
        carriage.emplace_back(std::stack<Baggage>());
    for (unsigned int i = 0; i < c; i++)
        slots.push(carriage);
}

void TransportCart::addBaggage(const Baggage &baggage) {

}
