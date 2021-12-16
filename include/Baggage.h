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
    double MAX_WEIGHT = 25;
    double weight;
    bool special;
    bool overweight;
    static unsigned int ID;

public:
    Baggage();
    Baggage(double weight, bool special);
    double getWeight() const;
    void setWeight(double weight);
    bool isSpecial() const;
    void setSpecial(bool special);
    bool isOverweight() const;
    void checkWeight();
    bool operator==(const Baggage &baggage);
    friend std::ostream& operator<<(std::ostream& os, const Baggage &baggage);
};


#endif //PROJETOAEROPORTO_BAGGAGE_H
