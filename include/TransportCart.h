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
    unsigned int c,n,m;  // c -> numero de carruagens, n -> numero de pilhas por carruagem, m -> numero de malas por pilha
    std::queue<std::list<std::stack<Baggage>>> slots;
public:
    TransportCart();
    TransportCart(unsigned int c, unsigned int n,unsigned int m);
    void setC(unsigned int c);
    void setN(unsigned int n);
    void setM(unsigned int m);
    void addCarriage();
    void addStack();
    bool addBaggage(const Baggage &baggage);
};


#endif //PROJETOAEROPORTO_TRANSPORTCART_H
