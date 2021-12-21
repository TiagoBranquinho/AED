//
// Created by Tiago Branquinho on 25/11/2021.
//

#ifndef PROJETOAEROPORTO_BAGGAGE_H
#define PROJETOAEROPORTO_BAGGAGE_H
#include <string>
#include <sstream>

class Baggage {
private:
    unsigned int id;
    int MAX_WEIGHT = 25;
    int weight;
    bool overweight;
    static unsigned int ID;

public:
    /**
     * Default class constructor
     */
    Baggage();
    /**
     * Class constructor with weight argument
     * @param weight weight of the baggage
     */
    Baggage(int weight);
    unsigned int getId() const;
    int getWeight() const;
    /**
     * Checks if the weight of the baggage is greater than the max weight and updates overweight bool attribute
     */
    void checkWeight();
    /**
     * Checks if a baggage is the same as the other based on their id attribute
     * @param baggage baggage object passed by reference
     * @return true if they have the same id or false otherwise
     */
    bool operator==(const Baggage &baggage) const;
    /**
     * Operator to print the baggage object in the correct format
     * @param os stream where the baggage will be printed
     * @param baggage baggage object passed by reference
     * @return ostream with the baggage printed
     */
    friend std::ostream& operator<<(std::ostream& os, const Baggage &baggage);
};


#endif //PROJETOAEROPORTO_BAGGAGE_H
