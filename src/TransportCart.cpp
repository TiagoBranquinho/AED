//
// Created by Tiago Branquinho on 12/12/2021.
//

#include "../include/TransportCart.h"

using namespace std;

TransportCart::TransportCart() = default;

TransportCart::TransportCart(unsigned int c, unsigned int n, unsigned int m) {
    this->c = c;
    this->n = n;
    this->m = m;
    for (unsigned int i = 0; i < n; i++)
        addStack();
    for (unsigned int i = 0; i < c; i++)
        addCarriage();
}

void TransportCart::setC(){
    this->c = c;
}

void TransportCart::setN(){
    this->n = n;
}

void TransportCart::setM(){
    this->m = m;
}

void TransportCart::addCarriage() {
    slots.push(list<stack<Baggage>>());
}

void TransportCart::addStack() {
    slots.back().push_back(stack<Baggage>());
}

bool TransportCart::addBaggage(const Baggage &baggage) {
    vector<list<stack<Baggage>>> slotsVector = vector<list<stack<Baggage>>>();
    bool done = false;
    for(int i = 0; i < c; i++){
        slotsVector.push_back(slots.front());
        slots.pop();
    }
    for(list<stack<Baggage>> carriage : slotsVector){
        for(stack<Baggage> stack : carriage){
            if(stack.size() == m){}
            else{
                stack.push(baggage);
                done = true;
                break;
            }
        }
        if(done)
            break;
    }
    for(list<stack<Baggage>> carriage : slotsVector){
        slots.push(carriage);
    }
    if(done)
        return true;
    return false;
}
