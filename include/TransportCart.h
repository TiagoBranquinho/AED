//
// Created by Tiago Branquinho on 12/12/2021.
//

#ifndef PROJETOAEROPORTO_TRANSPORTCART_H
#define PROJETOAEROPORTO_TRANSPORTCART_H


#include <queue>
#include <list>
#include <stack>
#include "Baggage.h"

class TransportCart {
private:
    bool cartFull = false;
    unsigned int numBaggages = 0;
    const unsigned int C_MAX = 0, N_MAX = 0, M_MAX = 0;  // C_MAX -> numero de carruagens, N_MAX -> numero de pilhas por carruagem, M_MAX -> numero de malas por pilha
    std::list<std::list<std::stack<Baggage>>> slots;
public:
    TransportCart();
    TransportCart(unsigned int c, unsigned int n,unsigned int m);
    unsigned int getC() const;
    unsigned int getN() const;
    unsigned int getM() const;
    std::list<std::list<std::stack<Baggage>>> getSlots();
    void addCarriage();
    void addStack();
    bool addBaggage(const Baggage &baggage);

private:
    void buildCartCarriages();
    void checkCartFull();
};


#endif //PROJETOAEROPORTO_TRANSPORTCART_H
