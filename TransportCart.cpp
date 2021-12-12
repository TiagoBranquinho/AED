//
// Created by Tiago Branquinho on 12/12/2021.
//

#include "TransportCart.h"

TransportCart::TransportCart() = default;

TransportCart::TransportCart(unsigned int c, unsigned int n, unsigned int m) {
    this->c = c;
    this->n = n;
    this->m = m;
}

void TransportCart::addBaggage(const Baggage &baggage) {

}
