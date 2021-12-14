//
// Created by Tiago Branquinho on 12/12/2021.
//

#include "../include/TransportCart.h"

using namespace std;

TransportCart::TransportCart() = default;

TransportCart::TransportCart(unsigned int c, unsigned int n, unsigned int m) {
    this->m = m;
    for (unsigned int i = 0; i < c; i++) {
        addCarriage();
        for (unsigned int i = 0; i < n; i++)
            addStack();
    }
    this->n= this->n / c;
}

void TransportCart::setC(unsigned int c){
    this->c = c;
}

void TransportCart::setN(unsigned int n){
    this->n = n;
}

void TransportCart::setM(unsigned int m){
    this->m = m;
}

int TransportCart::getC(){
    return c;
}

int TransportCart::getN(){
    return n;
}

int TransportCart::getM(){
    return m;
}

std::queue<std::list<std::stack<Baggage>>> TransportCart::getSlots() {
    return slots;
}

void TransportCart::addCarriage() {
    slots.push(list<stack<Baggage>>());
    c++;
}

void TransportCart::addStack() {
    slots.back().push_back(stack<Baggage>());
    n++;
}

bool TransportCart::addBaggage(const Baggage &baggage) {
    vector<list<stack<Baggage>>> slotsVector = vector<list<stack<Baggage>>>();
    bool done = false;
    for(int i = 0; i < c; i++){
        slotsVector.push_back(slots.front());
        slots.pop();
    }
    for(const list<stack<Baggage>> carriage : slotsVector){
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
    for(const list<stack<Baggage>> carriage : slotsVector){
        slots.push(carriage);
    }
    if(done)
        return true;
    return false;
}
