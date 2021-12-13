//
// Created by Tiago Branquinho on 25/11/2021.
//

#ifndef PROJETOAEROPORTO_BAGGAGE_H
#define PROJETOAEROPORTO_BAGGAGE_H
#include <string>


class Baggage {
private:
    double MAX_WEIGHT = 25;
    double weight;
    bool special;
    bool overweight;
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
};


#endif //PROJETOAEROPORTO_BAGGAGE_H