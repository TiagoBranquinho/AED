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
    unsigned int id;
    bool cartFull = false;
    unsigned int numBaggages = 0;
    unsigned int C_MAX = 0, N_MAX = 0, M_MAX = 0;// C_MAX -> numero de carruagens, N_MAX -> numero de pilhas por carruagem, M_MAX -> numero de malas por pilha
    std::list<std::list<std::stack<Baggage>>> slots;
    static unsigned int ID;
public:
    /**
     * Default class constructor
     */
    TransportCart();
    /**
     * Class constructor with the number of carriages, number of stacks per carriage and number of baggage per stack
     * @param c number of carriages
     * @param n number of stacks per carriage
     * @param m number of baggage per stack
     */
    TransportCart(unsigned int c, unsigned int n,unsigned int m);
    unsigned int getC() const;
    unsigned int getN() const;
    unsigned int getM() const;
    unsigned int getId()const;
    /**
     * Gets the maximum capacity of the transportation cart
     * @return maximum size of the cart
     */
    unsigned int getSize() const;
    /**
     * Checks if the cart is empty
     * @return true if it is empty or false otherwise
     */
    bool empty() const;
    /**
     * Gets a copy of the cart's data structure
     * @return list of lists of stacks of baggage
     */
    std::list<std::list<std::stack<Baggage>>> getSlots();
    void addCarriage();
    void addStack();
    bool addBaggage(const Baggage &baggage);
    /**
     * Gets the next baggage available in the transportation cart stacks
     * @return a copy of the baggage object
     */
    Baggage getaBaggage();
    /**
     * Clean all the baggage of the transportation cart
     */
    void reset();
    /**
     * Checks if the transportation cart is the same as another based on their id
     * @param cart transportation cart object passed by reference
     * @return true if the cart is the same or false otherwise
     */
    bool operator==(const TransportCart &cart) const;
    /**
     * Operator to print the transportation cart object in the correct format
     * @param os stream where the transportation cart will be printed
     * @param transportCart transportation cart object passed by reference
     * @return ostream with the transportation cart printed
     */
    friend std::ostream& operator<<(std::ostream& os, const TransportCart &transportCart);
private:
    /**
     * Builds the structure of the cart adding carriages and stacks as needed
     */
    void buildCartCarriages();
    /**
     * Checks if the transportation cart is full and update his bool cartFull attribute
     */
    void checkCartFull();
};


#endif //PROJETOAEROPORTO_TRANSPORTCART_H
